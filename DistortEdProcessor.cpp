#include "DistortEdProcessor.h"
#include "DistortEdEditor.h"
#include "DistortEd_Algorithms.h"

//==============================================================================
DistortEdProcessor::DistortEdProcessor ()
        : AudioProcessor (BusesProperties ()
#if !JucePlugin_IsMidiEffect
#if !JucePlugin_IsSynth
                                  .withInput ("Input", juce::AudioChannelSet::stereo (), true)
#endif
                                  .withOutput ("Output", juce::AudioChannelSet::stereo (), true)
#endif
),
          parameters (*this, nullptr, juce::Identifier ("DistortEdTree"),
                      {
                              std::make_unique<juce::AudioParameterFloat> ("gainModule",
                                                                           "Volume",
                                                                           0.0f,
                                                                           1.0f,
                                                                           0.0f),
                              std::make_unique<juce::AudioParameterFloat> ("tone",
                                                                           "Tone",
                                                                           0.0f,
                                                                           1.0f,
                                                                           0.0f),
                              std::make_unique<juce::AudioParameterFloat> ("drv",
                                                                           "Drive",
                                                                           0.0f,
                                                                           1.0f,
                                                                           0.0f),
                              std::make_unique<juce::AudioParameterBool> ("crsh",
                                                                          "Crush",
                                                                          0.0f
                              ),
                              std::make_unique<juce::AudioParameterBool> ("rect",
                                                                          "Rectify",
                                                                          0.0f
                              ),
                              std::make_unique<juce::AudioParameterBool> ("byp",
                                                                          "Bypass",
                                                                          0.0f
                              )
                      }
          )
{
    m_volume = parameters.getRawParameterValue ("gainModule");
    m_tone = parameters.getRawParameterValue ("tone");
    m_drive = parameters.getRawParameterValue ("drv");
    m_crush = parameters.getRawParameterValue ("crsh");
    m_bypass = parameters.getRawParameterValue ("byp");
    m_rectify = parameters.getRawParameterValue ("rect");

}

DistortEdProcessor::~DistortEdProcessor ()
{
}

//==============================================================================


//==============================================================================
void DistortEdProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    juce::ignoreUnused (sampleRate, samplesPerBlock);
    gainModule.prepare (sampleRate, samplesPerBlock);
}

void DistortEdProcessor::releaseResources ()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void DistortEdProcessor::processBlock (juce::AudioBuffer<float>& buffer,
                                       juce::MidiBuffer& midiMessages)
{


    juce::ignoreUnused (midiMessages);
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels = getTotalNumInputChannels ();
    auto totalNumOutputChannels = getTotalNumOutputChannels ();

    for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
    {
        buffer.clear (i, 0, buffer.getNumSamples ());
    }

    auto volume = m_volume->load ();
    auto drive = m_drive->load ();

    cubicModule.process (buffer, midiMessages, drive);

    gainModule.process (buffer, midiMessages, volume);


}

//==============================================================================


juce::AudioProcessorEditor* DistortEdProcessor::createEditor ()
{
    return new DistortEdEditor (*this, parameters);
}

void DistortEdProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    auto state = parameters.copyState ();
    std::unique_ptr<juce::XmlElement> xml (state.createXml ());
    copyXmlToBinary (*xml, destData);
}
void DistortEdProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    std::unique_ptr<juce::XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));

    if (xmlState.get () != nullptr)
        if (xmlState->hasTagName (parameters.state.getType ()))
            parameters.replaceState (juce::ValueTree::fromXml (*xmlState));
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter ()
{
    return new DistortEdProcessor ();
}
juce::AudioProcessorValueTreeState::ParameterLayout DistortEdProcessor::createParameters ()
{

}
bool DistortEdProcessor::isBusesLayoutSupported (const juce::AudioProcessor::BusesLayout& layouts) const
{
    if (layouts.getMainInputChannelSet () == juce::AudioChannelSet::disabled ()
        || layouts.getMainOutputChannelSet () == juce::AudioChannelSet::disabled ())
        return false;
    if (layouts.getMainOutputChannelSet () != juce::AudioChannelSet::stereo ())
        return false;
    if (layouts.getMainInputChannelSet () != juce::AudioChannelSet::stereo ()
        || layouts.getMainInputChannelSet () != juce::AudioChannelSet::mono ())
        return true;
    else
        return false;
    return true;
}



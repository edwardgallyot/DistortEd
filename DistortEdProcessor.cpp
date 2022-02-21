#include "DistortEdProcessor.h"
#include "DistortEdEditor.h"

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
                              std::make_unique<juce::AudioParameterFloat> ("vol",
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
                                                                           0.0f)
                      })
{
    m_volume = parameters.getRawParameterValue ("vol");
    m_tone = parameters.getRawParameterValue ("tone");
    m_drive = parameters.getRawParameterValue ("drv");
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
    for (auto sample = 0; sample < buffer.getNumSamples (); ++sample)
    {
        for (auto channel = 0; channel < buffer.getNumChannels (); ++channel)
        {
            // Do Nothing
        }
    }
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

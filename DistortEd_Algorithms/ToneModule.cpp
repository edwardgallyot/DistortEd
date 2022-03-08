//
// Created by edgallyot on 08/03/2022.
//

#include "ToneModule.h"

void ToneModule::prepare (double sampleRate, unsigned int samplesPerBlock, unsigned int numChannels)
{
    ProcessSpec processSpec{};
    processSpec.sampleRate = sampleRate;
    processSpec.maximumBlockSize = samplesPerBlock;
    processSpec.numChannels = numChannels;
    this->sampleRate = sampleRate;

    stateVariableFilter.reset();
    stateVariableFilter.prepare (processSpec);
    stateVariableFilter.state->type = StateVariableFilter::Parameters<float>::Type::lowPass;
}
void ToneModule::process (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages, float cutoff)
{
    AudioBlock<float> audioBlock(buffer);
    stateVariableFilter.state->setCutOffFrequency (sampleRate, cutoff, 0.5f);
    stateVariableFilter.process (ProcessContextReplacing<float> (audioBlock));
}


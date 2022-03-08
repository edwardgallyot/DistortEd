//
// Created by edgallyot on 08/03/2022.
//

#include "FullRectModule.h"

void FullRectModule::prepare (double sampleRate, unsigned int samplesPerBlock, unsigned int numChannels)
{

}
void FullRectModule::process (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    for (auto sample = 0; sample < buffer.getNumSamples (); ++sample)
    {
        for (auto channel = 0; channel < buffer.getNumChannels (); ++channel)
        {
            auto in = buffer.getSample (channel, sample);
            auto out = dsp (in);
            buffer.setSample (channel, sample, out);
        }
    }
}

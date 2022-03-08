//
// Created by edgallyot on 07/03/2022.
//

#include "HardClipModule.h"

void HardClipModule::prepare (double sampleRate, int maximumExpectedSamplesPerBlock)
{
    smoothedValue.reset (sampleRate, 0.0005);
}
void HardClipModule::process (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages, float gain)
{
    smoothedValue.setTargetValue (gain);
    for (auto sample = 0; sample < buffer.getNumSamples (); ++sample)
    {
        auto value = smoothedValue.getNextValue ();
        value += 0.2f;
        value *= 0.5;
        for (auto channel = 0; channel < buffer.getNumChannels (); ++channel)
        {
            auto in = buffer.getSample (channel, sample);
            auto inverseGain = 0.7f - value;

            auto out = dsp (in, inverseGain);

            out *= (1.1f + (2.0f * value));

            out = DistortEdAlgorithms::scaleInDb (out, 3.0f);

            buffer.setSample (channel, sample, out);
        }
    }
}

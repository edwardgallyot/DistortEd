//
// Created by edgallyot on 07/03/2022.
//

#include "CrushModule.h"
#include <cmath>

void CrushModule::prepare (double sampleRate, int maximumExpectedSamplesPerBlock)
{
    smoothedValue.reset (sampleRate, 0.0005);
}
void CrushModule::process (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages, float& drive)
{
    smoothedValue.setTargetValue (drive);
    for (auto sample = 0; sample < buffer.getNumSamples (); ++sample)
    {
        auto value = smoothedValue.getNextValue ();
        for (auto channel = 0; channel < buffer.getNumChannels (); ++channel)
        {
            auto crush = static_cast<float>(std::round (((1.0f - drive) * 4.0f) + 2.0f));
            auto in = buffer.getSample (channel, sample);
            auto out = dsp (in, crush);
            buffer.setSample (channel, sample, out);
        }
    }
}

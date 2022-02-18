//
// Created by edgallyot on 18/02/2022.
//

#include "SinOsc.h"

void SinOsc::prepare (double sampleRate, int samplesPerBlock)
{
    m_sampleRate = sampleRate;
    m_samplesPerBlock = samplesPerBlock;

}
void SinOsc::process (juce::AudioBuffer<float>& buffer, std::atomic<float>& freq)
{

    for (auto sample = 0; sample < m_samplesPerBlock; ++sample, ++t)
    {
        auto frequency = freq.load ();
        //std::cout << frequency << std::endl;
        auto freq_over_rate = frequency / m_sampleRate;
        for (auto channel = 0; channel < buffer.getNumChannels (); ++channel)
        {
            auto new_sound = std::sin (juce::MathConstants<float>::twoPi * freq_over_rate * t) * 0.2;
            buffer.setSample (channel, sample, new_sound);
        }
    }
}


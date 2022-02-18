//
// Created by edgallyot on 18/02/2022.
//

#ifndef DISTORTED_SINOSC_H
#define DISTORTED_SINOSC_H

#include "JuceHeader.h"

class SinOsc
{
public:
    void prepare (double sampleRate, int samplesPerBlock);
    void process (juce::AudioBuffer<float>& buffer, std::atomic<float>& freq);

private:
    double m_sampleRate;
    double m_samplesPerBlock;
    int t{0};
};


#endif //DISTORTED_SINOSC_H

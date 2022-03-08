//
// Created by edgallyot on 08/03/2022.
//

#ifndef DISTORTED_FULLRECTMODULE_H
#define DISTORTED_FULLRECTMODULE_H

#include "JuceHeader.h"
#include "DistortEd_Algorithms.h"

class FullRectModule
{
public:
    void prepare (double sampleRate, unsigned int samplesPerBlock, unsigned int numChannels);
    void process (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages);
private:
    float (& dsp) (float) = DistortEdAlgorithms::processFullWaveRect<float>;
};


#endif //DISTORTED_FULLRECTMODULE_H

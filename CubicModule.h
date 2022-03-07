//
// Created by edgallyot on 07/03/2022.
//

#ifndef DISTORTED_CUBICMODULE_H
#define DISTORTED_CUBICMODULE_H

#include "JuceHeader.h"
#include "DistortEd_Algorithms.h"

class  CubicModule
{
public:
    CubicModule () = default;
    void prepare (double sampleRate, int maximumExpectedSamplesPerBlock);
    void process (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages, float& drive);
private:
    juce::SmoothedValue<float, juce::ValueSmoothingTypes::Linear> smoothedValue;
    float (& dsp) (float, float) = DistortEdAlgorithms::processCubicClip<float>;

};


#endif //DISTORTED_CUBICMODULE_H

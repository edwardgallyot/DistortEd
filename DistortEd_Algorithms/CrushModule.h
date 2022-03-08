//
// Created by edgallyot on 07/03/2022.
//

#ifndef DISTORTED_CRUSHMODULE_H
#define DISTORTED_CRUSHMODULE_H

#include "JuceHeader.h"
#include "DistortEd_Algorithms.h"

class CrushModule
{
public:
    CrushModule () = default;
    void prepare (double sampleRate, int maximumExpectedSamplesPerBlock);
    void process (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages, float& drive);
private:
    juce::SmoothedValue<float, juce::ValueSmoothingTypes::Linear> smoothedValue;
    float (& dsp) (float, float) = DistortEdAlgorithms::processBitClip <float>;
};


#endif //DISTORTED_CRUSHMODULE_H

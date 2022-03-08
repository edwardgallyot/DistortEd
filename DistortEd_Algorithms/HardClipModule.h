//
// Created by edgallyot on 07/03/2022.
//

#ifndef DISTORTED_HARDCLIPMODULE_H
#define DISTORTED_HARDCLIPMODULE_H

#include "juce_audio_utils/juce_audio_utils.h"
#include "juce_gui_extra/juce_gui_extra.h"
#include "DistortEd_Algorithms.h"

class HardClipModule
{
public:
    HardClipModule() = default;
    void prepare (double sampleRate, int maximumExpectedSamplesPerBlock);
    void process (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages, float gain);
private:
    juce::SmoothedValue<float, juce::ValueSmoothingTypes::Linear> smoothedValue;
    float (& dsp) (float, float) = DistortEdAlgorithms::processHardClip<float>;
};


#endif //DISTORTED_HARDCLIPMODULE_H

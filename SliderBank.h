//
// Created by edgallyot on 18/02/2022.
//

#ifndef DISTORTED_SLIDERBANK_H
#define DISTORTED_SLIDERBANK_H

#include "JuceHeader.h"
#include "CustomSliders.h"

class SliderBank : public juce::Component
{
public:
    SliderBank(DistortEdProcessor&, juce::AudioProcessorValueTreeState&);
    void resized() override;
private:
    DistortEdProcessor& processor;
    juce::AudioProcessorValueTreeState& parameters;
    VolumeSlider volumeSlider;
    ToneSlider toneSlider;
    DriveSlider driveSlider;
};


#endif //DISTORTED_SLIDERBANK_H

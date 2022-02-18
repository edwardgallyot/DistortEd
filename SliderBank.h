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
    SliderBank(DistortEdAudioProcessor& p);
    void resized() override;
private:
    DistortEdAudioProcessor& processor;
    VolumeSlider volumeSlider;
    ToneSlider toneSlider;
    DriveSlider driveSlider;
};


#endif //DISTORTED_SLIDERBANK_H

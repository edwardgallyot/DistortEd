//
// Created by edgallyot on 18/02/2022.
//

#ifndef DISTORTED_TONESLIDER_H
#define DISTORTED_TONESLIDER_H

#include "DistortEdSlider.h"

class ToneSlider: public DistortEdSlider
{
    void sliderValueChanged (juce::Slider* slider) override;
};



#endif //DISTORTED_TONESLIDER_H

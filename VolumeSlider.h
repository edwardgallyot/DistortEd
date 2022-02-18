//
// Created by edgallyot on 18/02/2022.
//

#ifndef DISTORTED_VOLUMESLIDER_H
#define DISTORTED_VOLUMESLIDER_H

#include "DistortEdSlider.h"


class VolumeSlider : public DistortEdSlider
{
    void sliderValueChanged(juce::Slider *slider) override;
};


#endif //DISTORTED_VOLUMESLIDER_H
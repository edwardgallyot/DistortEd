//
// Created by edgallyot on 18/02/2022.
//

#ifndef DISTORTED_VOLUMESLIDER_H
#define DISTORTED_VOLUMESLIDER_H

#include "DistortEdSlider.h"


class VolumeSlider : public DistortEdSlider
{
    using DistortEdSlider::DistortEdSlider;
public:
    void intialise () override;

};


#endif //DISTORTED_VOLUMESLIDER_H
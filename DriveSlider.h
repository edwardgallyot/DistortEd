//
// Created by edgallyot on 18/02/2022.
//

#ifndef DISTORTED_DRIVESLIDER_H
#define DISTORTED_DRIVESLIDER_H

#include "DistortEdSlider.h"

class DriveSlider : public DistortEdSlider
{
    using DistortEdSlider::DistortEdSlider;
public:
    void intialise () override;
};


#endif //DISTORTED_DRIVESLIDER_H

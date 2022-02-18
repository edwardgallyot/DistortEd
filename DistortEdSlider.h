//
// Created by edgallyot on 18/02/2022.
//

#ifndef DISTORTED_DISTORTEDSLIDER_H
#define DISTORTED_DISTORTEDSLIDER_H

#include "JuceHeader.h"
#include <atomic>
#include "PluginProcessor.h"


class DistortEdSlider : public juce::Component,
                        public juce::Slider::Listener

{
public:
    DistortEdSlider (std::atomic<float>& value);
    void sliderValueChanged (juce::Slider* slider) override;
    void resized () override;
    virtual void intialise() = 0;
protected:
    juce::Slider m_slider;
    juce::Label m_label;
    double m_value {0.0f};
    std::atomic<float>& atomicValue;
};


#endif //DISTORTED_DISTORTEDSLIDER_H

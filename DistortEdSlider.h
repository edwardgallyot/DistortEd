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
    DistortEdSlider();
    void sliderValueChanged (juce::Slider* slider) override;
    void resized() override;
    void setProcessor(DistortEdAudioProcessor* processor);
private:
    DistortEdAudioProcessor* m_processor;
    juce::Slider m_slider;
};


#endif //DISTORTED_DISTORTEDSLIDER_H

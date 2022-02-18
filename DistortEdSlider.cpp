//
// Created by edgallyot on 18/02/2022.
//

#include "DistortEdSlider.h"

void DistortEdSlider::sliderValueChanged (juce::Slider* slider)
{
    m_processor->freq.store(slider->getValue());
}

DistortEdSlider::DistortEdSlider ()
{
    m_slider.setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    addAndMakeVisible (m_slider);
    m_slider.addListener (this);
    m_slider.setRange (100.0, 1000.0, 0.001);
}

void DistortEdSlider::resized ()
{
    m_slider.setBounds (getLocalBounds ());
}
void DistortEdSlider::setProcessor (DistortEdAudioProcessor* processor)
{
    m_processor = processor;
}


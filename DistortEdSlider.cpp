//
// Created by edgallyot on 18/02/2022.
//

#include "DistortEdSlider.h"

void DistortEdSlider::sliderValueChanged (juce::Slider* slider)
{
    if (slider == &m_slider)
    {
        m_value = slider->getValue ();
        m_label.setText (std::to_string (m_value), juce::NotificationType::dontSendNotification);
    }
}

DistortEdSlider::DistortEdSlider (std::atomic<float>& value) : atomicValue(value)
{
    m_slider.setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    // Setting Default Slider Values
    addAndMakeVisible (m_slider);
    m_slider.addListener (this);
    m_slider.setRange (100.0, 1000.0, 0.001);
    m_slider.getLookAndFeel ().setColour (juce::Slider::thumbColourId, juce::Colours::deeppink);
    m_slider.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    // Setting Some Default Label Values
    addAndMakeVisible (m_label);
    m_label.setText (std::to_string (value), juce::NotificationType::dontSendNotification);
}

void DistortEdSlider::resized ()
{
    auto area = getLocalBounds ();
    auto labelHeight = 10;
    auto sliderArea = area.removeFromBottom (labelHeight);
    auto labelArea = area.removeFromBottom (sliderArea.getHeight ());
    m_slider.setBounds (getLocalBounds ());
    m_label.setBounds (labelArea);
    m_label.setJustificationType (juce::Justification::centred);
}

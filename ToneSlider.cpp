//
// Created by edgallyot on 18/02/2022.
//

#include "ToneSlider.h"

void ToneSlider::initialise ()
{
    m_slider.setRange(500.0f, 20000.0f, 0.0001f);
    m_slider.setSkewFactorFromMidPoint (2000.0f);
    auto labelValue = parameters.getRawParameterValue (ID)->load ();
    labelValue = labelValue - 500.0f;
    labelValue = labelValue / 19500.0f;
    m_labelValue.setText (std::to_string (labelValue), juce::dontSendNotification);
}

void ToneSlider::sliderValueChanged (juce::Slider* slider)
{
    auto labelValue = parameters.getRawParameterValue (ID)->load ();
    labelValue = labelValue - 500.0f;
    labelValue = labelValue / 19500.0f;
    m_labelValue.setText (std::to_string (labelValue), juce::dontSendNotification);
}


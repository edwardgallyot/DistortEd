//
// Created by edgallyot on 18/02/2022.
//

#include "DistortEdSlider.h"

#include <memory>


DistortEdSlider::DistortEdSlider (juce::AudioProcessorValueTreeState& treeState, std::string ID, std::string Name) :
        parameters (treeState),
        ID (ID),
        Name (Name)
{
    // Slider Style
    m_slider.setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    m_slider.getLookAndFeel ().setColour (juce::Slider::thumbColourId, juce::Colours::deeppink);
    m_slider.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);

    // Setting Default Slider Values
    m_labelValue.setText (std::to_string (parameters.getRawParameterValue (ID)->load ()), juce::dontSendNotification);
    m_labelName.setText (Name, juce::dontSendNotification);
    m_slider.addListener (this);

    //m_labelValue.setText (ID, juce::NotificationType::dontSendNotification);

    // Making visible and attatching state to GUI
    m_slider.addListener (this);
    addAndMakeVisible (m_slider);
    addAndMakeVisible (m_labelValue);
    addAndMakeVisible (m_labelName);
    attachment = std::make_unique<SliderAttachment> (treeState, ID, m_slider);
}

void DistortEdSlider::resized ()
{
    auto sliderArea = getLocalBounds ();
    auto labelHeight = 20;
    sliderArea.removeFromTop (labelHeight);
    sliderArea.removeFromBottom (labelHeight);

    auto labelValueArea = getLocalBounds ();
    auto labelNameArea = getLocalBounds ();
    labelValueArea.removeFromTop (sliderArea.getHeight () + labelHeight);
    labelNameArea.removeFromBottom (sliderArea.getHeight () + labelHeight);

    m_slider.setBounds (sliderArea);
    m_labelValue.setBounds (labelValueArea);
    m_labelValue.setJustificationType (juce::Justification::centred);
    m_labelName.setBounds (labelNameArea);
    m_labelName.setJustificationType (juce::Justification::centred);
}
void DistortEdSlider::sliderValueChanged (juce::Slider* slider)
{
    m_labelValue.setText (std::to_string (parameters.getRawParameterValue (ID)->load ()), juce::dontSendNotification);
}

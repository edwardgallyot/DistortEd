//
// Created by edgallyot on 06/03/2022.
//

#include "DistortEdButton.h"

DistortEdButton::DistortEdButton (juce::AudioProcessorValueTreeState& treeState, std::string ID, std::string Name) :
        parameters (treeState),
        ID(std::move(ID)),
        Name (std::move(Name))
{
    m_button.setClickingTogglesState (true);
    addAndMakeVisible (m_button);
    m_labelName.setText(this->Name, juce::dontSendNotification);
    addAndMakeVisible (m_labelName);

    attachment = std::make_unique<ButtonAttachment>(treeState, this->ID, m_button);
}

void DistortEdButton::buttonClicked (juce::Button* button)
{

}

void DistortEdButton::resized ()
{
    auto buttonArea = getLocalBounds();
    auto labelArea = getLocalBounds();
    buttonArea.removeFromLeft (10);
    labelArea.removeFromLeft (5);
    labelArea.removeFromTop (40);
    m_button.setBounds (buttonArea);
    m_labelName.setBounds(labelArea);
}


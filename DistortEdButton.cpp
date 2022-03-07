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
    attachment = std::make_unique<ButtonAttachment>(treeState, this->ID, m_button);
}

void DistortEdButton::buttonClicked (juce::Button* button)
{

}

void DistortEdButton::resized ()
{
    m_button.setBounds (getLocalBounds());
}


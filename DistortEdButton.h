//
// Created by edgallyot on 06/03/2022.
//

#ifndef DISTORTED_DISTORTEDBUTTON_H
#define DISTORTED_DISTORTEDBUTTON_H

#include "JuceHeader.h"
#include "DistortEdAlias.h"

class DistortEdButton : public juce::Component,
                        public juce::Button::Listener
{
public:
    DistortEdButton(juce::AudioProcessorValueTreeState& treeState, std::string ID, std::string Name);
    void resized() override;

    void buttonClicked (juce::Button* button) override;
protected:
    juce::AudioProcessorValueTreeState& parameters;
    std::string ID;
    std::string Name;
    juce::ToggleButton m_button;
    std::unique_ptr<ButtonAttachment> attachment;
};


#endif //DISTORTED_DISTORTEDBUTTON_H

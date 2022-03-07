//
// Created by edgallyot on 06/03/2022.
//

#ifndef DISTORTED_BUTTONBANK_H
#define DISTORTED_BUTTONBANK_H

#include <vector>
#include <JuceHeader.h>
#include "CustomSliders.h"

class ButtonBank : public juce::Component
{
public:
    ButtonBank (DistortEdProcessor&, juce::AudioProcessorValueTreeState&);
    void resized() override;
protected:
private:
    DistortEdProcessor& processor;
    juce::AudioProcessorValueTreeState& parameters;
    DistortEdButton m_bypassButton;
    DistortEdButton m_crushButton;
    DistortEdButton m_rectifyButton;
};


#endif //DISTORTED_BUTTONBANK_H

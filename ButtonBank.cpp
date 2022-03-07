//
// Created by edgallyot on 06/03/2022.
//

#include "ButtonBank.h"

ButtonBank::ButtonBank (DistortEdProcessor& p, juce::AudioProcessorValueTreeState& vts) :
        processor (p),
        parameters (vts),
        m_bypassButton (vts,
                        "byp",
                        "Bypass"),
        m_crushButton (vts,
                       "crsh",
                       "Crush"),
        m_rectifyButton (vts,
                         "rect",
                         "Rectify")
{
    addAndMakeVisible (m_bypassButton);
    addAndMakeVisible (m_crushButton);
    addAndMakeVisible (m_rectifyButton);
}
void ButtonBank::resized ()
{
    auto bypassArea = getLocalBounds ();
    auto crushArea = getLocalBounds ();
    auto rectifyArea = getLocalBounds ();
    bypassArea.removeFromBottom (2 * (getHeight () / 3));
    crushArea.removeFromBottom (getHeight () / 3);
    crushArea.removeFromTop (getHeight () / 3);
    rectifyArea.removeFromTop (2 * (getHeight () / 3));

    m_bypassButton.setBounds (bypassArea);
    m_crushButton.setBounds (crushArea);
    m_rectifyButton.setBounds (rectifyArea);
}

//
// Created by edgallyot on 18/02/2022.
//

#include "SliderBank.h"

SliderBank::SliderBank (DistortEdProcessor& p, juce::AudioProcessorValueTreeState& vts) : processor (p),
                                                                                          parameters (vts),
                                                                                          volumeSlider (parameters,
                                                                                                        "gainModule",
                                                                                                        "Volume"),
                                                                                          toneSlider (parameters,
                                                                                                      "tone",
                                                                                                      "Tone"),
                                                                                          driveSlider (parameters,
                                                                                                       "drv",
                                                                                                       "Drive")
{
    driveSlider.initialise ();
    volumeSlider.initialise ();
    toneSlider.initialise ();
    addAndMakeVisible (driveSlider);
    addAndMakeVisible (volumeSlider);
    addAndMakeVisible (toneSlider);

}
void SliderBank::resized ()
{
    driveSlider.setBounds (0, 0, getWidth () / 3, getHeight ());
    toneSlider.setBounds (getWidth () / 3, 0, getWidth () / 3, getHeight ());
    volumeSlider.setBounds (2 * getWidth () / 3, 0, getWidth () / 3, getHeight ());
}

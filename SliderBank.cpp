//
// Created by edgallyot on 18/02/2022.
//

#include "SliderBank.h"

SliderBank::SliderBank (DistortEdAudioProcessor& p) : processor(p), toneSlider (p.tone),
                                                      volumeSlider (p.volume), driveSlider(p.drive)
{
    driveSlider.intialise();
    volumeSlider.intialise();
    toneSlider.intialise();
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

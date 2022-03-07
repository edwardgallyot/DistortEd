#pragma once

#include "DistortEdProcessor.h"
#include "SliderBank.h"
#include "ButtonBank.h"


//==============================================================================
class DistortEdEditor : public juce::AudioProcessorEditor
{
public:
    explicit  DistortEdEditor (DistortEdProcessor&, juce::AudioProcessorValueTreeState&);
    ~DistortEdEditor () override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized () override;



private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    DistortEdProcessor& processorRef;

    // Slider Controls
    SliderBank sliderBank;

    // Toggle Switches
    ButtonBank buttonBank;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DistortEdEditor)
};

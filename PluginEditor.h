#pragma once

#include "PluginProcessor.h"
#include "DistortEdSlider.h"
#include "VolumeSlider.h"

//==============================================================================
class DistortEdProcessorEditor : public juce::AudioProcessorEditor
{
public:
    explicit DistortEdProcessorEditor (DistortEdAudioProcessor&);
    ~DistortEdProcessorEditor () override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized () override;

private:
    // Slider Controls

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    DistortEdAudioProcessor& processorRef;
    DistortEdSlider testSlider;
    VolumeSlider volumeSlider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DistortEdProcessorEditor)
};

#pragma once

#include "PluginProcessor.h"

//==============================================================================
class DistortEdProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    explicit DistortEdProcessorEditor (DistortEdAudioProcessor&);
    ~DistortEdProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    DistortEdAudioProcessor& processorRef;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DistortEdProcessorEditor)
};

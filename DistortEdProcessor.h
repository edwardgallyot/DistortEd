#pragma once

#include <JuceHeader.h>
#include <atomic>
#include "BaseProcessor.h"


//==============================================================================
class DistortEdProcessor : public BaseProcessor
{
public:
    //==============================================================================
    DistortEdProcessor ();
    ~DistortEdProcessor () override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources () override;

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    void getStateInformation(juce::MemoryBlock& destData) override;
    void setStateInformation(const void* data, int sizeInBytes) override;

    juce::AudioProcessorEditor* createEditor () override;

private:
    std::atomic<float>* m_volume = nullptr;
    std::atomic<float>* m_drive = nullptr;
    std::atomic<float>* m_tone = nullptr;

    juce::AudioProcessorValueTreeState parameters;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DistortEdProcessor)
};

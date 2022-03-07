#pragma once

#include <JuceHeader.h>
#include <atomic>
#include "BaseProcessor.h"
#include "DistortEdAlias.h"
#include "DSPModules.h"

// Inheriting from my Base Processor to override some of the JUCE boiler plate
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
    juce::AudioProcessorValueTreeState::ParameterLayout createParameters();

protected:
    bool isBusesLayoutSupported (const BusesLayout& layout) const override;

private:
    // Parameters with their tree
    std::atomic<float>* m_volume = nullptr;
    std::atomic<float>* m_drive = nullptr;
    std::atomic<float>* m_tone = nullptr;
    std::atomic<float>* m_bypass = nullptr;
    std::atomic<float>* m_crush = nullptr;
    std::atomic<float>* m_rectify = nullptr;
    juce::AudioProcessorValueTreeState parameters;

    GainModule gainModule;
    CubicModule cubicModule;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DistortEdProcessor)
};

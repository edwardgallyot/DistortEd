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

    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    juce::AudioProcessorEditor* createEditor () override;
    juce::AudioProcessorValueTreeState::ParameterLayout createParameters ();

protected:
    bool isBusesLayoutSupported (const BusesLayout& layout) const override;


private:
    // Parameters with their tree
    std::atomic<float>* m_volume = nullptr;
    std::atomic<float>* m_drive = nullptr;
    std::atomic<float>* m_tone = nullptr;
    std::atomic<float>* m_bypass = nullptr;
    juce::SmoothedValue<float, juce::ValueSmoothingTypes::Linear> smoothedBypass;
    std::atomic<float>* m_crush = nullptr;
    juce::SmoothedValue<float, juce::ValueSmoothingTypes::Linear> smoothedRectify;
    std::atomic<float>* m_rectify = nullptr;

    juce::AudioProcessorValueTreeState parameters;

    // Pointers to Buffers
    juce::AudioBuffer<float> buffer1;
    juce::AudioBuffer<float> buffer2;
    juce::AudioBuffer<float> bufferDry;

    GainModule gainModule;
    CubicModule cubicModule;
    HardClipModule hardClipModule;
    CrushModule crushModule;
    ToneModule toneModule;
    FullRectModule fullRectModule;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DistortEdProcessor)
};

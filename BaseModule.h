//
// Created by edgallyot on 21/02/2022.
//

#ifndef DISTORTED_BASEMODULE_H
#define DISTORTED_BASEMODULE_H

#include <JuceHeader.h>

class BaseModule : public juce::AudioProcessor
{
    BaseModule ();
    //==============================================================================
    void prepareToPlay (double, int) override;
    void releaseResources () override;
    void processBlock (juce::AudioSampleBuffer&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor () override;
    bool hasEditor () const override;

    //==============================================================================
    const juce::String getName () const override;
    bool acceptsMidi () const override;
    bool producesMidi () const override;
    double getTailLengthSeconds () const override;

    //==============================================================================
    int getNumPrograms () override;
    int getCurrentProgram () override;
    void setCurrentProgram (int) override;
    const juce::String getProgramName (int) override;
    void changeProgramName (int, const juce::String&) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock&) override;
    void setStateInformation (const void*, int) override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BaseModule)
};

#endif //DISTORTED_BASEMODULE_H

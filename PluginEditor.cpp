#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DistortEdProcessorEditor::DistortEdProcessorEditor (DistortEdAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p)
{
    juce::ignoreUnused (processorRef);
    setResizable (false, false);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (500, 100);
    addAndMakeVisible (testSlider);
    addAndMakeVisible (volumeSlider);
    testSlider.setProcessor (&p);
}

DistortEdProcessorEditor::~DistortEdProcessorEditor()
{
}

//==============================================================================
void DistortEdProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

//    g.setColour (juce::Colours::pink);
//    g.setFont (15.0f);
//    g.drawFittedText ("DisortEd Plugin!", getLocalBounds(), juce::Justification::left, 1);
}

void DistortEdProcessorEditor::resized()
{
    testSlider.setBounds(0, 0, getWidth() / 3, getHeight());
    volumeSlider.setBounds (getWidth() / 3, 0, getWidth() / 3, getHeight());
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

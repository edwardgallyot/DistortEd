#include "DistortEdProcessor.h"
#include "DistortEdEditor.h"

//==============================================================================
DistortEdEditor::DistortEdEditor (DistortEdProcessor& p, juce::AudioProcessorValueTreeState& vts)
        : AudioProcessorEditor (&p),
          processorRef (p),
          sliderBank (p, vts),
          buttonBank (p, vts)
{
    juce::ignoreUnused (processorRef);
    setResizable (false, false);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (500, 200);

    addAndMakeVisible (sliderBank);
    addAndMakeVisible (buttonBank);
}

DistortEdEditor::~DistortEdEditor ()
{
}

//==============================================================================
void DistortEdEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
//    g.fillAll (getLookAndFeel ().findColour (juce::ResizableWindow::backgroundColourId));
    g.fillAll(juce::Colours::maroon);
}

void DistortEdEditor::resized ()
{
    auto editorSize = getLocalBounds ();

    auto headerFooterHeight = 30;
    auto sideBarWidth = 50;

    auto sliderBankSize = editorSize;

    sliderBankSize.removeFromTop (headerFooterHeight);
    sliderBankSize.removeFromBottom (headerFooterHeight);
    sliderBankSize.removeFromLeft (sideBarWidth);
    sliderBank.setBounds (sliderBankSize);

    auto buttonBankSize = editorSize;
    buttonBankSize.removeFromRight (getWidth () - sideBarWidth);
    buttonBankSize.removeFromTop (headerFooterHeight).removeFromBottom (headerFooterHeight);


    buttonBank.setBounds (buttonBankSize);

    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

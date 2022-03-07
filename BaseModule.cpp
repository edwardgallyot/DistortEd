//
// Created by edgallyot on 21/02/2022.
//

#include "BaseModule.h"

BaseModule::BaseModule ()
        : AudioProcessor (BusesProperties ().withInput ("Input", juce::AudioChannelSet::stereo ())
                                  .withOutput ("Output", juce::AudioChannelSet::stereo ()))
{}
void BaseModule::prepareToPlay (double, int)
{

}
void BaseModule::releaseResources ()
{

}
void BaseModule::processBlock (juce::AudioSampleBuffer&, juce::MidiBuffer&)
{

}
juce::AudioProcessorEditor* BaseModule::createEditor ()
{
    return nullptr;
}
bool BaseModule::hasEditor () const
{
    return false;
}
const juce::String BaseModule::getName () const
{
    return {};
}
bool BaseModule::acceptsMidi () const
{
    return false;
}
bool BaseModule::producesMidi () const
{
    return false;
}
double BaseModule::getTailLengthSeconds () const
{
    return 0;
}
int BaseModule::getNumPrograms ()
{
    return 0;
}
int BaseModule::getCurrentProgram ()
{
    return 0;
}
void BaseModule::setCurrentProgram (int)
{

}
const juce::String BaseModule::getProgramName (int)
{
    return {};
}
void BaseModule::changeProgramName (int, const juce::String&)
{

}
void BaseModule::getStateInformation (juce::MemoryBlock&)
{

}
void BaseModule::setStateInformation (const void*, int)
{

}

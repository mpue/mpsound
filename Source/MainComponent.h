/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "ExtendedFileBrowser.h"
#include "PlayerComponent.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public AudioAppComponent,
                        public juce::TimeSliceThread,
                        public juce::TimeSliceClient,
                        public DragAndDropContainer,
                        public ChangeListener
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();
    
    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;
    virtual int useTimeSlice() override;
    //==============================================================================
    void paint (Graphics& g) override;
    void resized() override;

private:
    //==============================================================================
    // Your private member variables go here...
    
    TabbedComponent* tab = nullptr;
    juce::DirectoryContentsList* directoryContents = nullptr;
    juce::WildcardFileFilter* filter = nullptr;
    ExtendedFileBrowser* browser = nullptr;
    PlayerComponent* playerPanel = nullptr;
    Slider* timeSlider = nullptr;
    virtual void changeListenerCallback (ChangeBroadcaster* source) override;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

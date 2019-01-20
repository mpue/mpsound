/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.3.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "ExtendedFileBrowser.h"
#include "CustomLookAndFeel.h"
#include "LCDisplay.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PlayerComponent  : public Component,
                         public Timer,
                         public TimeSliceClient,
                         public Button::Listener,
                         public Slider::Listener
{
public:
    //==============================================================================
    PlayerComponent (ExtendedFileBrowser* browser);
    ~PlayerComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void setSlider(Slider* slider) {
        this->timeSlider = slider;
        slider->addListener(this);
    }
    virtual int useTimeSlice() override;
    virtual void timerCallback() override;
    void setPlaying(bool playing) {
        this->playerRunning = playing;
    }

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;

    // Binary resources:
    static const char* foundationiconfonts_20150216_fastforward_64_0_000000_none_png;
    static const int foundationiconfonts_20150216_fastforward_64_0_000000_none_pngSize;
    static const char* foundationiconfonts_20150216_next_64_0_000000_none_png;
    static const int foundationiconfonts_20150216_next_64_0_000000_none_pngSize;
    static const char* foundationiconfonts_20150216_play_64_0_000000_none_png;
    static const int foundationiconfonts_20150216_play_64_0_000000_none_pngSize;
    static const char* foundationiconfonts_20150216_previous_64_0_000000_none_png;
    static const int foundationiconfonts_20150216_previous_64_0_000000_none_pngSize;
    static const char* foundationiconfonts_20150216_record_64_0_000000_none_png;
    static const int foundationiconfonts_20150216_record_64_0_000000_none_pngSize;
    static const char* foundationiconfonts_20150216_rewind_64_0_000000_none_png;
    static const int foundationiconfonts_20150216_rewind_64_0_000000_none_pngSize;
    static const char* foundationiconfonts_20150216_stop_64_0_000000_none_png;
    static const int foundationiconfonts_20150216_stop_64_0_000000_none_pngSize;
    static const char* ionicons_201_search_64_0_000000_none_png;
    static const int ionicons_201_search_64_0_000000_none_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    ExtendedFileBrowser* browser;
    Slider* timeSlider;
    bool playerRunning = false;
    CustomLookAndFeel* clf;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<ImageButton> prevButton;
    std::unique_ptr<ImageButton> rewindButton;
    std::unique_ptr<ImageButton> stopButton;
    std::unique_ptr<ImageButton> playButton;
    std::unique_ptr<ImageButton> forwardButton;
    std::unique_ptr<ImageButton> nextButton;
    std::unique_ptr<Slider> vuMeterLeft;
    std::unique_ptr<Slider> vuMeterRight;
    std::unique_ptr<LCDisplay> lcdisplay;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PlayerComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

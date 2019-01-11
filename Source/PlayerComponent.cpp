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

//[Headers] You can add your own extra header files here...
#include "ExtendedFileBrowser.h"
#include "AudioManager.h"
#include "CustomLookAndFeel.h"
//[/Headers]

#include "PlayerComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PlayerComponent::PlayerComponent (ExtendedFileBrowser* browser)
{
    //[Constructor_pre] You can add your own custom stuff here..
    clf = new CustomLookAndFeel();
    //[/Constructor_pre]

    prevButton.reset (new ImageButton ("prevButton"));
    addAndMakeVisible (prevButton.get());
    prevButton->setButtonText (TRANS("new button"));
    prevButton->addListener (this);

    prevButton->setImages (false, true, true,
                           ImageCache::getFromMemory (foundationiconfonts_20150216_previous_64_0_000000_none_png, foundationiconfonts_20150216_previous_64_0_000000_none_pngSize), 1.000f, Colour (0xff434343),
                           Image(), 1.000f, Colours::white,
                           Image(), 1.000f, Colour (0x00000000));
    prevButton->setBounds (8, 8, 32, 32);

    rewindButton.reset (new ImageButton ("rewindButton"));
    addAndMakeVisible (rewindButton.get());
    rewindButton->setButtonText (TRANS("new button"));
    rewindButton->addListener (this);

    rewindButton->setImages (false, true, true,
                             ImageCache::getFromMemory (foundationiconfonts_20150216_rewind_64_0_000000_none_png, foundationiconfonts_20150216_rewind_64_0_000000_none_pngSize), 1.000f, Colour (0xff434343),
                             Image(), 1.000f, Colours::white,
                             Image(), 1.000f, Colour (0x00000000));
    rewindButton->setBounds (48, 8, 32, 32);

    stopButton.reset (new ImageButton ("stopButton"));
    addAndMakeVisible (stopButton.get());
    stopButton->setButtonText (TRANS("new button"));
    stopButton->addListener (this);

    stopButton->setImages (false, true, true,
                           ImageCache::getFromMemory (foundationiconfonts_20150216_stop_64_0_000000_none_png, foundationiconfonts_20150216_stop_64_0_000000_none_pngSize), 1.000f, Colour (0xff434343),
                           Image(), 1.000f, Colours::white,
                           Image(), 1.000f, Colour (0x00000000));
    stopButton->setBounds (96, 8, 32, 32);

    playButton.reset (new ImageButton ("playButton"));
    addAndMakeVisible (playButton.get());
    playButton->setButtonText (TRANS("new button"));
    playButton->addListener (this);

    playButton->setImages (false, true, true,
                           ImageCache::getFromMemory (foundationiconfonts_20150216_play_64_0_000000_none_png, foundationiconfonts_20150216_play_64_0_000000_none_pngSize), 1.000f, Colour (0xff434343),
                           Image(), 1.000f, Colours::white,
                           Image(), 1.000f, Colour (0x00000000));
    playButton->setBounds (144, 8, 32, 32);

    forwardButton.reset (new ImageButton ("forwardButton"));
    addAndMakeVisible (forwardButton.get());
    forwardButton->setButtonText (TRANS("new button"));
    forwardButton->addListener (this);

    forwardButton->setImages (false, true, true,
                              ImageCache::getFromMemory (foundationiconfonts_20150216_fastforward_64_0_000000_none_png, foundationiconfonts_20150216_fastforward_64_0_000000_none_pngSize), 1.000f, Colour (0xff434343),
                              Image(), 1.000f, Colours::white,
                              Image(), 1.000f, Colour (0x00000000));
    forwardButton->setBounds (192, 8, 32, 32);

    nextButton.reset (new ImageButton ("new button"));
    addAndMakeVisible (nextButton.get());
    nextButton->addListener (this);

    nextButton->setImages (false, true, true,
                           ImageCache::getFromMemory (foundationiconfonts_20150216_next_64_0_000000_none_png, foundationiconfonts_20150216_next_64_0_000000_none_pngSize), 1.000f, Colour (0xff434343),
                           Image(), 1.000f, Colours::white,
                           Image(), 1.000f, Colour (0x00000000));
    nextButton->setBounds (240, 8, 32, 32);

    timeLabel.reset (new Label ("timeLabel",
                                TRANS("0:00")));
    addAndMakeVisible (timeLabel.get());
    timeLabel->setFont (Font (32.60f, Font::plain).withTypefaceStyle ("Bold"));
    timeLabel->setJustificationType (Justification::centredRight);
    timeLabel->setEditable (false, false, false);
    timeLabel->setColour (Label::textColourId, Colours::white);
    timeLabel->setColour (TextEditor::textColourId, Colours::black);
    timeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    timeLabel->setBounds (184, 48, 80, 24);

    vuMeterLeft.reset (new Slider ("vuMeterLeft"));
    addAndMakeVisible (vuMeterLeft.get());
    vuMeterLeft->setRange (0, 10, 0);
    vuMeterLeft->setSliderStyle (Slider::LinearBar);
    vuMeterLeft->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    vuMeterLeft->addListener (this);

    vuMeterLeft->setBounds (280, 12, 160, 8);

    vuMeterRight.reset (new Slider ("vuMeterRight"));
    addAndMakeVisible (vuMeterRight.get());
    vuMeterRight->setRange (0, 10, 0);
    vuMeterRight->setSliderStyle (Slider::LinearBar);
    vuMeterRight->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    vuMeterRight->addListener (this);

    vuMeterRight->setBounds (280, 24, 160, 8);


    //[UserPreSize]
    vuMeterLeft->setLookAndFeel(clf);
    vuMeterRight->setLookAndFeel(clf);
    vuMeterLeft->setRange(0, 1.2f);
    vuMeterRight->setRange(0, 1.2f);
    //[/UserPreSize]

    setSize (450, 80);


    //[Constructor] You can add your own custom stuff here..
    this->browser = browser;
    startTimer(250);
    //[/Constructor]
}

PlayerComponent::~PlayerComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    stopTimer();
    vuMeterRight->setLookAndFeel(nullptr);
    vuMeterLeft->setLookAndFeel(nullptr);
    delete clf;
    //[/Destructor_pre]

    prevButton = nullptr;
    rewindButton = nullptr;
    stopButton = nullptr;
    playButton = nullptr;
    forwardButton = nullptr;
    nextButton = nullptr;
    timeLabel = nullptr;
    vuMeterLeft = nullptr;
    vuMeterRight = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PlayerComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff909090));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PlayerComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PlayerComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == prevButton.get())
    {
        //[UserButtonCode_prevButton] -- add your button handler code here..
        browser->getSampler()->stop();
        browser->selectPreviousFile();
        browser->getSampler()->play();
        //[/UserButtonCode_prevButton]
    }
    else if (buttonThatWasClicked == rewindButton.get())
    {
        //[UserButtonCode_rewindButton] -- add your button handler code here..
        browser->getSampler()->rewindSamples(44100);
        //[/UserButtonCode_rewindButton]
    }
    else if (buttonThatWasClicked == stopButton.get())
    {
        //[UserButtonCode_stopButton] -- add your button handler code here..
        browser->getSampler()->stop();
        playerRunning = false;

        //[/UserButtonCode_stopButton]
    }
    else if (buttonThatWasClicked == playButton.get())
    {
        //[UserButtonCode_playButton] -- add your button handler code here..
        if (browser->getSelectedFile() != nullptr) {
            browser->getSampler()->play();
            playerRunning = true;
        }
        //[/UserButtonCode_playButton]
    }
    else if (buttonThatWasClicked == forwardButton.get())
    {
        //[UserButtonCode_forwardButton] -- add your button handler code here..
        browser->getSampler()->skipSamples(44100);
        //[/UserButtonCode_forwardButton]
    }
    else if (buttonThatWasClicked == nextButton.get())
    {
        //[UserButtonCode_nextButton] -- add your button handler code here..
        browser->getSampler()->stop();
        browser->selectNextFile();
        browser->getSampler()->play();
        //[/UserButtonCode_nextButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void PlayerComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == vuMeterLeft.get())
    {
        //[UserSliderCode_vuMeterLeft] -- add your slider handling code here..
        //[/UserSliderCode_vuMeterLeft]
    }
    else if (sliderThatWasMoved == vuMeterRight.get())
    {
        //[UserSliderCode_vuMeterRight] -- add your slider handling code here..
        //[/UserSliderCode_vuMeterRight]
    }

    //[UsersliderValueChanged_Post]

    else {
         browser->getSampler()->setCurrentSample(sliderThatWasMoved->getValue());
    }
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

int PlayerComponent::useTimeSlice() {
    /*
    std::function<void(void)> changeLambda =
    [=]() {
        vuMeterLeft->setValue(browser->getSampler()->getMagnitude(0));
        vuMeterRight->setValue(browser->getSampler()->getMagnitude(1));
    };
    juce::MessageManager::callAsync(changeLambda);
     */
    return 250;
}


void PlayerComponent::timerCallback() {

    Sampler* s = browser->getSampler();

    if (s->isPlaying()) {
        long currentSample = s->getCurrentPosition();

        int bufferSize  = AudioManager::getInstance()->getDeviceManager()->getCurrentAudioDevice()->getDefaultBufferSize();
        int sampleRate  = AudioManager::getInstance()->getDeviceManager()->getCurrentAudioDevice()->getCurrentSampleRate();

        // float pitch = browser->getSampler()->getSampleRate() / sampleRate;

        long totalseconds = (currentSample / s->getSampleRate());
        long minutes = totalseconds / 60;

        long seconds = totalseconds - minutes * 60;

        String time = "";

        time += String(minutes);
        time += ":";

        if (seconds < 10) {
            time += "0";
        }

        time += String(seconds);
        timeLabel.get()->setText(time, NotificationType::dontSendNotification);

        timeSlider->setValue(s->getCurrentPosition());

    }
    else {
        if (playerRunning) {
            browser->selectNextFile();
            vuMeterRight->setValue(0);
            vuMeterLeft->setValue(0);
        }
    }



}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PlayerComponent" componentName=""
                 parentClasses="public Component, public Timer, public TimeSliceClient"
                 constructorParams="ExtendedFileBrowser* browser" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="450" initialHeight="80">
  <BACKGROUND backgroundColour="ff909090"/>
  <IMAGEBUTTON name="prevButton" id="a68f3207d30dc0c" memberName="prevButton"
               virtualName="" explicitFocusOrder="0" pos="8 8 32 32" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="foundationiconfonts_20150216_previous_64_0_000000_none_png"
               opacityNormal="1.00000000000000000000" colourNormal="ff434343"
               resourceOver="" opacityOver="1.00000000000000000000" colourOver="ffffffff"
               resourceDown="" opacityDown="1.00000000000000000000" colourDown="0"/>
  <IMAGEBUTTON name="rewindButton" id="78a7c9ec540d2953" memberName="rewindButton"
               virtualName="" explicitFocusOrder="0" pos="48 8 32 32" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="foundationiconfonts_20150216_rewind_64_0_000000_none_png"
               opacityNormal="1.00000000000000000000" colourNormal="ff434343"
               resourceOver="" opacityOver="1.00000000000000000000" colourOver="ffffffff"
               resourceDown="" opacityDown="1.00000000000000000000" colourDown="0"/>
  <IMAGEBUTTON name="stopButton" id="94c502c12139cd9d" memberName="stopButton"
               virtualName="" explicitFocusOrder="0" pos="96 8 32 32" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="foundationiconfonts_20150216_stop_64_0_000000_none_png"
               opacityNormal="1.00000000000000000000" colourNormal="ff434343"
               resourceOver="" opacityOver="1.00000000000000000000" colourOver="ffffffff"
               resourceDown="" opacityDown="1.00000000000000000000" colourDown="0"/>
  <IMAGEBUTTON name="playButton" id="306aea4436b69c03" memberName="playButton"
               virtualName="" explicitFocusOrder="0" pos="144 8 32 32" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="foundationiconfonts_20150216_play_64_0_000000_none_png"
               opacityNormal="1.00000000000000000000" colourNormal="ff434343"
               resourceOver="" opacityOver="1.00000000000000000000" colourOver="ffffffff"
               resourceDown="" opacityDown="1.00000000000000000000" colourDown="0"/>
  <IMAGEBUTTON name="forwardButton" id="acb69f4fc693b0c9" memberName="forwardButton"
               virtualName="" explicitFocusOrder="0" pos="192 8 32 32" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="foundationiconfonts_20150216_fastforward_64_0_000000_none_png"
               opacityNormal="1.00000000000000000000" colourNormal="ff434343"
               resourceOver="" opacityOver="1.00000000000000000000" colourOver="ffffffff"
               resourceDown="" opacityDown="1.00000000000000000000" colourDown="0"/>
  <IMAGEBUTTON name="new button" id="1d6b6452756f35c0" memberName="nextButton"
               virtualName="" explicitFocusOrder="0" pos="240 8 32 32" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="foundationiconfonts_20150216_next_64_0_000000_none_png"
               opacityNormal="1.00000000000000000000" colourNormal="ff434343"
               resourceOver="" opacityOver="1.00000000000000000000" colourOver="ffffffff"
               resourceDown="" opacityDown="1.00000000000000000000" colourDown="0"/>
  <LABEL name="timeLabel" id="b2419f164399c401" memberName="timeLabel"
         virtualName="" explicitFocusOrder="0" pos="184 48 80 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="0:00" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="32.60000000000000142109" kerning="0.00000000000000000000"
         bold="1" italic="0" justification="34" typefaceStyle="Bold"/>
  <SLIDER name="vuMeterLeft" id="3a0991b71e203e6" memberName="vuMeterLeft"
          virtualName="" explicitFocusOrder="0" pos="280 12 160 8" min="0.00000000000000000000"
          max="10.00000000000000000000" int="0.00000000000000000000" style="LinearBar"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.00000000000000000000" needsCallback="1"/>
  <SLIDER name="vuMeterRight" id="f399f3485d8644f2" memberName="vuMeterRight"
          virtualName="" explicitFocusOrder="0" pos="280 24 160 8" min="0.00000000000000000000"
          max="10.00000000000000000000" int="0.00000000000000000000" style="LinearBar"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.00000000000000000000" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: foundationiconfonts_20150216_fastforward_64_0_000000_none_png, 867, "../images/foundation-icon-fonts_2015-02-16_fast-forward_64_0_000000_none.png"
static const unsigned char resource_PlayerComponent_foundationiconfonts_20150216_fastforward_64_0_000000_none_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,64,0,0,0,64,8,3,0,0,0,157,183,
129,236,0,0,1,44,80,76,84,69,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,213,10,7,117,0,0,0,99,116,82,78,83,0,1,2,3,4,5,6,7,9,11,13,15,16,18,19,21,22,24,25,26,28,33,35,37,38,39,40,45,46,47,51,53,54,56,57,59,61,63,68,69,74,76,77,82,84,86,87,89,92,
97,99,102,104,105,107,115,116,120,123,124,128,131,133,137,142,145,154,160,162,163,168,175,176,185,192,195,199,200,204,206,209,213,218,220,222,226,228,230,232,233,235,239,241,243,245,247,249,251,253,178,
173,240,114,0,0,1,131,73,68,65,84,88,195,237,214,87,83,194,80,16,134,97,2,68,16,187,130,29,187,162,88,17,177,87,64,20,84,138,216,0,17,228,253,255,255,193,91,7,179,158,51,115,238,148,189,221,228,153,76,
146,179,223,186,92,157,234,212,31,169,46,185,101,91,26,247,167,201,14,10,173,57,170,203,106,0,224,204,231,216,218,3,238,131,58,0,141,117,167,135,77,0,112,229,215,0,224,113,74,2,104,110,187,53,0,184,237,
19,0,120,10,235,0,112,108,11,128,147,238,4,80,95,179,4,0,142,108,13,0,74,19,18,192,123,68,7,128,76,143,0,64,33,164,3,192,129,87,0,32,217,173,3,80,139,72,0,173,152,91,3,128,194,168,0,192,203,172,14,0,169,
128,0,64,118,64,7,160,149,240,36,164,222,105,151,6,0,213,7,177,245,17,181,52,128,95,171,52,110,8,192,117,192,16,128,132,199,16,160,178,104,8,192,141,41,128,109,8,196,204,158,224,46,104,244,14,42,75,70,
159,177,181,239,49,250,15,82,1,245,159,152,73,139,173,226,152,250,48,149,38,165,227,76,125,213,82,158,198,122,212,18,231,65,219,244,119,188,230,196,22,39,210,143,132,112,186,166,95,156,137,229,176,122,
168,150,167,165,177,78,115,211,82,78,229,198,134,37,230,194,133,79,157,11,231,62,49,153,114,195,234,100,106,219,85,190,3,111,11,234,112,125,158,145,226,157,86,220,173,76,231,207,29,183,184,31,56,37,90,
59,112,233,23,55,148,124,72,189,226,228,70,92,210,142,84,91,81,44,89,77,120,157,119,110,197,129,67,175,106,75,219,42,238,74,47,104,40,159,236,117,117,170,83,255,164,190,0,189,243,84,30,88,172,176,155,
0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PlayerComponent::foundationiconfonts_20150216_fastforward_64_0_000000_none_png = (const char*) resource_PlayerComponent_foundationiconfonts_20150216_fastforward_64_0_000000_none_png;
const int PlayerComponent::foundationiconfonts_20150216_fastforward_64_0_000000_none_pngSize = 867;

// JUCER_RESOURCE: foundationiconfonts_20150216_next_64_0_000000_none_png, 893, "../images/foundation-icon-fonts_2015-02-16_next_64_0_000000_none.png"
static const unsigned char resource_PlayerComponent_foundationiconfonts_20150216_next_64_0_000000_none_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,64,0,0,0,64,8,3,0,0,0,157,183,129,236,
0,0,1,53,80,76,84,69,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,176,123,73,255,0,0,0,102,116,82,78,83,0,1,2,3,4,5,6,7,9,10,11,12,13,14,16,17,19,20,23,24,26,27,28,32,37,38,40,44,46,53,55,56,57,58,59,60,65,71,73,74,76,77,78,80,81,
82,84,85,86,89,92,93,95,100,104,108,109,111,115,116,120,126,131,134,136,139,143,146,152,155,162,163,165,166,168,173,178,186,188,190,192,193,202,209,211,213,215,217,220,226,228,230,232,233,235,237,239,
241,245,247,251,253,82,239,123,8,0,0,1,145,73,68,65,84,88,195,237,214,215,82,194,80,16,6,96,14,17,130,98,162,130,162,96,65,197,142,10,246,134,98,47,88,193,96,65,16,37,240,191,255,35,120,33,35,51,178,7,
118,130,35,51,202,222,238,230,187,202,217,127,109,182,86,253,231,106,247,233,186,174,9,203,223,247,0,0,144,81,173,2,51,159,0,166,173,2,209,50,16,253,1,192,46,29,18,44,224,4,71,46,114,196,254,92,90,179,
51,0,0,197,21,106,208,13,224,101,132,5,0,153,97,26,0,110,60,44,0,184,246,208,0,176,231,100,1,64,92,165,1,20,230,4,11,128,25,17,36,0,164,253,44,0,120,26,162,1,224,180,147,5,0,87,221,52,128,210,186,194,
2,128,93,7,9,0,185,81,30,128,194,172,32,1,224,206,203,2,128,116,128,6,128,125,149,5,0,9,157,6,96,206,11,22,0,108,183,185,233,198,67,128,7,224,109,71,214,185,208,88,64,173,218,84,26,4,240,26,90,109,12,
168,84,11,104,34,240,120,217,16,96,46,10,198,143,100,74,59,7,42,227,87,46,46,123,36,157,100,47,231,49,29,186,232,231,140,92,136,243,156,147,125,146,133,130,13,133,177,80,178,99,146,149,134,115,141,177,
210,190,18,213,45,89,37,117,128,227,14,122,173,195,12,11,198,86,78,245,75,130,165,42,248,72,32,63,33,137,54,220,122,57,209,182,165,208,225,138,108,144,19,174,103,154,36,222,191,135,26,13,220,15,72,14,
140,234,88,165,128,247,41,33,185,80,12,127,221,19,39,15,196,28,212,136,171,18,147,53,1,223,82,151,100,102,60,236,252,157,67,179,73,64,164,12,44,88,5,130,101,96,208,42,32,98,41,195,48,18,147,182,86,253,
137,250,0,125,219,180,158,117,59,137,124,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PlayerComponent::foundationiconfonts_20150216_next_64_0_000000_none_png = (const char*) resource_PlayerComponent_foundationiconfonts_20150216_next_64_0_000000_none_png;
const int PlayerComponent::foundationiconfonts_20150216_next_64_0_000000_none_pngSize = 893;

// JUCER_RESOURCE: foundationiconfonts_20150216_play_64_0_000000_none_png, 803, "../images/foundation-icon-fonts_2015-02-16_play_64_0_000000_none.png"
static const unsigned char resource_PlayerComponent_foundationiconfonts_20150216_play_64_0_000000_none_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,64,0,0,0,64,8,3,0,0,0,157,183,129,236,
0,0,1,47,80,76,84,69,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,2,239,12,165,0,0,0,100,116,82,78,83,0,1,2,3,4,5,6,7,8,9,10,11,12,14,15,16,18,20,21,22,24,25,28,29,30,32,33,34,35,39,40,42,44,49,50,53,55,56,60,64,66,68,69,75,79,81,82,88,93,97,
99,103,105,109,111,112,113,115,121,130,131,136,140,148,151,155,157,158,163,166,171,175,183,186,188,190,197,199,202,204,206,211,215,217,218,220,224,226,228,230,233,237,239,241,243,245,247,249,251,253,192,
202,71,73,0,0,1,63,73,68,65,84,88,195,173,215,197,82,3,81,16,70,225,201,48,4,73,112,135,224,238,46,193,130,187,187,219,156,247,127,6,54,44,41,42,149,67,239,239,183,184,115,167,251,239,32,248,143,106,188,
125,155,143,12,112,2,188,142,8,32,6,224,162,173,96,128,159,218,76,73,128,120,38,116,0,60,246,75,0,142,234,37,0,107,37,18,224,99,34,225,0,184,238,148,0,236,85,73,0,178,145,4,120,25,146,0,156,181,72,0,54,
202,37,192,215,116,232,0,120,232,149,0,28,214,73,0,86,147,18,224,125,44,225,0,184,234,144,0,236,86,74,0,22,34,9,240,60,40,1,56,109,150,0,228,202,36,192,215,84,232,0,184,239,145,0,28,212,72,0,178,22,160,
217,2,25,9,156,133,10,136,231,138,212,29,108,167,213,103,188,200,168,135,244,50,236,158,242,82,164,126,166,223,155,74,222,199,47,219,85,67,121,27,77,168,150,182,92,172,154,234,126,181,106,235,55,93,106,
176,124,140,39,212,104,91,73,170,225,122,80,171,198,251,93,183,10,24,159,147,161,138,56,235,165,42,100,29,55,168,152,247,216,167,130,102,94,209,234,15,32,87,30,4,2,56,105,82,113,255,105,64,45,28,241,108,
145,90,121,182,210,106,233,58,111,85,107,223,243,80,80,104,221,0,44,138,237,185,15,118,42,212,250,94,146,42,248,232,55,186,140,205,132,25,64,166,108,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PlayerComponent::foundationiconfonts_20150216_play_64_0_000000_none_png = (const char*) resource_PlayerComponent_foundationiconfonts_20150216_play_64_0_000000_none_png;
const int PlayerComponent::foundationiconfonts_20150216_play_64_0_000000_none_pngSize = 803;

// JUCER_RESOURCE: foundationiconfonts_20150216_previous_64_0_000000_none_png, 892, "../images/foundation-icon-fonts_2015-02-16_previous_64_0_000000_none.png"
static const unsigned char resource_PlayerComponent_foundationiconfonts_20150216_previous_64_0_000000_none_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,64,0,0,0,64,8,3,0,0,0,157,183,129,
236,0,0,1,38,80,76,84,69,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,6,214,244,241,0,0,0,97,116,82,78,83,0,1,2,3,4,5,6,7,8,9,10,12,13,15,18,19,20,21,22,23,24,26,28,29,30,33,34,37,38,42,44,45,46,49,50,54,56,57,61,67,75,76,78,82,85,86,89,91,92,98,102,104,107,
109,113,121,126,128,131,136,142,143,145,148,149,151,157,160,162,163,166,173,175,180,183,185,186,188,192,195,197,199,206,211,213,218,224,230,232,233,239,243,245,247,249,251,253,162,76,146,100,0,0,1,164,
73,68,65,84,88,195,237,215,91,59,2,81,20,6,224,53,147,14,36,231,99,66,8,37,57,31,163,156,138,132,72,74,169,152,239,255,255,9,23,67,77,51,171,102,55,92,244,244,180,110,191,181,222,185,153,89,123,15,81,
175,186,162,28,243,126,191,127,86,178,60,31,1,0,224,209,50,80,84,1,216,173,2,63,243,112,117,52,32,55,77,36,17,96,244,1,59,124,178,144,87,188,166,128,227,20,64,130,75,134,82,0,54,77,0,41,84,1,128,164,49,
177,31,3,0,34,173,129,185,156,26,26,0,41,88,134,57,224,190,249,13,245,128,47,247,155,180,0,228,61,5,60,224,185,173,5,45,128,64,177,222,213,0,244,29,105,130,166,192,248,147,182,75,11,172,127,192,28,112,
68,1,30,240,190,234,18,14,144,54,42,224,1,247,181,62,224,0,223,155,161,75,5,108,251,10,204,129,193,4,192,3,107,37,46,209,1,236,67,0,36,105,250,133,13,116,192,106,137,239,66,246,162,73,208,0,76,100,208,
126,213,129,169,51,11,227,90,192,98,245,128,127,5,98,127,5,92,252,87,208,6,160,221,116,250,170,138,1,245,93,171,175,228,80,74,8,32,178,159,240,0,209,98,94,8,32,26,190,231,1,146,194,85,33,128,104,169,192,
2,68,206,168,24,64,242,246,39,11,16,141,165,133,0,162,254,56,15,16,45,23,132,0,162,169,103,30,32,121,235,83,8,104,92,162,13,71,155,235,92,12,32,219,1,15,16,77,102,132,0,205,142,55,28,239,129,119,33,160,
246,118,27,47,24,242,174,34,4,144,20,42,179,0,209,192,149,16,160,190,221,151,108,50,147,5,130,34,215,188,145,45,79,147,100,37,108,235,160,155,170,211,42,112,167,206,127,89,254,97,112,30,198,226,241,120,
218,111,117,190,87,93,81,223,172,84,147,178,220,207,173,206,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PlayerComponent::foundationiconfonts_20150216_previous_64_0_000000_none_png = (const char*) resource_PlayerComponent_foundationiconfonts_20150216_previous_64_0_000000_none_png;
const int PlayerComponent::foundationiconfonts_20150216_previous_64_0_000000_none_pngSize = 892;

// JUCER_RESOURCE: foundationiconfonts_20150216_record_64_0_000000_none_png, 1191, "../images/foundation-icon-fonts_2015-02-16_record_64_0_000000_none.png"
static const unsigned char resource_PlayerComponent_foundationiconfonts_20150216_record_64_0_000000_none_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,64,0,0,0,64,8,3,0,0,0,157,183,129,
236,0,0,1,161,80,76,84,69,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,168,186,164,63,0,0,0,138,116,82,78,83,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,20,21,22,23,24,25,26,27,28,30,31,32,33,35,36,37,38,40,41,42,
44,45,46,47,48,49,50,53,54,56,57,58,61,62,65,66,67,68,70,73,74,75,76,77,79,80,84,87,88,91,92,93,95,98,102,104,105,107,108,109,111,112,113,115,116,120,121,123,126,127,128,130,134,136,145,146,148,149,151,
152,154,158,160,162,163,165,166,171,176,178,183,186,188,195,197,199,200,202,204,206,207,213,215,217,218,220,222,224,226,228,233,235,239,241,243,245,247,249,251,253,3,58,173,250,0,0,2,43,73,68,65,84,24,
25,157,193,141,95,11,113,28,7,240,207,217,78,91,18,45,15,41,25,145,76,42,15,243,144,132,37,68,168,149,66,34,228,49,79,35,73,218,134,218,186,238,243,87,219,170,189,246,112,223,223,237,238,222,111,216,168,
9,53,135,219,15,55,135,2,112,47,16,137,127,51,89,96,206,143,159,170,133,115,219,163,95,104,149,232,13,192,145,186,9,147,10,83,187,81,149,254,152,118,166,3,176,23,93,165,189,181,126,216,240,191,102,117,
115,53,80,217,155,162,19,127,91,33,107,51,232,140,217,5,73,15,157,187,2,171,78,186,113,17,149,90,77,186,18,65,185,157,89,186,99,54,162,148,246,157,110,253,246,161,196,36,221,123,137,162,22,122,209,129,
2,109,129,94,164,182,97,203,5,122,115,3,155,180,52,189,201,248,176,161,135,94,93,197,134,4,189,74,35,175,158,54,146,159,127,173,83,173,9,57,3,84,88,31,222,143,188,208,96,134,10,113,228,124,165,236,69,
0,5,254,39,148,165,1,248,40,187,141,82,253,148,5,129,131,20,221,67,185,65,138,78,2,151,40,249,128,74,111,41,185,5,140,82,210,128,74,13,148,76,3,239,40,120,5,171,247,20,252,0,230,41,232,134,213,121,10,
50,64,146,130,122,88,237,163,4,200,80,160,195,170,142,18,13,6,5,62,88,5,41,209,240,135,130,29,176,10,81,2,252,164,160,13,86,157,20,172,1,31,41,120,8,171,167,20,44,1,147,20,100,117,84,210,179,20,204,2,
215,40,25,67,165,7,148,12,3,199,40,138,160,220,17,138,206,2,1,138,140,67,40,181,39,67,81,3,128,101,202,122,81,212,189,78,81,6,57,113,42,36,218,52,228,105,45,115,84,152,70,206,1,42,25,179,99,131,35,51,
171,84,106,71,94,154,94,101,53,228,197,232,85,28,27,252,6,61,170,197,166,187,244,102,10,91,244,21,122,97,4,81,112,142,94,92,71,209,39,186,183,160,161,40,184,66,183,140,93,40,213,78,183,206,160,92,140,
238,220,71,165,81,186,49,5,171,71,116,238,57,36,119,232,212,4,100,125,116,230,38,84,154,210,172,238,95,24,106,250,51,86,243,166,6,182,194,139,180,147,58,142,106,180,211,139,84,89,142,106,112,226,232,140,
73,193,236,9,13,78,249,59,199,151,88,42,57,217,165,195,37,61,212,113,57,54,52,50,52,208,23,105,212,161,244,31,157,58,216,237,136,118,253,229,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PlayerComponent::foundationiconfonts_20150216_record_64_0_000000_none_png = (const char*) resource_PlayerComponent_foundationiconfonts_20150216_record_64_0_000000_none_png;
const int PlayerComponent::foundationiconfonts_20150216_record_64_0_000000_none_pngSize = 1191;

// JUCER_RESOURCE: foundationiconfonts_20150216_rewind_64_0_000000_none_png, 889, "../images/foundation-icon-fonts_2015-02-16_rewind_64_0_000000_none.png"
static const unsigned char resource_PlayerComponent_foundationiconfonts_20150216_rewind_64_0_000000_none_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,64,0,0,0,64,8,3,0,0,0,157,183,129,
236,0,0,1,56,80,76,84,69,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,167,181,177,183,0,0,0,103,116,82,78,83,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,17,19,20,21,23,26,27,28,30,31,35,37,39,40,44,47,48,49,52,53,54,58,59,60,64,
65,69,75,77,79,84,88,89,91,92,94,95,99,103,105,111,119,124,127,130,133,140,142,143,145,148,149,157,160,162,165,166,173,178,180,181,183,185,186,193,195,199,200,206,207,209,211,213,218,222,224,228,232,233,
237,239,243,245,247,249,251,253,167,241,18,44,0,0,1,137,73,68,65,84,88,195,237,214,199,86,194,80,0,4,208,73,16,20,197,222,43,246,222,197,174,216,11,246,222,192,46,204,255,255,129,11,59,102,200,59,100,
167,204,118,242,238,38,201,156,7,228,146,203,127,73,64,87,126,203,253,120,195,57,99,162,10,174,240,198,77,40,222,32,73,199,202,30,75,146,12,101,60,238,155,78,81,1,173,113,210,13,232,185,35,5,80,177,251,
94,101,0,106,143,73,1,248,231,62,43,9,4,151,73,1,88,3,143,116,3,236,209,23,42,160,241,242,123,229,12,180,197,73,1,20,111,254,172,156,128,138,61,82,0,190,233,244,234,55,16,152,39,21,208,125,71,55,192,26,
124,162,2,106,142,29,170,52,160,233,138,20,64,193,146,99,245,3,40,217,34,5,96,141,188,208,13,240,205,80,197,10,223,168,234,11,232,189,151,231,185,175,171,15,160,238,148,217,229,13,40,92,35,61,0,118,36,
73,47,64,71,130,244,2,140,147,222,128,184,87,32,252,232,17,248,62,47,217,190,198,242,29,143,0,160,63,85,67,64,255,44,166,0,80,16,213,79,77,38,13,0,160,250,72,61,133,224,170,9,0,116,221,170,61,64,221,137,
9,0,123,42,165,22,73,252,239,191,70,53,180,46,55,209,113,113,28,102,189,225,76,0,64,233,182,9,0,244,63,8,0,104,190,50,1,144,55,171,0,88,67,79,6,0,80,22,19,0,16,88,48,1,128,150,107,1,0,149,7,38,0,172,225,
103,1,0,237,9,3,0,200,95,84,192,215,142,102,190,35,161,234,80,0,159,75,30,114,187,229,117,38,200,148,115,85,127,74,178,200,245,158,104,71,46,38,84,215,119,22,69,46,185,252,145,188,2,20,11,108,163,190,
149,43,73,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PlayerComponent::foundationiconfonts_20150216_rewind_64_0_000000_none_png = (const char*) resource_PlayerComponent_foundationiconfonts_20150216_rewind_64_0_000000_none_png;
const int PlayerComponent::foundationiconfonts_20150216_rewind_64_0_000000_none_pngSize = 889;

// JUCER_RESOURCE: foundationiconfonts_20150216_stop_64_0_000000_none_png, 208, "../images/foundation-icon-fonts_2015-02-16_stop_64_0_000000_none.png"
static const unsigned char resource_PlayerComponent_foundationiconfonts_20150216_stop_64_0_000000_none_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,64,0,0,0,64,4,3,0,0,0,88,71,108,237,
0,0,0,45,80,76,84,69,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,193,160,40,62,0,0,0,14,116,82,78,83,0,1,6,7,16,19,20,62,63,73,74,81,224,226,42,84,26,21,0,
0,0,68,73,68,65,84,72,199,99,96,14,75,195,3,28,25,24,230,189,195,7,222,40,48,156,195,171,224,93,1,3,126,249,119,27,70,21,140,42,24,85,48,170,96,84,193,168,130,81,5,212,84,64,160,106,110,96,88,135,87,254,
173,2,3,115,26,254,230,1,0,8,213,59,23,0,160,253,202,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PlayerComponent::foundationiconfonts_20150216_stop_64_0_000000_none_png = (const char*) resource_PlayerComponent_foundationiconfonts_20150216_stop_64_0_000000_none_png;
const int PlayerComponent::foundationiconfonts_20150216_stop_64_0_000000_none_pngSize = 208;

// JUCER_RESOURCE: ionicons_201_search_64_0_000000_none_png, 1223, "../images/ionicons_2-0-1_search_64_0_000000_none.png"
static const unsigned char resource_PlayerComponent_ionicons_201_search_64_0_000000_none_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,64,0,0,0,64,8,3,0,0,0,157,183,129,236,0,0,1,122,80,
76,84,69,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,144,14,4,2,0,0,0,125,116,82,78,83,0,
1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,23,24,26,28,29,30,32,33,34,35,39,40,42,43,44,45,47,50,51,52,59,63,68,70,71,74,75,76,77,78,82,84,85,86,87,89,92,93,95,97,98,99,100,108,111,115,123,128,130,133,
137,142,145,146,148,149,151,152,154,157,158,160,163,165,166,171,173,175,176,178,180,181,183,185,188,192,193,197,199,200,202,204,206,207,209,211,213,215,217,218,220,222,224,226,228,230,232,233,239,241,
243,245,247,249,251,253,53,233,26,79,0,0,2,127,73,68,65,84,24,25,173,193,7,87,211,80,0,6,208,47,165,133,164,45,171,226,40,136,10,130,200,114,107,5,17,220,40,8,136,50,4,69,177,32,148,50,210,10,202,104,
191,255,238,193,227,75,94,214,163,65,239,133,143,154,182,135,175,190,110,239,31,152,217,241,199,215,18,8,41,121,39,71,135,194,80,10,149,107,154,164,143,133,22,84,198,152,96,128,249,122,84,160,247,136,
193,50,56,73,213,91,42,205,196,160,164,175,242,4,91,73,40,212,154,60,209,94,10,129,140,2,43,176,151,68,128,104,142,21,217,138,193,223,52,29,246,70,46,39,35,128,102,52,15,108,210,97,6,190,238,82,150,109,
135,228,194,60,101,25,248,168,45,211,86,234,131,75,231,47,74,234,225,53,67,219,78,10,30,241,21,218,230,224,145,166,109,173,6,62,162,75,180,53,195,109,142,150,130,14,95,177,28,45,31,225,210,64,91,19,2,
52,150,104,73,193,105,144,150,12,2,221,162,101,16,78,5,10,166,134,64,90,158,130,9,135,4,45,221,80,232,162,37,14,89,7,133,114,20,10,85,37,10,29,144,13,81,152,130,210,56,133,33,200,198,40,244,67,169,135,
194,24,100,89,10,45,80,74,83,88,129,204,164,80,15,165,58,10,69,200,14,40,24,80,210,41,28,65,118,64,193,128,146,78,225,16,50,147,66,61,148,234,40,108,65,150,165,208,2,165,52,133,37,200,198,40,244,65,169,
135,194,4,100,67,20,38,161,52,78,225,1,100,157,20,202,81,40,68,74,20,90,33,75,208,210,13,133,46,90,12,56,20,40,152,26,2,105,121,10,203,112,122,68,75,6,129,110,210,210,15,167,70,218,206,32,64,67,137,22,
3,46,243,180,152,58,124,69,115,180,140,194,45,77,219,90,13,124,68,151,104,107,128,199,44,109,219,41,120,24,89,218,222,192,171,174,76,91,169,23,46,29,63,41,217,173,133,215,125,202,190,181,65,114,126,142,
78,63,146,240,122,79,135,221,225,75,137,8,160,233,233,76,158,30,197,4,60,98,121,134,80,72,192,35,94,100,8,102,28,30,117,69,134,176,99,192,195,88,103,8,91,6,60,162,147,12,97,83,135,215,141,18,43,151,215,
225,21,159,98,128,103,35,116,219,168,129,143,179,239,232,227,69,18,24,166,91,174,26,126,146,247,54,232,240,233,122,12,199,158,208,109,189,26,254,244,246,129,209,229,157,253,253,220,226,235,219,205,213,
16,158,210,237,123,12,161,60,167,219,106,12,161,188,164,219,34,194,25,165,75,17,225,104,227,116,56,108,66,72,218,20,37,71,231,16,154,246,129,150,82,26,167,160,205,242,175,242,69,156,74,100,129,127,148,
91,113,74,145,207,60,118,5,167,86,245,133,228,85,252,131,232,244,78,27,254,151,223,155,171,253,96,77,37,228,197,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PlayerComponent::ionicons_201_search_64_0_000000_none_png = (const char*) resource_PlayerComponent_ionicons_201_search_64_0_000000_none_png;
const int PlayerComponent::ionicons_201_search_64_0_000000_none_pngSize = 1223;


//[EndFile] You can add extra defines here...
//[/EndFile]

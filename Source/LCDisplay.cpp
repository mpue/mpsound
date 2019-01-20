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
//[/Headers]

#include "LCDisplay.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
LCDisplay::LCDisplay ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    timeLabel.reset (new Label ("timeLabel",
                                TRANS("0:00")));
    addAndMakeVisible (timeLabel.get());
    timeLabel->setFont (Font ("Dot Matrix", 20.00f, Font::bold).withExtraKerningFactor (0.055f));
    timeLabel->setJustificationType (Justification::centredLeft);
    timeLabel->setEditable (false, false, false);
    timeLabel->setColour (Label::textColourId, Colour (0xffba7c12));
    timeLabel->setColour (TextEditor::textColourId, Colours::black);
    timeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    timeLabel->setBounds (8, 8, 150, 20);

    nameLabel.reset (new Label ("nameLabel",
                                TRANS("unknown title")));
    addAndMakeVisible (nameLabel.get());
    nameLabel->setFont (Font ("Dot Matrix", 12.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (0.055f));
    nameLabel->setJustificationType (Justification::centredLeft);
    nameLabel->setEditable (false, false, false);
    nameLabel->setColour (Label::textColourId, Colour (0xffba7c12));
    nameLabel->setColour (TextEditor::textColourId, Colours::black);
    nameLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    nameLabel->setBounds (8, 32, 312, 20);

    artistLabel.reset (new Label ("artistLabel",
                                  TRANS("unknown artist")));
    addAndMakeVisible (artistLabel.get());
    artistLabel->setFont (Font ("Dot Matrix", 12.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (0.055f));
    artistLabel->setJustificationType (Justification::centredLeft);
    artistLabel->setEditable (false, false, false);
    artistLabel->setColour (Label::textColourId, Colour (0xffba7c12));
    artistLabel->setColour (TextEditor::textColourId, Colours::black);
    artistLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    artistLabel->setBounds (8, 56, 312, 20);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (400, 200);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

LCDisplay::~LCDisplay()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    timeLabel = nullptr;
    nameLabel = nullptr;
    artistLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void LCDisplay::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::black);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void LCDisplay::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="LCDisplay" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="400" initialHeight="200">
  <BACKGROUND backgroundColour="ff000000"/>
  <LABEL name="timeLabel" id="925d5b3c1504f09e" memberName="timeLabel"
         virtualName="" explicitFocusOrder="0" pos="8 8 150 20" textCol="ffba7c12"
         edTextCol="ff000000" edBkgCol="0" labelText="0:00" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Dot Matrix"
         fontsize="20.00000000000000000000" kerning="0.05500000000000000028"
         bold="1" italic="0" justification="33" typefaceStyle="Bold"/>
  <LABEL name="nameLabel" id="3f2c1482566bae6f" memberName="nameLabel"
         virtualName="" explicitFocusOrder="0" pos="8 32 312 20" textCol="ffba7c12"
         edTextCol="ff000000" edBkgCol="0" labelText="unknown title" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Dot Matrix"
         fontsize="12.00000000000000000000" kerning="0.05500000000000000028"
         bold="0" italic="0" justification="33"/>
  <LABEL name="artistLabel" id="e43f3749fa47c5cc" memberName="artistLabel"
         virtualName="" explicitFocusOrder="0" pos="8 56 312 20" textCol="ffba7c12"
         edTextCol="ff000000" edBkgCol="0" labelText="unknown artist"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Dot Matrix" fontsize="12.00000000000000000000" kerning="0.05500000000000000028"
         bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

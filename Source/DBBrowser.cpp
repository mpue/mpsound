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

#include "DBBrowser.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
DBBrowser::DBBrowser ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    textEditor.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (textEditor.get());
    textEditor->setMultiLine (false);
    textEditor->setReturnKeyStartsNewLine (false);
    textEditor->setReadOnly (false);
    textEditor->setScrollbarsShown (true);
    textEditor->setCaretVisible (true);
    textEditor->setPopupMenuEnabled (true);
    textEditor->setText (String());

    textEditor->setBounds (16, 8, 320, 24);

    viewport.reset (new Viewport ("new viewport"));
    addAndMakeVisible (viewport.get());

    updateButton.reset (new TextButton ("updateButton"));
    addAndMakeVisible (updateButton.get());
    updateButton->setButtonText (TRANS("Update DB"));
    updateButton->addListener (this);

    updateButton->setBounds (352, 8, 100, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (450, 600);


    //[Constructor] You can add your own custom stuff here..

    model = new DBTableModel();

    table = new TableListBox();
    table->getHeader().addColumn("File", 1, 400);
    table->setAutoSizeMenuOptionShown(true);
    table->getHeader().setStretchToFitActive(true);
    table->setModel(model);
    table->addMouseListener(this, true);
    viewport->setViewedComponent(table);
    viewport->setTopLeftPosition(10,48);
    repaint();
    resized();
    model->loadData();
    table->updateContent();
    textEditor->addListener(this);
    //[/Constructor]
}

void DBBrowser::textEditorTextChanged(TextEditor &t) {
    model->filter(textEditor.get()->getText());
    table->updateContent();
}

DBBrowser::~DBBrowser()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    textEditor = nullptr;
    viewport = nullptr;
    updateButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    if (sampler != nullptr) {
        delete sampler;
    }
    //[/Destructor]
}

void DBBrowser::mouseDoubleClick(const juce::MouseEvent &event) {
    playSelectedFile();
}

//==============================================================================
void DBBrowser::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]
    g.fillAll (Colour (0xff222222));
    g.fillRect (getLocalBounds());

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void DBBrowser::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    if (getParentComponent() != nullptr) {
        setSize(getParentWidth(), getParentHeight());

    }
    
    if (viewport != nullptr) {
        viewport->setSize(getWidth() - 10, getHeight() - 64);
        if (table !=  nullptr) {
            table->setSize(viewport->getWidth(), viewport->getHeight());
        }
        
    }
    

    //[/UserPreResize]

    //viewport->setBounds (16, 48, proportionOfWidth (0.9801f), proportionOfHeight (0.9800f));
    //[UserResized] Add your own custom resize handling here..

    //[/UserResized]
}

void DBBrowser::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == updateButton.get())
    {
        //[UserButtonCode_updateButton] -- add your button handler code here..
        model->update();
        table->updateContent();
        //[/UserButtonCode_updateButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void DBBrowser::playSelectedFile() {
    AudioIODevice*  device = AudioManager::getInstance()->getDeviceManager()->getCurrentAudioDevice();
    
    if (sampler != nullptr) {
        sampler->stop();
        delete sampler;
    }
    
    sampler = new Sampler(device->getCurrentSampleRate(),device->getDefaultBufferSize());
    sampler->loadSample(model->getFile(table->getSelectedRow()));
    sampler->play();
}

Sampler* DBBrowser::getSampler() {
    return sampler;
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="DBBrowser" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="450" initialHeight="600">
  <BACKGROUND backgroundColour="ff323e44"/>
  <TEXTEDITOR name="new text editor" id="806cd18d3537f2c2" memberName="textEditor"
              virtualName="" explicitFocusOrder="0" pos="16 8 320 24" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <VIEWPORT name="new viewport" id="4bbf170e84583707" memberName="viewport"
            virtualName="" explicitFocusOrder="0" pos="16 48 98.012% 98.004%"
            vscroll="1" hscroll="1" scrollbarThickness="8" contentType="0"
            jucerFile="" contentClass="TableListBox" constructorParams=""/>
  <TEXTBUTTON name="updateButton" id="176f55b593519c44" memberName="updateButton"
              virtualName="" explicitFocusOrder="0" pos="352 8 100 24" buttonText="Update DB"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

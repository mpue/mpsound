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
#include "SQLiteWrapper.h"
#include "AudioManager.h"
#include "Sampler.h"

class DBTableModel : public TableListBoxModel {
public:

    DBTableModel() {
        sqlite = new SQLiteWrapper();
        sqlite->createDatabase();
        sqlite->openDatabase("files");
    }

    ~DBTableModel() {
        sqlite->close();
        delete sqlite;
    }

    virtual void paintRowBackground (juce::Graphics& g,
                                     int rowNumber,
                                     int width, int height,
                                     bool rowIsSelected) override {
        if (rowIsSelected) {
            g.setColour(juce::Colours::orange);
        }
        else {
            g.setColour(Colour (0xff222222));
        }

        g.fillRect(0,0,width,height);

    }
    virtual void paintCell (juce::Graphics& g,
                            int rowNumber,
                            int columnId,
                            int width, int height,
                            bool rowIsSelected) override {

        g.setColour(juce::Colours::black);

        String text = "";

        if (columnId == 1) {
            text = fileList.getReference(rowNumber).getFileName();
            g.setColour(juce::Colours::white);
            g.drawText(text, 0,0, width,height, juce::Justification::centredLeft);

        }

    }
    virtual int getNumRows() override {

        return fileList.size();
    }

    void update() {
        // sqlite->updateDB();
        sqlite->query("select * from files");
        
        for(std::map<juce::String, juce::String>::iterator itr = SQLiteWrapper::results.begin(); itr != SQLiteWrapper::results.end(); itr++)
        {
            
            juce::String name = itr->first;
            
            // fileList.add(File(path));
        
            fileList.add(File(SQLiteWrapper::results[name]));
        }
        
    }

    File getFile(int row) {
        return fileList.getReference(row);
    }


private:
    SQLiteWrapper* sqlite = nullptr;
    Array<File> fileList;

};

//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class DBBrowser  : public Component,
                   public Button::Listener
{
public:
    //==============================================================================
    DBBrowser ();
    ~DBBrowser();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void mouseDoubleClick(const juce::MouseEvent &event) override;
    Sampler* getSampler();

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    TableListBox* table = nullptr;
    DBTableModel* model = nullptr;
    void playSelectedFile();
    Sampler* sampler = nullptr;
    
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<TextEditor> textEditor;
    std::unique_ptr<Viewport> viewport;
    std::unique_ptr<TextButton> updateButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DBBrowser)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

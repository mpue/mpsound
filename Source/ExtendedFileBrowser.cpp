//
//  ExtendedFileBrowser.cpp
//  Synthlab - App
//
//  Created by Matthias Pueski on 30.04.18.
//  Copyright © 2018 Pueski. All rights reserved.
//

#include "ExtendedFileBrowser.h"
#include "../JuceLibraryCode/JuceHeader.h"
#include "AudioManager.h"

using juce::File;
using juce::WildcardFileFilter;
using juce::TableListBox;
using juce::Viewport;
using juce::Colour;
using juce::String;
using juce::DirectoryContentsList;
using juce::ChangeBroadcaster;
using juce::Graphics;
using juce::ValueTree;
using juce::OutputStream;
using juce::XmlElement;
using juce::XmlDocument;
using juce::ScopedPointer;

ExtendedFileBrowser::ExtendedFileBrowser(const File& initialFileOrDirectory,const WildcardFileFilter* fileFilter, FileBrowserModel* model) : initialDir(initialFileOrDirectory) {
    
    // addMouseListener(this, true);
    table = new TableListBox();
    table->getHeader().addColumn("File", 1, 400);
    table->getHeader().addColumn("Size", 2, 100);
    table->setAutoSizeMenuOptionShown(true);
    table->getHeader().setStretchToFitActive(true);
    table->setModel(model);
    this->model = model;
    view  = new Viewport();
    view->setViewedComponent(table);
    addAndMakeVisible(view);
    
    AudioIODevice* device = AudioManager::getInstance()->getDeviceManager()->getCurrentAudioDevice();
    sampler = new Sampler(device->getCurrentSampleRate(),device->getDefaultBufferSize());

    table->addMouseListener(this, true);
    
    loadState();
    
    model->update();

    repaint();
}

ExtendedFileBrowser::~ExtendedFileBrowser() {
    saveState();
    delete table;
    delete view;
    sampler->stop();
    delete sampler;
}

void ExtendedFileBrowser::mouseDrag(const juce::MouseEvent &event) {
    /*
    var description;
    
    // setDragImageForIndex(0, ImageCache::getFromMemory(BinaryData::module_png, BinaryData::module_pngSize));
    startDragging(description,table);
     */
    
    /*
    StringArray files = StringArray();
    if (selectedFile != nullptr && selectedFile->getFullPathName().isNotEmpty()) {
        files.add(selectedFile->getFullPathName());
        DragAndDropContainer::performExternalDragDropOfFiles(files, false);
    }
     */

}

void ExtendedFileBrowser::paint(juce::Graphics &g) {
    g.fillAll (Colour (0xff222222));
    g.fillRect (getLocalBounds());
    // Component::paint(g);
}

void ExtendedFileBrowser::resized() {
    if (getParentComponent() != nullptr) {
        setSize(getParentWidth(), getParentHeight());
        view->setSize(getWidth(), getHeight());
        table->setSize(getWidth(), getHeight() - 30);
    }
}

void ExtendedFileBrowser::changeListenerCallback (ChangeBroadcaster* source) {
    table->updateContent();
}

void ExtendedFileBrowser::mouseDown(const juce::MouseEvent &event) {


}

void ExtendedFileBrowser::mouseDoubleClick(const juce::MouseEvent &event) {
    
    if (table->getSelectedRow() > 0) {
        File* f = new File(model->getDirectoryList()->getFile(table->getSelectedRow()));
        if (f->exists()) {
            if (f->isDirectory()) {
                model->setCurrentDir(f);
            }
            else {
                if (table->getSelectedRow() > 0) {
                    playFile(table->getSelectedRow());
                }
            }
        }
    }
    else {
        File* current = new File(model->getCurrentDir());
        File* parent = new File(current->getParentDirectory());
        model->setCurrentDir(parent);
        delete current;
    }

}

void ExtendedFileBrowser::selectNextFile() {
    int row = table->getSelectedRow();

    if (row < table->getNumRows() - 1) {
        row++;
        table->selectRow(row);
        playFile(row);
    }
}

void ExtendedFileBrowser::selectPreviousFile() {
    int row = table->getSelectedRow();
    
    if (row > 0) {
        row--;
        table->selectRow(row);
        playFile(row);
    }
}

void ExtendedFileBrowser::timerCallback() {
   
}

void ExtendedFileBrowser::playFile(int row) {
    File* f = new File(model->getDirectoryList()->getFile(row));
    if (f->exists()) {
        if (!f->isDirectory()) {
            
            if (sampler != nullptr) {
                delete sampler;
            }
            
            AudioIODevice*  device = AudioManager::getInstance()->getDeviceManager()->getCurrentAudioDevice();
            
            sampler = new Sampler(device->getCurrentSampleRate(),device->getDefaultBufferSize());
         
            
            if (f->getFileExtension().toLowerCase().contains("wav") ||
                f->getFileExtension().toLowerCase().contains("aif") ||
                f->getFileExtension().toLowerCase().contains("aiff") ||
                f->getFileExtension().toLowerCase().contains("mp3") ||
                f->getFileExtension().toLowerCase().contains("ogg")) {
                sampler->stop();
                sampler->loadSample(*f);
                // sampler->setPitch(44100.0f/48000.0f);
                sampler->play();
                selectedFile = f;
                sendChangeMessage();
            }
        }
        
    }
    delete f;
}

//===========================================================================
// Model
//===========================================================================

FileBrowserModel::FileBrowserModel(DirectoryContentsList* directoryList, File& initalDir) {
    this->directoryList = directoryList;
    this->currentDirectory = initalDir.getFullPathName();
    directoryList->setDirectory(initalDir, true,true);
}

int FileBrowserModel::getNumRows() {
    return directoryList->getNumFiles() + 1;
}
void FileBrowserModel::paintCell (Graphics& g,
                int rowNumber,
                int columnId,
                int width, int height,
                bool rowIsSelected) {
    
    g.setColour(juce::Colours::black);
    
    String text = "";
    
    if (columnId == 1) {
 
        if (rowNumber > 0) {
            text = directoryList->getFile(rowNumber).getFileName();
        }
        else {
            text = "[up]";
        }
        g.setColour(juce::Colours::white);
        g.drawText(text, 0,0, width,height, juce::Justification::centredLeft);
       
    }
    else if (columnId == 2) {
        if (rowNumber > 0) {
            text = String(directoryList->getFile(rowNumber).getSize() / 1024) + "kB";
        }
        else {
            text = "";
        }
        
        g.setColour(juce::Colours::white);
        g.drawText(text, 0,0, width,height, juce::Justification::right);
    }

    
    
}

void FileBrowserModel::paintRowBackground (Graphics& g,
                         int rowNumber,
                         int width, int height,
                         bool rowIsSelected) {

    
    if (rowIsSelected) {
        g.setColour(juce::Colours::orange);
    }
    else {
        g.setColour(Colour (0xff222222));
    }
    
    g.fillRect(0,0,width,height);
}

void FileBrowserModel::setCurrentDir(juce::File* dir){
    this->currentDirectory = dir->getFullPathName();
    directoryList->setDirectory(*dir, true, true);
}

void FileBrowserModel::update() {
    directoryList->refresh();
}

DirectoryContentsList* FileBrowserModel::getDirectoryList() {
    return directoryList;
}

void ExtendedFileBrowser::saveState(){
    String userHome = File::getSpecialLocation(File::userHomeDirectory).getFullPathName();
    File appDir = File(userHome+"/.Synthlab");
    
    if (!appDir.exists()) {
        appDir.createDirectory();
    }
    
    File configFile = File(userHome+"/.Synthlab/state.xml");
    
    if (!configFile.exists()) {
        configFile.create();
    }
    else {
        configFile.deleteFile();
        configFile = File(userHome+"/.Synthlab/state.xml");
    }
    
    ValueTree* v = new ValueTree("SavedState");
    
    ValueTree child = ValueTree("File");
    child.setProperty("lastDirectory", model->getCurrentDir(), nullptr);
    v->addChild(child, -1, nullptr);
    
    OutputStream* os = configFile.createOutputStream();
    
    XmlElement* xml = v->createXml();
    
    xml->writeToStream(*os, "");
    
    delete os;
    delete xml;
    delete v;
}

void ExtendedFileBrowser::loadState() {
    String userHome = File::getSpecialLocation(File::userHomeDirectory).getFullPathName();
    
    File appDir = File(userHome+"/.Synthlab");
    
    if (!appDir.exists()) {
        appDir.createDirectory();
    }
    
    File configFile = File(userHome+"/.Synthlab/state.xml");
    
    if (configFile.exists()) {
        ScopedPointer<XmlElement> xml = XmlDocument(configFile).getDocumentElement();
        ValueTree v = ValueTree::fromXml(*xml.get());
        
        if (v.getNumChildren() > 0) {
            String path = v.getChild(0).getProperty("lastDirectory");
            File* file = new File(path);
            model->setCurrentDir(file);
            delete file;
        }
        xml = nullptr;
    }
}


File* ExtendedFileBrowser::getSelectedFile() {
    return selectedFile;
}

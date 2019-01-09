/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a JUCE application.

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "MainComponent.h"
#include "CustomLookAndFeel.h"

//==============================================================================
class mpsoundApplication  : public JUCEApplication
{
public:
    //==============================================================================
    mpsoundApplication() {}

    const String getApplicationName() override       { return ProjectInfo::projectName; }
    const String getApplicationVersion() override    { return ProjectInfo::versionString; }
    bool moreThanOneInstanceAllowed() override       { return true; }

    //==============================================================================
    void initialise (const String& commandLine) override
    {
        // This method is where you should put your application's initialisation code..
        
        mainWindow.reset (new MainWindow (getApplicationName()));
    }

    void shutdown() override
    {
        // Add your application's shutdown code here..

        mainWindow = nullptr; // (deletes our window)
    }

    //==============================================================================
    void systemRequestedQuit() override
    {
        // This is called when the app is being asked to quit: you can ignore this
        // request and let the app carry on running, or call quit() to allow the app to close.
        quit();
    }

    void anotherInstanceStarted (const String& commandLine) override
    {
        // When another instance of the app is launched while this one is running,
        // this method is invoked, and the commandLine parameter tells you what
        // the other instance's command-line arguments were.
    }

    //==============================================================================
    /*
        This class implements the desktop window that contains an instance of
        our MainComponent class.
    */
    class MainWindow    : public DocumentWindow
    {
    public:
        MainWindow (String name)  : DocumentWindow (name,
                                                    Desktop::getInstance().getDefaultLookAndFeel()
                                                                          .findColour (ResizableWindow::backgroundColourId),
                                                    DocumentWindow::allButtons)
        {
            lf = new CustomLookAndFeel();
            setLookAndFeel(lf);
            setUsingNativeTitleBar (true);
            setContentOwned (new MainComponent(), true);
            setResizable (true, true);

            centreWithSize (getWidth(), getHeight());
            loadState();
            setVisible (true);
        }
        
        ~MainWindow() {
            saveState();
            setLookAndFeel(nullptr);
            delete lf;
        }

        void closeButtonPressed() override
        {
            // This is called when the user tries to close this window. Here, we'll just
            // ask the app to quit when this happens, but you can change this to do
            // whatever you need.
            JUCEApplication::getInstance()->systemRequestedQuit();
        }

        /* Note: Be careful if you override any DocumentWindow methods - the base
           class uses a lot of them, so by overriding you might break its functionality.
           It's best to do all your work in your content component instead, but if
           you really have to override any DocumentWindow methods, make sure your
           subclass also calls the superclass's method.
        */
        
        /*
        void resized() override {
            saveState();
        }
         */
        
        void saveState(){
            String userHome = File::getSpecialLocation(File::userHomeDirectory).getFullPathName();
            File appDir = File(userHome+"/.Synthlab");
            
            if (!appDir.exists()) {
                appDir.createDirectory();
            }
            
            File configFile = File(userHome+"/.Synthlab/window.xml");
            
            if (!configFile.exists()) {
                configFile.create();
            }
            else {
                configFile.deleteFile();
                configFile = File(userHome+"/.Synthlab/window.xml");
            }
            
            ValueTree* v = new ValueTree("SavedState");
            
            ValueTree child = ValueTree("Properties");
            child.setProperty("state",getWindowStateAsString(), nullptr);
            v->addChild(child, -1, nullptr);
            
            OutputStream* os = configFile.createOutputStream();
            
            XmlElement* xml = v->createXml();
            
            xml->writeToStream(*os, "");
            
            delete os;
            delete xml;
            delete v;
        }
        
        void loadState() {
            String userHome = File::getSpecialLocation(File::userHomeDirectory).getFullPathName();
            
            File appDir = File(userHome+"/.Synthlab");
            
            if (!appDir.exists()) {
                appDir.createDirectory();
            }
            
            File configFile = File(userHome+"/.Synthlab/window.xml");
            
            if (configFile.exists()) {
                ScopedPointer<XmlElement> xml = XmlDocument(configFile).getDocumentElement();
                ValueTree v = ValueTree::fromXml(*xml.get());
                
                if (v.getNumChildren() > 0) {
                    String state = v.getChild(0).getProperty("state");
                    restoreWindowStateFromString(state);
                }
                xml = nullptr;
            }
        }

    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow)
        CustomLookAndFeel* lf;
    };

private:
    std::unique_ptr<MainWindow> mainWindow;
};

//==============================================================================
// This macro generates the main() routine that launches the app.
START_JUCE_APPLICATION (mpsoundApplication)

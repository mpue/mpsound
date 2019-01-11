/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
#include "ExtendedFileBrowser.h"
#include "AudioManager.h"

//==============================================================================
MainComponent::MainComponent() : TimeSliceThread("PropertyWatcher") {
    
    // Make sure you set the size of the component after
    // you add any child components.
    setSize (400, 400);

    // specify the number of input and output channels that we want to open
    setAudioChannels (2, 2);
    
    AudioManager::getInstance()->setDeviceManager(&deviceManager);

    addTimeSliceClient(this);
    filter = new WildcardFileFilter("*.wav;*.aif;*.aiff;*.mp3;*.slb","*","*");
    directoryContents = new DirectoryContentsList(filter,*this);
    directoryContents->setIgnoresHiddenFiles(false);
    File initialDir = File::getSpecialLocation(File::SpecialLocationType::userHomeDirectory).getFullPathName()+"/Documents/samples";
    FileBrowserModel* model = new FileBrowserModel(directoryContents, initialDir);
    browser  = new ExtendedFileBrowser(File::getSpecialLocation(File::userHomeDirectory),filter,model);
    directoryContents->addChangeListener(browser);
    startThread();
    
    dbbrowser = new DBBrowser();
    
    
    playerPanel = new PlayerComponent(browser);
    playerPanel->setTopLeftPosition(getWidth() / 2 - playerPanel->getWidth() / 2,0);
    addTimeSliceClient(playerPanel);
    addAndMakeVisible(playerPanel);
    timeSlider = new Slider(Slider::LinearHorizontal, Slider::NoTextBox);
    timeSlider->setSize(getWidth(), 10);
    playerPanel->setSlider(timeSlider);
    browser->addChangeListener(this);
    addAndMakeVisible(timeSlider);
    timeSlider->setTopLeftPosition(0 ,80);
 
    tab = new TabbedComponent(TabbedButtonBar::Orientation::TabsAtTop);
    addAndMakeVisible(tab);
    tab->setTopLeftPosition(5,90);
    tab->addTab("Browser",Colours::lightgrey, browser, true);
    tab->addTab("Database",Colours::lightgrey, dbbrowser, true);
    //addAndMakeVisible(browser);
    resized();
}

MainComponent::~MainComponent()
{
    removeTimeSliceClient(this);
    removeTimeSliceClient(playerPanel);
    delete filter;
    delete directoryContents;
    browser->removeAllChangeListeners();
    delete browser;
    delete dbbrowser;
    delete playerPanel;
    delete timeSlider;
    delete tab;
    AudioManager::getInstance()->destroy();
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    // This function will be called when the audio device is started, or when
    // its settings (i.e. sample rate, block size, etc) are changed.

    // You can use this function to initialise any resources you might need,
    // but be careful - it will be called on the audio thread, not the GUI thread.

    // For more details, see the help for AudioProcessor::prepareToPlay()
}

void MainComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
    // Your audio-processing code goes here!

    // For more details, see the help for AudioProcessor::getNextAudioBlock()

    // Right now we are not producing any data, in which case we need to clear the buffer
    // (to prevent the output of random noise)
    bufferToFill.clearActiveBufferRegion();
    
    if (browser != nullptr && browser->getSampler() != nullptr) {
        
        if (browser->getSampler()->isPlaying() && !browser->getSampler()->isDone()) {
        
            for (int i = 0; i < bufferToFill.numSamples;i++) {
                
                browser->getSampler()->nextSample();
                
                float left = browser->getSampler()->getCurrentSample(0);
                float right = browser->getSampler()->getCurrentSample(1);
                
                bufferToFill.buffer->addSample(0, i, left);
                bufferToFill.buffer->addSample(1, i, right);
                
            }
        }
    }
    
    if (dbbrowser != nullptr && dbbrowser->getSampler() != nullptr) {
        
        if (dbbrowser->getSampler()->isPlaying() && !dbbrowser->getSampler()->isDone()) {
            
            for (int i = 0; i < bufferToFill.numSamples;i++) {
                
                dbbrowser->getSampler()->nextSample();
                
                float left = dbbrowser->getSampler()->getCurrentSample(0);
                float right = dbbrowser->getSampler()->getCurrentSample(1);
                
                bufferToFill.buffer->addSample(0, i, left);
                bufferToFill.buffer->addSample(1, i, right);
                
            }
        }
    }
    
}

void MainComponent::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    // For more details, see the help for AudioProcessor::releaseResources()
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (Colours::grey);

    // You can add your drawing code here!
}

void MainComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    if (tab != nullptr) {
        tab->setSize(getWidth() - 10, getHeight() - playerPanel->getHeight() - 20);
        tab->repaint();
        tab->resized();
        if (browser != nullptr) {
            browser->setSize(tab->getWidth() - 150, tab->getHeight());
            browser->repaint();
            browser->resized();
        }
        
    }
    

    if (playerPanel != nullptr) {
        playerPanel->setTopLeftPosition((getWidth() / 2) - (playerPanel->getWidth()) / 2,0);
    }
    
    if (timeSlider != nullptr) {
        timeSlider->setSize(getWidth(), 10);
    }
    
    repaint();
}

int MainComponent::useTimeSlice() {
    return 1000;
}

void MainComponent::changeListenerCallback(ChangeBroadcaster *source) {
    timeSlider->setRange(0, browser->getSampler()->getSampleLength());
}

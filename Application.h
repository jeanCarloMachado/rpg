#ifndef SYSApplication
#define SYSApplication

/**
 * main requirements
 */
#include <OgreException.h>

/**
 * basic application requirements
 */
#include <OgreRoot.h>
#include <OISEvents.h>
#include <OISInputManager.h>
#include <OISKeyboard.h>
#include <OISMouse.h>
#include <OgreWindowEventUtilities.h>

#include "Application/Modules/Main/ModelPlayer.h"

#include "Semaphore.h"

#define MAIN_WINDOW_NAME "RPG - Diabo!"

using namespace std;

class Application : public Ogre::WindowEventListener
{
public:
    Application(void);
    ~Application(void);
    bool run();
    bool bootstrap();

    // Ogre::WindowEventListener
    virtual void windowResized(Ogre::RenderWindow* rw);
    virtual void windowClosed(Ogre::RenderWindow* rw);

    Semaphore* getSemaphore()
    {
        return this->semaphore;
    }
    
    Application* setSemaphore(Semaphore* semaphore)
    {
        this->semaphore = semaphore;
        return this;
    }
        
  
public:
    Ogre::Root* root;
    Ogre::String resourcesCfg;
    Ogre::String pluginsCfg;
    Ogre::RenderWindow* window;

    // OIS Input devices
    OIS::InputManager* mInputManager;
    OIS::Mouse*    mouse;
    OIS::Keyboard* keyboard;

    ModelPlayer* player;
private:
    string defaultController;
    Semaphore* semaphore;
 
};


#endif

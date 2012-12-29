#ifndef __SYSControllerAbstract__
#define __SYSControllerAbstract__

#include "Application.h"
#include <OgreCamera.h>
#include <OgreLogManager.h>
#include <OgreRoot.h>
#include <OgreViewport.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>
#include <OgreConfigFile.h>

#include <OISEvents.h>
#include <OISInputManager.h>
#include <OISKeyboard.h>
#include <OISMouse.h>

#include <SdkTrays.h>
#include <SdkCameraMan.h>

#define DEFAULT_NEAR_CLIP_DISTANCE 5
#define DEFAULT_FAR_CLIP_DISTANCE 5000

using namespace Ogre;

class ControllerAbstract :  public Ogre::FrameListener
{
public:
	ControllerAbstract(Application *app);

	void _init();
	virtual void init();

	virtual ControllerAbstract* indexAction();
    	virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);

public:
	Application *app;
	Ogre::SceneManager* sceneMgr;
	Ogre::Camera* camera;
	Ogre::SceneNode *camNode;
	Ogre::Viewport* vp;

	Ogre::Real timeSinceLastFrame;

	
	bool shutdown = false;
};

#endif
#include "InputMgr.h"
#include "System/Object/Util.h"


#include <OgreRoot.h>

InputMgr* InputMgr::getInstance()
{
	static InputMgr* inputMgr = new InputMgr();


	return inputMgr;
}

InputMgr::InputMgr()
{
}

// OIS::KeyListener
bool InputMgr::keyPressed( const OIS::KeyEvent& evt )
{
	switch(evt.key)
	{
		case OIS::KC_ESCAPE:
			controllerPtr->shutdown = true;
			break;
		/**
		 * movement keys
		 */
		case OIS::KC_W:

			controllerPtr->app->player->moveForward();
			break;
		case OIS::KC_S:
			controllerPtr->app->player->moveBackward();
			break;
		case OIS::KC_A:
			controllerPtr->app->player->moveLeftSide();
			break;
		case OIS::KC_D:
			controllerPtr->app->player->moveRightSide();
			break;
		/**
		 * end of movement keys
		 */
	}
	return true;
}

bool InputMgr::keyReleased( const OIS::KeyEvent& evt )
{	
	this->controllerPtr->app->player->stopMovement();
	return true;
}

// OIS::MouseListener
bool InputMgr::mouseMoved( const OIS::MouseEvent& evt )
{
	this->controllerPtr->camNode->yaw(Ogre::Degree(-this->controllerPtr->app->player->getRotateSpeed() * evt.state.X.rel), Ogre::Node::TS_WORLD);
    	this->controllerPtr->camNode->getChild("CamNode")->pitch(Ogre::Degree(-this->controllerPtr->app->player->getRotateSpeed() * evt.state.Y.rel), Ogre::Node::TS_LOCAL);
	return true;
}

bool InputMgr::mousePressed( const OIS::MouseEvent& evt, OIS::MouseButtonID id )
{
	return true;
}

bool InputMgr::mouseReleased( const OIS::MouseEvent& evt, OIS::MouseButtonID id )
{
	return true;
}

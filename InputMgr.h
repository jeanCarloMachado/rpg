#ifndef SYSInputMgr
#define SYSInputMgr


#include <OgreRoot.h>

#include <OISEvents.h>
#include <OISInputManager.h>
#include <OISKeyboard.h>
#include <OISMouse.h>


#include <SdkTrays.h>
#include <SdkCameraMan.h>

#include "Semaphore.h"
#include "ControllerAbstract.h"

#include <string>


using namespace std;

	
class InputMgr :  public OIS::KeyListener, public OIS::MouseListener, OgreBites::SdkTrayListener
{
public:
	//virtual ~InputMgr(void);
	static InputMgr* getInstance();
	
	// OIS::KeyListener
	bool keyPressed( const OIS::KeyEvent& evt );
	bool keyReleased( const OIS::KeyEvent& evt );
	// OIS::MouseListener
	bool mouseMoved( const OIS::MouseEvent& evt );
	bool mousePressed( const OIS::MouseEvent& evt, OIS::MouseButtonID id );
	bool mouseReleased( const OIS::MouseEvent& evt, OIS::MouseButtonID id );


	Semaphore* getSemaphore()
	{
		return this->semaphore;
	}
	
	InputMgr* setSemaphore(Semaphore* semaphore)
	{
		this->semaphore = semaphore;
		return this;
	}
	
	ControllerAbstract* getControllerPtr()
	{
		return this->controllerPtr;
	}
	
	InputMgr* setControllerPtr(ControllerAbstract* controllerPtr)
	{
		this->controllerPtr = controllerPtr;
		return this;
	}

private:
	InputMgr();

	/**
	 * requisitos da classe
	 */
	Semaphore* semaphore;
	ControllerAbstract* controllerPtr;
};

#endif

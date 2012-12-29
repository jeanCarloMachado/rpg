#include "ControllerAbstract.h"
#include "InputMgr.h"

#include "System/Object/Util.h"
ControllerAbstract::ControllerAbstract(Application *app) : 
camera(0),
sceneMgr(0)
{
        this->app = app;
        app->root->addFrameListener(this);
          //Set initial mouse clipping size
        this->app->windowResized(this->app->window);
        this->_init();
}

/**
 * inicialização básica do sistema
 */
void ControllerAbstract::_init()
{
    // initialise all resource groups
    Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

    Ogre::LogManager::getSingletonPtr()->logMessage("*** Init of default controller***");

    // Create the SceneManager, in this case a generic one
    sceneMgr = app->root->createSceneManager("DefaultSceneManager");

    // Create the camera
    camera = sceneMgr->createCamera("PlayerCam");
    camera->setNearClipDistance(DEFAULT_NEAR_CLIP_DISTANCE);
    camera->setFarClipDistance(DEFAULT_FAR_CLIP_DISTANCE);

    // Create one viewport, entire window
    vp = this->app->window->addViewport(camera);

     /**
     * seta a cor de fundo do viewport
     */
    vp->setBackgroundColour(Ogre::ColourValue(0,0,0));

    this->camNode = this->sceneMgr->getRootSceneNode()->createChildSceneNode("3rdPersonNode",Ogre::Vector3(0,0,0));
    //this->camNode->roll( Degree(-90) );
    //this->camNode->yaw(Ogre::Degree(180));
    Ogre::SceneNode* childCamNode;
    childCamNode = this->camNode->createChildSceneNode("CamNode");
    childCamNode->attachObject(this->camera);

   /**
     * seta cordenadas default para a camera
     */
    camera->setPosition(Ogre::Vector3(0,100,150));
    /**
     * olha para  a origem
     */
    camera->lookAt(Ogre::Vector3(0,0,-400));
 
    // Alter the camera aspect ratio to match the viewport
    camera->setAspectRatio(
    Ogre::Real(vp->getActualWidth()) / Ogre::Real(vp->getActualHeight()));

    Ogre::SceneNode* childSceneNode;
    childSceneNode = this->camNode->createChildSceneNode("RobotNode",Ogre::Vector3(0,0,0));
    childSceneNode->attachObject(this->app->player->getEntityPtr(this->sceneMgr));
    childSceneNode->yaw(Ogre::Degree(90));

    this->init();
}


void ControllerAbstract::init()
{
}


ControllerAbstract* ControllerAbstract::indexAction()
{
	using namespace std;

	cout << "index action base";

	ControllerAbstract *controller = NULL;
	return controller;
}

bool ControllerAbstract::frameRenderingQueued(const Ogre::FrameEvent& evt)
{
    
    if(this->app->window->isClosed() || this->shutdown)
        return false;
 
    //Need to capture/update each device
    this->app->keyboard->capture();
    this->app->mouse->capture();


    //this->timeSinceLastFrame = (evt.timeSinceLastFrame);

    /**
     * aponta o nodo da camera para onde o player se moveu
     */
    this->camNode->translate(this->app->player->getDirection() * evt.timeSinceLastFrame, Ogre::Node::TS_LOCAL);


    this->app->player->animationWalkingSyncer(evt.timeSinceLastFrame);
    
    return true;
}
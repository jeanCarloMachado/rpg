#include "ControllerMain.h"

#include "Application/Modules/Main/ModelGround.h"

using namespace std;

ControllerMain::ControllerMain(Application *app) : ControllerAbstract(app)
{
}

ControllerAbstract* ControllerMain::indexAction()
{

    /**
     * cria o solo
     */
    Main::ModelGround modelGround;
    modelGround.createSimpleStoneGround(this);

    // Set ambient light
    sceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));
    Ogre::Light* l = sceneMgr->createLight("MainLight");
    l->setPosition(20,1000,50);

    
     app->root->startRendering();
   
    ControllerAbstract *controller = NULL;
     return controller;
}

void ControllerMain::init( )
{
}

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

/**
 * seta o inimigo 1
 */
    Ogre::Entity* enemy1;
    Ogre::SceneNode *enemy1SN;
    enemy1 = this->sceneMgr->createEntity("Enemy1","dragon.mesh");
    enemy1SN = this->sceneMgr->getRootSceneNode()->createChildSceneNode("Enemy1SN",Ogre::Vector3(20.0f,200.0f,25.0f));
    enemy1SN->attachObject(enemy1);
    enemy1SN->setScale(5.5f, 5.5f, 5.5f);
    
    /**
 * seta o inimigo 2
 */
    Ogre::Entity* enemy2;
    Ogre::SceneNode *enemy2SN;
    enemy2 = this->sceneMgr->createEntity("Enemy2","robot.mesh");
    enemy2SN = this->sceneMgr->getRootSceneNode()->createChildSceneNode("enemy2SN",Ogre::Vector3(-20.0f,0.0f,25.0f));
    enemy2SN->attachObject(enemy2);

 
    /**
 * seta o inimigo 3
 */
    Ogre::Entity* enemy3;
    Ogre::SceneNode *enemy3SN;
    enemy3 = this->sceneMgr->createEntity("enemy3","geosphere8000.mesh");
    enemy3SN = this->sceneMgr->getRootSceneNode()->createChildSceneNode("enemy3SN",Ogre::Vector3(-250.0f,50.0f,50.0f));
    enemy3SN->attachObject(enemy3);



     app->root->startRendering();
   
    ControllerAbstract *controller = NULL;
     return controller;
}

void ControllerMain::init( )
{
}

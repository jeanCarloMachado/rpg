#include "Application/Modules/Main/ModelGround.h"

void Main::ModelGround::createSimpleStoneGround(ControllerAbstract *controller)
{
        Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);

        Ogre::MeshManager::getSingleton().createPlane("ground", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
        plane, 1500, 1500, 20, 20, true, 1, 5, 5, Ogre::Vector3::UNIT_Z);

        Ogre::Entity* entGround = controller->sceneMgr->createEntity("GroundEntity", "ground");
        controller->sceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(entGround);

        entGround->setMaterialName("Examples/Rockwall");
        entGround->setCastShadows(false);
}
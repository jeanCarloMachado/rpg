#include "Application/Modules/Main/ModelPlayer.h"

ModelPlayer::ModelPlayer(void) 
{
}

void ModelPlayer::moveForward()
{
	this->direction.z = -this->moveSpeed;
	this->getAnimationWalking()->setEnabled(true);  

	
}

void ModelPlayer::stopMovement()
{
	this->direction = Ogre::Vector3::ZERO;
	animationWalking->setEnabled(false);  
}	

void ModelPlayer::moveBackward()
{
	this->direction.z = this->moveSpeed;
	this->getAnimationWalking()->setEnabled(true);  
}
void ModelPlayer::moveRightSide()
{
	this->direction.x = this->moveSpeed;
	this->getAnimationWalking()->setEnabled(true);  
	

}
void ModelPlayer::moveLeftSide()
{
	this->direction.x = -this->moveSpeed;
	this->getAnimationWalking()->setEnabled(true);  
}

Ogre::Entity* ModelPlayer::getEntityPtr(Ogre::SceneManager* sceneManager)
{
	/**
	 * se a entidade ainda não foi criada a cria
	 */
	if(this->entity == NULL) {
		this->entity = sceneManager->createEntity(this->meshName, this->meshFile);
	}


	return this->entity;
}

Ogre::Entity* ModelPlayer::getEntityPtr()
{
	/**
	 * se a entidade ainda não foi criada a cria
	 */
	if(this->entity == NULL) {
		std::string error = "entidade não setada e sem parametro *sceneManager";
		throw error;
	}

	return this->entity;
}

void ModelPlayer::setEntityPtr(Ogre::Entity* entity)
{
	this->entity = entity;
}
	
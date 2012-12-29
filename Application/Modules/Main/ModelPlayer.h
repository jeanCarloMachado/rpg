
#ifndef SYSModelPlayer
#define SYSModelPlayer

using namespace std;

#include <OgreRoot.h>
#include <OgreEntity.h>
#include <OgreSceneManager.h>

#include <string>
	
class ModelPlayer 
{
public:
	ModelPlayer(void);
	//virtual ~ModelPlayer(void);
	void moveForward();
	void moveBackward();
	void moveRightSide();
	void moveLeftSide();
	void stopMovement();

	Ogre::Entity* getEntityPtr(Ogre::SceneManager* sceneManager);
	Ogre::Entity* getEntityPtr();
	void setEntityPtr(Ogre::Entity* entity);


	Ogre::Vector3 getDirection()
	{
		return this->direction;
	}
	
	void setDirection(Ogre::Vector3 direction)
	{
		this->direction = direction;
	}
	

	Ogre::Real getRotateSpeed()
	{
		return this->rotateSpeed;
	}
	
	void setRotateSpeed(Ogre::Real rotateSpeed)
	{
		this->rotateSpeed = rotateSpeed;
	}

	Ogre::AnimationState* getAnimationWalking()
	{
		if(animationWalking == NULL) {
			this->animationWalking  = this->getEntityPtr()->getAnimationState("Walk");
			this->animationWalking->setLoop(true);  


		}

		return this->animationWalking;
	}
	
	void setAnimationWalking(Ogre::AnimationState* animationWalking)
	{
		this->animationWalking = animationWalking;
	}

	/**
	 * sincroniza o caminhar com os frames
	 * @param syncTime [description]
	 */
	void animationWalkingSyncer(Ogre::Real syncTime)
	{	
		Ogre::AnimationState* animation; 
		animation = this->getAnimationWalking();
		
		if(animation->getEnabled()) {
			animation->addTime(syncTime);
		}
	}	
		
protected:

private:
	Ogre::Entity* entity = NULL;
	std::string meshFile = "robot.mesh";
	std::string meshName = "Robot";

	Ogre::Real rotateSpeed  = 0.13; //rotate constant
	Ogre::Real moveSpeed = 100; //the movement constant
	Ogre::Vector3 direction = Ogre::Vector3::ZERO; //value to move in the correct direction


	/**
	 * entity animations
	 */
	Ogre::AnimationState *animationWalking = NULL;
	Ogre::AnimationState *animationIdle = NULL;
	
};	

#endif

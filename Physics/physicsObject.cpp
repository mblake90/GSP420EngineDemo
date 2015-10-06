#include "physicsObject.h"


physicsObject::physicsObject() 
{ 
	 
	body      = NULL; 
    userData  = NULL; 
	for (int indexLoop = 0; indexLoop < 16; indexLoop++) {
		shape[indexLoop] = -1.0f;
	}
}


physicsObject::~physicsObject()
{
}


// turn on the object to react in phyiscs world
int physicsObject::activate()
{
	return 0;
}


// turn off the physics object but not remove it. It will not react to physics or collisions
int physicsObject::deactivate()
{
	return 0;
}


// remove this object from the game manager. This is  stub method that will call the gameManagers remove method
int physicsObject::remove()
{
	return 0;
}

//applies force from the center of an object
int physicsObject::applyForceFromCenter(float32 x, float32 y)
{
	b2Vec2 theforce(x, y); 
	body->ApplyForce(theforce, body->GetWorldCenter(), true);
	return 0;
}

//applies force from the center of an object
int physicsObject::applyImpulseFromCenter(float32 x, float32 y)
{
	b2Vec2 theforce(x, y);
	body->ApplyLinearImpulse(theforce, body->GetWorldCenter(), true);
	return 0;
}

//applies force from the center of an object
int physicsObject::applyTorqueFromCenter(float32 x, float32 y)
{
	b2Vec2 theforce(x, y);
	body->ApplyForce(theforce, body->GetWorldCenter(), true);
	return 0;
}


int physicsObject::setLinkedObject(void* linkedObject)
{
	userData = linkedObject;
	return 0;
}

int physicsObject::setBounceAmount(float32 ba)
{
	bounceAmount = ba; // track locally for convenience.
	body->GetFixtureList()->SetDensity(ba);
	body->ResetMassData();
	return 0;
}
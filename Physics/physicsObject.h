#pragma once

#include <string>
#include "Box2D/Box2D.h"



class physicsObject
{
public:
	
	b2Body* body;
	std::string objectName;
	float32 shape[16];
	float32 angle;
	float32 angularVelocityX; 
	float32 angularVelocityY; 
	float32 linearVelocityX;
	float32 linearVelocityY;
	float  bounceAmount; 
	float  friction; 
	bool   isActive;
	bool   isColliding; 
	bool   isDynamic;
	int    x; 
	int    y; 
	int    halfHeight; 
	int    halfWidth; 
	std::string shapeList; 
	void* userData; 
	
	physicsObject();
	~physicsObject();
	// turn on the object to react in phyiscs world
	int activate();
	// turn off the physics object but not remove it. It will not react to physics or collisions
	int deactivate();
	// remove this object from the game manager. This is  stub method that will call the gameManagers remove method
	int remove();
	int applyForceFromCenter(float32 x, float32 y);
	int applyImpulseFromCenter(float32 x, float32 y);
	int applyTorqueFromCenter(float32 x, float32 y);
	int setLinkedObject(void* linkedObject);
	int setBounceAmount(float32 ba);
	// int addForceAtPos(std::string name, int x, int y);
	// int addConstentForce(std::string name, int x, int y);
	// int addTorque(std::string name, int x, int y);
};


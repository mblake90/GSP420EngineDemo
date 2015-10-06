#pragma once 
#pragma comment(lib, "Box2d")
#include <iostream>
#include <vector> 
#include "gameObjectManager.h"
#include "Box2D/Box2D.h"
const float M2P = 8.00;
const float P2M = 1 / M2P;

class CollissionCallBackListener : public b2ContactListener
{

 public: 
	void* listenerParent;
	void CollissionCallBackListener::BeginContact(b2Contact* contact);
	void EndContact(b2Contact* contact);
	void setParent(void* theParent);

};

class physics 
{
public:
	
	b2Vec2 gravity; 
    b2World* world;
	CollissionCallBackListener collissionCallBackListener; 
	b2BodyDef groundBodyDef;
	b2PolygonShape groundBox;
	
	
	float32 timeStep = 1.0f / 240.0f;
	int32 velocityIterations = 10;
	int32 positionIterations = 6;
	physics();
	~physics();
	gameObjectManager* GameObjectManager; 

	// 
	//int onStartCollission(void* object1, void* object2);
	//int onEndCollission(void* object1, void* object2);
	// clean up and get rid of any traces of our world phyiscs world
	int endWorld();
	// create and Instance of the physics world 
	int startWorld();
	// update the simulation by calling this in the main loop.
	int updateWorld();
};







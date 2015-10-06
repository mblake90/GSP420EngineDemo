#include "physics.h"
#include "physicsObject.h"

physics::physics()
{
	
    gravity = b2Vec2(0.0f, 9.8f); // need to expose gravtiy in constuctor.
	world = new b2World(gravity);


	GameObjectManager = new gameObjectManager();
}


physics::~physics()
{ 
	delete GameObjectManager; 
	
}

/*
// registers local method to handle collissions. 
int physics::collissionCallBack(void* callBackMethod)
{
	return NULL;
}
*/

// clean up and get rid of any traces of our world phyiscs world
int physics::endWorld()
{
	return 0;
}


// create and Instance of the physics world 
int physics::startWorld()
{
	
	world->SetContactListener(&collissionCallBackListener);

	/*  Example code from hello world */

	// Define the ground body.
	
	groundBodyDef.position.Set(P2M*5.0f, P2M*400.0f);

	// Call the body factory which allocates memory for the ground body
	// from a pool and creates the ground box shape (also from a pool).
	// The body is also added to the world.
	b2Body* groundBody = world->CreateBody(&groundBodyDef);

	// Define the ground box shape.

	// The extents are the half-widths of the box.
	groundBox.SetAsBox(P2M*800.0f, P2M*10.0f);
		// Add the ground fixture to the ground body.
	groundBody->CreateFixture(&groundBox, 0.0f);

	return 0;
}


// update the simulation by calling this in the main loop.
int physics::updateWorld()
{

	world->Step(timeStep, velocityIterations, positionIterations);

	// Lets Loop through and create all our objects.
	std::map<std::string, physicsObject*>::iterator gameObject;

	for (gameObject = GameObjectManager->gameManangerMap.begin(); gameObject != GameObjectManager->gameManangerMap.end(); gameObject++)
	{

		
		if (gameObject->second->body == NULL) // Has the object been created yet ? If not create it. 

		{

			// Define the dynamic body. We set its position and call the body factory.

			b2BodyDef bodyDef;

			if (gameObject->second->isDynamic)  {
				bodyDef.type = b2_dynamicBody;
			}

			bodyDef.position.Set(P2M*gameObject->second->x, P2M*gameObject->second->y);

			b2Body* body = world->CreateBody(&bodyDef);

			//b2CircleShape circleShape;
			//circleShape.m_p.Set(0, 0); //position, relative to body position
			//circleShape.m_radius = 1; //radius

			// Define another box shape for our dynamic body.
			b2PolygonShape dynamicBox;
		
			
			if (gameObject->second->shapeList == "Box") {
				dynamicBox.SetAsBox(P2M*gameObject->second->halfHeight, P2M*gameObject->second->halfWidth);
			}
			else // we can assume polygon for now unless we add circles later.
			{ 
				// Build the vertices from the float32 array there should be max 8 pairs and should be even number.

			}

			b2FixtureDef fixtureDef;
			fixtureDef.shape = &dynamicBox;

			// Set the box density to be non-zero, so it will be dynamic.
			fixtureDef.density = 1.0f;

			fixtureDef.restitution = 0.949875f;

			// Override the default friction.
			fixtureDef.friction = 0.9800f;

			// Add the shape to the body.
			body->CreateFixture(&fixtureDef);

			gameObject->second->body = body;



		}
		else  // need to update the objects information..
		{

			//*** To do ****
			//Need to check if object was added or removed after the world was created
			//and do create or remove it.

			b2Vec2 position = gameObject->second->body->GetPosition();
			gameObject->second->x = position.x*M2P;
			gameObject->second->y = position.y*M2P;
			float32 theAngle = gameObject->second->body->GetAngle();
			gameObject->second->angle = theAngle;

		}

		
	}




	return 0;
}


void CollissionCallBackListener::BeginContact(b2Contact* contact)
{
	b2Fixture* fixtureA = contact->GetFixtureA();
	b2Fixture* fixtureB = contact->GetFixtureB();
	b2Body* body1 = fixtureA->GetBody();
	b2Body* body2 = fixtureB->GetBody();
	physicsObject* poA = (physicsObject*)body1->GetUserData();
	physicsObject* poB = (physicsObject*)body2->GetUserData();




}

void CollissionCallBackListener::EndContact(b2Contact* contact)
{
	std::cout << "Collission ended" << std::endl;
}

void CollissionCallBackListener::setParent(void* theParent) {
	listenerParent = theParent;
}

//Game class created by Darrell Smith and edited by Brent Spector

#pragma once


#include <Windows.h>
//include parent class
#include "App.h"


//include state information
#include "GameState.h"


#include "AsteroidManager.h"
#include "EnemyManager.h"
#include "PickupManager.h"
#include "Player.h"
#include "ProjectileManager.h"

#include <list>
//include other cores
/***** Will add these back in once the files are available
#include "AI.h"
#include "Audio.h"
#include "Physics.h"
#include "UI.h"
*******/

#define GAMECLASS Game::Instance()
#define ASTEROIDS Game::Instance()->asteroids
#define ENEMIES Game::Instance()->enemies
#define PICKUPS Game::Instance()->pickups
#define PROJECTILES Game::Instance()->projectiles
#define PLAYER Game::Instance()->player

//this inherits from the base class App and adds things that are specific to this game or demo
class Game : public App
{
	friend class InitState;
	friend class MenuState;
	friend class CreditsState;
	friend class PlayState;
	friend class ExitState;
public:
	void Run();
	static Game* Instance();
	inline bool GetPaused() { return paused; }
	void Delete();
	//managers
	AsteroidManager asteroids;
	EnemyManager enemies;
	PickupManager pickups;
	ProjectileManager projectiles;
	Player player;
	inline GAMESTATE getState() { return currentState; }
protected:
	//the one instance of the object
	static Game* Singleton;
	//constructor can't be called by nonmember functions
	Game() : App(), paused(false) {}
	inline GameState* getGameState() { return States; }
	void changeState(GAMESTATE newstate);
private:
	//toggle the game being paused
	inline void togglePause() { paused = !paused; }
	//framework methods from the App class
	void init();//used upon game startup
	void onLostDevice();//used when screen changes size or other event causes device to be lost
	void onResetDevice();//used after onLostDevice to reaquire needed elements
	void update(const float);//update the scene every frame, anything that is not rendering goes here
	void render();//render all the visual elements of the game
	void shutdown();//used upon game exit
	//the present state of the game
	GameState		States[NUM_STATES];
	GAMESTATE		currentState;
	/*****
	GameState States[NUM_STATES];
	AI gameAI;
	Physics gamePhysics;
	UI gameUI;
	Audio gameAudio;
	*****/
	//is game play paused
	bool paused;
};


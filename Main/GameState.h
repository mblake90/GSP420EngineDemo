//GameState classes created by Darrell Smith and edited by Brent Spector
#pragma once


enum GAMESTATE { STATE_INIT, STATE_MENU, STATE_CREDIT, STATE_PLAY, STATE_EXIT };
const static int NUM_STATES = 5;

class GameState
{
	//only the game class can use the states
	friend class Game;
public:
	GameState() {}
	~GameState() {}
protected:
	virtual void init() {}
	virtual void update(const float) {}
	virtual void render() {}
	virtual void onLostDevice() {}
	virtual void onResetDevice() {}
	virtual void shutdown() {}
};

class InitState : public GameState
{
public:
	InitState() {}
	~InitState() {}
private:
	void init();
	void shutdown();
};

class MenuState : public GameState
{
public:
	MenuState() {}
	~MenuState() {}
private:
	void init();
	void update(const float);
	void render();
	void onLostDevice();
	void onResetDevice();
	void shutdown();
};

class CreditsState : public GameState
{
public:
	CreditsState() {}
	~CreditsState() {}
private:
	void init();
	void update(const float);
	void render();
	void onLostDevice();
	void onResetDevice();
	void shutdown();
};

class PlayState : public GameState
{
public:
	PlayState() {}
	~PlayState() {}
private:
	void init();
	void update(const float);
	void render();
	void onLostDevice();
	void onResetDevice();
	void shutdown();
};

class ExitState : public GameState
{
public:
	ExitState() {}
	~ExitState() {}
private:
	void init();
};


//Player class created by Darrell Smith and edited by Brent Spector

#pragma once

#include "ABC.h"


//keeping the score amounts in one place to make them easier to alter
const static int ENEMY_1_SCORE = 15;
const static int ENEMY_2_SCORE = 25;
const static int ENEMY_3_SCORE = 50;
const static int ENEMY_BOSS_SCORE = 250;
const static int ASTEROID_SMALL_SCORE = 20;
const static int ASTEROID_LARGE_SCORE = 20;
const static float BULLET_COOL_DOWN = .5f;
const static D3DXVECTOR3 BULLET_START_DIRECTION = D3DXVECTOR3(0.f, -1.f, 0.f);
const static float MISSILE_COOL_DOWN = 1.f;
const static float PLAYER_SPEED = 30.f;


const static float HURT_INVULNERABILITY = 1.f;//how long player is invulnerable after being harmed

class Player : public GSP420::ABC
{
public:
	Player() : ABC(), missileAmmo(0), maxHealth(25), invulnerable(0.f), score(0), 
		lastBullet(0.f), lastMissile(0.f)
		{ nHealth = 25; }
	void fireBullet();
	void fireMissile();
	void heal(int);
	void hurt(int);
	void move(D3DXVECTOR3);
	void endGame();
	void update(const float);
	void shutdown();

	inline int getMissileAmmo() { return missileAmmo; }
	inline int getMaxHealth() { return maxHealth; }
	inline void giveScore(int s) { score += s; }
	void makeInvulnerable(float secs);
	inline void giveMissileAmmo(int ammo) { missileAmmo += ammo; }
	inline int getScore() { return score; }
private:
	int missileAmmo;
	int maxHealth;
	float invulnerable;//seconds of invulnerability left
	float lastBullet;//if <= 0, player can fire a bullet
	float lastMissile;//if <=0, player can fire a missile
	int score;
};

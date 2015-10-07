//Projectile Manager, Bullet, and Missile classes created by Darrell Smith and Brent Spector
#include "ProjectileManager.h"

#include "Game.h"

void ProjectileManager::update(const float dt)
{
	std::list<Bullet>::iterator it1 = Bullets.begin();
	while (it1 != Bullets.end())
	{
		if (!it1->isEnabled())
			it1 = Bullets.erase(it1);
		else
			++it1;
	}
	std::list<Missile>::iterator it2 = Missiles.begin();
	while (it2 != Missiles.end())
	{
		if (!it2->isEnabled())
			it2 = Missiles.erase(it2);
		else
			++it2;
	}
}

void ProjectileManager::removeTarget(Enemy* targ)
{
	for (std::list<Missile>::iterator it = Missiles.begin(), end = Missiles.end();
	it != end; ++it)
	{
		//if it is a player missile and has a matching target, set the target to NULL instead
		if (it->getEnemyTarget() == targ)
		{
			it->setEnemyTarget(NULL);
		}
	}
}


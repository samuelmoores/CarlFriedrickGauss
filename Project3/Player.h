#pragma once
#include <iostream>
#include "Enemy.h"


struct Pickups {
	enum  Health { FULL_HEALTH, HALF_HEALTH, QUARTER_HEALTH };
	enum  AMMO { GLOCK_AMMO, COLT45_AMMO, DESERT_EAGLE_AMMO, RAGING_BULL_AMMO };
	enum  ARMOR { LITE, MEDIUM, HEAVY };

};

struct Weapons {
	enum Sword { LONGSWORD, DAGGER, LEGOLAS_SWORDS, EXCALIBUR };
	enum Pistol { GLOCK, COLT45, DESERT_EAGLE, RAGING_BULL };
	enum Grenade { FRAG_GRENADE, FLASHBANG, SMOKE, MALOTOV };


};

struct Attacks {

	enum Pistol { SINGLE_SHOT, MULTIPLE_SHOT, PISTOL_WHIP, THROW_PISTOL };
	enum Sword { QUICK, STRONG, COMBO };
	enum Grenade { THROW, COOK, SMACK_WITH_GRENADE };

};

class Enemy;

class Player {
public:
	int rank = 0;
	std::string RankType[4] = { "You're not too bad", "Getting Better", "Wow, look out!", "You need to touch grass" };
	std::string name = "";
	float health = 100.0f;
	float stamina = 50.0f;
	int initiative = 15;
	int weaponChoice = 0;
	Pickups pickup;
	Weapons weapon;
	Attacks attacks;
	std::string CurrentRank = RankType[2];


public:
	void SetDifficulty(Player& player1);
	void PlayerSetup(Player& player1);
	void Battle();
	void AttackEnemy(Enemy &enemy); 
};
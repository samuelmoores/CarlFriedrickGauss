#pragma once
#include "Player.h"
#include <string>
#include <iostream>

#include <random>


struct EWeapons {
	enum Sword { LONGSWORD, DAGGER, LEGOLAS_SWORDS, EXCALIBUR };
	enum Pistol { GLOCK, COLT45, DESERT_EAGLE, RAGING_BULL };
	enum Grenade { FRAG_GRENADE, FLASHBANG, SMOKE, MALOTOV };


};

struct EAttacks {

	enum Pistol { SINGLE_SHOT, MULTIPLE_SHOT, PISTOL_WHIP, THROW_PISTOL };
	enum Sword { QUICK, STRONG, COMBO };
	enum Grenade { THROW, COOK, SMACK_WITH_GRENADE };

};


class Player;

class Enemy  {
public:
	std::string name = "";
	float health = 100.0f;
	float stamina = 50.0f;
	EAttacks attacks;
	EWeapons weapon;
	int initiative = 10;

	bool isArmed = true;
public:
	void ArmEnemy(Enemy &enemy1);
	void Battle();
	void AttackPlayer(Player &player);
};
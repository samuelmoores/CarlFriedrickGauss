#pragma once
#include <iostream>
#include "Weapon.h"
#include <random>




struct Pickups {
	enum  Health { FULL_HEALTH, HALF_HEALTH, QUARTER_HEALTH };
	enum  AMMO { GLOCK_AMMO, COLT45_AMMO, DESERT_EAGLE_AMMO, RAGING_BULL_AMMO };
	enum  ARMOR { LITE, MEDIUM, HEAVY };

};



class Player {
public:
	int rank = 0;
	std::string RankType[4] = { "You're not too bad", "Getting Better", "Wow, look out!", "You need to touch grass" };
	std::string name = "";
	float health = 100.0f;
	float stamina = 50.0f;
	int initiative = 15;
	int pistolChoice = 0;
	int swordChoice = 0;
	int grenadeChoice = 0;
	int accuracy{10};
	int defense{0};
	bool isArmed{ true };
	Pickups pickup;
	Weapons weapon;
	Attacks attacks;
	int scores[4] = { 0 , 0, 0, 0 };
	std::string CurrentRank = RankType[2];
	Weapon weapons;
	bool isAttacking = false;
	bool isDead = false;
	bool isBattle = false;


public:
	void SetDifficulty(Player& player1);
	void PlayerSetup(Player& player1);

	void AttackEnemy(Player &player, class Enemy &enemy); 
	void CheckAmmoType();
};



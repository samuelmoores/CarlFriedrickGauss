#pragma once
#include <iostream>

#include <random>




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



class Player {
public:
	int rank = 0;
	std::string RankType[4] = { "You're not too bad", "Getting Better", "Wow, look out!", "You need to touch grass" };
	std::string name = "";
	float health = 100.0f;
	float stamina = 50.0f;
	int initiative = 15;
	int weaponChoice = 0;
	int accuracy{10};
	int defense{0};
	bool isArmed{ true };
	Pickups pickup;
	Weapons weapon;
	Attacks attacks;
	int glockammo{0};
	int colt45ammo{ 0 };
	int DEammo{ 0 };
	int ragingammo{ 0 };
	int glockDamage[5] = { 50, 20, 15, 10, 5 };
	int scores[4] = { 0 , 0, 0, 0 };
	std::string CurrentRank = RankType[2];


public:
	void SetDifficulty(Player& player1);
	void PlayerSetup(Player& player1);
	void PistolSingleShot(Player& player);
	void PistolMultiShot(Player &player);
	void PistolThrow(Player &player);
	void PistolWhip(Player& player);
	void AttackEnemy(Player &player, const class Enemy &enemy); 
	void CheckAmmoType();
};



#pragma once


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

class Weapon {
public:
	int glockammo{ 0 };
	int colt45ammo{ 0 };
	int DEammo{ 0 };
	int ragingammo{ 0 };
	int glockDamage[5] = { 30, 20, 15, 10, 5 };
	int colt45Damage[5] = { 40, 30, 20, 15, 7 };
	int deDamage[5] = { 50, 35, 25, 20, 12 };
	int ragingDamage[5] = { 60, 40, 30, 25, 17 };
	int ExcaliburDamage[3] = { 45, 75, 30 };
	int LegolasDamage[3] = { 35, 65, 20 };
	int LongSwordDamage[3] = { 25, 55, 15 };
	int DaggerDamage[3] = { 20, 40, 10 };

	int FragDamage[3] = { 100, 50,  20 };
	int MolotovDamage[3] = { 45, 45, 45 };
	int smokeDamage[3] = { 10, 20, 10 };
	int flashDamage[3] = { 15, 30, 45 };

	void PistolSingleShot( class Player& player, class Enemy& enemy);
	void PistolMultiShot( class Player&  player, class Enemy& enemy);
	void PistolWhip( class Player& player, class Enemy& enemy);
	void PistolThrow( class Player& player, class Enemy& enemy);

	void SwordQuick(class Player& player, class Enemy& enemy);
	void SwordCombo(class Player& player, class Enemy& enemy);
	void SwordStrong(class Player& player, class Enemy& enemy);

	void GrenadeThrow(class Player& player, class Enemy& enemy);
	void GrenadeCook(class Player& player, class Enemy& enemy);
	void GrenadeSmack(class Player& player, class Enemy& enemy);
};
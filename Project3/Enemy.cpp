#include "Enemy.h"
#include "Player.h"

void Enemy::ArmEnemy(Enemy &enemy1)
{
	srand((unsigned)time(NULL));
	int enemyWeapon = rand() % 4 + 0;
	int enemyWeaponType = rand() % 4 + 0;
	switch (enemyWeapon)
	{
	case 0:
		switch (enemyWeaponType)
		{
		case 0:
			enemy1.weapon.Sword::DAGGER;
			std::cout << " dagger!\n";
			break;
		case 1:
			enemy1.weapon.Sword::LONGSWORD;
			std::cout << "longsword!\n";
			break;
		case 2:
			enemy1.weapon.Sword::LEGOLAS_SWORDS;
			std::cout << "legolas swords!\n";
			break;
		case 3:
			enemy1.weapon.Sword::EXCALIBUR;
			std::cout << "Excalibur!\n";
			break;
		}
		break;
	case 1:
		switch (enemyWeaponType) {
		case 0:
			std::cout << " glock!\n";
			enemy1.weapon.Pistol::GLOCK;
			break;
		case 1:
			enemy1.weapon.Pistol::COLT45;
			std::cout << "colt 45!\n";
			break;
		case 2:
			enemy1.weapon.Pistol::DESERT_EAGLE;
			std::cout << "Desert Eagle!\n";
			break;
		case 3:
			enemy1.weapon.Pistol::RAGING_BULL;
			std::cout << "Raging bull!\n";
			break;
		}
		break;
	case 2:
		switch (enemyWeaponType) {
		case 0:
			enemy1.weapon.Grenade::FRAG_GRENADE;
			std::cout << "frag grenade!\n";
			break;
		case 1:
			enemy1.weapon.Grenade::SMOKE;
			std::cout << "smoke grenade!\n";
			break;
		case 2:
			enemy1.weapon.Grenade::FLASHBANG;
			std::cout << "flashbang!\n";
			break;
		case 3:
			enemy1.weapon.Grenade::MALOTOV;
			std::cout << "molotov!\n";
			break;
		}
		break;
	}
}

void Enemy::Battle()
{
	std::cout << "Hooray";
}

void Enemy::AttackPlayer(const Player& player)
{
}

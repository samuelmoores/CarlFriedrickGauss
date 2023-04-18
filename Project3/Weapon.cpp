#include "Weapon.h"
#include "Player.h"
#include "Enemy.h"


auto const seed = std::random_device()();
std::mt19937 rng(seed);

void Weapon::PistolSingleShot(Player& player, Enemy& enemy)
{
	std::uniform_int_distribution<int> singleshot(0, 10);
	double chance = singleshot(rng) * .50 + player.accuracy;
	if (player.weapons.glockammo > 0) {
		if (chance > 12)
		{
			std::cout << "Hit " << enemy.name << "for " << player.weapons.glockDamage[1];
			enemy.health -= player.weapons.glockDamage[1];
		}
		player.weapons.glockammo -= 1;
		
	}
	else {
		std::cout << "Not enough ammo.";
	}
	std::cout << "Enemy: " << enemy.name << " has " << enemy.health << " health remaining.\n";
	player.isAttacking = false;
}

void Weapon::PistolMultiShot(Player& player, Enemy& enemy)
{
	std::uniform_int_distribution<int> ShotAttempts(2, 6);
	std::uniform_int_distribution<int> shotaccuracy(0, 10);
	int shots = ShotAttempts(rng);
	if (player.weapons.glockammo - shots >= 0)
	{
		for (int i = 0; i < shots; i++)
		{
			double chance = shotaccuracy(rng) * .20 + player.accuracy;
			if (chance > 10) {
				std::cout << "Hit for " << player.weapons.glockDamage[2] << '\n';
				player.weapons.glockammo--;
				enemy.health -= glockDamage[2];
			}
			else {
				std::cout << "Miss\n";
			}
		}
	}
	else if (player.weapons.colt45ammo - shots >= 0)
	{
		std::uniform_int_distribution<int> ShotAttempts(2, 6);
		std::uniform_int_distribution<int> shotaccuracy(0, 10);
		int shots = ShotAttempts(rng);
		if (player.weapons.colt45ammo - shots >= 0)
		{
			for (int i = 0; i < shots; i++)
			{
				double chance = shotaccuracy(rng) * .20 + player.accuracy;
				if (chance > 10) {
					std::cout << "Hit for " << player.weapons.glockDamage[2] << '\n';
					player.weapons.glockammo--;
					enemy.health -= glockDamage[2];
				}
				else {
					std::cout << "Miss\n";
				}
			}
		}
	}
	else if (player.weapons.DEammo - shots >= 0)
	{
		std::uniform_int_distribution<int> ShotAttempts(2, 6);
		std::uniform_int_distribution<int> shotaccuracy(0, 10);
		int shots = ShotAttempts(rng);
		if (player.weapons.DEammo - shots >= 0)
		{
			for (int i = 0; i < shots; i++)
			{
				double chance = shotaccuracy(rng) * .20 + player.accuracy;
				if (chance > 10) {
					std::cout << "Hit for " << player.weapons.deDamage[2] << '\n';
					player.weapons.DEammo--;
					enemy.health -= deDamage[2];
				}
				else {
					std::cout << "Miss\n";
				}
			}
		}
	}
	else if (player.weapons.ragingammo - shots >= 0)
	{
		std::uniform_int_distribution<int> ShotAttempts(2, 6);
		std::uniform_int_distribution<int> shotaccuracy(0, 10);
		int shots = ShotAttempts(rng);
		if (player.weapons.ragingammo - shots >= 0)
		{
			for (int i = 0; i < shots; i++)
			{
				double chance = shotaccuracy(rng) * .20 + player.accuracy;
				if (chance > 10) {
					std::cout << "Hit for " << player.weapons.ragingDamage[2] << '\n';
					player.weapons.ragingammo--;
					enemy.health -= ragingDamage[2];
				}
				else {
					std::cout << "Miss\n";
				}
			}
		}

	}
	std::cout << "Enemy: " << enemy.name << " has " << enemy.health << " health remaining.\n";
	player.isAttacking = false;
}
	
		
void Weapon::PistolWhip(Player& player, Enemy& enemy)
{
	std::uniform_int_distribution<> ThrowChance(1, 5);
	int throwing = ThrowChance(rng);
	double throwingChance = throwing * .50 + player.accuracy;
	if (throwingChance > 12)
	{
		std::cout << "Hit for " << player.weapons.glockDamage[3] << '\n';
		player.isArmed = false;
	}
	else
	{
		std::cout << " A swing and a miss. I hope you have something up your sleeve because the pain train is coming.\n";
		
	}
	std::cout << "Enemy: " << enemy.name << " has " << enemy.health << " health remaining\n";
	player.isAttacking = false;
}

void Weapon::PistolThrow(Player& player, Enemy& enemy)
{
	std::uniform_int_distribution<> ThrowChance(1, 5);
	int throwing = ThrowChance(rng);
	double throwingChance = throwing * .50 + player.accuracy;
	if (throwingChance > 12)
	{
		std::cout << "Hit for " << player.weapons.glockDamage[3] << '\n';
		enemy.health - glockDamage[3];
		
	}
	else {
		std::cout << "You threw your gun away. I sincerely hope you were out of ammo. If you still had ammo... Uh what are you doing?\n";
		std::cout << "You know what happens when you're unarmed right? No? You're about to find out.\n";
	}
	player.isArmed = false;
	player.isAttacking = false;
	std::cout << "Enemy: " << enemy.name << " has " << enemy.health << " health remaining \n";
}

void Weapon::SwordQuick(Player& player, Enemy& enemy)
{	
	if (player.swordChoice == 1) {
		std::uniform_int_distribution<> QuickStrike(0, 3);
		int QuickChance = 34;
	}
	else if (player.swordChoice == 2)
	{

	}
	else if (player.swordChoice == 3) {

	}
	else if (player.swordChoice == 4) {

	}
}

void Weapon::SwordCombo(Player& player, Enemy& enemy)
{
	if (player.swordChoice == 1) {
		std::uniform_int_distribution<> QuickStrike(0, 3);
		int QuickChance = 34;
	}
	else if (player.swordChoice == 2)
	{

	}
	else if (player.swordChoice == 3) {

	}
	else if (player.swordChoice == 4) {

	}
}

void Weapon::SwordStrong(Player& player, Enemy& enemy)
{
	if (player.swordChoice == 1) {
		std::uniform_int_distribution<> QuickStrike(0, 3);
		int QuickChance = 34;
	}
	else if (player.swordChoice == 2)
	{

	}
	else if (player.swordChoice == 3) {

	}
	else if (player.swordChoice == 4) {

	}
}

void Weapon::GrenadeThrow(Player& player, Enemy& enemy)
{
	if (player.grenadeChoice == 1) {

	}
	else if (player.grenadeChoice == 2) {

	}
	else if (player.grenadeChoice == 3) {

	}
	else if (player.grenadeChoice == 4) {

	}
}

void Weapon::GrenadeCook(Player& player, Enemy& enemy)
{
	if (player.grenadeChoice == 1) {

	}
	else if (player.grenadeChoice == 2) {

	}
	else if (player.grenadeChoice == 3) {

	}
	else if (player.grenadeChoice == 4) {

	}
}

void Weapon::GrenadeSmack(Player& player, Enemy& enemy)
{
	if (player.grenadeChoice == 1) {

	}
	else if (player.grenadeChoice == 2) {

	}
	else if (player.grenadeChoice == 3) {

	}
	else if (player.grenadeChoice == 4) {

	}
}

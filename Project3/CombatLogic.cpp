#include "CombatLogic.h"
#include "Player.h"
#include "Enemy.h"

void Resolution(Player &player, Enemy &enemy)
{	
	if (player.initiative > enemy.initiative) {
		std::cout << player.name << " attacks " << enemy.name << '\n';
		player.AttackEnemy(player, enemy);
	}
	else{
		std::cout << "yes";
	}
}


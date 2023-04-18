#include "CombatLogic.h"
#include "Player.h"
#include "Enemy.h"

void Resolution(Player &player, Enemy &enemy)
{	
	player.isBattle = true;


	if (player.initiative > enemy.initiative) {
		player.isAttacking = true;
		std::cout << player.name << " attacks " << enemy.name << '\n';
		player.AttackEnemy(player, enemy);
		
	}
	else{
		std::cout << "yes";
		enemy.isAttacking = true;
	}
}


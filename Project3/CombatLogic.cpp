#include "CombatLogic.h"

void Resolution(Player &player, Enemy &enemy)
{	
	if (player.initiative > enemy.initiative) {
		player.Battle();
	}
	else{
		std::cout << "yes";
	}
}

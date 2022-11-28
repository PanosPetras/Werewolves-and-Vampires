#include "Player.h"
#include <Windows.h>
#include "Map.h"
#include "NPC.h"
#include <iostream>

Player::Player(Map* map) : GameEntity(map) {
	//Initialize the player's potions
	potions = 1;

	//Prompt the player to choose which team he will support
	do {
		std::cout << "Choose your side(V or W): ";
		std::cin >> team;
	} while (team != 'V' && team != 'W');
}

void Player::Move() {
	if (GetKeyState('W') & 0x8000) {
		map->MoveEntity(*this, x, y + 1);
	}
	if (GetKeyState('A') & 0x8000) {
		map->MoveEntity(*this, x - 1, y);
	}
	if (GetKeyState('S') & 0x8000) {
		map->MoveEntity(*this, x, y - 1);
	}
	if (GetKeyState('D') & 0x8000) {
		map->MoveEntity(*this, x + 1, y);
	}
}

void Player::HealTeam(std::vector<NPC*>& vec) {
	//Check if the player has enough potions
	if (potions > 0) {
		//Check that it is the right time of the day
		if ((team == 'V' && map->GetTimeOfDay() == Day) ||
			(team == 'W' && map->GetTimeOfDay() == Night)) {
			potions--;

			//Heal all the members of the player's team
			for (auto e : vec) {
				if (e->GetSymbol() == team) {
					e->GetHealed();
				}
			}
		}
	}
}

char Player::GetSymbol() const {
	return 'P';
}

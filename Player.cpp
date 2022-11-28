#include "Player.h"
#include <Windows.h>
#include "Map.h"

Player::Player(Map* map) : Entity(map) {
	potions = 1;
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

void Player::HealTeam() {
}

char Player::GetSymbol() const {
	return 'P';
}

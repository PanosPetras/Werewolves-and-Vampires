#include "Player.h"

Player::Player(Map* map) : Entity(map) {
	potions = 1;
}

void Player::Move() {
}

void Player::HealTeam() {
}

char Player::GetSymbol() const {
	return 'P';
}

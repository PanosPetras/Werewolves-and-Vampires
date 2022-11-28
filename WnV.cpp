#include "WnV.h"
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <thread>
#include "Vampire.h"
#include "Werewolf.h"
#include "Player.h"

using namespace std;
using namespace std::chrono;

WnV::WnV(){
	quit = false;
	paused = false;

	InitializeGame();
}

WnV::~WnV(){
	//Free all the memory that we allocated
	delete player;

	for (auto i : entities) {
		delete i;
	}

	delete map;
}

void WnV::InitializeGame(){
	GetRefreshRate();

	InitializeMap();

	InitializeEntities();

	HideCursor();
}

void WnV::GetRefreshRate() {
	//Ask for the desired refresh rate
	cout << "Please enter the desired refresh rate of the game: ";
	cin >> refreshRate;
}

void WnV::InitializeMap() {
	//Ask for the dimensions of the map
	int x, y;

	cout << "Please enter the desired width of the map: ";
	cin >> x;

	cout << "Please enter the desired height of the map: ";
	cin >> y;

	//Initialize the map
	map = new Map(x, y);
}

void WnV::InitializeEntities() {
	std::function<void(NPC*)> func = std::bind(&WnV::DeleteNPC, this, std::placeholders::_1);
	NPC::ChangeDeathFunc(func);

	NPC* v;

	//Create all the Vampires
	for (int i = 0; i < map->GetWidth() * map->GetHeight() / 18; i++) {
		v = new Vampire(map);
		entities.push_back(v);
	}

	//Create all the Werewolves
	for (int i = 0; i < map->GetWidth() * map->GetHeight() / 18; i++) {
		v = new Werewolf(map);
		entities.push_back(v);
	}

	//Create the player
	player = new Player(map);
}

void WnV::MainLoop() {
	auto timeThen = high_resolution_clock::now();

	while (!quit) {
		//Get input from the user
		HandleInput();

		if (!paused) {
			Tick();

			//Draw the map and it's entities
			Render();

			//Make sure that the game plays at a constant refresh rate
			auto timeNow = high_resolution_clock::now();
			auto elapsed = duration_cast<milliseconds>(timeNow - timeThen);

			if (elapsed.count() < 1000.0 / refreshRate) {
				int timeToSleep = (int)(1000.0 / refreshRate) - int(elapsed.count());

				this_thread::sleep_for(milliseconds(timeToSleep));
			}

			timeThen = high_resolution_clock::now();
		}
	}
}

void WnV::Render() {
	//Clear the screen
	system("cls");

	//Render the map
	map->Render();

	//Print the potions that the player has left
	cout << endl << "Potions: " << player->GetPotions() << endl;
}

void WnV::HandleInput() {
	if (GetKeyState('Q') & 0x8000) {
		Quit();
	}
	if (GetKeyState('P') & 0x8000) {
		Pause();
	}
	if (GetKeyState('U') & 0x8000) {
		Unpause();
	}

	//Player input
	if (!paused) {
		player->Move();

		if (GetKeyState('F') & 0x8000) {
			player->HealTeam(entities);
		}
	}
}

void WnV::Tick() {
	for (auto entity : entities) {
		entity->Move();
	}

	for (auto entity : entities) {
		entity->PerformAction();
	}

	map->Tick();
}

void WnV::Pause() {
	if (!paused) {
		paused = true;

		//Clear the screen
		system("cls");

		cout << "The game is now paused." << endl << endl << 
			"Vampires alive: " << Vampire::GetVampireCount() << endl << 
			"Werewolves alive: " << Werewolf::GetWerewolfCount() << endl << endl << 
			"Controls:" << endl <<
			"Use the WASD keys to move." << endl << 
			"Press the F key to heal the team that you support*." << endl <<
			"Press U to unpause." << endl << "Press Q to quit.";
	}
}

void WnV::Unpause() {
	paused = false;
}

void WnV::Quit(){
	quit = true;
}

//Code to hide cursor sourced from the answer of user VolAnd in the following thread: https://stackoverflow.com/questions/30126490/how-to-hide-console-cursor-in-c
void WnV::HideCursor() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;

	info.dwSize = 100;
	info.bVisible = FALSE;

	SetConsoleCursorInfo(consoleHandle, &info);
}

void WnV::DeleteNPC(NPC* npc) {
	//Find the NPC on the entities vector
	auto obj = std::find(entities.begin(), entities.end(), npc);

	//Delete the NPC from the entities vector
	if (obj != entities.end()) {
		entities.erase(obj);
	}

	//Make sure that the destructor is called
	if (npc->GetSymbol() == 'V') {
		delete (Vampire*)npc;
	} else {
		delete (Werewolf*)npc;
	}

	//If the number of one of the two teams has reached zero, end the game
	if (Werewolf::GetWerewolfCount() <= 0 || Vampire::GetVampireCount() <= 0) {
		EndGame();
	}
}

void WnV::EndGame() {
	//Stop the game loop
	Quit();

	//Clear the screen
	system("cls");

	//Show the end game messages
	cout << "Game Over!" << endl;

	if (Werewolf::GetWerewolfCount() <= 0) {
		cout << "The Werewolves were eliminated." << endl << Vampire::GetVampireCount() << " Vampires survived." << endl;
	} else {
		cout << "The Vampires were eliminated." << endl << Werewolf::GetWerewolfCount() << " Werewolves survived." << endl;
	}

	//Wait for user input so that the console window does not disappear
	std::string s;
	cin >> s;
}

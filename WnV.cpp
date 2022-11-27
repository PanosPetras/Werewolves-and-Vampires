#include "WnV.h"
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;

WnV::WnV(){
	quit = 0;

	InitializeGame();
}

WnV::~WnV(){
	delete map;
}

void WnV::InitializeGame(){
	//Ask for the desired refresh rate
	cout << "Please enter the desired refresh rate of the game: ";
	cin >> refreshRate;

	//Ask for the dimensions of the map
	int x, y;

	cout << "Please enter the desired width of the map: ";
	cin >> x;

	cout << "Please enter the desired height of the map: ";
	cin >> y;

	//Initialize the map
	map = new Map(x, y);

	HideCursor();
}

void WnV::MainLoop(){
	auto timeThen = high_resolution_clock::now();

	while (!quit) {
		HandleInput();
		Render();
		
		auto timeNow = high_resolution_clock::now();
		auto elapsed = duration_cast<milliseconds>(timeNow - timeThen);

		if (elapsed.count() < 1000.0 / refreshRate) {
			int timeToSleep = (int)(1000.0 / refreshRate) - int(elapsed.count());

			this_thread::sleep_for(milliseconds(timeToSleep));
			timeThen = high_resolution_clock::now();
		}
	}
}

void WnV::Render() {
	system("cls");

	map->Render();
}

void WnV::HandleInput(){
	if (GetKeyState('Q') & 0x8000) {
		Quit();
	}
}

void WnV::Quit(){
	quit = 1;
}

//Code to show/hide cursor sourced from the answer of user VolAnd in the following thread: https://stackoverflow.com/questions/30126490/how-to-hide-console-cursor-in-c
void WnV::HideCursor(){
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void WnV::ShowCursor(){
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = TRUE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

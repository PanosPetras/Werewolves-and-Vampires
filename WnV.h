#pragma once
#include <vector>
#include "Entity.h"
#include "Map.h"

class Player;

class WnV {
private:
	int quit;

	int refreshRate;

	std::vector<Entity*> entities;
	Player* player = NULL;

	Map* map = NULL;

public:
	WnV();

	~WnV();

	void MainLoop();

private:
	void InitializeGame();

	void InitializeEntities();

	void GetRefreshRate();

	void InitializeMap();

	void Render();

	void HandleInput();

	void Pause();

	void UnPause();

	void Quit();

	void HideCursor();

	void ShowCursor();
};
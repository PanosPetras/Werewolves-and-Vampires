#pragma once
#include <vector>
#include "Entity.h"
#include "Map.h"

class WnV {
private:
	int quit;

	int refreshRate;

	std::vector<Entity> entities;

	Map* map = NULL;

public:
	WnV();

	~WnV();

	void MainLoop();

private:
	void InitializeGame();

	void Render();

	void HandleInput();

	void Pause();

	void UnPause();

	void Quit();

	void HideCursor();

	void ShowCursor();
};
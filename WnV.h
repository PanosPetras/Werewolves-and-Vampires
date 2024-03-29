#pragma once
#include <vector>

class Player;
class NPC;
class Map;

class WnV {
private:
	bool quit;
	bool paused;

	double refreshRate;

	std::vector<NPC*> entities;
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

	void Tick();

	void Pause();

	void Unpause();

	void Quit();

	void HideCursor();

	void DeleteNPC(NPC* npc);

	void EndGame();
};
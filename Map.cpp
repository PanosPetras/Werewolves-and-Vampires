#include "Map.h"
#include <iostream>

using namespace std;

Map::Map(int x, int y){
	this->x = x;
	this->y = y;
}

void Map::Render(){
	cout << "  ";

	for (int i = 0; i < x; i++) {
		cout << i + 1;
	}

	cout << endl;

	for (int i = 0; i < x; i++) {
		cout << " " << i + 1 << endl;
	}
}

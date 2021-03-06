#ifndef TILE_MAP_H
#define TILE_MAP_H

#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "Mesh.h"

using std::vector;
using std::string;

class TileMap
{
public:
	TileMap(void);
	~TileMap(void);

	void Init(const int screenHeight, const int screenWidth, const int tileSize = 25);
	void Create(const int screenWidth, const int screenHeight, const int mapWidth, const int mapHeight, const int tileSize = 25, bool collision = false);
	bool LoadMap(const string graphicMap, const string collisionMap = "");
	bool LoadTileSheet(const string fileLoc);

	int GetNumOfTiles_ScreenHeight();		// Get the number of tiles for height of the screen
	int GetNumOfTiles_ScreenWidth();		// Get the number of tiles for width of the screen
	int GetNumOfTiles_MapHeight();		// Get the number of tiles for height of the map
	int GetNumOfTiles_MapWidth();		// Get the number of tiles for width of the map
	int GetScreenHeight();
	int GetScreenWidth();
	int GetTileSize();
	int GetMapWidth();
	int GetMapHeight();

	Mesh* GetTileSheet();

	vector<vector<int> > theScreenMap;
	vector<vector<int> > theCollisionMap;

private:
	int screenHeight;
	int screenWidth;
	int numOfTiles_ScreenHeight;		// Number of tiles in the screen's height
	int numOfTiles_ScreenWidth;		// Number of tiles in the screen's width
	int tileSize;

	int mapHeight;				// The map's height
	int mapWidth;				// The map's width
	int numOfTiles_MapWidth;	// Number of tiles in the map's height
	int numOfTiles_MapHeight;		// Number of tiles in the map's width

	int tileOffsetX, tileOffsetY;
	int fineOffsetX, fineOffsetY;

	bool LoadFile(const string mapName, vector<vector<int> >& map);

	Mesh *tileSheet;
};

#endif
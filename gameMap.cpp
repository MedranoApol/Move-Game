/*   gameMap.cpp
*   
*    NOTES: [PLEASE WRITE ANYTHIGN OF NOTING WHETHER YOU ARE APOL OR NOT, LIST YOUR NAME THOUGH]
*
*
*
*/

#include "gameMap.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <unordered_map>
#include <ctime>
#include <cstdlib>
#include <windows.h>

/*
	###############################################
	###############################################
	####### HELPER FUNCTIONS FOR THIS FILE ########
	###############################################
	###############################################
*/

int clamp(int val)
{
	if (val <= 2)
		return 3;
	else if (val > 16)
		return 16;
	else
		return val;
}

std::string hexidecimal()
{
	const char* hexi = "0123456789ABCDEF";
	return hexi;
}

void spaceNeededForNiceness(const int &width)
{
	int maxLength = 10;
	int amountNeeded = maxLength - width;
	for (int i = 0; i < amountNeeded; i++)
		std::cout << "  ";
}

void printBoxRow(const int &width, const bool &locations = false)
{
	int distance;
	if (locations)
		distance = 4;
	else
		distance = 3;

	std::cout << "\t";
	spaceNeededForNiceness(width);
	for (int i = 0; i < width; i++)
	{
		std::cout << "+";
		for (int i = 0; i < distance; i++)
		{
			std::cout << "-";
		}
	}
	std::cout << "+\n";
}

/* ###########################################################
   ########## Function Defintions for the Game Map ###########
   ###########################################################
   #														 #
   #                  1. Constructors						 #
   #                  2. Member Functions					 #
   #                  3. Destuctor							 #
   #													     #
   ###########################################################
   ###########################################################
*/

// constructor for game map
GameMap::GameMap() : H(0), W(0), mapAdj(nullptr) {}

// generates the game map given height and width
GameMap::GameMap(int h, int w)
{
	// ensures no naughty user values
	H = clamp(h);
	W = clamp(w);

	// creates array empty node memory to fill a map h x w
	mapAdj = new Node **[H];
	for (int i = 0; i < H; i++)
	{
		mapAdj[i] = new Node *[W];
		for (int j = 0; j < W; j++)
		{
			mapAdj[i][j] = new Node;
		}
	}

	// iterates through the map nodes to connect them
	// also assigning values to them
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{

			// configure up link, if at top edge link is null
			if (i == 0)
				mapAdj[i][j]->up = nullptr;
			else
				mapAdj[i][j]->up = mapAdj[i - 1][j];

			// configure down link, if at bottom edge link is null
			if (i == H - 1)
				mapAdj[i][j]->down = nullptr;
			else
				mapAdj[i][j]->down = mapAdj[i + 1][j];

			// configure left link, if at left edge link is null
			if (j == 0)
				mapAdj[i][j]->left = nullptr;
			else
				mapAdj[i][j]->left = mapAdj[i][j - 1];

			// configure right link, if at right edge link is null
			if (j == W - 1)
				mapAdj[i][j]->right = nullptr;
			else
				mapAdj[i][j]->right = mapAdj[i][j + 1];

			// assign location value to that specific map location
			mapAdj[i][j]->data = (i * 10) + j;
		}
	}
}

void GameMap::clearGameMap()
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			delete mapAdj[i][j];
		}
		delete[] mapAdj[i];
	}
	delete[] mapAdj;
}

void GameMap::changeGameMap(int h, int w)
{
	// clear the prior map
	clearGameMap();

	// update height and width class variables
	H = clamp(h);
	W = clamp(w);

	// creates array empty node memory to fill a map h x w
	mapAdj = new Node **[H];
	for (int i = 0; i < H; i++)
	{
		mapAdj[i] = new Node *[W];
		for (int j = 0; j < W; j++)
		{
			mapAdj[i][j] = new Node;
		}
	}

	// iterates through the map nodes to connect them
	// also assigning values to them
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; W < w; j++)
		{

			// configure up link, if at top edge link is null
			if (i == 0) 
				mapAdj[i][j]->up = nullptr;
			else
				mapAdj[i][j]->up = mapAdj[i - 1][j];

			// configure down link, if at bottom edge link is null
			if (i == h - 1)
				mapAdj[i][j]->down = nullptr;
			else
				mapAdj[i][j]->down = mapAdj[i + 1][j];

			// configure left link, if at left edge link is null
			if (j == 0)
				mapAdj[i][j]->left = nullptr;
			else
				mapAdj[i][j]->left = mapAdj[i][j - 1];

			// configure right link, if at right edge link is null
			if (j == w - 1)
				mapAdj[i][j]->right = nullptr;
			else
				mapAdj[i][j]->right = mapAdj[i][j + 1];

			// assign location value to that specific map location
			mapAdj[i][j]->data = (i * 10) + j;
		}
	}
}

void GameMap::printGameMapNums()
{
	// helper function to print top & bottom of the boxes
	printBoxRow(W, true);

	// gets map that converts integers to hexidecimals
	std::string hexi = hexidecimal();

	// loops through every node printing in a grid
	for (int i = 0; i < H; i++)
	{
		std::cout << "\t";
		spaceNeededForNiceness(W);
		std::cout << "| ";
		for (int j = 0; j < W; j++)
		{
			std::cout << hexi[i] << hexi[j] << " | ";
		}
		std::cout << "\n";
		printBoxRow(W, true);
	}
}

void GameMap::printGameMap()
{
	// helper function to print top & bottom of the boxes
	printBoxRow(W);

	// loops through every node printing in a grid
	for (int i = 0; i < H; i++)
	{
		std::cout << "\t";
		spaceNeededForNiceness(W);
		std::cout << "| ";
		for (int j = 0; j < W; j++)
		{
			if (mapAdj[i][j]->space == '\0')
				std::cout << "  | ";
			else
				std::cout << mapAdj[i][j]->space << " | ";
		}
		std::cout << "\n";
		printBoxRow(W);
		Sleep(25);
	}
}

Node* GameMap::getMapLocation(int h, int w)
{
	return mapAdj[h][w];
}

Node* GameMap::getStartOfMap() 
{
	return mapAdj[0][0];
}

Node* GameMap::getGoal()
{
	return mapAdj[H - 1][W - 1];
} 

int GameMap::getWidth()
{
	return W;
}

int GameMap::getHeight()
{
	return H;
}

void GameMap::placeObstacles(){
	
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			//gets numbers randomly 1 to 10 inclusive
			int randomInt = 1 + (rand() % 10);
 
			if (mapAdj[i][j]->space == 'C' || mapAdj[i][j]->space == 'G' || mapAdj[i][j]->space == 'A' || mapAdj[i][j]->space == 'E')
			{
				continue;
			}

			if (randomInt == 7) 
			{
				mapAdj[i][j]->space = '#';
			}
		}
	}
}

void GameMap::placeEnemies(){
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			//gets numbers randomly 1 to 10 inclusive
			int randomInt = 1 + (rand() % 10);
 
			if (mapAdj[i][j]->space == 'C' || mapAdj[i][j]->space == 'G' || mapAdj[i][j]->space == 'A' || mapAdj[i][j]->space == '#')
			{
				continue;
			}

			if (randomInt == 7) 
			{
				mapAdj[i][j]->space = 'E';
			}
		}
	}
}

void GameMap::placeAllies(){
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			//gets numbers randomly 1 to 20 inclusive
			int randomInt = 1 + (rand() % 20);
 
			if (mapAdj[i][j]->space == 'C' || mapAdj[i][j]->space == 'G' || mapAdj[i][j]->space == 'E' || mapAdj[i][j]->space == '#')
			{
				continue;
			}

			if (randomInt == 7) 
			{
				mapAdj[i][j]->space = 'A';
			}
		}
	}
}

GameMap::~GameMap()
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			delete mapAdj[i][j];
		}
		delete[] mapAdj[i];
	}
	delete[] mapAdj;
}


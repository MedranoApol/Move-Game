/*   gameMap.hpp
*   
*    NOTES: [PLEASE WRITE ANYTHIGN OF NOTING WHETHER YOU ARE APOL OR NOT, LIST YOUR NAME THOUGH]
*
* 	 AS OF MAY 22ND, I BELIEVE THIS CLASS IS COMPLETED! - AM
*
*/


#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "node.hpp"
#include <string>
#include <vector>
#include <unordered_map>


class GameMap{
private:

	int H; // height of the map

	int W; // width of the map

	Node*** mapAdj; // the formation of the map

public:
	// Constructor for no parameters
	GameMap();

	// Constructor for height and width
	GameMap(int h, int w);

    // clears the game map
	void clearGameMap();

    // changes the game map depending on the parameters set by the zero
    // Minimum: 1, Maximu: 15
	void changeGameMap (int h, int w);

    // prints the game map with number locations
	void printGameMapNums();

    //print the game map
    void printGameMap();

	//returns a map location
	Node* getMapLocation(int h, int w);

	//returns the start of the map
	Node* getStartOfMap(); 

	//returns the goal of the map
	Node* getGoal();

	//get the width of the map
	int getWidth();

	//get the height of the map
	int getHeight();

	//assigns randomly generated obstacles to obscure path
	void placeObstacles();

	//assigns randomly generated enemies to fight along the path
	void placeEnemies();

	//assigns randomly generated allies to help join the fight
	void placeAllies();

	// Destructor
	~GameMap();
};

#endif
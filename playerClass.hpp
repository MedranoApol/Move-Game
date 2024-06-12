/*   playerClass.hpp
*   
*    NOTES: [PLEASE WRITE ANYTHIGN OF NOTING WHETHER YOU ARE APOL OR NOT, LIST YOUR NAME THOUGH]
*
*
*
*/

#ifndef PLAYERCLASS_H
#define PLAYERCLASS_H
#include "node.hpp"
#include <string>
#include <vector>
#include <unordered_map>
#include "enemyClass.hpp"
#include "allyClass.hpp"

class Player {
private:
	// players location on the game map
	Node* playerLocation;

	// name of the player
	std::string playerName;

	// items in inventory
	std::vector<std::string> playerInventory;

	// keeps track of allies acquired
	std::vector<Ally> alliesParty;

	// keeps track of enemy defeated
	std::vector<Enemy> enemiesDefeated;
	
	// numbers of moves made by players
	int playerMovesAmount;

	// player score from playing the game
	int playerScore;

	// player health
	int playerHealth;

	// player attack
	int playerAttack;

	// player damage dealt
	int playerDealtDamage;

	// player damage taken
	int playerTakenDamage;

public:
	//constructor with no name, default name is Player 1
	Player();

	//constructor with player inputed name
	Player(std::string name); 

	//gets the starting location of the grid;
	void assignPlayerLocation(Node* startingLocation);

	//checks player moves depending on their choice of direction
	char validatePlayerMove(std::string direction);

	//executes player move depending on their choice of direction
	void executePlayerMove(std::string direction);

	// Add allies to alliesParty vector
	void addAlliesToParty(Ally ally);

	// Add defeated enemy to enemyDefeated vector
	void addDefeatedEnemy(Enemy enemy);

	//gets the player's name
	std::string getPlayerName();

	//gets the player's current location
	Node* getPlayerLocation();

	// get the player's inventory
	std::vector<std::string> getPlayerInventory();

	// get the allies's party
	std::vector<Ally> getAlliesParty();

	// get the enemies's defeated
	std::vector<Enemy> getDefeatedEnemies();

	// get the inventory size
	int getInventorySize();

	// get the ally party size
	int getPartySize();

	// get number of enemies defeated
	int getEnemyDefeatSize();

	//gets the player's amount of moves
	int getPlayerMoves();

	// get player's score
	int getPlayerScore();

	//gets the player's health
	int getPlayerHealth();

	//gets the player's attack
	int getPlayerAttack();

	// send over player attack to an enemy
	int playerAttackBattleTurn();
	
	// send damage to the player
	void playerTakingDamage(int damage);

	// gets damage dealt by player and adds it to sum of dealt damage
	void playerSumDamageDealt(int damage);

	// gets damage taken by plyaer and adds it to sum of taken damage
	void playerSumDamageTaken(int damage);

	//deconstructor
	~Player();

};

#endif
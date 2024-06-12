/*   moveGame.cpp
*   
*    NOTES: [PLEASE WRITE ANYTHIGN OF NOTING WHETHER YOU ARE APOL OR NOT, LIST YOUR NAME THOUGH]
*
*
*
*/

//Apol Medrano
//First Game No Tutorials & Without Win32
// Start Date: 2/6/24
// Releasable Product Date: TBD

#include "gameMap.hpp"
#include "playerClass.hpp"
#include "gameFunctions.hpp"
#include <iostream>
#include <ctime>
#include <windows.h>
#include <fstream>
#include <cstdlib>

int main() {
	//initalize random seed generator
	srand(time(nullptr));	

	//prints the logo
	startTheGame();

	//gets Player's named
	std::string playerName;
	std::cout << "\t\t\tEnter your name: ";
	std::cin >> playerName;
	std::cout << "\t\t\t   Enjoy, " << playerName << "!\n\n";

	//sets the map dimensions
	std::cout << "\t\t       [Game Map Dimensions]\n";
	int h, w;
	std::cout << "\t\t\t  Enter width: ";
	std::cin >> w;
	std::cout << "\t\t\t Enter height: ";
	std::cin >> h;
	GameMap mapOfGame(h, w);
	clearScreen();

	//initializes player class //sets player start and goal
	Node* playerStart = mapOfGame.getStartOfMap();
	Node* playerGoal = mapOfGame.getGoal();
	playerGoal->space = 'G';
	Player playerOfGame(playerName);
	playerOfGame.assignPlayerLocation(playerStart);

	//places randomly generated obstacles and enemies
	mapOfGame.placeObstacles();
	mapOfGame.placeEnemies();
	mapOfGame.placeAllies();

	while (true) 
	{
		//prints the game map
		mapOfGame.printGameMap();

		//prompts user to choose direction
		std::string selection;
		printMoveOptions();
		Sleep(0.2);
		std::cin >> selection;

		//executes move or executes move
		char move = playerOfGame.validatePlayerMove(selection);

		switch(move)
		{
			case '\0':
			{
				playerOfGame.executePlayerMove(selection);
				clearScreen();
			} break;

			case 'A':
			{
				Ally game_ally;
				playerOfGame.addAlliesToParty(game_ally);
				playerOfGame.executePlayerMove(selection);
				clearScreen();
			} break;

			case 'E':
			{
				Enemy enemy;
				Enemy enemyToFight(enemy);
				clearScreen();
				 
				while (true) // Attack Battle Game Loop
				{
					std::cout << "HEALTH : <" << playerName << " : " << playerOfGame.getPlayerHealth() << ",\t"
							  << enemyToFight.getEnemyName() << " : " << enemyToFight.getEnemyHealth() << ">\n";

					system("pause");
					int playerAttack = playerOfGame.playerAttackBattleTurn();
					std::cout << playerName << " attacks\n";
					enemyToFight.EnemyTakingDamage(playerAttack);
					std::cout << enemyToFight.getEnemyName() << " takes " << playerAttack << " damage\n\n";
					playerOfGame.playerSumDamageDealt(playerAttack);
					Sleep(100);
					if (enemyToFight.getEnemyHealth() == 0)
					{
						playerOfGame.addDefeatedEnemy(enemy);
						std::cout << enemyToFight.getEnemyName() << " has been defeated.\n"
								  << "JOURNEY CONTINUES\n";
						system("pause");
						break;
					}
					else
					{
						std::cout << "HEALTH : <" << playerName << " : " << playerOfGame.getPlayerHealth() << ",\t"
							  	  << enemyToFight.getEnemyName() << " : " << enemyToFight.getEnemyHealth() << ">\n";
						system("pause");
					}

					int enemyAttack = enemy.getEnemyDamage();
					std::cout << enemyToFight.getEnemyName() << " attacks\n";
					playerOfGame.playerTakingDamage(enemyAttack);
					std::cout << playerName << " takes " << enemyAttack << " damage\n\n";
					playerOfGame.playerSumDamageTaken(enemyAttack);

					if (playerOfGame.getPlayerHealth() == 0)
					{
						// assign variables for the results
						std::string nameOfPlayer = playerOfGame.getPlayerName();
						int mapWidth = mapOfGame.getWidth();
						int mapHeight = mapOfGame.getHeight();
						int numOfMoves = playerOfGame.getPlayerMoves();
						// numOfItems = playerOfGame.getNumOfItems()
						int enemiesDefeated = playerOfGame.getEnemyDefeatSize();
						int alliesMet = playerOfGame.getPartySize();
						std::string currentTime = getCurrentTime();

						// print the players results
						printGameStatsAndWrite(nameOfPlayer, mapWidth, mapHeight, numOfMoves, 0, enemiesDefeated, alliesMet, currentTime,'L');

						//send game stats the database
						system("python sendPlayerStats.py");
						playerStart = nullptr;
						playerGoal = nullptr;
						system("pause");
						exit(1);
					}
					else
					{
						Sleep(100);
					}
				}

				playerOfGame.executePlayerMove(selection);
				clearScreen();
			} break;
			
			case '#':
			{
				std::cout << "Obstacle There!!\n";
				system("pause");
				clearScreen();
			} break;

			case '@':
			{
				std::cout << "Invalid Location!!\n";
				system("pause");
				clearScreen();
			} break;

			case '~':
			{
				std::cout << "No Move Selected!!\n";
				system("pause");
				clearScreen();
			} break;

			case 'G':
			{
				// assign variables for the results
				std::string nameOfPlayer = playerOfGame.getPlayerName();
				int mapWidth = mapOfGame.getWidth();
				int mapHeight = mapOfGame.getHeight();
				int numOfMoves = playerOfGame.getPlayerMoves();
				// numOfItems = playerOfGame.getNumOfItems()
				int enemiesDefeated = playerOfGame.getEnemyDefeatSize();
				int alliesMet = playerOfGame.getPartySize();
				std::string currentTime = getCurrentTime();
				
				// print the players results
				printGameStatsAndWrite(nameOfPlayer, mapWidth, mapHeight, numOfMoves, 0, enemiesDefeated, alliesMet, currentTime,'W');
				
				//send game stats the database
				system("python sendPlayerStats.py");
				playerStart = nullptr;
				playerGoal = nullptr;
				system("pause");
				exit(1);

			} break;

			default:
			{
				std::cout << "No Move Made!!\n";
				system("pause");
				clearScreen();
			} break;
		}
	}
	return 0; 
}
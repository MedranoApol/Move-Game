/*   playerClass.cpp
*   
*    NOTES: [PLEASE WRITE ANYTHIGN OF NOTING WHETHER YOU ARE APOL OR NOT, LIST YOUR NAME THOUGH]
*	
*	 NEXT TIME, I'LL HAVE A SYSTEM WHERE YOU CAN DETECT THE LOCATION OF THE PLAYER,
*	 ON A X-Y AXIS. THUS, MAKING IT EASY SINCE WE HAVE THAT COORDINATE SYSTEM
*	 ENGRAVED IN OUR BRAINS - AM
*/

#include "playerClass.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <vector>

/*
	###############################################
	###############################################
	####### HELPER FUNCTIONS FOR THIS FILE ########
	###############################################
	###############################################
*/

char findTheLetterForMove(std::string direction)
{
	char selection = '~';

	if (!isalpha(direction[0]))
	{
		for (auto letter : direction)
		{
			if (isalpha(letter))
			{
				selection = tolower(letter);
				return selection;
			}
		}
		return selection;
	}
	else
	{
		selection = tolower(direction[0]);
	}
	return selection;
}

/* ###########################################################
   ########## Function Defintions for Player Class ###########
   ###########################################################
   #														 #
   #                  1. Constructors						 #
   #                  2. Member Functions					 #
   #                  3. Destuctor							 #
   #													     #
   ###########################################################
   ###########################################################
*/

Player::Player() : playerLocation(nullptr), playerName("Maxo"), playerInventory({}), alliesParty({}), enemiesDefeated({}), playerMovesAmount(0), playerScore(0), playerHealth(20), playerAttack(3), playerDealtDamage(0), playerTakenDamage(0) {}

Player::Player(std::string name) : playerLocation(nullptr), playerInventory({}), alliesParty({}), enemiesDefeated({}), playerMovesAmount(0), playerScore(0), playerHealth(20), playerAttack(3), playerDealtDamage(0), playerTakenDamage(0)
{
	if (name == "No_Name")
	{
		playerName = "Maxo";
	}
	else
	{
		playerName = name;
	}
}

void Player::assignPlayerLocation(Node *startingLocation)
{
	playerLocation = startingLocation;
	playerLocation->space = 'C';
}

char Player::validatePlayerMove(std::string direction)
{
	char move = findTheLetterForMove(direction);
	if (move == '~')
		return '~';

	char spaceChar = '@';
	Node *tempSpace = getPlayerLocation();

	switch (tolower(move))
	{
	case 'w': // checks if up is a valid movement option
	{
		if (playerLocation->up != nullptr)
			spaceChar = tempSpace->up->space;

		return spaceChar;
	}
	break;

	case 's': // checks if down is a valid movement option
	{
		if (playerLocation->down != nullptr)
			spaceChar = tempSpace->down->space;

		return spaceChar;
	}
	break;

	case 'a': // checks if right is a valid movement option
	{
		if (playerLocation->left != nullptr)
			spaceChar = tempSpace->left->space;

		return spaceChar;
	}
	break;

	case 'd': // checks if left is a valid movement option
	{
		if (playerLocation->right != nullptr)
			spaceChar = tempSpace->right->space;

		return spaceChar;
	}
	break;

	case 'l': // exit out of program immediately
	{
		exit(1);
	}
	break;

	default: // if no valid letter is presented
	{
		return spaceChar;
	}
	break;
	}
}

void Player::executePlayerMove(std::string direction)
{
	char move = findTheLetterForMove(direction);
	switch (tolower(move))
	{
	case 'w':
	{
		playerLocation->space = '\0';
		playerLocation = playerLocation->up;
		playerLocation->space = 'C';
		playerMovesAmount++;
		return;
	}
	break;

	case 's':
	{
		playerLocation->space = '\0';
		playerLocation = playerLocation->down;
		playerLocation->space = 'C';
		playerMovesAmount++;
		return;
	}
	break;

	case 'a':
	{
		playerLocation->space = '\0';
		playerLocation = playerLocation->left;
		playerLocation->space = 'C';
		playerMovesAmount++;
		return;
	}
	break;

	case 'd':
	{
		playerLocation->space = '\0';
		playerLocation = playerLocation->right;
		playerLocation->space = 'C';
		playerMovesAmount++;
		return;
	}
	break;

	default:
	{
		std::cout << "HACKER" << "\n";
	}
	break;
	}
}

void Player::addAlliesToParty(Ally ally)
{
	alliesParty.push_back(ally);
}

void Player::addDefeatedEnemy(Enemy enemy)
{
	enemiesDefeated.push_back(enemy);
}

std::string Player::getPlayerName()
{
	return playerName;
}

Node *Player::getPlayerLocation()
{
	return playerLocation;
}

std::vector<std::string> Player::getPlayerInventory()
{
	return playerInventory;
}

std::vector<Ally> Player::getAlliesParty()
{
	return alliesParty;
}

std::vector<Enemy> Player::getDefeatedEnemies()
{
	return enemiesDefeated;
}

int Player::getInventorySize()
{
	return playerInventory.size();
}

int Player::getPartySize()
{
	return alliesParty.size();
}

int Player::getEnemyDefeatSize()
{
	return enemiesDefeated.size();
}

int Player::getPlayerMoves()
{
	return playerMovesAmount;
}

int Player::getPlayerScore()
{
	return playerScore;
}

int Player::getPlayerHealth()
{
	return playerHealth;
}

int Player::getPlayerAttack()
{
	return playerAttack;
}

int Player::playerAttackBattleTurn()
{
	int randomAttack = 1 + (rand() % 10);
	int currentAttack = playerAttack;

	if (randomAttack >= 1 && randomAttack < 7)
	{
		// Does nothing from 1-6
	}
	if (randomAttack >= 7 && randomAttack <= 9)
	{	// Adds 1 to attack 7-9
		currentAttack++; 
	}
	else
	{	// Subtracts 1 to attack if 10
		currentAttack--;
	}

	currentAttack += alliesParty.size(); // adds 1 to attack for every ally

	return currentAttack;
}

void Player::playerTakingDamage(int damage)
{
	if (damage > playerHealth)
		playerHealth = 0;
	else
		playerHealth -= damage;

	playerTakenDamage += damage;
}

void Player::playerSumDamageDealt(int damage)
{
	playerDealtDamage += damage;
}

void Player::playerSumDamageTaken(int damage)
{
	playerTakenDamage += damage;
}

Player::~Player()
{
	playerLocation = nullptr;
}
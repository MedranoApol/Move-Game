/*   enemyClass.cpp
*   
*    NOTES: [PLEASE WRITE ANYTHIGN OF NOTING WHETHER YOU ARE APOL OR NOT, LIST YOUR NAME THOUGH]
*
*
*
*   IN A FUTURE PROJECT I SHOULD MAKE EVERY TYPE OF ENEMY ITS OWN SUB-CLASS
*   THEN HAVE A SUPER-CLASS THAT GENERALIZES EVERY TYPE ENEMY.  
*   I AM SERIOUSLY MISSING THE CORE OOP CONCEPT OF INHERITANCE, IT APPLIED SO WELL. - AM
*
*
*
*/

#include "enemyClass.hpp"
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <iostream>

/*
	###############################################
	###############################################
	####### HELPER FUNCTIONS FOR THIS FILE ########
	###############################################
	###############################################
*/

std::string getRandomEnemyType()
{
    int randomInt = 1 + (rand() % 1000);

    if (randomInt == 1)
    {
        return "Skeleton King";
    }
    else if (randomInt > 1 && randomInt <= 10)
    {
        return "Dragon";
    }
    else if (randomInt == 210)
    {
        return "Kanye West from the past, the one used to Love";
    }
    else if (randomInt > 10 && randomInt <= 500)
    {
        return "Snake";
    }
    else if (randomInt == 607)
    {
        return "Beautiful Bearded Dragon named Baby West";
    }
    else if (randomInt == 608)
    {
        return "Kanye West";
    }
    else if (randomInt > 500 && randomInt <= 750)
    {
        return "Goblin";
    }
    else if (randomInt > 750 && randomInt <= 900)
    {
        return "Slimy Green Cube";
    }
    else if (randomInt > 900 && randomInt <= 950)
    {
        return "Golem";
    }
    else if (randomInt == 951)
    {
        return "Fish";
    }
    else if (randomInt == 952)
    {
        return "Osmar Alvarez, SSN: 45-678-2234";
    }
    else if (randomInt == 953)
    {
        return "Beetle";
    }
    else if (randomInt == 954)
    {
        return "Monkey";
    }
    else if (randomInt == 955)
    {
        return "Pastel Painting";
    }
    else if (randomInt == 956)
    {
        return "Peanut Butter Baby";
    }
    else if (randomInt == 957)
    {
        return "Normal Boot's cast of creators";
    }
    else if (randomInt == 958)
    {
        return "Centipede";
    }
    else if (randomInt == 959){
        return "Leech";
    }
    else
    {
        return "Anomly";
    }
}

std::string getRandomAdjective()
{
    // intializes the adjective vector
    std::vector<std::string> adjectives;
    std::string line;

    //opens the adjective files to look into 
    std::ifstream file("adjectives.txt");
    
    // reads whole file
    while (!file.eof())
    {
      //iterators through file line by line
      while (std::getline(file, line))
      {
        //adds the adjective at that line to vector
        adjectives.push_back(line);
      }
    }

    //save random adjective to a variable
    std::string word = adjectives[rand() % adjectives.size()];

    return word;
}

std::string getRandomFirstName()
{
   // intializes the first name vector & line
    std::vector<std::string> firstName;
    std::string line;

    //opens the adjective files to look into 
    std::ifstream file("firstNames.txt");
    
    // reads whole file
    while (!file.eof())
    {
      //iterators through file line by line
      while (std::getline(file, line))
      {
        //adds the adjective at that line to vector
        firstName.push_back(line);
      }
    }

    //save random adjective to a variable
    std::string word = firstName[rand() % firstName.size()];

    return word;
}

std::string getRandomLastName()
{
    // intializes the adjective vector & line
    std::vector<std::string> lastName;
    std::string line;

    //opens the adjective files to look into 
    std::ifstream file("lastNames.txt");
    
    // reads whole file
    while (!file.eof())
    {
      //iterators through file line by line
      while (std::getline(file, line))
      {
        //adds the adjective at that line to vector
        lastName.push_back(line);
      }
    }

    //save random adjective to a variable
    std::string word = lastName[rand() % lastName.size()];

    return word; 
}

std::string getRandomVibe()
{

    // intializes the vibes vector
    std::vector<std::string> theVibe;
    std::string line;

    //opens the adjective files to look into 
    std::ifstream file("enemyVibes.txt");
    
    // reads whole file
    while (!file.eof())
    {
      //iterators through file line by line
      while (std::getline(file, line))
      {
        //adds the adjective at that line to vector
        theVibe.push_back(line);
      }
    }

    //save random adjective to a variable
    std::string word = theVibe[rand() % theVibe.size()];

    return word;  
}

int getRandomDamage(std::string type)
{
    return 0;
}

bool getRandomDoesEnemyHaveItem(std::string type)
{
    return false;
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

Enemy::Enemy()
{  
    enemyType = getRandomEnemyType();
    setEnemyName();
    setEnemyVibe();
    setRandomStats(enemyType);
}

//copy constructor
Enemy::Enemy(const Enemy &prev)
{
    enemyType = prev.enemyType;
    enemyName = prev.enemyName;
    enemyVibe = prev.enemyVibe;
    enemyHealth = prev.enemyHealth;
    enemyDamage = prev.enemyDamage;
    enemyItem = prev.enemyItem;
}

void Enemy::setEnemyType()
{
    enemyType = getRandomEnemyType();
}

void Enemy::setEnemyName()
{
    std::string firstName = getRandomFirstName();
    std::string lastName = getRandomLastName();
    std::string adjective = getRandomAdjective();
    std::string type = enemyType;
    std::string fullName = "";

    //ensures random output
    int randomInt = 1 + (rand() % 100);
    
    if (randomInt <= 70 )
    {
        fullName = firstName + " " + lastName + " the " + adjective + " " + type; 
        enemyName = fullName;
        return;
    } 
    else if (randomInt >= 71 && randomInt <= 99)
    {
        fullName = "A " + adjective + " " + type + " named " + firstName + " " + lastName; 
        enemyName = fullName;
        return;
    }
    else
    {
        fullName = "A " + type + " who is " + adjective + " by the name of " + firstName + " " + lastName;
        enemyName = fullName;
        return;
    }
}

void Enemy::setEnemyVibe()
{
    enemyVibe = getRandomVibe();
}

//
void Enemy::setRandomStats(std::string type)
{
    int randomHealth = 1 + (rand() % 100);
    int randomDamage = 1 + (rand() % 100);
    int randomIfItem = 1 + (rand() % 100);

    if (type == "Skeleton King")
    {
        if (randomHealth <= 50)
        {
            enemyHealth = 100;
        }
        else if (randomHealth <= 85)
        {
            enemyHealth = 75;
        }
        else
        {
            enemyHealth = 50;
        }

        if (randomDamage <= 50)
        {
            enemyDamage = 20;
        }
        else if (randomDamage <= 85)
        {
            enemyDamage = 25;
        }
        else
        {
            enemyDamage = 30;
        }

        enemyItem = true;
        return;
    }
    else if (type == "Dragon")
    {
        if (randomHealth <= 50)
        {
            enemyHealth = 75;
        }
        else if (randomHealth <= 85)
        {
            enemyHealth = 50;
        }
        else
        {
            enemyHealth = 35;
        }

        if (randomDamage <= 50)
        {
            enemyDamage = 15;
        }
        else if (randomDamage <= 85)
        {
            enemyDamage = 30;
        }
        else
        {
            enemyDamage = 45;
        }

        enemyItem = true;
        return;
    }
    else if (type == "Kanye West from the past, the one used to Love")
    {
        if (randomHealth  <= 50)
        {
            enemyHealth = 5;
        }
        else if (randomHealth <= 85)
        {
            enemyHealth = 3;
        }
        else
        {
            enemyHealth = 2;
        }

        if (randomDamage <= 50)
        {
            enemyDamage = 2;
        }
        else if (randomDamage <= 85)
        {
            enemyDamage = 3;
        }
        else
        {
            enemyDamage = 1;
        }

        enemyItem = true;
        return;
    }
    else if (type == "Snake")
    {
        if (randomHealth <= 50)
        {
            enemyHealth = 2;
        }
        else if (randomHealth <= 85)
        {
            enemyHealth = 3;
        }
        else
        {
            enemyHealth = 4;
        }

        enemyDamage = 1;

        if (randomIfItem <= 95)
        {
            enemyItem = false;
        }
        else
        {
            enemyItem = true;
        }
        return;
    }
    else if (type == "Beautiful Bearded Dragon named Baby West")
    {
        enemyHealth = 999999;
        enemyDamage = 0;
        enemyItem = true;
        
    }
    else if (type == "Kanye West")
    {
        enemyHealth = 3;

        if (randomDamage <= 50)
        {
            enemyDamage = 1;
        }
        else
        {
            enemyDamage = 2;
        }

        enemyItem = true;
        return;
    }
    else if (type == "Goblin")
    {
        if (randomHealth <= 50)
        {
            enemyHealth = 2;
        }
        else if (randomHealth <= 85)
        {
            enemyHealth = 3;
        }
        else
        {
            enemyHealth = 4;
        }

        enemyDamage = 1;

        if (randomIfItem <= 95)
        {
            enemyItem = false;
        }
        else
        {
            enemyItem = true;
        }
        return;

    }
    else if (type == "Slimy Green Cube" )
    {
        if (randomHealth  <= 50)
        {
            enemyHealth = 5;
        }
        else if (randomHealth <= 85)
        {
            enemyHealth = 3;
        }
        else
        {
            enemyHealth = 2;
        }

        if (randomDamage <= 50)
        {
            enemyDamage = 4;
        }
        else if (randomDamage <= 85)
        {
            enemyDamage = 5;
        }
        else
        {
            enemyDamage = 1;
        }

        if (randomIfItem <= 75)
        {
            enemyItem = false;
        }
        else
        {
            enemyItem = true;
        }
        return;
    }
    else if (type == "Golem" )
    {
        if (randomHealth  <= 50)
        {
            enemyHealth = 20;
        }
        else if (randomHealth <= 85)
        {
            enemyHealth = 18;
        }
        else
        {
            enemyHealth = 16;
        }

        if (randomDamage <= 50)
        {
            enemyDamage = 4;
        }
        else if (randomDamage <= 85)
        {
            enemyDamage = 5;
        }
        else
        {
            enemyDamage = 1;
        }

        if (randomIfItem <= 75)
        {
            enemyItem = false;
        }
        else
        {
            enemyItem = true;
        }
    }
    else if (type == "Fish")
    {
        if (randomHealth  <= 50)
        {
            enemyHealth = 1;
        }
        else
        {
            enemyHealth = 2;
        }

        enemyDamage = 0;

        enemyItem = false;
        return;
    }
    else if (type == "Osmar Alvarez, SSN: 45-678-2234")
    {
        if (randomHealth  <= 50)
        {
            enemyHealth = 1;
        }
        else
        {
            enemyHealth = 2;
        }

        enemyDamage = 0;

        enemyItem = true;
        return;
    }
    else if (type == "Beetle")
    {
        if (randomHealth  <= 50)
        {
            enemyHealth = 20;
        }
        else if (randomHealth <= 85)
        {
            enemyHealth = 18;
        }
        else
        {
            enemyHealth = 16;
        }

        if (randomDamage <= 50)
        {
            enemyDamage = 4;
        }
        else if (randomDamage <= 85)
        {
            enemyDamage = 5;
        }
        else
        {
            enemyDamage = 3;
        }

        if (randomIfItem <= 95)
        {
            enemyItem = false;
        }
        else
        {
            enemyItem = true;
        }
        return;
    }
    else if (type == "Monkey" )
    {
        if (randomHealth  <= 50)
        {
            enemyHealth = 7;
        }
        else if (randomHealth <= 85)
        {
            enemyHealth = 9;
        }
        else
        {
            enemyHealth = 11;
        }

        if (randomDamage <= 50)
        {
            enemyDamage = 4;
        }
        else if (randomDamage <= 85)
        {
            enemyDamage = 5;
        }
        else
        {
            enemyDamage = 3;
        }

        if (randomIfItem <= 95)
        {
            enemyItem = false;
        }
        else
        {
            enemyItem = true;
        }
        return;
    }
    else if (type == "Pastel Painting")
    {
        if (randomHealth  <= 50)
        {
            enemyHealth = 2;
        }
        else if (randomHealth <= 85)
        {
            enemyHealth = 1;
        }
        else
        {
            enemyHealth = 3;
        }

        if (randomDamage <= 50)
        {
            enemyDamage = 4;
        }
        else if (randomDamage <= 85)
        {
            enemyDamage = 5;
        }
        else
        {
            enemyDamage = 3;
        }

        if (randomIfItem <= 55)
        {
            enemyItem = false;
        }
        else
        {
            enemyItem = true;
        }
        return;
    }
    else if (type == "Peanut Butter Baby")
    {
        if (randomHealth  <= 50)
        {
            enemyHealth = 2;
        }
        else
        {
            enemyHealth = 1;
        }

        enemyDamage = 0;
       
        if (randomIfItem <= 55)
        {
            enemyItem = false;
        }
        else
        {
            enemyItem = true;
        }
        return;
    }
    else if (type == "Normal Boot's cast of creators")
    {
        if (randomHealth  <= 50)
        {
            enemyHealth = 10;
        }
        else
        {
            enemyHealth = 11;
        }

        enemyDamage = 4;
       
        if (randomIfItem <= 30)
        {
            enemyItem = false;
        }
        else
        {
            enemyItem = true;
        }
        return;
    }
    else if (type == "Centipede")
    {
        if (randomHealth  <= 50)
        {
            enemyHealth = 10;
        }
        else if (randomHealth <= 85)
        {
            enemyHealth = 12;
        }
        else
        {
            enemyHealth = 15;
        }

        if (randomDamage <= 50)
        {
            enemyDamage = 4;
        }
        else if (randomDamage <= 85)
        {
            enemyDamage = 5;
        }
        else
        {
            enemyDamage = 3;
        }

        if (randomIfItem <= 98)
        {
            enemyItem = false;
        }
        else
        {
            enemyItem = true;
        }
        return;
    }
    else if (type == "Leech" )
    {
        if (randomHealth  <= 50)
        {
            enemyHealth = 8;
        }
        else if (randomHealth <= 85)
        {
            enemyHealth = 9;
        }
        else
        {
            enemyHealth = 7;
        }

        if (randomDamage <= 50)
        {
            enemyDamage = 1;
        }
        else if (randomDamage <= 85)
        {
            enemyDamage = 2;
        }
        else
        {
            enemyDamage = 3;
        }

        if (randomIfItem <= 90)
        {
            enemyItem = false;
        }
        else
        {
            enemyItem = true;
        }
    }
    else
    {
        if (randomHealth  <= 50)
        {
            enemyHealth = 8;
        }
        else if (randomHealth <= 85)
        {
            enemyHealth = 9;
        }
        else
        {
            enemyHealth = 7;
        }

        if (randomDamage <= 50)
        {
            enemyDamage = 1;
        }
        else if (randomDamage <= 85)
        {
            enemyDamage = 2;
        }
        else
        {
            enemyDamage = 3;
        }

        if (randomIfItem <= 10)
        {
            enemyItem = false;
        }
        else
        {
            enemyItem = true;
        }
    }
}

std::string Enemy::getEnemyType()
{
    return enemyType;
}

std::string Enemy::getEnemyName()
{
    return enemyName;
}

std::string Enemy::getEnemyVibe()
{
    return enemyVibe;
}

int Enemy::getEnemyHealth()
{
    return enemyHealth;
}

int Enemy::getEnemyDamage()
{
    return enemyDamage;
}

bool Enemy::getEnemyItem()
{
    return enemyItem;
}

void Enemy::printEnemyStats()
{
    //declares what type of enemy it is
    std::cout << "The enemy type is " << enemyType << "\n";

    // full name of an enemy
    std::cout << "The enemy name is " << enemyName << "\n";

    // how the enemy feels
    std::cout << "The enemy vibe is " << enemyVibe << "\n";

    //declares the health of enemy
    std::cout << "The enemy health is " << enemyHealth << "\n";

    //declares the damage that can be dealt by enemy
    std::cout << "The enemy health is " << enemyDamage << "\n";

    if (enemyItem)
    {
        std::cout << "The enemy has an item" << "\n";
    }
    else 
    {
        std::cout << "The enemy doesn't have an item" << "\n";
    }
}

void Enemy::EnemyTakingDamage(int damage)
{
    if (enemyHealth < damage) enemyHealth = 0;
    else enemyHealth -= damage;
    
}
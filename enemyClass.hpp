/*   enemyClass.hpp
*   
*    NOTES: [PLEASE WRITE ANYTHIGN OF NOTING WHETHER YOU ARE APOL OR NOT, LIST YOUR NAME THOUGH]
*    
*
*
*/

#ifndef ENEMYCLASS_H
#define ENEMYCLASS_H
#include <string>
#include <vector>

class Enemy {
private:
    //declares what type of enemy it is
    std::string enemyType;

    // full name of an enemy
    std::string enemyName;

    // how the enemy feels
    std::string enemyVibe;

    //declares the health of enemy
    int enemyHealth;

    //declares the damage that can be dealt by enemy
    int enemyDamage;

    // has an item
    bool enemyItem;

public:
    //constructor
    Enemy();

    //copy constructor
    Enemy(const Enemy &prev);

    //set enemy type
    void setEnemyType();

    //set enemy name
    void setEnemyName();

    //set enemy current vibe
    void setEnemyVibe();

    //sets all the random stats for an enemy type
    void setRandomStats(std::string type);

    //get enemy type
    std::string getEnemyType();

    //get enemy name
    std::string getEnemyName();

    //get enemy current vibe
    std::string getEnemyVibe();

    //get enemy health
    int getEnemyHealth();

    //get enemy damage output
    int getEnemyDamage();

    //get if enemy has an item
    bool getEnemyItem();

    //prints the enemy variables
    void printEnemyStats();

    // enemy taking damage
    void EnemyTakingDamage(int damage);
};

#endif
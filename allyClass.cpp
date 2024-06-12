/*   allyClass.hpp
*   
*    NOTES: [PLEASE WRITE ANYTHIGN OF NOTING WHETHER YOU ARE APOL OR NOT, LIST YOUR NAME THOUGH]
*
* 	 
*
*/

#include "allyClass.hpp"
#include <string>
#include <vector>
#include <unordered_map>

/*
	###############################################
	###############################################
	####### HELPER FUNCTIONS FOR THIS FILE ########
	###############################################
	###############################################
*/

int ALLY_NUM = 0;

std::string allyNameGenerator()
{ 
    std::string name = "Ally " + std::to_string(ALLY_NUM++);
    return name;
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

Ally::Ally()
{
    allyName = allyNameGenerator();
} 

Ally::Ally(std::string name)
{
    allyName = name;
}

// gets the ally name
std::string Ally::getAllyName()
{
    return allyName;
}

// set the ally name
void Ally::setAllyName(std::string name)
{
    allyName = name;
}


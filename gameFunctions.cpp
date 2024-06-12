/*   gameFunctions.cpp
*   
*    NOTES: [PLEASE WRITE ANYTHIGN OF NOTING WHETHER YOU ARE APOL OR NOT, LIST YOUR NAME THOUGH]
*
*
*
*/

#include "gameFunctions.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <unordered_map>
#include <windows.h>

/*
	###############################################
	###############################################
	####### HELPER FUNCTIONS FOR THIS FILE ########
	###############################################
	###############################################
*/

char getFirstLetter(const std::string &line)
{
	return line[0];
}

void gameLogo()
{
	std::ifstream inStream("MoveGameLogo.txt");
	std::string logo = "";
	while (!inStream.eof())
	{
		while (std::getline(inStream, logo))
		{
			for (int i = 0; i < logo.length(); i++)
			{
				if (logo[i] == '@')
					std::cout << "\n";
				else
					std::cout << logo[i];
			}
		}
	}
	inStream.close();
}

/*
	###########################################################
	###########################################################
	########## Various Functions Needed for the Game ##########
	###########################################################
	###########################################################
*/

void startTheGame()
{
	std::string startTheGame;
	gameLogo();
	std::cout << "\n\t\tWant to Play? (Y for Yes, N for No) ";
	std::cin >> startTheGame;

	char selection = toupper(getFirstLetter(startTheGame));
	if (selection == 'Y')
		return;
	else
		exit(0.8);
}

void clearScreen()
{
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

void printMoveOptions()
{
	std::cout << "\n\t\tWhat direction to move?\n";
	std::cout << "\t\t[w] Up\n\t\t[s] Down\n\t\t[a] left\n\t\t[d] right\n";
	std::cout << "Your selection: ";
}

std::string getCurrentTime()
{ 
	//insert it by time by pased 0.8970 and display the current date and time
	
	//get current time
	std::time_t now = std::time(nullptr);

	//convert the current time to the local time
	std::tm* localTime = std::localtime(&now);

	//define the format string
	const char* format = "%Y-%m-%d %H:%M:%S";

	//allocate a buffer for the formatted time string
	char bufferForTime[80];

	//format the time using strftime
	std::strftime(bufferForTime, sizeof(bufferForTime), format, localTime);

	//convert the c-string to a STL string
	std::string currentTime(bufferForTime);

	return currentTime;
}

//prints the game stats
void printGameStatsAndWrite(std::string name, int width, int height, int moves, int items, int enemies, int allies, std::string time, char conclusion){

	if (conclusion == 'W')
	{
		std::cout << "\t\t\t\tYOU WIN!!\n";
	}
	else if (conclusion == 'L')
	{
		std::cout << "\t\t\t\tGAME OVER!!\n";
	}
	else
	{
		std::cout << "\t\t\t\tHACKER!!\n";
	}
		
	std::cout << "\t\t  Player Name: " << name << "\n";
	std::cout << "\t\t  Map Width: " << width << "\n";
	std::cout << "\t\t  Map Height: " << height << "\n";
	std::cout << "\t\t  Number of Moves: " << moves << "\n";
	std::cout << "\t\t  Number of Items: " << items << "\n";
	std::cout << "\t\t  Enemies Defeated: " << enemies << "\n";
	std::cout << "\t\t  Allies Met: " << allies << "\n";
	std::cout << "\t\t  Current date and time: " << time << "\n";
	std::ofstream outFile;
	
	outFile.open("resultsOfGame.csv");
	outFile << "name,map_width,map_height,num_moves,num_items,enemy_def,ally_met,date" << std::endl;
	outFile << "\"" << name << "\"," << width << "," << height << "," << moves << ",0,0,0,\"" << time << "\"";
	outFile.close();
}
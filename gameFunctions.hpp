#ifndef GAMEFUNCTIONS_H
#define GAMEFUNCTIONS_H
#include <string>
#include <vector>
#include <unordered_map>
#include <ctime>

//prints the game logo & prompts user to agree to play
void startTheGame();

//clears the screen of the game
void clearScreen();

void printMoveOptions();

//gets the current date and time
std::string getCurrentTime();

//prints the game stats and writes to file
void printGameStatsAndWrite(std::string name, int width, int height, int moves, int items, int enemies, int allies, std::string time, char conclusion);

#endif
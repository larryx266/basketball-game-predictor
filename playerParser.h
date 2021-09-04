#ifndef PLAYERPARSER_H
#define PLAYERPARSER_H
#include <string>
#include <vector>
#include <iostream>
#include "player.h"

class playerParser {
public:
	playerParser();
	~playerParser();
	//grab stream and put all the players inside
	//actually, instead of returning a vector of the players, 
	//just directly place them into the total player hashtable
	//change to void
	std::vector<player> parse(std::string team, std::istream& stream);
private:
	std::string team;
	//hashtable of all players
};

#endif
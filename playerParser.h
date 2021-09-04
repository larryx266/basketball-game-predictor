#ifndef PLAYERPARSER_H
#define PLAYERPARSER_H
#include <string>
#include <vector>
#include <iostream>
#include "hashtable.h"

class playerParser {
public:
	playerParser();
	~playerParser();
	//grab stream and put all the players inside
	void parse(std::string team, hashtable* players, std::istream& stream);
private:
	std::string team;
	//hashtable of all players
	//hashtable allPlayers;
};

#endif
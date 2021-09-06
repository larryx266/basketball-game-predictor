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
	//grab players from stream and dump inside hashtable
	void parse(std::string team, hashtable<player>* players, std::istream& stream);
private:
	std::string team;
	//hashtable of all players
	//hashtable allPlayers;
};

#endif
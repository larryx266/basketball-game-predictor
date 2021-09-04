#ifndef PLAYERPARSER_H
#define PLAYERPARSER_H
#include <string>
#include <vector>
#include <iostream>
#include "player.h"

class playerParser {
public:
	//grab stream and put all the players inside
	std::vector<player> parse(std::string team, std::istream& stream);
private:
	std::string team;
};

#endif
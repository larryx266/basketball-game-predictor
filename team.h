#ifndef TEAM_H
#define TEAM_H
#include <string>
#include <vector>
#include "hashtable.h"

class team {
public:
    team();
	team(std::string name);
	~team();
	void addPlayer(player* player);
	hashtable getAllPlayers();

private:
	std::string name;
    std::string coach;
    hashtable players;
};
#endif
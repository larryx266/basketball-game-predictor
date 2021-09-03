#ifndef TEAM_H
#define TEAM_H
#include <string>
#include <vector>
#include "player.h"

class team {
public:
    team();
	team(std::string name);
	~team();
	void addPlayer(player plyr);
	std::vector<player> getAllPlayers();

private:
	std::string name;
    std::string coach;
    std::vector<player> players;
};
#endif
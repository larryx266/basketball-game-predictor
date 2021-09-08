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
	hashtable<player>* getAllPlayers();
	player* getPlayer(std::string name);
	std::vector<std::string> getRoster();

private:
	std::string name;
    std::string coach;
    hashtable<player>* players;
};
#endif
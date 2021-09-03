#include "team.h"

using namespace std;

team::team() {
	name = "kekw";
}

team::team(string name) {
	this->name = name;
}

team::~team() { }

void team::addPlayer(player plyr) {
	players.push_back(plyr);
}

std::vector<player> team::getAllPlayers() {
	return players;
}
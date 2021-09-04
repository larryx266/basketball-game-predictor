#include "team.h"

using namespace std;

team::team() {
	players = hashtable(false, 1);
	name = "Empty";
}

team::team(string name) {
	players = hashtable(false, 1);
	this->name = name;
}

team::~team() { }

void team::addPlayer(player* player) {
	players.add(player->getName(), player);
}

hashtable team::getAllPlayers() {
	return players;
}
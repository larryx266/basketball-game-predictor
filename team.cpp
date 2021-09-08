#include "team.h"
#include "hashtable.h"

using namespace std;

team::team() {
	//auto use quadratic probing for collision resolution
	players = new hashtable<player>(false, 1);
	name = "Empty";
}

team::team(string name) {
	players = new hashtable<player>(false, 1);
	this->name = name;
}

team::~team() { 
	delete players;
}

void team::addPlayer(player* player) {
	players->add(player->getName(), player);
}

hashtable<player>* team::getAllPlayers() {
	return players;
}

player* team::getPlayer(string name) {
	return players->getValue(name);
}

vector<string> team::getRoster() {
	return players->getAllKeys();
}
#include "team.h"

using namespace std;

team::team() {
	//auto use quadratic probing for collision resolution
	players = new hashtable(false, 1);
	name = "Empty";
}

team::team(string name) {
	players = new hashtable(false, 1);
	this->name = name;
}

team::~team() { 
	delete players;
}

void team::addPlayer(player* player) {
	players->add(player->getName(), player);
}

hashtable* team::getAllPlayers() {
	return players;
}

player* team::getPlayer(string name) {
	return players->getPlayer(name);
}
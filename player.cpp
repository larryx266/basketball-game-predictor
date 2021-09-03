#include "player.h"
#include <iostream>
using namespace std;

player::player(string team, string name, int age, double heightcm, double bmi, 
        int games, double points, double rebounds, double assists, double wowFactor,
		double turnovers, double steals, double blocks, double fgPercent) {
		this->team = team;
		this->name = name;
		this->age = age;
		this->heightcm = heightcm;
		this->bmi = bmi;
		this->games = games;
		this->points = points;
		this->rebounds = rebounds;
		this->assists = assists;
		this->wowFactor = wowFactor;
		this->turnovers = turnovers;
		this->steals = steals;
		this->blocks = blocks;
		this->fgPercent = fgPercent;
		updateStats();
}

player::~player() { }

void player::changeTeam(string team) {
	this->team = team;
}

void player::setStats(vector<string> statNames, vector<double> statChanges) {
	for (int i = 0; i < statNames.size(); i++) {
		//just call statNames[i] on hashtable to change 
		if (statNames[i] == "age") age = statChanges[i];
		if (statNames[i] == "heightcm") heightcm = statChanges[i];
		if (statNames[i] == "bmi") bmi = statChanges[i];
		if (statNames[i] == "games") games = statChanges[i];
		if (statNames[i] == "points") points = statChanges[i];
		if (statNames[i] == "rebounds") rebounds = statChanges[i];
		if (statNames[i] == "assists") assists = statChanges[i];
		if (statNames[i] == "wowFactor") wowFactor = statChanges[i];
		if (statNames[i] == "turnovers") turnovers = statChanges[i];
		if (statNames[i] == "steals") steals = statChanges[i];
		if (statNames[i] == "blocks") blocks = statChanges[i];
		if (statNames[i] == "fgPercent") fgPercent = statChanges[i];
	}
	updateStats();
}

void player::updateStats() {
	if (stats.empty()){
		stats.push_back(age);
		stats.push_back(heightcm);
		stats.push_back(bmi);
		stats.push_back(games);
		stats.push_back(points);
		stats.push_back(rebounds);
		stats.push_back(assists);
		stats.push_back(wowFactor);
		stats.push_back(turnovers);
		stats.push_back(steals);
		stats.push_back(blocks);
		stats.push_back(fgPercent);
	}
	else {
		stats[0] = age;
		stats[1] = heightcm;
		stats[2] = bmi;
		stats[3] = games;
		stats[4] = points;
		stats[5] = rebounds;
		stats[6] = assists;
		stats[7] = wowFactor;
		stats[8] = turnovers;
		stats[9] = steals;
		stats[10] = blocks;
		stats[11] = fgPercent;
	}
}

void player::computeAggregate() {
	if (age < 25) aggregate -= 0.75 * age;
	else if (age > 32) aggregate -= 2 * (age - 32);
	if (heightcm < 198) aggregate -= 1 * (198 - heightcm);
	aggregate += games / 4;
	aggregate += points * fgPercent;
	aggregate += rebounds + assists;
	aggregate -= 3 * turnovers;
	aggregate += 3 * steals;
	aggregate += 7 * blocks;
	aggregate *= wowFactor;
}

double player::getAggregate() {
	return aggregate;
}

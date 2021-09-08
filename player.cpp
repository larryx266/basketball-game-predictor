#include "player.h"
#include <iostream>
using namespace std;

player::player(string team, string name, int age, double heightcm, double bmi, 
        int games, double points, double rebounds, double assists, double wowFactor,
		double turnovers, double steals, double blocks, double fgPercent) {
	this->team = team;
	this->name = name;
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

	computeAggregate();
}

player::~player() { }

void player::changeTeam(string team) {
	this->team = team;
}

void player::setStats(vector<string> statNames, vector<double> statChanges) {
	for (unsigned int i = 0; i < statNames.size(); i++) {
		//just call statNames[i] on hashtable to change 
		if (statNames[i] == "age") stats[0] = statChanges[i];
		if (statNames[i] == "heightcm") stats[1] = statChanges[i];
		if (statNames[i] == "bmi") stats[2] = statChanges[i];
		if (statNames[i] == "games") stats[3] = statChanges[i];
		if (statNames[i] == "points") stats[4] = statChanges[i];
		if (statNames[i] == "rebounds") stats[5] = statChanges[i];
		if (statNames[i] == "assists") stats[6] = statChanges[i];
		if (statNames[i] == "wowFactor") stats[7] = statChanges[i];
		if (statNames[i] == "turnovers") stats[8] = statChanges[i];
		if (statNames[i] == "steals") stats[9] = statChanges[i];
		if (statNames[i] == "blocks") stats[10] = statChanges[i];
		if (statNames[i] == "fgPercent") stats[11] = statChanges[i];
	}
	computeAggregate();
}

void player::computeAggregate() {
	//age
	if (stats[0] < 25) aggregate -= 0.75 * stats[0];
	else if (stats[0] > 32) aggregate -= 2 * (stats[0] - 32);
	//height
	if (stats[1] < 198) aggregate -= 1 * (198 - stats[1]);
	//games
	aggregate += stats[3] / 4;
	//points * field goal percentage
	aggregate += stats[4] * stats[11];
	//rebounds + assists
	aggregate += stats[5] + stats[6];
	//turnovers
	aggregate -= 3 * stats[8];
	//steals
	aggregate += 3 * stats[9];
	//blocks
	aggregate += 7 * stats[10];
	//wow factor
	aggregate *= stats[7];
}

double player::getAggregate() {
	return aggregate;
}

string player::getName() {
	return name;
}

string player::getTeam() {
	return team;
}

vector<double> player::getStats() {
	return stats;
}
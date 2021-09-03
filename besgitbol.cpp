#include "player.h"
//#include "team.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main () {
	string name;
	string team;
	int age;
    double heightcm;
    double bmi;
    int games;
    double points;
    double rebounds;
    double assists;
    double wowFactor;
    double turnovers;
    double steals;
    double blocks;
    double fgPercent;

	cout << "Enter Player name then team, separated by new line" << endl;
	cin >> name;
	cin >> team;

	cout << "Enter player stats, separated by new line" << endl;
	cin >> age;
	cin >> heightcm;
	cin >> bmi;
	cin >> games;
	cin >> points;
	cin >> rebounds;
	cin >> assists;
	cin >> wowFactor;
	cin >> turnovers;
	cin >> steals;
	cin >> blocks;
	cin >> fgPercent;

	player giannis = player(team, name, age, heightcm, bmi, games, points, rebounds, assists, wowFactor,
						turnovers, steals, blocks, fgPercent);
	
	double score;
	giannis.computeAggregate();
	score = giannis.getAggregate();
	cout << score << endl;

	return 0;
}

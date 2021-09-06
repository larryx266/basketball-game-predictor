#include "playerParser.h"

using namespace std;

playerParser::playerParser() { }

playerParser::~playerParser() { }

//pass in hashtable pointer
//make players out of the streams, and hash them in
void playerParser::parse(string team, hashtable<player>* players, istream& stream) {
	this->team = team;
	string curr;
	while (getline(stream, curr)) {
		//start a new player
		if (curr == "<player>") {
			string name;
			int age, games;
    		double heightcm, bmi, points, rebounds, assists, wowFactor,
					turnovers, steals, blocks, fgPercent;
			getline(stream, name);
			getline(stream, curr);
			age = stoi(curr);
			getline(stream, curr);
			heightcm = stod(curr);
			getline(stream, curr);
			bmi = stod(curr);
			getline(stream, curr);
			games = stoi(curr);
			getline(stream, curr);
			points = stod(curr);
			getline(stream, curr);
			rebounds = stod(curr);
			getline(stream, curr);
			assists = stod(curr);
			getline(stream, curr);
			wowFactor = stod(curr);
			getline(stream, curr);
			turnovers = stod(curr);
			getline(stream, curr);
			steals = stod(curr);
			getline(stream, curr);
			blocks = stod(curr);
			getline(stream, curr);
			fgPercent = stod(curr);
			player* currPlayer = new player(team, name, age, heightcm, bmi, games, points, 
					rebounds, assists, wowFactor, turnovers, steals, blocks, fgPercent);
			players->add(name, currPlayer);
		}
	}
}
#include "player.h"
#include "team.h"
#include "hashtable.h"
#include "playerParser.h"
#include <iostream>
#include <iomanip>

using namespace std;

//type make
//then ./bin/besgitbol "Milwaukee Bucks.txt" "Golden State Warriors.txt" "hashtable dump test.txt"
//capitalization matters
//type make clean to clear executables

//run for team generation + comparison
//need to upload teams manually

//currently sums aggregates -> want to implement linear regression to predict + consider more stats

int main(int argc, char *argv[])
{
	srand(time(0));
	if (argc < 4)
	{
		cout << "Enter 2 Team Rosters, followed by a File Dump Location" << endl;
		return -1;
	}

	ifstream stream;
	playerParser parser = playerParser();

	stream.open(argv[1]);
	team bucks = team("Milwaukee Bucks");
	parser.parse("Milwaukee Bucks", bucks.getAllPlayers(), stream);
	stream.close();
	vector<string> bucksPlayers = bucks.getRoster();
	//cout << "Bucks" << endl;
	double bucksAggregate = 0;
	for (unsigned int i = 0; i < bucksPlayers.size(); i++)
	{
		//cout << bucksPlayers[i] << " Aggregate: " << bucks.getPlayer(bucksPlayers[i])->getAggregate() << endl;
		bucksAggregate += bucks.getPlayer(bucksPlayers[i])->getAggregate();
	}
	//cout << endl;

	stream.open(argv[2]);
	team warriors = team("Golden State Warriors");
	parser.parse("Golden State Warriors", warriors.getAllPlayers(), stream);
	vector<string> warriorsPlayers = warriors.getRoster();
	//cout << "Warriors" << endl;
	double warriorsAggregate = 0;
	for (unsigned int i = 0; i < warriorsPlayers.size(); i++)
	{
		//cout << warriorsPlayers[i] << " Aggregate: " << warriors.getPlayer(warriorsPlayers[i])->getAggregate() << endl;
		warriorsAggregate += warriors.getPlayer(warriorsPlayers[i])->getAggregate();
	}

	if (warriorsAggregate > bucksAggregate) {
		cout << "Warriors are favored to win" << endl;
	}

	else if (warriorsAggregate < bucksAggregate) {
		cout << "Bucks are favored to win" << endl;
	}

	else {
		cout << "Too close to call" << endl;
	}

	ofstream dump;
	dump.open(argv[3]);
	dump << "Bucks:\n";
	bucks.getAllPlayers()->reportAll(dump);
	dump << "Warriors:\n";
	warriors.getAllPlayers()->reportAll(dump);

	return 0;
}

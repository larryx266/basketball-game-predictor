#include "player.h"
#include "team.h"
#include "hashtable.h"
#include "playerParser.h"
#include <iostream>
#include <iomanip>

using namespace std;

//type make
//then ./bin/besgitbol "Milwaukee Bucks.txt" "hashtable dump test.txt"
//capitalization matters
//type make clean to clear executables

//run for team generation + comparison
//need to upload teams manually

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
	cout << "Bucks" << endl;
	for (unsigned int i = 0; i < bucksPlayers.size(); i++)
	{
		cout << bucksPlayers[i] << " Aggregate: " << bucks.getPlayer(bucksPlayers[i])->getAggregate() << endl;
	}
	cout << endl;

	stream.open(argv[2]);
	team warriors = team("Golden State Warriors");
	parser.parse("Golden State Warriors", warriors.getAllPlayers(), stream);
	vector<string> warriorsPlayers = warriors.getRoster();
	cout << "Warriors" << endl;
	for (unsigned int i = 0; i < warriorsPlayers.size(); i++)
	{
		cout << warriorsPlayers[i] << " Aggregate: " << warriors.getPlayer(warriorsPlayers[i])->getAggregate() << endl;
	}

	ofstream dump;
	dump.open(argv[2]);
	bucks.getAllPlayers()->reportAll(dump);
	warriors.getAllPlayers()->reportAll(dump);

	return 0;
}

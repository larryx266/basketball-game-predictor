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

int main (int argc, char* argv[]) {
	if (argc < 3) {
		cout << "Enter a Team Roster and File Dump Location" << endl;
		return -1;
	}

	ifstream stream;
	stream.open(argv[1]);
	team bucks = team("Milwaukee Bucks");
	playerParser parser = playerParser();
	parser.parse("Milwaukee Bucks", bucks.getAllPlayers(), stream);
	cout << "Giannis Aggregate: " << bucks.getPlayer("Giannis Antetokounmpo")->getAggregate() << endl;
	cout << "Khris Aggregate: " << bucks.getPlayer("Khris Middleton")->getAggregate() << endl;

	ofstream dump;
	dump.open(argv[2]);
	bucks.getAllPlayers()->reportAll(dump);

	return 0;
}

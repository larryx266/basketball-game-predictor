#include "playerParser.h"

using namespace std;

playerParser::playerParser() { }

playerParser::~playerParser() { }

vector<player> playerParser::parse(string team, istream& stream) {
	this->team = team;
}
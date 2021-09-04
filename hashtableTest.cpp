#include "player.h"
#include "hashtable.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main (int argc, char* argv[]) {
	vector<double> x;
	ofstream stream(argv[1]);
	x.push_back(2);
	x.push_back(33);
	hashtable h = hashtable(false, 0);
	h.add("giannis", x);
	x.push_back(100);
	h.add("kek", x);
	vector<double> y;
	h.reportAll(stream);
	return 0;
}

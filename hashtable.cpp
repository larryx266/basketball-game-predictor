#include "hashtable.h"

using namespace std;

hashtable::hashtable(bool debug, unsigned int probing){
	//initializing everything
	this->debug = debug;
	probingType = probing;
	size = 11;
	numItems = 0;
	loadFactor = 0;

	data = new pair<string, player*>[11];
	resizeIndex = 1;

	for (int i = 0; i < 11; i++){
		data[i].first = "";
	}

	if (debug){
		randomNums[0] = 983132572;
		randomNums[1] = 62337998;
		randomNums[2] = 552714139;
		randomNums[3] = 984953261;
		randomNums[4] = 261934300;
	}

	else{
		for (int i = 0; i < 5; i++){
			randomNums[i] = rand() % 11;
		}
	}
}

hashtable::~hashtable(){ 
	delete[] data;
}

//run this as update() too
void hashtable::add(string name, player* player){
	//asking find() for where to put it, and if it exists
	pair<bool, int> result = find(name);
	
	data[result.second].first = name;
	data[result.second].second = player;

	if(!result.first){
		numItems++;
		loadFactor = (double) numItems / (double) size;
		if (loadFactor >= 0.5) resize();
	}
}

player* hashtable::getPlayer(string name){
	//asking find for the string
	pair<bool, int> result = find(name);

	//if player doesn't exist, return null
	if (!result.first) return NULL;

	return data[result.second].second;
}

void hashtable::reportAll(ostream& ofile) const{
	//simple ostream dump into parser format
	int count = 0;
	for (int i = 0; i < size; i++){
		if (count == numItems){
			break;
		}
		if (data[i].first != ""){
			count++;
			ofile << "<player>" << endl << data[i].first << endl;
			vector<double> stats = data[i].second->getStats();
			for (unsigned int j = 0; j < stats.size(); j++) {
				ofile << stats[j] << endl;
			}
			ofile << "</player>" << endl << endl;
		}
	}
}

void hashtable::resize() {
	//creating a new "hashtable" and rehashing
	int oldSize = size;
	size = resizingSizes[resizeIndex];
	resizeIndex++;

	if (!debug){
		for (int i = 0; i < 5; i++){
			randomNums[i] = rand() % size;
		}
	}

	pair<string, player*>* oldData = data;
	pair<string, player*>* temp = new pair<string, player*>[size];
	data = temp;

	for (int i = 0; i < size; i++){
		data[i].first = "";
	}
	
	//rehashing process
	int count = 0;
	for (int i = 0; i < oldSize; i++){
		//if we have done every word, no need to keep checking
		if (count == numItems){
			break;
		}
		if (oldData[i].first != ""){
			count++;
			pair<bool, int> result = find(oldData[i].first);
			data[result.second] = make_pair(oldData[i].first, oldData[i].second);
		}
		//new comment: once again, my geniosity astounds me; that logic is crazy
	}

	delete[] oldData;
	loadFactor = (double) numItems / (double) size;
}

int hashtable::hash(string k) const{
	//doing the a1 r1 and w1 method that was requested
	int stringSize = k.size();
	int w[5];
	int counter = 4;
	for (int i = stringSize - 1; i > -1; i -= 6){
		int a[6];
		for (int j = 5; j > -1; j--){
			if (i - j < 0){
				a[5 - j] = 0;
			}
			else{
				a[5 - j] = k[i - j] - 97;
			}
		}
		w[counter] = 26*26*26*26*26*a[0] + 26*26*26*26*a[1] + 
					 26*26*26*a[2] + 26*26*a[3] + 26*a[4] + a[5];
		counter--;
	}

	for (int i = 0; i <= counter; i++){
		w[i] = 0;
	}

	long long result = 0;

	for (int i = 0; i < 5; i++){
		result += (long long) (randomNums[i] % size) * (long long) w[i];
	}

	result = result % size;

	return (int) result;
}

int hashtable::doubleHash(string k) const{
	//doing the double hash function that was requested
	int stringSize = k.size();
	int w[5];
	int counter = 4;
	for (int i = stringSize - 1; i > -1; i -= 6){
		int a[6];
		for (int j = 5; j > -1; j--){
			if (i - j < 0){
				a[5 - j] = 0;
			}
			else{
				a[5 - j] = k[i - j] - 97;
			}
		}
		w[counter] = 26*26*26*26*26*a[0] + 26*26*26*26*a[1] + 
					 26*26*26*a[2] + 26*26*a[3] + 26*a[4] + a[5];
		counter--;
	}

	for (int i = 0; i <= counter; i++){
		w[i] = 0;
	}

	long long result = 0;

	for (int i = 0; i < 5; i++){
		result += (long long) w[i];
	}

	result = result % secondHashPrimes[resizeIndex - 1];
	result = secondHashPrimes[resizeIndex - 1] - result;

	return (int) result;
}

//true = found in table
//int is the index
pair<bool, int> hashtable::find(string k){
	//if the initial hash is empty or the desired string, done
	int h = hash(k);
	if (data[h].first == ""){
		return make_pair(false, h);
	}

	if (data[h].first == k){
		return make_pair(true, h);
	}

	//otherwise, do the probing types accordingly to check further down
	if (probingType == 0){
		for (int i = 1; i < size; i++){
			if (data[(h + i) % size].first == ""){
				return make_pair(false, (h + i) % size);
			}
			else if (data[(h + i) % size].first == k){
				return make_pair(true, (h + i) % size);
			}
		}
	}

	else if (probingType == 1){
		for (int i = 1; i < size; i++){
			if (data[(h + (i * i)) % size].first == ""){
				return make_pair(false, (h + (i * i)) % size);
			}
			else if (data[(h + (i * i)) % size].first == k){
				return make_pair(true, (h + (i * i)) % size);
			}
		}
	}
	
	else if (probingType == 2){
		int dh = doubleHash(k);
		for (int i = 1; i < size; i++){
			if (data[(h + (i * dh)) % size].first == ""){
				return make_pair(false, (h + (i * dh)) % size);
			}
			else if (data[(h + (i * dh)) % size].first == k){
				return make_pair(true, (h + (i * dh)) % size);
			}
		}
	}
	
	//never hits, but compiler was complaining that I might never return
	return make_pair(true, 0);
}
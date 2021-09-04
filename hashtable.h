#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <cstdlib>
#include <cstddef>
#include <iostream>
#include <utility>
#include <string>
#include <fstream>
#include <vector>

class hashtable {
public:
    //can drop debug mode but it might be a resume boost thing
    hashtable(bool debug = false, unsigned int probing = 0);
    ~hashtable();

    //v1.0 adds string with value 1 to the hashtable, if it already exists
    //increment its value by 1
    //v2.0 hash based on name, keep a vector of stats -> might want to do arrays 
    //but that's fixed
    void add(std::string k, std::vector<double> stats);

    //v1.0 (count) returns the value of the string, if could not find, return 0
    //v2.0 if you end up changing to array, returning is gonna need to be different
    vector<double> getStats(std::string k);

    //puts everything in a file
    void reportAll(std::ostream& ofile) const;

private:
    //resizes the array
    void resize();

    //primary hash function
    int hash(std::string k) const;

    //secondary hash function for double hashing
    int doubleHash(std::string k) const;

    //basically all other functions call this, 
    //returns <whether or not it was found, the index location>
    //note: if it was not found, the index location is where it should be placed
    //new comment: bro my brain was so fucking big when I wrote that 
    std::pair<bool, int> find(std::string k);

    //linear probing, quadratic probing, or double hashing
    unsigned int probingType;
    
    bool debug;

    //the random numbers - to be generated/decided later
    int randomNums[5];

    //below 2 are the primes requested by the assignment
    //hashtable resizing sizes
    int resizingSizes[28] = {11, 23, 47, 97, 197, 397, 797, 1597, 
							3203, 6421, 12853, 25717, 51437, 102877, 
							205759, 411527, 823117, 1646237, 3292489, 
							6584983, 13169977, 26339969, 52679969, 105359969, 
							210719881, 421439783, 842879579, 1685759167};
    
    //double hash primes
    int secondHashPrimes[28] = {7, 19, 43, 89, 193, 389, 787, 1583, 3191, 
							    6397, 12841, 25703, 51431, 102871, 205721, 
								411503, 823051, 1646221, 3292463, 6584957, 
								13169963, 26339921, 52679927, 105359939, 210719881, 
								421439749, 842879563, 1685759113};
    //keeps track of where in the above size 28 arrays we are at
    int resizeIndex;

    //current hashtable size, ie: 11, 23, 47...
    int size;

    //how many items are currently in the hashtable
    int numItems;

    double loadFactor;

    //the "hashtable"
    //<name, vector of stats>
    std::pair<std::string, std::vector<double>* data;
};
#endif
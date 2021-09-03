#include <string>
#include <vector>

class player {
public:
    player();
    vector <double> getStats();

private:
    std::string team;
    double weightedInjury;
    double heightcm;
    double weight;
};
#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>

class player {
public:
    player(std::string team, std::string name, int age, double heightcm, double weight, 
        int games, double points, double rebounds, double assists);

    void changeTeam(std::string team);
    vector <double> getStats();
    //vector <double> setStats();
    ~player();
private:
    std::string team;
    //double weightedInjury;
    std::string name;
    int age;
    double heightcm;
    double weight;
    int games;
    double points;
    double rebounds;
    double assists;
    //double fgPercent;
    //double fg3Percent;
    //double per;
};
#endif
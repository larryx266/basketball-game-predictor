#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>

class player {
public:
    player(std::string team, std::string name, int age, double heightcm, double bmi, 
        int games, double points, double rebounds, double assists, double wowFactor,
        double turnovers, double steals, double blocks, double fgPercent);
    ~player();
    void changeTeam(std::string team);
    std::vector<double> getStats();
    //after converting to hashtables, we can directly use vector statNames to look up and change stats 
    void setStats(std::vector<std::string> statNames, std::vector<double> statChanges);
    void updateStats();
    void computeAggregate();
    double getAggregate();

private:
    double aggregate = 0;
    std::string team;
    //double weightedInjury;
    std::string name;
    int age;
    double heightcm;
    double bmi;
    int games;
    double points;
    double rebounds;
    double assists;
    double wowFactor;
    double turnovers;
    double steals;
    double blocks;
    double fgPercent;
    std::vector<double> stats;
    //double fg3Percent;
    //double per;
};






#endif
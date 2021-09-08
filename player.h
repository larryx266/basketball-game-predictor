#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>

class player {
public:
    //player will be automatically made through parser, no default constructor
    player(std::string team, std::string name, int age, double heightcm, double bmi, 
        int games, double points, double rebounds, double assists, double wowFactor,
        double turnovers, double steals, double blocks, double fgPercent);
    ~player();

    //changes team of player
    void changeTeam(std::string team);

    //gets all stats, excluding aggregate
    std::vector<double> getStats();

    //manually set specific stats
    void setStats(std::vector<std::string> statNames, std::vector<double> statChanges);

    double getAggregate();
    std::string getName();
    std::string getTeam();

private:
    void computeAggregate();
    double aggregate = 0;
    std::string team;
    std::string name;

    //age, height, bmi, games, points, rebounds, assists,
    //wow factor, turnovers, steals, blocks, field goal percent
    std::vector<double> stats;

    //double weightedInjury;
    //double fg3Percent;
    //double per;
};

#endif
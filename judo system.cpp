#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include <cctype>
#include <cstdlib>

using namespace std;

const int MAX_PRIVATE_HOURS_PER_WEEK = 5;

struct Athlete {
    int id;
    string name;
    string trainingPlan;
    double currentWeight;
    string competitionWeightCategory;
    int competitionsThisMonth;
    int privateHours;
    double weeklyFee;
    double privateCost;
    double competitionCost;
    double totalCost;
};

class JudoSystemManager {
private:
    vector<Athlete> athleteDatabase;
    int nextId = 1;

    double getPlanFee(const string& plan) const {
        string p = plan;

        transform(
            p.begin(),
            p.end(),
            p.begin(),
            [](unsigned char c) {
                return static_cast<char>(tolower(c));
            }
        );

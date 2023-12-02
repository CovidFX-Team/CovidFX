// Header file for Country class

#ifndef COUNTRY_H
#define COUNTRY_H


#include <string>

using namespace std;

class Country {
private:
    string countryName;
    double deathsPerCaseScale; // for a rating, used by taking total deaths per million/total cases per million/total times 100
    int GDP, totalCasesPerMillion, totalDeathsPerMillion;

public:
    Country(string countryName, int GDP, int totalCasesPerMillion, int totalDeathsPerMillion) {
        this->countryName = countryName;
        this->GDP = GDP;
        this->totalCasesPerMillion = totalCasesPerMillion;
        this->totalDeathsPerMillion = totalDeathsPerMillion;
        this->deathsPerCaseScale = (double)(totalDeathsPerMillion / totalCasesPerMillion) * 100;
    }

    string getName() {return countryName;}
    int getGDP() {return GDP;}
    int getCases() {return totalCasesPerMillion;}
    int getDeaths() {return totalDeathsPerMillion;}
    double getDeathsPerCase() {return deathsPerCaseScale;}
};

# endif // COUNTRY_H

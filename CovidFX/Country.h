#include <string>

using namespace std;

class Country
{
public:
	string countryName;
	double deathsPerCaseScale;//for a rating, used by taking total deaths per million/total cases per million/total times 100
	int GDP, totalCasesPerMillion, totalDeathsPerMillion;
	Country(string countryName, int GDP, int totalCasesPerMillion, int totalDeathsPerMillion);
	
};
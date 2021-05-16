#include <iostream>
#include <cmath>
using namespace std;

int main() {

	const double LARGE_PIZZA_COST = 14.68;
	const double MEDIUM_PIZZA_COST = 11.48;
	const double SMALL_PIZZA_COST = 7.28;
	const int PEOPLE_FED_LARGE = 7;
	const int PEOPLE_FED_MEDIUM = 3;
	const int PEOPLE_FED_SMALL = 1;
	const int RADIUS_LARGE = 10;
	const int RADIUS_MEDIUM = 8;
	const int RADIUS_SMALL = 6;
	const double PI_VAL = 3.1415926535;
	int numGuests = 0;
	int numLargePizzas = 0;
	int numMediumPizzas = 0;
	int numSmallPizzas = 0;
	double areaPizza = 0.0;
	double areaEaten = 0.0;
	int userPercentage = 0;
	double totalCostNoTip = 0.0;
	int totalCost = 0;

	cout << "Please enter the number of guests: " << endl;
	cin >> numGuests;

	numLargePizzas = numGuests / PEOPLE_FED_LARGE;
	numMediumPizzas = (numGuests % PEOPLE_FED_LARGE) / PEOPLE_FED_MEDIUM;
	numSmallPizzas = ((numGuests % PEOPLE_FED_LARGE) % PEOPLE_FED_MEDIUM) / PEOPLE_FED_SMALL;

	cout << numLargePizzas << " large pizzas, " << numMediumPizzas << " medium pizzas, ";
	cout << "and " << numSmallPizzas << " small pizzas will be needed." << endl;
	cout << endl;

	areaPizza = (numLargePizzas * (PI_VAL * (pow(RADIUS_LARGE, 2.0)))) + (numMediumPizzas * (PI_VAL * (pow(RADIUS_MEDIUM, 2.0))));
	areaPizza = areaPizza + (numSmallPizzas * (PI_VAL * (pow(RADIUS_SMALL, 2.0)))); //Keeping lines under 120 characters
	areaEaten = (numLargePizzas * (PI_VAL * (pow(RADIUS_LARGE, 2.0)))) + (numMediumPizzas * (PI_VAL * (pow(RADIUS_MEDIUM, 2.0))));
	areaEaten = (areaEaten + (numSmallPizzas * (PI_VAL * (pow(RADIUS_SMALL, 2.0))))) / numGuests;

	cout << "A total of " << areaPizza << " square inches of pizza will be purchased (" << areaEaten << " per guest)." << endl;
	cout << endl;

	cout << "Please enter the tip as a percentage (i.e. 10 means 10%): " << endl;
	cout << endl;
	cin >> userPercentage;

	totalCostNoTip = ((LARGE_PIZZA_COST * numLargePizzas) + (MEDIUM_PIZZA_COST * numMediumPizzas)
		+ (SMALL_PIZZA_COST * numSmallPizzas));
	totalCost = round(((totalCostNoTip * (static_cast <double>(userPercentage) / 100)) + totalCostNoTip));

	cout << "The total cost of the event will be: $" << totalCost << endl;

	return 0;
}
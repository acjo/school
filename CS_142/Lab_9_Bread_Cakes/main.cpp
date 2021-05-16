#include <vector>
#include <iomanip>
#include <ios>
#include <iostream>
#include "Bread.h"
#include "Cake.h"
#include "CupCake.h"
#include "LayerCake.h"
#include "BakedGood.h"
using namespace std;

int main() {
	bool getOrder = true;
	string bakedGoodType;
	string breadType;
	string flavorOfCake;
	string frostingType;
	string sprinkleColor;
	int numCakeLayers;
	unsigned int quantityOfItem;
	vector<BakedGood*> allBakedGoods;
	Bread* breadPointer = nullptr;
	CupCake* cupCakePointer = nullptr;
	LayerCake* layerCakePointer = nullptr;
	
	cout << "**Bread and Cakes Bakery**" << endl;
	cout << endl;

	cout << "Enter sub-order (enter \"done\" to finish)" << endl;
	while (getOrder) {
		cout << "Sub-order: " << endl;
		cin >> bakedGoodType;
		if (bakedGoodType == "Bread") {
			cin >> breadType;
			cin >> quantityOfItem;
			for (unsigned int i = 0; i < quantityOfItem; ++i) {
				breadPointer = new Bread(breadType, quantityOfItem);
				allBakedGoods.push_back(breadPointer);
			}
		}
		else if (bakedGoodType == "Cupcake") {
			cin >> flavorOfCake;
			cin >> frostingType;
			cin >> sprinkleColor;
			cin >> quantityOfItem;
			for (unsigned int i = 0; i < quantityOfItem; ++i) {
				cupCakePointer = new CupCake(flavorOfCake, frostingType, sprinkleColor, quantityOfItem);
				allBakedGoods.push_back(cupCakePointer);
			}
		}
		else if (bakedGoodType == "Layer-cake")
		{
			cin >> flavorOfCake;
			cin >> frostingType;
			cin >> numCakeLayers;
			cin >> quantityOfItem;
			for (unsigned int i = 0; i < quantityOfItem; ++i) {
				layerCakePointer = new LayerCake(flavorOfCake, frostingType, numCakeLayers, quantityOfItem);
				allBakedGoods.push_back(layerCakePointer);
			}
		}
		else if (bakedGoodType == "done")
		{
			getOrder = false;
		}
	}
	
	vector<BakedGood*> finalInvoice(0);
	cout << endl;
	cout << "Order Confirmations: " << endl;
	for (unsigned int i = 0; i < allBakedGoods.size(); ++i) {
		auto orderConfirmationString = allBakedGoods.at(i)->ToStr();
		cout << orderConfirmationString << endl;
		BakedGood* foundInInvoice = nullptr;
		auto intialQuantityValue = 0;
		for (unsigned int j = 0; j < finalInvoice.size(); ++j) {
			if (orderConfirmationString == finalInvoice.at(j)->ToStr()) {
				foundInInvoice = finalInvoice.at(j);
				break;
			}
		}
		if (foundInInvoice == nullptr) {
			foundInInvoice = allBakedGoods.at(i);
			foundInInvoice->SetQuantiy(intialQuantityValue);
			finalInvoice.push_back(foundInInvoice);
		}
		foundInInvoice->IncrementQuantity();
	}
	
	int totalQuantity = 0;
	double totalCost = 0.0;
	cout << endl;
	cout << fixed << setprecision(2);
	cout << setw(75) << left << "Invoice:" << endl;
	cout << setw(75) << left << "Baked Good" << setw(9) << right << "Quantity" << setw(9) << "Total" << endl;
	for (unsigned int i = 0; i < finalInvoice.size(); ++i) {
		cout << setw(75) << left << finalInvoice.at(i)->ToStr() << setw(9) << right << finalInvoice.at(i)->GetQuantity();
		cout << setw(9) << finalInvoice.at(i)->DiscountedPrice(finalInvoice.at(i)->GetQuantity()) << endl;
		totalQuantity += finalInvoice.at(i)->GetQuantity();
		totalCost += finalInvoice.at(i)->DiscountedPrice(finalInvoice.at(i)->GetQuantity());
	}
	cout << setw(75) << left << "Totals" << setw(9) << right << totalQuantity << setw(9) << totalCost << endl;
	cout << "Good Bye" << endl;

	for (unsigned int i = 0; i < finalInvoice.size(); ++i) {
		delete finalInvoice.at(i);
	}
	allBakedGoods.clear();
	finalInvoice.clear();

	return 0;
}
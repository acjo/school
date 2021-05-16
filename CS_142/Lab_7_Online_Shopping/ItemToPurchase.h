#pragma once
#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H
#include <string>
using namespace std;
class ItemToPurchase
{
public:
	ItemToPurchase();
	ItemToPurchase(string itemName, string itemDescription, double itemPrice, int itemQuantity);
	void SetName(string itemName);
	string GetName() const;
	void SetPrice(double itemPrice);
	double GetPrice() const;
	void SetQuantity(int itemQuantity);
	int GetQuantity() const;
	void SetDescription(string itemDescription);
	string GetDescription() const;
	void PrintCost() const;
	void PrintDescription() const;

private:
	string itemName;
	string itemDescription;
	double itemPrice;
	int itemQuantity;
};


#endif

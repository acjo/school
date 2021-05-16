#include "ItemToPurchase.h"
#include <iostream>
#include <iomanip>
#include <ios>
using namespace std;

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase() {
	itemName = "none";
	itemDescription = "none";
	itemPrice = 0.0;
	itemQuantity = 0;
}
ItemToPurchase::ItemToPurchase(string itemName, string itemDescription, double itemPrice, int itemQuantity) {
	this->itemName = itemName;
	this->itemDescription = itemDescription;
	this->itemPrice = itemPrice;
	this->itemQuantity = itemQuantity;
}
void ItemToPurchase::SetName(string itemName) {
	this->itemName = itemName;
}
string ItemToPurchase::GetName() const {
	return itemName;
}
void ItemToPurchase::SetPrice(double itemPrice) {
	this->itemPrice = itemPrice;
}
double ItemToPurchase::GetPrice() const {
	return itemPrice;
}
void ItemToPurchase::SetQuantity(int itemQuantity) {
	this->itemQuantity = itemQuantity;
}
int ItemToPurchase::GetQuantity() const {
	return itemQuantity;
}
void ItemToPurchase::SetDescription(string itemDescription) {
	this->itemDescription = itemDescription;
}
string ItemToPurchase::GetDescription() const {
	return itemDescription;
}
void ItemToPurchase::PrintCost() const {
	cout << fixed << setprecision(2);
	cout << itemName << " " << itemQuantity << " @ " << itemPrice << " = " << itemQuantity * itemPrice << endl;
}
void ItemToPurchase::PrintDescription() const {
	cout << itemName << ": " << itemDescription << endl;
}
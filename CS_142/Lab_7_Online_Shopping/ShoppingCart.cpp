#include "ItemToPurchase.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <ios>
using namespace std;

#include "ShoppingCart.h"

ShoppingCart::ShoppingCart() {
	customerName = "none";
	dateCreated = "January 1, 2016";
}
ShoppingCart::ShoppingCart(string customerName, string dateCreated) {
	this->customerName = customerName;
	this->dateCreated = dateCreated;
}
string ShoppingCart::GetCustomerName() const {
	return customerName;
}
string ShoppingCart::GetDate() const {
	return dateCreated;
}
void ShoppingCart::AddItem() {
	unsigned int i = 0;
	string newDescription;
	string newItemName;
	double newItemPrice;
	int newItemQuantity;

	cout << "Enter the item name: " << endl;
	getline(cin, newItemName);
	cout << "Enter the item description: " << endl;
	getline(cin, newDescription);
	cout << "Enter the item price: " << endl;
	cin >> newItemPrice;
	cin.ignore();
	cout << "Enter the item quantity: " << endl;
	cin >> newItemQuantity;
	cin.ignore();
	for (i = 0; i < cartContents.size(); ++i) {
		if (cartContents.at(i).GetName() == newItemName) {
			cout << "Item is already in cart. Nothing added." << endl;
			return;
		}
	}
	ItemToPurchase newItem;
	newItem.SetName(newItemName);
	newItem.SetDescription(newDescription);
	newItem.SetPrice(newItemPrice);
	newItem.SetQuantity(newItemQuantity);
	cartContents.push_back(newItem);
}
void ShoppingCart::RemoveItem(string itemToRemove) {
	unsigned int i = 0;
	for (i = 0; i < cartContents.size(); ++i) {
		if (cartContents.at(i).GetName() == itemToRemove) {
			cartContents.erase(cartContents.begin() + i);
			return;
		}
	}
	cout << "Item not found in cart. Nothing removed." << endl;
}
void ShoppingCart::UpdateItemQuantity() {
	string itemToChange;
	unsigned int i = 0;
	int newQuantity = 0;
	cout << "Enter the item name: " << endl;
	getline(cin, itemToChange);
	cout << "Enter the new quantity: " << endl;
	cin >> newQuantity;
	cin.ignore();
	for (i = 0; i < cartContents.size(); ++i) {
		if (cartContents.at(i).GetName() == itemToChange) {
			cartContents.at(i).SetQuantity(newQuantity);
			return;
		}
	}
	cout << "Item not found in cart. Nothing modified." << endl;
}
void ShoppingCart::TotalContents() const {
	unsigned int i = 0;
	int contents = 0;
	double total = 0.0;
	if (cartContents.size() == 0) {
		cout << "Shopping cart is empty." << endl;
	}
	else {
		for (i = 0; i < cartContents.size(); ++i) {
			contents += cartContents.at(i).GetQuantity();
		}
		cout << "Number of items: " << contents << endl;
		cout << endl;
		cout << fixed << setprecision(2);
		for (i = 0; i < cartContents.size(); ++i) {
			cout << cartContents.at(i).GetName() << " " << cartContents.at(i).GetQuantity() << " @ $" << cartContents.at(i).GetPrice() << " = $";
			cout << cartContents.at(i).GetQuantity() * cartContents.at(i).GetPrice() << endl;
			total += cartContents.at(i).GetQuantity() * cartContents.at(i).GetPrice();
		}
		cout << endl;
		cout << "Total: $" << total << endl;
	}
}
void ShoppingCart::GetDescriptions() const {
	unsigned int i = 0;
	if (cartContents.size() == 0) {
		cout << "Shopping cart is empty." << endl;
	}
	else {
		cout << "Item Descriptions" << endl;
		for (i = 0; i < cartContents.size(); ++i) {
			cout << cartContents.at(i).GetName() << ": " << cartContents.at(i).GetDescription() << endl;
		}
	}
}

/*
Return the quantity of items in the cart
Return the total cost of all items in the cart
Print the total number and cost of items in the cart
If cart is empty, output this message: "Shopping cart is empty"
Print the description of each item in the cart
If cart is empty, output this message: "Shopping cart is empty"*/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <ios>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"
using namespace std;

void Menu() {
	cout << "Menu" << endl;
	cout << "add - Add item to cart" << endl;
	cout << "remove - Remove item from cart" << endl;
	cout << "change - Change item quantity" << endl;
	cout << "descriptions - Output items' descriptions" << endl;
	cout << "cart - Output shopping cart" << endl;
	cout << "options - Print the options menu" << endl;
	cout << "quit - Quit" << endl;
	return;
}

void Title(ShoppingCart& shoppingCart1) {
	cout << shoppingCart1.GetCustomerName() << "'s Shopping Cart - " << shoppingCart1.GetDate() << endl;
}

int main() {
	string customerName;
	string date;
	string choice;
	bool run = true;

	cout << "Enter Customer's Name: " << endl;
	getline(cin, customerName);
	cout << "Enter Today's Date: " << endl;
	getline(cin, date);

	ShoppingCart shoppingCart1(customerName, date);

	while (run) {
		cout << endl;
		cout << "Enter option: " << endl;
		cin >> choice;
		cin.ignore();

		if ((choice == "options") || (choice != "quit" && choice != "add" && choice != "cart" && choice != "descriptions" && choice != "change" && choice != "remove")) {
			Menu();
		}
		else if (choice == "quit") {
			run = false;
		}
		else if (choice == "add") {
			shoppingCart1.AddItem();
		}
		else if (choice == "cart") {
			Title(shoppingCart1);
			shoppingCart1.TotalContents();
		}
		else if (choice == "descriptions") {
			Title(shoppingCart1);
			shoppingCart1.GetDescriptions();
		}
		else if (choice == "change") {
			shoppingCart1.UpdateItemQuantity();
		}
		else if (choice == "remove") {
			string itemToRemove;
			cout << "Enter name of the item to remove: " << endl;
			getline(cin, itemToRemove);
			shoppingCart1.RemoveItem(itemToRemove);
		}
	}
	cout << "Goodbye." << endl;
	return 0;
}
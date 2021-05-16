#pragma once
#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H
#include <vector>
#include <string>
#include "ItemToPurchase.h"
class ShoppingCart
{

public:
	ShoppingCart();
	ShoppingCart(string customerName, string dateCreated);
	string GetCustomerName() const;
	string GetDate() const;
	void AddItem();
	void RemoveItem(string itemToRemove);
	void UpdateItemQuantity();
	void TotalContents() const;
	void GetDescriptions() const;
private:
	string customerName;
	string dateCreated;
	vector<ItemToPurchase> cartContents;
};

#endif
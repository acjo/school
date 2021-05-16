#pragma once
#ifndef BAKEDGOOD_H
#define BAKEDGOOD_H
#include <string>
using namespace std;

class BakedGood
{
public:
	virtual string ToStr();
	virtual double PricePerItem() = 0;
	BakedGood(int quantityIn = 0);
	int GetQuantity() const;
	void IncrementQuantity();
	void SetQuantiy(int quantityIn);
	virtual double DiscountedPrice(int quantityIn) = 0;
protected:
	int itemQuantity;
};
#endif
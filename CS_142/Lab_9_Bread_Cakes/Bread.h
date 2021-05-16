#pragma once
#ifndef BREAD_H
#define BREAD_H
#include "BakedGood.h"
class Bread : public BakedGood
{

public:
	Bread(string bread = "none", int breadQuantity = 0);
	virtual string ToStr();
	virtual double PricePerItem();
	virtual double DiscountedPrice(int quantityIn);
private:
	string breadType;
};
#endif
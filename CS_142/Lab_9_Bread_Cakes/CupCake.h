#pragma once
#ifndef CUPCAKE_H
#define CUPCAKE_H
#include "Cake.h"
class CupCake : public Cake
{
public:
	CupCake(string cupcakeFlavor = "none", string frostingFlavorIn = "none", string colorOfSprinkles = "nothing", int cupCakeQuantity = 0);
	virtual double PricePerItem();
	virtual string ToStr();
	virtual double DiscountedPrice(int quantityIn);
private:
	string sprinklesColor;
};
#endif
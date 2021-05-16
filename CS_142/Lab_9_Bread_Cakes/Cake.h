#pragma once
#ifndef CAKE_H
#define CAKE_H
#include "BakedGood.h"
class Cake : public BakedGood
{
public:
	Cake(int quantity = 0, string flavorOfCake = "none", string flavorOfFrosting = "none");
protected:
	string cakeFlavor;
	string frostingFlavor;
};
#endif
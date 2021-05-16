#pragma once
#ifndef LAYERCAKE_H
#define LAYERCAKE_H
#include "Cake.h"
class LayerCake : public Cake
{
public:
	LayerCake(string layerCakeFlavor = "none", string frostingFlavorIn = "none", int cakeLayers = 0, int cakeQuantity = 0);
	virtual double PricePerItem();
	virtual string ToStr();
	double DiscountedPrice(int quantityIn);
private:
	int numLayers;
};
#endif
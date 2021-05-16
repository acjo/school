#include "LayerCake.h"
LayerCake::LayerCake(string layerCakeFlavor, string frostingFlavorIn, int cakeLayers, int cakeQuantity) : Cake(cakeQuantity, layerCakeFlavor, frostingFlavorIn) {
	numLayers = cakeLayers;
}
double LayerCake::PricePerItem() {
	double layerCakePrice;
	if (frostingFlavor == "cream-cheese") {
		if (numLayers == 1) {
			layerCakePrice = 10.00;
		}
		else {
			layerCakePrice = 10.00 + (4.00 * (static_cast<double>(numLayers) - 1));
		}
	}
	else {
		if (numLayers == 1) {
			layerCakePrice = 9.00;
		}
		else {
			layerCakePrice = 9.00 + (3.00 * (static_cast<double>(numLayers) - 1));
		}
	}
	return layerCakePrice;
}
string LayerCake::ToStr() {
	string finalString = to_string(numLayers) + "-layer " + cakeFlavor + " cake with " + frostingFlavor + " frosting ($" + BakedGood::ToStr() + ")";
	return finalString;
}
double LayerCake::DiscountedPrice(int quantityIn) {
	double discountFromQuantity = 0.0;
	double discountedLayerCakePrice = 0.0;
	if (quantityIn >= 3) {
		discountFromQuantity = 2.0 * quantityIn;
	}
	discountedLayerCakePrice = (PricePerItem() * quantityIn) - discountFromQuantity;
	return discountedLayerCakePrice;
}
#include "CupCake.h"
CupCake::CupCake(string cupcakeFlavor, string frostingFlavorIn, string colorOfSprinkles, int cupCakeQuantity) : Cake(cupCakeQuantity, cupcakeFlavor, frostingFlavorIn)  {
	sprinklesColor = colorOfSprinkles;
}
double CupCake::PricePerItem() {
	double cupCakePrice;
	if (frostingFlavor == "cream-cheese") {
		cupCakePrice = 1.95 + 0.2;
	}
	else {
		cupCakePrice = 1.95;
	}
	return cupCakePrice;
}
string CupCake::ToStr() {
	string finalString = cakeFlavor + " cupcake with " + frostingFlavor + " frosting and " + sprinklesColor + " sprinkles ($" + BakedGood::ToStr() + ")";
	return finalString;
}
double CupCake::DiscountedPrice(int quantityIn) {
	double discountedCupcakePrice = 0.0;
	double discountFromQuantity = 0.0;
	if (quantityIn >= 4) {
		discountFromQuantity = quantityIn * 0.4;
	}
	else if (quantityIn >= 2) {
		discountFromQuantity = quantityIn * 0.3;
	}
	discountedCupcakePrice = (PricePerItem() * quantityIn) - discountFromQuantity;
	return discountedCupcakePrice;
}
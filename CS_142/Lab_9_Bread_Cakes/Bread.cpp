#include "Bread.h"

Bread::Bread(string bread, int breadQuantity) : BakedGood(breadQuantity) {
	breadType = bread;
}
double Bread::PricePerItem() {
	double breadPrice = 4.50;
	return breadPrice;
}
string Bread::ToStr() {
	string finalString = breadType + " bread ($" + BakedGood::ToStr() + ")";
	return finalString;
}
double Bread::DiscountedPrice(int quantityIn) {
	double discountedBreadPrice = 0.0;
	int multiplier = quantityIn / 3;
	if (multiplier >= 1) {
		discountedBreadPrice = (double(quantityIn) - double(multiplier)) * PricePerItem();
	}
	else {
		discountedBreadPrice = quantityIn * PricePerItem();
	}
	return discountedBreadPrice;
}

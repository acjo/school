#include "BakedGood.h"
BakedGood::BakedGood(int quantityIn) {
	itemQuantity = quantityIn;
}
string BakedGood::ToStr() {
	double price = PricePerItem();
	return to_string(price);
}
int BakedGood::GetQuantity() const {
	return itemQuantity;
}
void BakedGood::IncrementQuantity() {
	itemQuantity += 1;
}
void BakedGood::SetQuantiy(int quantityIn) {
	itemQuantity = quantityIn;
}
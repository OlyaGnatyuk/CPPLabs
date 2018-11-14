#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

using namespace std;

class  Product
{
public:
	Product(string name, double price);
	double getPriceWithDiscount();
	void applyDiscountPercentage(double percentage);
	string getName();
	bool getWasDiscountApplied();
	void setWasDiscountApplied(bool newValueWasDiscountApplied);
	bool equals(Product * product);
private:
	string name;
	double price;
	double priceWithDiscount;
	bool wasDiscountApplied;
};

#endif

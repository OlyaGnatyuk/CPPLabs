#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

using namespace std;

class  Product
{
public:
	Product(string name, double price);
	bool getIsDiscountApplied();
	double getPriceWithDiscount();
	void applyDiscountPercentage(double percentage);
	string getName();
private:
	string name;
	double price;
	double priceWithDiscount;
};

#endif

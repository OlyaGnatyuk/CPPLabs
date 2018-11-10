#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

using namespace std;

class  Product
{
public:
	Product(string name, double price);
	bool getIsDiscountApplied();
	void setIsDiscountApplied(bool applied);
	double getPriceWithDiscount();
	void applyDiscountPercentage(double percentage);

private:
	string name;
	double price;
	double priceWithDiscount;
	bool isDiscountApplied;
};

#endif

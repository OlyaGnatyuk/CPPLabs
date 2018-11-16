#ifndef DISCOUNT_FOR_PRODUCT_SET_H
#define DISCOUNT_FOR_PRODUCT_SET_H
#include <map>
#include "Discount.h"

class DiscountForProductSet : public IDiscount
{
public:
	DiscountForProductSet();
	void addProduct(Product product);
	void setPercentage(double newPercentage) override;
	void applyToProducs(vector<Product*> products) override;
private:
	map<string, int> productCounters;
	double percentage;
};

#endif
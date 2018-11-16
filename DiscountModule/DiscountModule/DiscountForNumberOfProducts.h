#pragma once
#include "Discount.h"
class DiscountForNumberOfProducts :
	public IDiscount
{
public:
	DiscountForNumberOfProducts();
	void setPercentage(double newPercentage) override;
	void applyToProducs(vector<Product*> products) override;
	void setDiscountPercentageForNumberOfProducts(int numberOfProducts, int percentage);
private:
	double percentage;
	map<int, int> discountPercentageForNumberOfProducts;
};


#pragma once
#include "Discount.h"
#include <string>
#include <map>
#include <vector>

class DiscountWithDependency :	public IDiscount
{
public:
	DiscountWithDependency();
	void setMainProduct(Product newMainProduct);
	void addDependentProduct(Product dependentProduct);
	void setPercentage(double newPercentage) override;
	void applyToProducs(vector<Product*> products) override;
private:
	Product mainProduct;
	vector<Product> dependentProducts;
	double percentage;
	int evaluateNumberOfMainProducts(vector<Product*> products);
};


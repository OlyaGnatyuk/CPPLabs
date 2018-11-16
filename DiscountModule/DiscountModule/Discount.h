#pragma once
#include <vector>
#include "Product.h"

class IDiscount
{
public:
	void virtual applyToProducs(vector<Product*> products) = 0;
	void virtual setPercentage(double newPercentage) = 0;
};


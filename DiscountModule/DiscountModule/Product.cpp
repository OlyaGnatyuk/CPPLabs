#include "pch.h"
#include "product.h"

Product::Product(string newName, double newPrice)
{
	name = newName;
	price = newPrice;
	priceWithDiscount = price;
	isDiscountApplied = false;
}

bool Product::getIsDiscountApplied()
{
	return isDiscountApplied;
}

void Product::setIsDiscountApplied(bool applied)
{
	isDiscountApplied = applied;
}

double Product::getPriceWithDiscount()
{
	return priceWithDiscount;
}

void Product::applyDiscountPercentage(double percentage)
{
	if ((percentage > 0.0) && (percentage < 100.0))
	{
		priceWithDiscount = price * (100.0 - percentage);
	}
}


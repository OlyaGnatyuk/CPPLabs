#include "pch.h"
#include "product.h"

Product::Product(string newName, double newPrice)
{
	name = newName;
	price = newPrice;
	priceWithDiscount = price;
	wasDiscountApplied = false;
}

double Product::getPriceWithDiscount()
{
	return priceWithDiscount;
}

void Product::applyDiscountPercentage(double percentage)
{
	if ((percentage > 0.0) && (percentage < 100.0))
	{
		priceWithDiscount = price * (100.0 - percentage)/100;
		wasDiscountApplied = true;
	}
}

string Product::getName()
{
	return name;
}

bool Product::getWasDiscountApplied()
{
	return wasDiscountApplied;
}

void Product::setWasDiscountApplied(bool newValueWasDiscountApplied)
{
	wasDiscountApplied = newValueWasDiscountApplied;
}

bool Product::equals(Product * product)
{
	return name == (* product).getName();
}


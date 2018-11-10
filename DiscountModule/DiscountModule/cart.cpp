#include "pch.h"
#include "Cart.h"

Cart::Cart()
{
	products = vector<Product>();
}

Cart::~Cart()
{
	
}

double Cart::getTotal()
{
	double total = 0.0;
	for (auto &singleProduct : products)
	{
		total += singleProduct.getPriceWithDiscount();
	}
	return total;
}

vector<Product> Cart::getProductsWithoutDiscount()
{
	vector<Product> productsWithoutDiscount = vector<Product>();

	for (auto &singleProduct : products)
	{
		if (!singleProduct.getIsDiscountApplied)
		{
			productsWithoutDiscount.push_back(singleProduct);
		}
	}

	return productsWithoutDiscount;
}


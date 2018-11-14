#include "pch.h"
#include "Cart.h"

Cart::Cart()
{
	products = vector<Product*>();
}

void Cart::addProduct(Product* newProduct)
{
	products.push_back(newProduct);
}

void Cart::addDiscount(IDiscount & discount)
{
	discount.applyToProducs(getProductsWithoutDiscount());
}

double Cart::getTotal()
{
	double total = 0.0;
	for (auto &singleProduct : products)
	{
		total += (*singleProduct).getPriceWithDiscount();
	}
	return total;
}

vector<Product*> Cart::getProductsWithoutDiscount()
{
	vector<Product*> productsWithoutDiscount = vector<Product*>();

	for (auto &singleProduct : products)
	{
		if (!(*singleProduct).getWasDiscountApplied())
		{
			productsWithoutDiscount.push_back(singleProduct);
		}
	}

	return productsWithoutDiscount;
}


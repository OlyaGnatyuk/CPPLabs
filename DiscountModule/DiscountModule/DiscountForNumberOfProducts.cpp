#include "pch.h"
#include "DiscountForNumberOfProducts.h"


DiscountForNumberOfProducts::DiscountForNumberOfProducts()
{
}

void DiscountForNumberOfProducts::setPercentage(double newPercentage)
{
	percentage = newPercentage;
}

void DiscountForNumberOfProducts::applyToProducs(vector<Product*> products)
{
	int numberOfProducts = products.size();
	if (discountPercentageForNumberOfProducts.find(numberOfProducts) != discountPercentageForNumberOfProducts.end())
	{

		int discountPercentage = discountPercentageForNumberOfProducts.at(numberOfProducts);

		for (auto &singleProduct : products)
		{
			(*singleProduct).applyDiscountPercentage(discountPercentage);
		}
	}
}

void DiscountForNumberOfProducts::setDiscountPercentageForNumberOfProducts(int numberOfProducts, int percentage)
{
	discountPercentageForNumberOfProducts.insert(make_pair(numberOfProducts, percentage));
}

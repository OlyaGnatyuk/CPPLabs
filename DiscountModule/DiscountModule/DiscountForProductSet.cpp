#include "pch.h"

DiscountForProductSet::DiscountForProductSet()
{
}

void DiscountForProductSet::addProduct(Product product)
{
	productCounters.insert(make_pair(product.getName(), 0));
}

void DiscountForProductSet::setPercentage(double newPercentage)
{
	percentage = newPercentage;
}

void DiscountForProductSet::applyToProducs(vector<Product*> products)
{
	for (auto & product : products)
	{
		string currentProductName = (*product).getName();
		if (productCounters.find(currentProductName) != productCounters.end())
		{
			productCounters[currentProductName]++;
		}
		
	}

	int numberOfSets = INT_MAX;

	for (pair<std::string, int> productCounter : productCounters)
	{
		if (productCounter.second < numberOfSets)
		{
			numberOfSets = productCounter.second;
		}
	}

	for (pair<std::string, int> productCounter : productCounters)
	{
		productCounters[productCounter.first] = numberOfSets;
	}

	for (auto & product : products)
	{
		string currentProductName = (*product).getName();
		if (productCounters[currentProductName] > 0)
		{
			productCounters[currentProductName]--;
			(*product).applyDiscountPercentage(percentage);
		}
	}
}

#include "pch.h"
#include "DiscountWithDependency.h"


DiscountWithDependency::DiscountWithDependency()
{
}

void DiscountWithDependency::setMainProduct(Product newMainProduct)
{
	mainProduct = newMainProduct;
}

void DiscountWithDependency::addDependentProduct(Product dependentProduct)
{
	dependentProducts.push_back(dependentProduct);
}

void DiscountWithDependency::setPercentage(double newPercentage)
{
	percentage = newPercentage;
}

int DiscountWithDependency::evaluateNumberOfMainProducts(vector<Product*> products)
{
	int numberOfMainProducts = 0;
	for (auto &singleProduct : products)
	{
		if (mainProduct.equals(singleProduct))
		{
			numberOfMainProducts++;
		}
	}

	return numberOfMainProducts;
}

void DiscountWithDependency::applyToProducs(vector<Product*> products)
{
	
	int numberOfMainProducts = evaluateNumberOfMainProducts(products);

	for (auto &singleProduct : products)
	{
		if (numberOfMainProducts == 0)
		{
			break;
		}

		for (auto &dependentProduct : dependentProducts)
		{
			if (dependentProduct.equals(singleProduct))
			{
				numberOfMainProducts--;
				(*singleProduct).applyDiscountPercentage(percentage);
			}
		}
	}
}

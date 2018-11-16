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

void DiscountWithDependency::saveMainProducts(vector<Product*> products)
{
	for (auto &singleProduct : products)
	{
		if (mainProduct.equals(singleProduct))
		{
			mainProducts.push_back(singleProduct);
		}
	}
}

void DiscountWithDependency::applyToProducs(vector<Product*> products)
{
	
	saveMainProducts(products);

	for (auto &singleProduct : products)
	{
		if (mainProducts.size() == 0)
		{
			break;
		}

		for (auto &dependentProduct : dependentProducts)
		{
			if (dependentProduct.equals(singleProduct))
			{
				mainProducts.pop_back();
				(*singleProduct).applyDiscountPercentage(percentage);
			}

			if (mainProducts.size() == 0)
			{
				break;
			}
		}
	}
}

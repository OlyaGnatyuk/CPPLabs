#pragma once
#include "Discount.h"
#include <string>
#include <map>

class DiscountWithDependency :	public IDiscount
{
public:
	DiscountWithDependency();
private:
	string mainProductName;
	
};


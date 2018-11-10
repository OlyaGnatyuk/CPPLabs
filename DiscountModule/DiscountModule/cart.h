#ifndef CART_H
#define CART_H
#include <vector>
#include "Product.h"

using namespace std;

class Cart
{
public:
	Cart();
	~Cart();
	double getTotal();
	vector<Product> getProductsWithoutDiscount();
private:
	vector<Product> products;
};

#endif
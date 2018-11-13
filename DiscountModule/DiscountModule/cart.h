#ifndef CART_H
#define CART_H
#include <vector>
#include "Product.h"
#include "Discount.h"

using namespace std;

class Cart
{
public:
	Cart();
	void addProduct(Product* newProduct);
	void addDiscount(IDiscount & discount);
	double getTotal();
	vector<Product*> getProductsWithoutDiscount();
private:
	vector<Product*> products;
};

#endif
// DiscountModule.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
using namespace std;

int main()
{
	cout << "Hello User!" << endl; 
	
	// Создаем экземпляры продуктов
	Product productA = Product("A", 100.0);
	Product oneMoreProductA = Product("A", 100.0);
	Product productB = Product("B", 50.0);
	Product productC = Product("C", 150.0);
	Product productD = Product("D", 10.0);
	Product productE = Product("E", 20.0);
	Product oneMoreProductE = Product("E", 20.0);
	Product andOneMoreProductE = Product("E", 20.0);
	Product productF = Product("F", 70.0);
	Product oneMoreProductF = Product("F", 70.0);
	Product productG = Product("G", 25.0);
	Product oneMoreProductG = Product("G", 25.0);
	Product productK = Product("K", 25.0);
	Product productL = Product("L", 125.0);
	Product productM = Product("M", 250.0);

	// Создаем экземпляр скидки для набора продуктов
	DiscountForProductSet discountSetAB = DiscountForProductSet();
	discountSetAB.setPercentage(10.0);
	discountSetAB.addProduct(productA);
	discountSetAB.addProduct(productB);
	

	DiscountForProductSet discountSetDE = DiscountForProductSet();
	discountSetDE.setPercentage(5.0);
	discountSetDE.addProduct(productD);
	discountSetDE.addProduct(productE);

	DiscountForProductSet discountSetEFG = DiscountForProductSet();
	discountSetEFG.setPercentage(5.0);
	discountSetEFG.addProduct(productE);
	discountSetEFG.addProduct(productF);
	discountSetEFG.addProduct(productG);

	DiscountWithDependency discountWithDependency = DiscountWithDependency();
	discountWithDependency.setPercentage(5.0);
	discountWithDependency.setMainProduct(productA);
	discountWithDependency.addDependentProduct(productK);
	discountWithDependency.addDependentProduct(productL);
	discountWithDependency.addDependentProduct(productM);

	// Создаем экэемпляр корзины
	Cart cart = Cart();
	cart.addProduct(&productA);
	cart.addProduct(&oneMoreProductA);
	cart.addProduct(&productB);
	cart.addProduct(&productC);
	cart.addProduct(&productD);
	cart.addProduct(&productE);
	cart.addProduct(&oneMoreProductE);
	cart.addProduct(&andOneMoreProductE);
	cart.addProduct(&productF);
	cart.addProduct(&productG);
	cart.addProduct(&oneMoreProductF);
	cart.addProduct(&oneMoreProductG);
	cart.addProduct(&productK);
	cart.addProduct(&productL);
	cart.addProduct(&productM);

	// Вывод суммарной стоимости продуктов без учета скидки
	cout << "Before discount: " << cart.getTotal() << " RUB" << endl;
	cart.addDiscount(discountSetAB);
	cart.addDiscount(discountSetDE);
	cart.addDiscount(discountSetEFG);
	cart.addDiscount(discountWithDependency);
	// Вывод суммарной стоимости продуктов с учетом скидки
	cout << "After discount: " << cart.getTotal() << " RUB" << endl;
}

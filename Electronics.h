#pragma once
#include "Product.h"

class Electronics : public Product {
private:
	string brand;

public:
	Electronics(string name, int quantity, double price, string brand)
		: Product(name, quantity, price), brand(brand) {}

	double calculateCost() const  {
		return quantity * price;
	}
	string getBrand()const { return brand; }
	void setBrand(const string& Brand) { brand = Brand; }
	void display() const override {
		cout << "Electronics: " << name << " (" << brand << "), Quantity: " << quantity
			<< ", Price: " << price << ", Total Cost: " << calculateCost() << endl;
	}
};

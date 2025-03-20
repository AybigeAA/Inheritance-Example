#pragma once
#include "Product.h"

class Food : public Product {
private:
	double pricePerUnit;

public:
	Food(string name, int quantity, double pricePerUnit)
		: Product(name, quantity, pricePerUnit), pricePerUnit(pricePerUnit) {}

	double calculateCost() const override {
		return (quantity * pricePerUnit);
	}

	void display() const  {
		cout << "Food: " << name << ", Quantity: " << quantity << ", Price per Unit: " << pricePerUnit
			<< ", Total Cost: " << calculateCost() << endl;
	}
};

#pragma once
#include "Product.h"

class Clothing : public Product {
private:
	string size;

public:
	Clothing(string name, int quantity, double price, string size)
		: Product(name, quantity, price), size(size) {}

	double calculateCost() const  {
		return quantity * price;
	}

	void display() const override {
		cout << "Clothing: " << name << " (Size: " << size << "), Quantity: " << quantity
			<< ", Price: " << price << ", Total Cost: " << calculateCost() << endl;
	}	
	string getSize()const { return size; }
	void setSize(const string& Size) { size = Size; }
};

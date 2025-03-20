#pragma once
#include <iostream>
#include <string>

using namespace std;

class Product {
protected:
    string name;
    int quantity;
    double price;

public:
    Product(string name, int quantity, double price)
        : name(name), quantity(quantity), price(price) {}

    virtual ~Product() {}

    // Getter and setter methods
    string getName() const { return name; }
    void setName(const string& name) { this->name = name; }

    int getQuantity() const { return quantity; }
    void setQuantity(int quantity) { this->quantity = quantity; }

    double getPrice() const { return price; }
    void setPrice(double price) { this->price = price; }

    // Virtual methods
    virtual double calculateCost() const = 0;
    virtual void display() const = 0;
};

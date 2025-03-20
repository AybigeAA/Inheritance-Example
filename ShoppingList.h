#pragma once
#include "Food.h"
#include "Electronics.h"
#include "Clothing.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

class ShoppingList {
private:
    vector<Food> foods;
    vector<Electronics> electronics;
    vector<Clothing> clothes;

public:
    ShoppingList() {}

    // Add products to the respective categories
    void add(const Food& food) { foods.push_back(food); }
    void add(const Electronics& electronic) { electronics.push_back(electronic); }
    void add(const Clothing& clothing) { clothes.push_back(clothing); }

    // Calculate total cost
    double calculateTotalCost() const {
        double total = 0.0;
        for (const auto& food : foods) { total += food.calculateCost(); }
        for (const auto& electronic : electronics) { total += electronic.calculateCost(); }
        for (const auto& clothing : clothes) { total += clothing.calculateCost(); }
        return (total);
    }

    // Display all items in the list
    void displayAll() const {
        cout << "FOOD ITEMS:" << endl;
        for (const auto& food : foods) food.display();

        cout << "ELECTRONICS ITEMS:" << endl;
        for (const auto& electronic : electronics) electronic.display();

        cout << "CLOTHING ITEMS:" << endl;
        for (const auto& clothing : clothes) clothing.display();
    }

    // Clear all items from the list
    void clearList() {
        foods.clear();
        electronics.clear();
        clothes.clear();
    }

    // Remove an item by name
    void removeItem(const string& name) {
        auto removeByName = [&](auto& items) {
            items.erase(remove_if(items.begin(), items.end(),
                [&name](const auto& item) { return item.getName() == name; }),
                items.end());
            };

        removeByName(foods);
        removeByName(electronics);
        removeByName(clothes);
    }

    // Print the shopping list
    void printList() const {
        displayAll();
    }

    // Get total cost of the list
    double totalCost() const {
        return calculateTotalCost();
    }

    // Save the shopping list to a file
    void saveToFile(const string& filename) const {
        ofstream outFile(filename);

        if (outFile.is_open()) {
            // Save Food items
            for (const auto& food : foods) {
                outFile << "Food," << food.getName() << "," << food.getQuantity() << "," << food.getPrice() << endl;
            }

            // Save Electronics items
            for (const auto& electronic : electronics) {
                outFile << "Electronics," << electronic.getName() << "," << electronic.getQuantity() << "," << electronic.getPrice() << "," << electronic.getBrand() << endl;
            }

            // Save Clothing items
            for (const auto& clothing : clothes) {
                outFile << "Clothing," << clothing.getName() << "," << clothing.getQuantity() << "," << clothing.getPrice() << "," << clothing.getSize() << endl;
            }

            outFile.close();
            cout << "Shopping list saved to " << filename << endl;
        }
        else {
            cout << "Unable to open file to save shopping list." << endl;
        }
    }

    // Load the shopping list from a file
    void loadFromFile(const string& filename) {
        ifstream inFile(filename);

        if (inFile.is_open()) {
            string line;
            while (getline(inFile, line)) {
                stringstream ss(line);
                string category;
                getline(ss, category, ',');

                string name;
                getline(ss, name, ',');

                int quantity;
                ss >> quantity;
                ss.ignore();  // Ignore the comma after quantity

                double price;
                ss >> price;

                if (category == "Food") {
                    add(Food(name, quantity, price));
                }
                else if (category == "Electronics") {
                    string brand;
                    getline(ss, brand);
                    add(Electronics(name, quantity, price, brand));
                }
                else if (category == "Clothing") {
                    string size;
                    getline(ss, size);
                    add(Clothing(name, quantity, price, size));
                }
            }
            inFile.close();
            cout << "Shopping list loaded from " << filename << endl;
        }
        else {
            cout << "Unable to open file to load shopping list." << endl;
        }
    }
};




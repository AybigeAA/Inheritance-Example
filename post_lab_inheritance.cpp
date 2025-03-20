#include <iostream>
#include "Food.h"
#include "Electronics.h"
#include "Clothing.h"
#include "ShoppingList.h"

using namespace std;

void printMenu() {
    cout << "\nShopping List Menu:" << endl;
    cout << "1. Add Food Item" << endl;
    cout << "2. Add Electronics Item" << endl;
    cout << "3. Add Clothing Item" << endl;
    cout << "4. View Shopping List" << endl;
    cout << "5. Clear Shopping List" << endl;
    cout << "6. Save Shopping List to File" << endl;
    cout << "7. Load Shopping List from File" << endl;
    cout << "8. Exit" << endl;
}

int main() {
    ShoppingList myList;
    string filename = "shopping_list.txt";
    int choice;

    while (true) {
        printMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore();  // Clear the input buffer before using getline

        if (choice == 1) {
            string name;
            int quantity;
            double price;
            cout << "Enter food name: ";
            getline(cin, name);  // Use getline to read the whole name, including spaces
            cout << "Enter quantity: ";
            cin >> quantity;
            cout << "Enter price per unit: ";
            cin >> price;
            myList.add(Food(name, quantity, price));
        }
        else if (choice == 2) {
            string name, brand;
            int quantity;
            double price;
            cout << "Enter electronics name: ";
            cin.ignore();  // Clear the input buffer
            getline(cin, name);
            cout << "Enter quantity: ";
            cin >> quantity;
            cout << "Enter price: ";
            cin >> price;
            cout << "Enter brand: ";
            cin.ignore();  // Clear the input buffer
            getline(cin, brand);
            myList.add(Electronics(name, quantity, price, brand));
        }
        else if (choice == 3) {
            string name, size;
            int quantity;
            double price;
            cout << "Enter clothing name: ";
            cin.ignore();  // Clear the input buffer
            getline(cin, name);
            cout << "Enter quantity: ";
            cin >> quantity;
            cout << "Enter price: ";
            cin >> price;
            cout << "Enter size: ";
            cin.ignore();  // Clear the input buffer
            getline(cin, size);
            myList.add(Clothing(name, quantity, price, size));
        }
        else if (choice == 4) {
            myList.printList();
            cout << "Total Cost: " << myList.totalCost() << endl;
        }
        else if (choice == 5) {
            myList.clearList();
            cout << "Shopping list cleared." << endl;
        }
        else if (choice == 6) {
            myList.saveToFile(filename);
        }
        else if (choice == 7) {
            myList.loadFromFile(filename);
        }
        else if (choice == 8) {
            cout << "Exiting program..." << endl;
            break;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}



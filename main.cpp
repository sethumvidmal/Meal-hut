#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

// Struct to store menu item details
struct MenuItem {
    int itemNo;
    string name;
    double price;
};

// Function to load menu data
vector<MenuItem> getData() {
    return {
        {111, "Plain Egg", 1.45},
        {112, "Bacon and Egg", 2.45},
        {113, "Muffin", 0.99},
        {114, "French Toast", 1.99},
        {115, "Fruit Basket", 2.49},
        {116, "Cereal", 0.69},
        {117, "Coffee", 0.50},
        {118, "Tea", 0.75}
    };
}

// Function to display the menu
void showMenu(const vector<MenuItem> &menuList) {
    cout << "********Welcome to Meal Hut*********\n";
    cout << "\tBreakfast Billing System\n\n";
    cout << left << setw(10) << "Item No" << setw(20) << "Menu Item" << "Price\n";
    cout << "--------------------------------------------\n";
    for (const auto &item: menuList) {
        cout << left << setw(10) << item.itemNo << setw(20) << item.name << "$" << fixed << setprecision(2) << item.
                price << "\n";
    }
}

// Function to calculate and print the bill
void printCheck(const vector<MenuItem> &menuList, const vector<int> &order) {
    double subtotal = 0.0;

    cout << "\nYour Order:\n";
    cout << left << setw(10) << "Item No" << setw(20) << "Menu Item" << "Price\n";
    cout << "--------------------------------------------\n";

    for (const int itemNo: order) {
        for (const auto &item: menuList) {
            if (item.itemNo == itemNo) {
                cout << left << setw(10) << item.itemNo << setw(20) << item.name << "$" << fixed << setprecision(2) <<
                        item.price << "\n";
                subtotal += item.price;
                break;
            }
        }
    }

    const double tax = subtotal * 0.05;
    const double total = subtotal + tax;

    cout << "--------------------------------------------\n";
    cout << left << setw(30) << "Tax" << "$" << fixed << setprecision(2) << tax << "\n";
    cout << left << setw(30) << "Amount Due" << "$" << fixed << setprecision(2) << total << "\n";
}

int main() {
    vector<MenuItem> menuList = getData();
    vector<int> order;
    int choice;

    do {
        cout << "\n";
        showMenu(menuList);
        cout << "\nEnter the item number to add to your order (or 0 to finish): ";
        cin >> choice;

        if (choice != 0) {
            bool found = false;
            for (const auto &item: menuList) {
                if (item.itemNo == choice) {
                    order.push_back(choice);
                    found = true;
                    cout << item.name << " added to your order.\n";
                    break;
                }
            }
            if (!found) {
                cout << "Invalid item number. Please try again.\n";
            }
        }
    } while (choice != 0);

    if (!order.empty()) {
        printCheck(menuList, order);
    } else {
        cout << "\nNo items were ordered.\n";
    }

    cout << "\nThank you for dining at Meal Hut!\n";
    return 0;
}

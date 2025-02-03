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

// Modified to include quantity in order tracking
struct OrderItem {
    int itemNo;
    int quantity;
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

void printCheck(const vector<MenuItem> &menuList, const vector<OrderItem> &order) {
    double subtotal = 0.0;

    cout << "\nYour Order:\n";
    cout << left << setw(10) << "Item No" << setw(20) << "Menu Item" << setw(10) << "Qty" << "Price\n";
    cout << "------------------------------------------------\n";

    for (const auto &orderItem: order) {
        for (const auto &menuItem: menuList) {
            if (menuItem.itemNo == orderItem.itemNo) {
                double itemTotal = menuItem.price * orderItem.quantity;
                cout << left << setw(10) << menuItem.itemNo
                        << setw(20) << menuItem.name
                        << setw(10) << orderItem.quantity
                        << "$" << fixed << setprecision(2) << itemTotal << "\n";
                subtotal += itemTotal;
                break;
            }
        }
    }

    const double tax = subtotal * 0.05;
    const double total = subtotal + tax;

    cout << "------------------------------------------------\n";
    cout << left << setw(30) << "Subtotal" << "$" << fixed << setprecision(2) << subtotal << "\n";
    cout << left << setw(30) << "Tax" << "$" << fixed << setprecision(2) << tax << "\n";
    cout << left << setw(30) << "Amount Due" << "$" << fixed << setprecision(2) << total << "\n";
}

int main() {
    vector<MenuItem> menuList = getData();
    vector<OrderItem> order;
    int choice;
    int quantity;

    do {
        cout << "\n";
        showMenu(menuList);
        cout << "\nEnter the item number to add to your order (or 0 to finish): ";
        cin >> choice;

        if (choice != 0) {
            bool found = false;
            for (const auto &item: menuList) {
                if (item.itemNo == choice) {
                    cout << "Enter quantity for " << item.name << ": ";
                    cin >> quantity;

                    // Validate quantity
                    while (quantity <= 0) {
                        cout << "Invalid quantity. Please enter a positive number: ";
                        cin >> quantity;
                    }

                    order.push_back({choice, quantity});
                    found = true;
                    cout << quantity << " " << item.name << "(s) added to your order.\n";
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

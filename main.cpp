#include <iostream>
#include <iomanip>
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

const int MAX_MENU_ITEMS = 8; // Maximum number of menu items
const int MAX_ORDER_ITEMS = 50; // Maximum number of items in an order

// Function to initialize menu data
void getData(MenuItem menuList[], int &menuSize) {
    const MenuItem items[] = {
        {111, "Plain Egg", 1.45},
        {112, "Bacon and Egg", 2.45},
        {113, "Muffin", 0.99},
        {114, "French Toast", 1.99},
        {115, "Fruit Basket", 2.49},
        {116, "Cereal", 0.69},
        {117, "Coffee", 0.50},
        {118, "Tea", 0.75}
    };

    menuSize = 8;
    // Copy menu items to menuList
    for (int i = 0; i < menuSize; i++) {
        menuList[i] = items[i];
    }
}

void showMenu(const MenuItem menuList[], const int menuSize) {
    cout << "********Welcome to Meal Hut*********\n";
    cout << "\tBreakfast Billing System\n\n";
    cout << left << setw(10) << "Item No" << setw(20) << "Menu Item" << "Price\n";
    cout << "--------------------------------------------\n";
    for (int i = 0; i < menuSize; i++) {
        cout << left << setw(10) << menuList[i].itemNo
                << setw(20) << menuList[i].name
                << "$" << fixed << setprecision(2) << menuList[i].price << "\n";
    }
}

void printCheck(const MenuItem menuList[], const int menuSize, const OrderItem order[], const int orderSize) {
    double subtotal = 0.0;

    cout << "\nYour Order:\n";
    cout << left << setw(10) << "Item No" << setw(20) << "Menu Item" << setw(10) << "Qty" << "Price\n";
    cout << "------------------------------------------------\n";

    for (int i = 0; i < orderSize; i++) {
        for (int j = 0; j < menuSize; j++) {
            if (menuList[j].itemNo == order[i].itemNo) {
                double itemTotal = menuList[j].price * order[i].quantity;
                cout << left << setw(10) << menuList[j].itemNo
                        << setw(20) << menuList[j].name
                        << setw(10) << order[i].quantity
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
    MenuItem menuList[MAX_MENU_ITEMS];
    OrderItem order[MAX_ORDER_ITEMS];
    int menuSize;
    int orderSize = 0;
    int choice;
    int quantity;

    getData(menuList, menuSize);

    do {
        cout << "\n";
        showMenu(menuList, menuSize);
        cout << "\nEnter the item number to add to your order (or 0 to finish): ";
        cin >> choice;

        if (choice != 0) {
            bool found = false;
            for (int i = 0; i < menuSize; i++) {
                if (menuList[i].itemNo == choice) {
                    cout << "Enter quantity for " << menuList[i].name << ": ";
                    cin >> quantity;

                    // Validate quantity
                    while (quantity <= 0) {
                        cout << "Invalid quantity. Please enter a positive number: ";
                        cin >> quantity;
                    }

                    if (orderSize < MAX_ORDER_ITEMS) {
                        order[orderSize].itemNo = choice;
                        order[orderSize].quantity = quantity;
                        orderSize++;
                        found = true;
                        cout << quantity << " " << menuList[i].name << "(s) added to your order.\n";
                    } else {
                        cout << "Order is full. Cannot add more items.\n";
                    }
                    break;
                }
            }
            if (!found) {
                cout << "Invalid item number. Please try again.\n";
            }
        }
    } while (choice != 0);

    if (orderSize > 0) {
        printCheck(menuList, menuSize, order, orderSize);
    } else {
        cout << "\nNo items were ordered.\n";
    }

    cout << "\nThank you for dining at Meal Hut!\n";
    return 0;
}

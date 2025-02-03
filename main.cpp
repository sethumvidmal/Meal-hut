#include <iostream>
#include <string>

using namespace std;

// Structure to store menu item details
struct MenuItem {
    int itemNo;       // Item number
    string name;      // Item name
    float price;      // Price of the item
};

// Structure to store order details
struct OrderItem {
    int itemNo;      // Item number ordered
    int quantity;    // Quantity ordered
};

// Function to load menu items (get data)
void loadMenu(MenuItem menu[], int &size) {
    size = 8; // Total number of items in the menu

    menu[0] = {111, "Plain Egg", 1.45};
    menu[1] = {112, "Bacon and Egg", 2.45};
    menu[2] = {113, "Muffin", 0.99};
    menu[3] = {114, "French Toast", 1.99};
    menu[4] = {115, "Fruit Basket", 2.49};
    menu[5] = {116, "Cereal", 0.69};
    menu[6] = {117, "Coffee", 0.50};
    menu[7] = {118, "Tea", 0.75};
}

// Function to display menu
void displayMenu(const MenuItem menu[], const int size) {
    cout << "******** Welcome to Meal Hut ********\n";
    cout << "******** Breakfast Billing System ********\n\n";
    cout << "Item No\tMenu Item\tPrice\n";
    cout << "------------------------------------\n";

    for (int i = 0; i < size; i++) {
        cout << menu[i].itemNo << "\t" << menu[i].name << "\t\t$" << menu[i].price << "\n";
    }
}

// Function to display order receipt
void printReceipt(const MenuItem menu[], const int menuSize, const OrderItem order[], const int orderSize) {
    float subtotal = 0.0;

    cout << "\nYour Order:\n";
    cout << "Item No\tMenu Item\tQty\tPrice\n";
    cout << "-------------------------------------\n";

    for (int i = 0; i < orderSize; i++) {
        for (int j = 0; j < menuSize; j++) {
            if (menu[j].itemNo == order[i].itemNo) {
                float itemTotal = menu[j].price * order[i].quantity;
                cout << menu[j].itemNo << "\t" << menu[j].name << "\t\t" << order[i].quantity << "\t$" << itemTotal << "\n";
                subtotal += itemTotal;
                break;
            }
        }
    }

    const float tax = subtotal * 0.05; // 5% tax
    const float total = subtotal + tax;

    cout << "-------------------------------------\n";
    cout << "Subtotal:\t\t$" << subtotal << "\n";
    cout << "Tax (5%):\t\t$" << tax << "\n";
    cout << "Total Amount:\t\t$" << total << "\n";
}

int main() {
    const int MAX_MENU = 10;  // Max menu items
    const int MAX_ORDER = 10; // Max orders
    MenuItem menu[MAX_MENU];  // Array to store menu
    OrderItem order[MAX_ORDER]; // Array to store orders
    int menuSize;
    int orderSize = 0;
    int choice, quantity;

    loadMenu(menu, menuSize); // Load menu items to array

    do {
        cout << "\n";
        displayMenu(menu, menuSize);
        cout << "\nEnter item number to order (0 to finish): ";
        cin >> choice;

        if (choice != 0) {
            bool found = false;

            // Check if item exists in menu
            for (int i = 0; i < menuSize; i++) {
                if (menu[i].itemNo == choice) {
                    cout << "Enter quantity for " << menu[i].name << ": ";
                    cin >> quantity;

                    while (quantity <= 0) {
                        cout << "Invalid quantity. Enter again: ";
                        cin >> quantity;
                    }

                    order[orderSize++] = {choice, quantity};
                    found = true;
                    cout << quantity << " " << menu[i].name << "(s) added to order.\n";
                    break;
                }
            }

            if (!found) {
                cout << "Invalid item number. Try again.\n";
            }
        }
    } while (choice != 0 && orderSize < MAX_ORDER);

    // Print receipt if order exists
    if (orderSize > 0) {
        printReceipt(menu, menuSize, order, orderSize);
    } else {
        cout << "\nNo items ordered.\n";
    }

    cout << "\nThank you for dining at Meal Hut!\n";
    return 0;
}

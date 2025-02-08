#include <iostream>
#include <iomanip>
using namespace std;

// Structure to store menu items
struct MenuItem
{
    int itemNo;
    string itemName;
    double price;
};

// Function to load data into menuList
void getData(MenuItem menuList[], int &menuSize)
{
    // Initialize menu items
    menuList[0] = {111, "Plain Egg", 1.45};
    menuList[1] = {112, "Bacon and Egg", 2.45};
    menuList[2] = {113, "Muffin", 0.99};
    menuList[3] = {114, "French Toast", 1.99};
    menuList[4] = {115, "Fruit Basket", 2.49};
    menuList[5] = {116, "Cereal", 0.69};
    menuList[6] = {117, "Coffee", 0.50};
    menuList[7] = {118, "Tea", 0.75};
    menuSize = 8; // Number of items in the menu
}

// Function to display the menu in a table format
void showMenu(const MenuItem menuList[], int menuSize)
{
    cout << "********Welcome to Meal Hut*********\n";
    cout << "          Breakfast Billing System\n";
    cout << "--------------------------------------------\n";
    cout << left << setw(10) << "Item No" << setw(20) << "Menu Item" << setw(10) << "Price" << endl;
    cout << "--------------------------------------------\n";
    for (int i = 0; i < menuSize; i++)
    {
        cout << left << setw(10) << menuList[i].itemNo << setw(20) << menuList[i].itemName << "$" << fixed << setprecision(2) << menuList[i].price << endl;
    }
    cout << "--------------------------------------------\n";
}

// Function to calculate and print the bill in a table format
void printCheck(const int selectedItems[], int selectedSize, const MenuItem menuList[], int menuSize)
{
    double subtotal = 0.0;
    cout << "\n********Your Bill********\n";
    cout << "--------------------------------------------\n";
    cout << left << setw(10) << "Item No" << setw(20) << "Menu Item" << setw(10) << "Price" << endl;
    cout << "--------------------------------------------\n";
    for (int i = 0; i < selectedSize; i++)
    {
        for (int j = 0; j < menuSize; j++)
        {
            if (menuList[j].itemNo == selectedItems[i])
            {
                cout << left << setw(10) << menuList[j].itemNo << setw(20) << menuList[j].itemName << "$" << fixed << setprecision(2) << menuList[j].price << endl;
                subtotal += menuList[j].price;
                break;
            }
        }
    }
    double tax = subtotal * 0.05;
    double total = subtotal + tax;
    cout << "--------------------------------------------\n";
    cout << right << setw(30) << "Tax: " << "$" << fixed << setprecision(2) << tax << endl;
    cout << right << setw(30) << "Amount Due: " << "$" << fixed << setprecision(2) << total << endl;
    cout << "--------------------------------------------\n";
}

int main()
{
    const int MAX_MENU_ITEMS = 100;     // Maximum number of menu items
    const int MAX_SELECTED_ITEMS = 100; // Maximum number of selected items
    MenuItem menuList[MAX_MENU_ITEMS];
    int selectedItems[MAX_SELECTED_ITEMS];
    int menuSize = 0;     // Number of items in the menu
    int selectedSize = 0; // Number of selected items
    int choice;

    // Load menu data
    getData(menuList, menuSize);

    do
    {
        cout << "\n********Welcome to Meal Hut*********\n";
        cout << "1. Show Menu\n";
        cout << "2. Add Item to Order\n";
        cout << "3. Print Bill\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            showMenu(menuList, menuSize);
            break;
        case 2:
            int itemNo;
            cout << "Enter item number to add to order: ";
            cin >> itemNo;
            if (selectedSize < MAX_SELECTED_ITEMS)
            {
                selectedItems[selectedSize] = itemNo;
                selectedSize++;
                cout << "Item added to order.\n";
            }
            else
            {
                cout << "Order limit reached. Cannot add more items.\n";
            }
            break;
        case 3:
            printCheck(selectedItems, selectedSize, menuList, menuSize);
            break;
        case 4:
            cout << "Thank you for using Meal Hut!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
# Breakfast Billing System

This project is a console-based C++ application for managing a restaurant's breakfast billing system. It allows customers to select breakfast items, calculates the total cost including tax, and displays a detailed bill.

## Features
- Displays a menu of breakfast items with prices.
- Allows customers to select multiple items.
- Calculates the total bill, including a 5% tax.
- Provides a detailed breakdown of selected items and the total amount due.

## Menu Items
| Item No | Menu Item           | Price  |
|---------|---------------------|--------|
| 111     | Plain Egg           | $1.45  |
| 112     | Bacon and Egg       | $2.45  |
| 113     | Muffin              | $0.99  |
| 114     | French Toast        | $1.99  |
| 115     | Fruit Basket        | $2.49  |
| 116     | Cereal              | $0.69  |
| 117     | Coffee              | $0.50  |
| 118     | Tea                 | $0.75  |

## How It Works
1. The application loads the menu items into an array.
2. It displays the menu and allows users to select items by entering their item numbers and quantities.
3. The application calculates the total cost of the selected items.
4. A 5% tax is added to the total.
5. The detailed bill is displayed, including itemized costs, tax, and the final amount due.

## Example Output
```
********Welcome to Meal Hut*********
        Breakfast Billing System

Item No   Menu Item           Price
111       Plain Egg           $1.45
112       Bacon and Egg       $2.45
113       Muffin              $0.99
...

Enter the item number to add to your order (or 0 to finish): 112
Enter quantity for Bacon and Egg: 2
...

********Your Bill*********
Item No   Menu Item           Price    Quantity   Total
112       Bacon and Egg       $2.45    2          $4.90
...
Tax: $0.25
Amount Due: $5.15
```

## Assumptions
- All prices are fixed and inclusive of any applicable discounts.
- The user provides valid input for item numbers and quantities.

## File Structure
- `main.cpp`: Contains the implementation of the billing system.

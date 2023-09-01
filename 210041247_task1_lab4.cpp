#include <iostream>
#include <string>
using namespace std;

class Product
{
private:
    string name;
    int id;
    double price;
    int quantity;
    int maxQuantity;
    bool availability;

public:
    static double totalInventoryValue;
    Product()
    {
        name = "";
        id = 0;
        price = 0;
        quantity = 0;
        maxQuantity = 0;
        availability = false;
    }
    Product(string input_name, int input_id, double input_price, int input_quantity, int input_maxquantity)
    {
        name = input_name;
        id = input_id;
        price = input_price;
        quantity = input_quantity;
        maxQuantity = input_maxquantity;
        if (quantity == 0)
        {
            availability = false;
        }
        else
        {
            availability = true;
        }
    }
    ~Product()
    {
        name = "";
    }
    string getter_name()
    {
        return name;
    }
    int getter_id()
    {
        return id;
    }
    double getter_price()
    {
        return price;
    }
    int getter_quantity()
    {
        return quantity;
    }
    bool getter_availability()
    {
        return availability;
    }
    void setter_name(string input_name)
    {
        name = input_name;
    }
    void setter_id(int input_id)
    {
        id = input_id;
    }
    void setter_price(double input_price)
    {
        price = input_price;
    }
    void setter_quantity(int input_quantity)
    {
        if (input_quantity <= maxQuantity)
        {
            quantity = input_quantity;
            availability = true;
        }
    }
    void setter_availability(bool input_availability)
    {
        availability = input_availability;
    }
    void setMaxQuantity(int qty)
    {
        maxQuantity = qty;
    }
    void addToInventory(int added_quantity)
    {
        quantity += added_quantity;
    }
    bool isAvailable()
    {
        return availability;
    }
    void purchase(int purchased_quantity)
    {
        if (purchased_quantity <= quantity)
        {
            quantity -= purchased_quantity;
        }
    }
    int updatePrice(int percent)
    {
        price = price + price * ((double)percent) / 100;
        return 0;
    }
    void calculatetotalinventoryvalue()
    {
        totalInventoryValue += quantity * price;
    }
    void displayInventoryValue()
    {
        cout << "Total value  of products of " << name << " is: " << (double)quantity * price << endl;
    }
    void displayDetails()
    {
        cout << "Product Name: " << name << endl;
        cout << "Produce id: " << id << endl;
        cout << "Product Price: " << price << endl;
        cout << "Product quantitiy: " << quantity << endl;
        if (availability)
        {
            cout << "Product availability: available" << endl;
        }
        else
        {
            cout << "Product availability: Unavailable" << endl;
        }
    }
    void displayTotalInventoryValue()
    {
        cout << "Total value is: " << totalInventoryValue << endl;
    }
};
double Product::totalInventoryValue;

int main()
{
    Product sun;
    Product lays("Lays", 1, 25, 10, 15);
    Product meridian("Meridian", 2, 15, 5, 15);
    lays.displayDetails();
    sun.displayDetails();
    meridian.displayDetails();
    sun.setter_name("sun");
    sun.setter_id(3);
    sun.setter_quantity(13);
    sun.setMaxQuantity(20);
    sun.setter_price(10);
    sun.displayDetails();
    sun.updatePrice(50);
    sun.displayDetails();
    sun.setter_quantity(13);
    sun.displayDetails();
    lays.calculatetotalinventoryvalue();
    sun.calculatetotalinventoryvalue();
    meridian.calculatetotalinventoryvalue();
    meridian.displayTotalInventoryValue();
    return 0;
}
#include <iostream>
#include <string>
using namespace std;

class Medicine
{
private:
    string name;
    string genericName;
    double discountPercent;
    double unitPrice;
    double initialPrice;

public: 
    static double totalsoldprice;
    Medicine()
    {
        name = "";
        genericName = "";
        discountPercent = 0;
        unitPrice = 0;
        initialPrice = 0;
    }
    Medicine(string input_name, string input_generic_name, double input_unitprice)
    {
        name = input_name;
        genericName = input_generic_name;
        unitPrice = input_unitprice;
        initialPrice = input_unitprice;
        discountPercent = 0;
    }
    ~Medicine()
    {

    }
    void setName(string input_name)
    {
        name = input_name;
    }
    string getName()
    {
        return name;
    }
    void setGenericName(string input_generic_name)
    {
        genericName = input_generic_name;
    }
    string getGenericName()
    {
        return genericName;
    }
    void setDiscoutPercent(double discount = 15)
    {
        if (discount > 0 && discount <= 45)
            discountPercent = discount;
    }
    double getDiscountPercent()
    {
        return discountPercent;
    }
    void setPrice(double input_price = 0)
    {
        unitPrice = input_price;
    }
    double getSellingPrice()
    {
        return unitPrice - unitPrice*discountPercent/100;
    }
    bool isAffordable(double budget)
    {
        if(budget<unitPrice)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    void resetPrice()
    {
        unitPrice = initialPrice;
        cout << "Initial price is: " << initialPrice << endl;
    }
    void sell(int amount)
    {
        totalsoldprice += amount*getSellingPrice();
    }
    void showtotalSoldPrice()
    {
        cout << "Total price of sold medicine is : " << totalsoldprice << endl;
    }
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Generic Name: " << genericName << endl;
        cout << "Unit Price : " << unitPrice << endl;
        cout << "discount : " << discountPercent << endl;
    }
};

double Medicine::totalsoldprice;
int main()
{
    Medicine napa("napa","Paracetamol", 1);
    Medicine fexo("fexo", "Fenadin", 5);
    Medicine antacid("antacid" , "antacid",2);
    napa.setPrice(2);
    napa.display();
    napa.resetPrice();
    napa.setDiscoutPercent(15);
    napa.getSellingPrice();
    napa.display();
    fexo.display();
    antacid.display();
    fexo.sell(5);
    napa.sell(10);
    if(fexo.isAffordable(2))
    {
        cout << "Affordable" << endl;
    }
    else
    {
        cout << "Not affordable" << endl;
    }
    napa.showtotalSoldPrice();
    return 0;

}
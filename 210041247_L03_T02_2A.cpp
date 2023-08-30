#include<iostream>
#include<cstring>
//#include<cstdlib>
using namespace std;

class Medicine
{
private:
    char name[20];
    char  genericName[50];
    double discountPercent,unitPrice;
public:
    void assignName(char input_name[], char input_genericName[])
    {
        strcpy(name,input_name);
        strcpy(genericName,input_genericName);
    }
    void assignPrice(double price = 0)
    {
        if(price < 0)
        {
            cout << "Error: Invalid Price" << endl;
            return;
        }
        unitPrice = price;
    }
    void setDiscountPercent(double percent = 5)
    {
        if(percent >= 0 && percent <= 45)
        {
            discountPercent = percent;
        }
        else
        {
            cout << "Error: Discount must be between 0-45" << endl;
        }
    }
    double getSellingPrice()
    {
        double selling_price = unitPrice - unitPrice*discountPercent/100;
        return selling_price;
    }
    void display()
    {
        cout << name << " (" << genericName << ") has a unit price BDT " << unitPrice << ". Current discount " << discountPercent<< "%" << endl;

    }
};

int main()
{
    Medicine test_medicine;
    test_medicine.assignName("Napa","Paracetamol");
    test_medicine.assignPrice(.80);
    test_medicine.setDiscountPercent(46);
    test_medicine.setDiscountPercent(25);
    test_medicine.display();
    cout << "Selling price is " << test_medicine.getSellingPrice() << endl;
}

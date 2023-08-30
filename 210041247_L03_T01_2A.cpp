#include<iostream>
using namespace std;


class RationalNumber
{
    private:
        int numerator;
        int denominator;
    public:
        void assign_values(int input_numerator, int input_denominator)
        {
            if(input_denominator)
            {
                numerator = input_numerator;
                denominator = input_denominator;
            }
            else
            {
                cout << "The values are mathematically undefined"<< endl;
            }


        }
        double convert()
        {
            double value = (double)numerator/(double)denominator;
            return value;
        }
        void invert()
        {
            if(numerator)
            {
                int temp = numerator;
                numerator = denominator;
                denominator = temp;
            }
            else
            {
                cout << "Mathematically undefined operation" << endl;
            }
        }
        void print()
        {
            cout << "The Rational Number is " << numerator << '/' << denominator <<endl;
        }
};

int main()
{
    int a = 3, b= 2;
    int c = 0, d = 1;
    RationalNumber test_rational_number;
    RationalNumber test_rational_number1;

    test_rational_number.assign_values(3,2);
    cout << "converted value for 3/2 is " << test_rational_number.convert() << endl;
    test_rational_number.print();
    test_rational_number.invert();
    cout << "Print after inversion: ";
    test_rational_number.print();

    test_rational_number1.assign_values(c,d);
    test_rational_number1.invert();
    test_rational_number1.assign_values(d,c);
    return 0;
}

#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    int accountnumber;
    string holdername;
    string accounttype;
    double currentbalance;
    double minimumbalance;
    int penaltyfee;

public:
    static int totalaccounts;
    BankAccount()
    {
        totalaccounts++;
        accountnumber = 0;
        holdername = "";
        accounttype = "";
        currentbalance = 500;
        minimumbalance = 500;
        penaltyfee = 20;
    }
    BankAccount(int input_accountnumber, string input_holdername, string input_accounttype, double input_accountbalance, double input_minimumbalance)
    {
        totalaccounts++;
        accountnumber = input_accountnumber;
        holdername = input_holdername;
        accounttype = input_accounttype;
        currentbalance = input_accountbalance;
        minimumbalance = input_minimumbalance;
        penaltyfee = 20;
    }
    void showBalance()
    {
        cout << "Balance is: " << currentbalance << endl;
    }
    void deposit(int value)
    {
        currentbalance += value;
    }
    void withdrawal(int value)
    {
        if (value > currentbalance)
        {
            cout << "Low balance : Can't withdraw" << endl;
        }
        else
        {
            currentbalance -= value;
        }
    }
    void giveinterest()
    {
        currentbalance += (3.0 - .1)*currentbalance/100.0; 
    }
    void printAccountStatement()
    {
        cout << "Account number: " << accountnumber << endl;
        cout << "Account Holder name: " << holdername << endl;
        cout << "Account current balance: " << currentbalance << endl;
        cout << "Account type: " << accounttype << endl;
    }
    void appPenalty()
    {
        if (currentbalance < minimumbalance)
            currentbalance -= penaltyfee;
    }
    static void showtotalAccounts()
    {
        cout << "Total accouts created: " << totalaccounts << endl;
    }
    ~BankAccount()
    {
        cout << "Account of " << holdername << "with account no " << accountnumber << " is destroyed with a balance of BDT of " << currentbalance << endl;
    }
};

int BankAccount::totalaccounts;
int main()
{
    BankAccount first;
    BankAccount secound(100, "Jaber", "saving", 2000, 500);
    BankAccount third(101, "Ismail", "saving", 5000, 500);
    first.showtotalAccounts();
    secound.giveinterest();
    secound.withdrawal(1700);
    secound.showBalance();
    secound.appPenalty();
    return 0;
}
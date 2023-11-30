#include<iostream>
#include<string>
using namespace std;

class product
{
    protected:
        static int no_of_product;
        string title;
        string author;
        int id;
    public:
        product(string _title,string _author, int _id)
        {
            title = _title;
            author = _author;
            id = _id;
            no_of_product++;
        }
        virtual void displayInfo() const = 0;
        static int getnoofproduct()
        {
            return no_of_product;
        }
};
int product::no_of_product;
class book : public product
{
    public:
        book(string _title,string _author, int _id):product(_title,_author,_id)
        {}
        void displayInfo() const
        {
            cout << "Info:" << endl;
            cout << "Type: Book" << endl;
            cout<< "Title: " << title << endl;
            cout << "Author: " << author << endl;
            cout << "ID: " << id << endl<<endl;
        }
        bool operator<(const  book& pro)
        {
            return id< pro.id;
        }
        bool operator>(const  book& pro)
        {
            return id> pro.id;
        }
        bool operator==(const  book& pro)
        {
            return id== pro.id;
        }
        void operator=(const  book& pro)
        {
            title = pro.title;
            author = pro.author;
            id = pro.id;
        }

};
class dvd : public product
{
    public:
        dvd(string _title,string _author, int _id):product(_title,_author,_id)
        {}
        void displayInfo() const
        {
            cout << "Info:" << endl;
            cout << "Type: DVD" << endl;
            cout<< "Title: " << title << endl;
            cout << "Author: " << author << endl;
            cout << "ID: " << id << endl<< endl;
        }
        bool operator<(const dvd& pro)
        {
            return id< pro.id;
        }
        bool operator>(const dvd& pro)
        {
            return id> pro.id;
        }
        bool operator==(const dvd& pro)
        {
            return id== pro.id;
        }
        void operator=(const dvd& pro)
        {
            title = pro.title;
            author = pro.author;
            id = pro.id;
        }

};
int main()
{
    product* inventory[10];
    inventory[0] = new book("book1","author1",101);
    inventory[1] = new book("book2","author2",102);
    inventory[2] = new book("book3","author3",103);
    inventory[3] = new book("book4","author4",104);
    inventory[4] = new book("book5","author5",105);
    inventory[5] = new dvd("dvd1","author1",201);
    for(int i= 0;i< 5;i++)
    {
        inventory[i]->displayInfo();
    }
    if(inventory[0]>inventory[1])
    {
        cout << "Product 0 is greater then produt 1"<< endl;
    }
    else{
        cout << "Product 0 is less then produt 1"<< endl;
    }
    cout << endl;
    //default copy  constructor example:
    book b1("book1","author1",101);
    book b2 = b1;
    b1.displayInfo();
    //my own assingnment operator using operator overloading:
    book b3("book5","author5",105);
    b3 = b2;
    b3.displayInfo();
    //here the stirng is handled by string class so no dynamic memmory allocation.So, no problem with default copy constructor
    //but if we used the dynamic memory allocation then it would just copy the pointer and wouldnt copy the strings.
    //same goes for pointer based data sturcture like arrays as it will only copy the pointer and wont copy the content which is known as shallow copy.

    cout << endl;
    cout << "Total no of product is: " << product::getnoofproduct() << endl;
    

    return 0;
}
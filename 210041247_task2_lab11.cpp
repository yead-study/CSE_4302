#include<iostream>
#include<string>
#include <fstream>            //for file-stream functions
#include <iostream>
#include <typeinfo> 
//#include <process.h>
#include<bits/stdc++.h>
using namespace std;
const int LEN = 32;           //maximum length of last names
const int MAXEM = 100; 
enum product_type{tbook,tdvd};
class product
{
    protected:
        string title;
        string author;
        int id;
         float unitprice;
         static int n;
         static  product* arrap[];
      static int getnoofproduct()
        {
            return n;
        }
    public:
    product(){}
        product(string _title,string _author, int _id,float _unitprice)
        {
            title = _title;
            author = _author;
            id = _id;
            unitprice = _unitprice;
            n++;
        }
        virtual void displayInfo() const = 0;
        static void write();
        static void read();
        static void add();
        virtual product_type get_type();
        void getdata()
        {
         cout << "title: "; cin >> title;
         cout << "author: " ; cin >> author;
         cout << "id: " ; cin >> id;
         cout << "unitprice: "; cin >> unitprice;
        }
   static void display()
   {
   for(int j=0; j<n; j++)
      {
      cout  << (j+1);           //display number
      switch( arrap[j]->get_type() )   //display type
         {
         case tdvd:    cout << ". Type: dvd";   break;
         case tbook:  cout << ". Type: book"; break;
         default: cout << ". Unknown type";
         }
      arrap[j]->displayInfo();    //display employee data
      cout << endl;
      }
   }

};
int product::n;              //current number of 
product* product::arrap[MAXEM];
class book : public product
{
    public:
      book()
      {}
        book(string _title,string _author, int _id,float _unitprice):product(_title,_author,_id,_unitprice)
        {}
        void displayInfo() const
        {
            cout << "\nInfo:" << endl;
            cout << "Type: Book" << endl;
            cout<< "Title: " << title << endl;
            cout << "Author: " << author << endl;
            cout << "ID: " << id << endl;
            cout << "Unitprice: " << unitprice << endl<< endl;
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
      dvd()
      {}
        dvd(string _title,string _author, int _id,float _unitprice):product(_title,_author,_id,_unitprice)
        {}
        void displayInfo() const
        {
            cout << "\nInfo:" << endl;
            cout << "Type: DVD" << endl;
            cout<< "Title: " << title << endl;
            cout << "Author: " << author << endl;
            cout << "ID: " << id << endl;
            cout << "Unitprice: " << unitprice << endl << endl;
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
product_type product::get_type()
   {
   if( typeid(*this) == typeid(dvd) )
      return tdvd;
   else if( typeid(*this)==typeid(book) )
      return tbook;
   
   else
      { cerr << "\nBad product type"; exit(1); }
   return tbook;
   }
   void product::add()
   {
   char ch;
   cout << "'m' to add a book"
           "\n's' to add a dvd"
           "\nEnter selection: ";
   cin >> ch;
   switch(ch)
      {                       //create specified product type
      case 'm': arrap[n] = new book;   break;
      case 's': arrap[n] = new dvd; break;
      default: cout << "\nUnknown product type\n"; return;
      }
   arrap[n++]->getdata();     //get product data from user
   }
void product::write()
   {
   int size;
   cout << "Writing " << n << " products.\n";
   ofstream ouf;              //open ofstream in binary
   product_type etype;       //type of each product object

   ouf.open("EMPLOY.DAT", ios::trunc | ios::binary);
   if(!ouf)
      { cout << "\nCan't open file\n"; return; }
   for(int j=0; j<n; j++)     //for every product object
      {                       //get its type
      etype = arrap[j]->get_type();
                              //write type to file
      ouf.write( (char*)&etype, sizeof(etype) );
      switch(etype)           //find its size
         {
         case tdvd:   size=sizeof(dvd); break;
         case tbook: size=sizeof(book); break;
         }                    //write product object to file
      ouf.write( (char*)(arrap[j]), size );
      if(!ouf)
         { cout << "\nCan't write to file\n"; return; }
      }
   }
void product::read()
   {
   int size;                  //size of product object
   product_type etype;       //type of product
   ifstream inf;              //open ifstream in binary
   inf.open("EMPLOY.DAT", ios::binary);
   if(!inf)
      { cout << "\nCan't open file\n"; return; }
   n = 0;                     //no products in memory yet
   while(true)
      {                       //read type of next product
      inf.read( (char*)&etype, sizeof(etype) );
      if( inf.eof() )         //quit loop on eof
         break;
      if(!inf)                //error reading type
         { cout << "\nCan't read type from file\n"; return; }
      switch(etype)
         {                    //make new product
         case tbook:       //of correct type
            arrap[n] = new book;
            size=sizeof(book);
            break;
         case tdvd:
            arrap[n] = new dvd;
            size=sizeof(dvd);
            break;
         
         default: cout << "\nUnknown type in file\n"; return;
         }                    //read data from file into it
      inf.read( (char*)arrap[n], size  );
      if(!inf)                //error but not eof
         { cout << "\nCan't read data from file\n"; return; }
      n++;                    //count product
      }  //end while
   cout << "Reading " << n << " products\n";
   }

int main()
{
   char ch;
   while(true)
      {
      cout << "'a' -- add data for an product"
              "\n'd' -- display data for all products"
              "\n'w' -- write all product data to file"
              "\n'r' -- read all product data from file"
              "\n'x' -- exit"
              "\nEnter selection: ";
      cin >> ch;
      switch(ch)
         {
         case 'a':            //add an product to list
            product::add(); break;
         case 'd':            //display all products
            product::display(); break;
         case 'w':            //write products to file
            product::write(); break;
         case 'r':            //read all products from file
            product::read(); break;
         case 'x': exit(0);   //exit program
         default: cout << "\nUnknown command";
         }  //end switch
      }  //end while


   return 0;
}

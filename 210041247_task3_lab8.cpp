#include <iostream>
using namespace std;

class Book
{
private:
    string title;
    string author;
    string publicationdate;
    string isbn;
    string edition;

public:
    Book() {}
    Book(string _title, string _author, string _publicationdate, string _isbn, string _edition)
    {
        title = _title;
        author = _author;
        publicationdate = _publicationdate;
        isbn = _isbn;
        edition = _edition;
    }
    void setvalues(string _title, string _author, string _publicationdate, string _isbn, string _edition)
    {
        title = _title;
        author = _author;
        publicationdate = _publicationdate;
        isbn = _isbn;
        edition = _edition;
    }
    string getTitle()
    {
        return title;
    }

    string getAuthor()
    {
        return author;
    }

    string getPublicationDate()
    {
        return publicationdate;
    }

    string getISBN()
    {
        return isbn;
    }

    string getEdition()
    {
        return edition;
    }
};

class Members
{
private:
    string name;
    string postal;
    string phone;
    string email;
    string membership;

public:
    Members() {}
    Members(string _name, string _postal, string _phone, string _email, string _membership)
    {
        name = _name;
        postal = _postal;
        phone = _phone;
        email = _email;
        membership = _membership;
    }
    void setvalue(string _name, string _postal, string _phone, string _email, string _membership)
    {
        name = _name;
        postal = _postal;
        phone = _phone;
        email = _email;
        membership = _membership;
    }
    string getName()
    {
        return name;
    }

    string getPostalAddress()
    {
        return postal;
    }

    string getPhoneNumber()
    {
        return phone;
    }

    string getEmail()
    {
        return email;
    }

    string getMembershipStatus()
    {
        return membership;
    }
};

class Library
{
private:
    string name;
    string location;
    string workhour;
    Book library_book[10];
    Members library_member[5];
    int bookCount;
    int memberCount;

public:
    Library() {}
    Library(string _name, string _location, string _workhour)
    {
        name = _name;
        location = _location;
        workhour = _workhour;
        bookCount = 0;
        memberCount = 0;
    }
    void addBook(const Book &book)
    {
        if (bookCount < 10)
        {
            library_book[bookCount] = book;
            bookCount++;
        }
    }
    void addMember(const Members &member)
    {
        if (memberCount < 5)
        {
            library_member[memberCount] = member;
            memberCount++;
        }
    }
    void showbook()
    {
        for (int i = 0; i < bookCount; i++)
        {
            cout << "title:" << library_book[i].getTitle() << endl;
            cout << "author: " << library_book[i].getAuthor() << endl;
            cout << "publication date: " << library_book[i].getPublicationDate() << endl;
            cout << "ISBN:" << library_book[i].getISBN() << endl;
            cout << "edition: " << library_book[i].getEdition() << endl;
        }
    }
    void showMemberDetails()
    {
        for (int i = 0; i < memberCount; i++)
        {
            cout << "Name:" << library_member[i].getName() << endl;
            cout << "Postal Address: " << library_member[i].getPostalAddress() << endl;
            cout << "Phone:" << library_member[i].getPhoneNumber() << endl;
            cout << "Email: " << library_member[i].getEmail() << endl;
            cout << "Membership: " << library_member[i].getMembershipStatus() << endl;
        }
    }
    void showAll()
    {
        showbook();
        showMemberDetails();
    }
};

int main()
{
    Library mylibrary("libname","liblocation","9-6");
    Book book1("Book1", "Author1", "1/2/2001", "132412312341234", "edition1");
    Book book2("Book2", "Author2", "12/123/123", "1324123412342134", "edition2");
    Book book3("Book3", "Author3", "12/123/123", "1234123412", "edition3");
    Book book4("Book3", "Author3", "12/123/123", "1234123412", "edition3");
    Book book5("Book3", "Author3", "12/123/123", "1234123412", "edition3");
    Book book6("Book3", "Author3", "12/123/123", "1234123412", "edition3");
    Book book7("Book3", "Author3", "12/123/123", "1234123412", "edition3");
    Book book8("Book3", "Author3", "12/123/123", "1234123412", "edition3");
    Book book9("Book3", "Author3", "12/123/123", "1234123412", "edition3");
    Book book10("Book3", "Author3", "12/123/123", "1234123412", "edition3");
    mylibrary.addBook(book1);
    mylibrary.addBook(book2);
    mylibrary.addBook(book3);
    mylibrary.addBook(book4);
    mylibrary.addBook(book5);
    mylibrary.addBook(book6);
    mylibrary.addBook(book7);
    mylibrary.addBook(book8);
    mylibrary.addBook(book9);
    mylibrary.addBook(book10);
    Members member1("Member1", "addd1", "1234123412", "adfasd@asdfasf", "mem1");
    Members member2("Member2", "add1", "12341234123", "adfasdsad@asdfasdfas", "mem2");
    Members member3("Member3", "add3", "132412342134", "asdsfas@adfasdfasd", "mem3");
    mylibrary.addMember(member1);
    mylibrary.addMember(member2);
    mylibrary.addMember(member3);
    mylibrary.addMember(member3);
    mylibrary.addMember(member3);
    mylibrary.showAll();
    return 0;
}

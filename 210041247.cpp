#include<iostream>
#include<string>
using namespace std;

class Student
{
private:
    const int MAX_MARKS = 100;
    const int MAX_COURSES = 5;
    string name;
    string courses[6];
    float marks[6];
public:
    Student()
    {
        name = "";
        for(int i = 0; i< MAX_COURSES+1; i++)
        {
            marks[i] = 0;
        }
    }
    Student(string input_name)
    {
        name = input_name;
    }
    string getname()const
    {
        return name;
    }
    string setname(string input_name)
    {
        name = input_name;
    }
    void setcoursename()
    {
        string temp;
        cout << "Input the course name:" << endl;
        for(int i = 0; i< MAX_COURSES; i++)
        {
            cin >> temp;
            courses[i] = temp;
        }
    }
    void setmarks()
    {
        float temp;
        cout << "Enter the marks:" << endl;
        for(int i = 0; i< MAX_COURSES; i++)
        {
            cin >> temp;
            if(temp > 100)
            {
                cout << "Inavlid marks. Insert again:" << endl;
                i--;
            }
            else{
                marks[i] = temp;
            }
        }
    }
    float getmarks(int index)const
    {
        if(index >= MAX_COURSES)
        {
            return marks[5];
        }
        else
        {
            return marks[index];
        }
    }
    float& operator[](int index)
    {
        if(index >= MAX_COURSES)
        {
            return marks[5];
        }
        else
        {
            return marks[index];
        }
    }
};

class CGPA
{
private:
    string name;
    float cgpa;
public:
    CGPA()
    {
        name = "";
        cgpa = 0;
    }
    CGPA(Student stu)
    {
        name = stu.getname();
        float temptotalgpa =0 ;
        for(int i = 0; i< 5; i++)
        {
            temptotalgpa+= calcGPA(stu.getmarks(i));
        }
        cgpa = temptotalgpa/5;

    }
    float calcGPA(float marks)
    {
        if(marks >= 80)
        {
            return 4.0;
        }
        else if(marks >= 75)
        {
            return 3.75;
        }
        else if(marks >= 70)
        {
            return 3.5;
        }
        else if(marks >= 65)
        {
            return 3.25;
        }
        else if(marks >= 60)
        {
            return 3.00;
        }
        else if(marks >= 55)
        {
            return 2.75;
        }
        else if(marks >= 50)
        {
            return 2.5;
        }
        else if(marks >= 45)
        {
            return 2.00;
        }
        else if(marks >= 40)
        {
            return 1.00;
        }
        else
        {
            return 0;
        }
    }
    float getcg()
    {
        return cgpa;
    }
};


int main()
{
//    Student s[5];
//    Student k;
//    s[0].setname("aaaaa");
//    s[1].setname("baaaa");
//    s[2].setname("caaaa");
//    s[3].setname("daaaa");
//    s[5].setname("eaaaa");
//    s[0][0] = 80;
//    cout << s[0][0];
//    k[0] = 2;
//    cout << k[0];
    Student s;
    s.setname("asdfa");
    cout << s.getname();
    s.setmarks();
    cout <<"Marks" << s[0] << endl;
    //CGPA cg(s);
    return 0;
}

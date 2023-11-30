#include<iostream>

using namespace std;
#define Max 10

template<class T>

class stack
{
private:
    T arr[Max];
    int top;
public:
    stack()
    {
        top = -1;
    }
    void push(T input)
    {
        if(top < Max)
        {
            top++;
        }
        else
        {
            cout << "Memory full" << endl;
            return;
        }
        arr[top] = input;
    }
    T pop()
    {
        top--;
        return arr[top+1];
    }
    T peek()
    {
        return arr[0];
    }

};

int main()
{
    stack<int> mystack1;
    mystack1.push(100);
    mystack1.push(200);
    cout << mystack1.peek() << endl;
    mystack1.pop();
    cout << mystack1.peek() << endl;
    mystack1.pop();
    //mystack1.pop();
    stack<char> mystack2;
    mystack2.push('a');
    mystack2.push('b');
    cout << mystack2.peek()<< endl;
    mystack2.pop();
    cout << mystack2.peek() << endl;
    mystack2.pop();
    //mystack2.pop();
    return 0;
}
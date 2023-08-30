#include<iostream>
using namespace std;

class Time
{
private:
    int minute;
    int hour;
    int secound;
public:
    int hours()
    {
        return hour;
    }
    int minutes()
    {

        return minute;
    }
    int secounds()
    {
        return secound;
    }
    void reset(int h, int m, int s)
    {
        minute = m;
        hour = h;
        secound = s;
    }
    void advance(int h, int m, int s)
    {
        if(secound + s >= 60)
        {
            minute += (secound+s)/60;
            secound = (secound+s)%60;
        }
        else
        {
            secound += s;
        }
        if(minute + m >= 60)
        {
            hour += (minute+m)/60;
            minute = (minute+m)%60;
        }
        else
        {
            minute+= m;
        }
        if(hour + h >= 24)
        {
            hour = (hour+h)%24;
        }
        else
        {
            hour += h;
        }
    }
    void print()
    {
        cout << "Time " << hour << ":" << minute << ":" << secound << endl;
    }
};

int main()
{
    Time test_time;
    test_time.reset(12,12,12);
    test_time.print();
    test_time.advance(12,12,12);
    test_time.print();
    return 0;
}

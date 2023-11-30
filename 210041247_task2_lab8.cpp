#include <iostream>
#include <string>
using namespace std;

class seats
{
private:
    string comfort;
    bool warm;

public:
    seats() : comfort(""), warm(false) {}
    seats(string _comfort, bool _warm) : comfort(_comfort), warm(_warm) {}
    void setcomfort(string _comfort) { comfort = _comfort; }
    string getcomfort() { return comfort; }
    void setwarm(bool _warm) { warm = _warm; }
    bool getwarm() { return warm; }
};

class wheels
{
private:
    float circum;

public:
    wheels() : circum(0.0) {}
    wheels(float _circum) : circum(_circum) {}
    void setcircum(float _circum) { circum = _circum; }
    float getcircum() { return circum; }
};

class engine
{
private:
    float maxf;
    float maxe;
    float rpm;

public:
    engine() : maxf(0.0), maxe(0.0), rpm(0.0) {}
    engine(float _maxf, float _maxe, float _rpm) : maxf(_maxf), maxe(_maxe), rpm(_rpm) {}
    void setmaxf(float _maxf) { maxf = _maxf; }
    void setmaxe(float _maxe) { maxe = _maxe; }
    void setrpm(float _rpm) { rpm = _rpm; }
    float getrpm() { return rpm; }
    float getmaxe() { return maxe; }
    float getmaxf() { return maxf; }
};

class door
{
private:
    string openmode;

public:
    door() : openmode("") {}
    door(string _openmode) : openmode(_openmode) {}
    void setopenmode(string _openmode) { openmode = _openmode; }
    string getopenmode() { return openmode; }
};

class car
{
private:
    float max_acce;
    float fuel_cap;
    seats carseat;
    wheels carwheels;
    engine carengine;
    door cardoors;

public:
    car() : max_acce(0.0), fuel_cap(0.0) {}
    car(float _max_acce, float _fuel_cap, string _comfort, bool _warm, float _circum, float _maxf, float _maxe, float _rpm, string _openmode)
        : max_acce(_max_acce),
          fuel_cap(_fuel_cap),
          carseat(_comfort, _warm),
          carwheels(_circum),
          carengine(_maxf, _maxe, _rpm),
          cardoors(_openmode) {}

    void setvalues(float _max_acce, float _fuel_cap, string _comfort, bool _warm, float _circum, float _maxf, float _maxe, float _rpm, string _openmode)
    {
        max_acce = _max_acce;
        fuel_cap = _fuel_cap;
        carseat.setcomfort(_comfort);
        carseat.setwarm(_warm);
        carwheels.setcircum(_circum);
        carengine.setmaxe(_maxe);
        carengine.setmaxf(_maxf);
        carengine.setrpm(_rpm);
        cardoors.setopenmode(_openmode);
    }

    void showvalues()
    {
        cout << "max_acce: " << max_acce << endl;
        cout << "fuel_cap: " << fuel_cap << endl;
        cout << "comfort: " << carseat.getcomfort() << endl;
        cout << "warm: " << carseat.getwarm() << endl;
        cout << "circum: " << carwheels.getcircum() << endl;
        cout << "max acceleration: " << carengine.getmaxe() << endl;
        cout << "max fuel: " << carengine.getmaxf() << endl;
        cout << "max_rpm: " << carengine.getrpm() << endl;
        cout << "Openmode: " << cardoors.getopenmode() << endl;
    }
};

int main()
{
    car c(100, 150, "pleasant", true, 12.12, 500, 230, 230, "sideways");
    car b(100, 150, "pleasant", true, 12.12, 500, 230, 230, "sideways");
    c.showvalues();
    return 0;
}

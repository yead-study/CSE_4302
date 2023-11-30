#include <iostream>
#include <string>
using namespace std;

enum class Mobility
{
    Walking,
    Swimming,
    Flying,
    Crawling
};
class Animals
{
protected:
    string color;
    double weight;
    Mobility mobility;
    string sound;

public:
    Animals(string p, double d, Mobility m) :  weight(0), mobility(Mobility::Walking)
    {
        setColor(p);
        setWeight(d);
        setMobility(m);
        sound = "";
    }
    Animals(string p, double d, Mobility m,string s) :  weight(0), mobility(Mobility::Walking)
    {
        setColor(p);
        setWeight(d);
        setMobility(m);
        sound = s;
    }

    void setColor(string val)
    {
            color = val;
    }
    void setWeight(double val)
    {
        if (val > 0)
            weight = val;
    }
    void setMobility(Mobility val)
    {
        mobility = val;
    }
    string getMadeof()
    {
        if (mobility == Mobility::Walking)
            return string("Walking");
        else if (mobility == Mobility::Swimming)
            return string("Swimming");
        else if (mobility == Mobility::Flying)
            return string("Flying");
        else if (mobility == Mobility::Crawling)
            return string("Crawling");
        else
            return string("NUll");
    }
    int getweight()
    {
        return weight;
    }
    virtual void animalDetails() = 0;
};

enum class MammalType
{
    Dog,
    Cat,
    Elephant,
    Human
};

class Mammal : public Animals
{
private:
    MammalType type;

public:
    // Mammal(){}
    Mammal(string _color, double _weight, Mobility _mobility, MammalType _type) : Animals(_color, _weight, _mobility)
    {
        type = _type;
    }
    Mammal(string _color, double _weight, Mobility _mobility, MammalType _type,string _sound) : Animals(_color, _weight, _mobility,_sound)
    {
        type = _type;
    }
    void animalDetails()
    {
        cout << "Details:" << endl;
        cout << "Mammal type: ";
        if (type == MammalType::Dog)
        {
            cout << "Dog" << endl;
        }
        else if (type == MammalType::Cat)
        {
            cout << "Cat" << endl;
        }
        else if (type == MammalType::Elephant)
        {
            cout << "Elephant" << endl;
        }
        else if (type == MammalType::Human)
        {
            cout << "Human" << endl;
        }
        cout << "Colour: " << color << endl;
        cout << "Weight: " << weight << "kg" <<  endl;
        cout << "Mobility" << getMadeof() << endl;
        cout << "Sound: " << sound << endl;
    }
};
enum class Birdtype
{
    Eagles,
    penguins,
    sparrows,
    ostriches
};
class Bird : public Animals
{
private:
    Birdtype type;

public:
    Bird(string _color, double _weight, Mobility _mobility,Birdtype _type,string _sound) : Animals(_color, _weight, _mobility,_sound)
    {
        type = _type;
    }
    Bird(string _color, double _weight, Mobility _mobility,Birdtype _type): Animals(_color, _weight, _mobility)
    {
        type = _type;
    }
    void animalDetails()
    {
        cout << "Details:" << endl;
        cout << "Bird type: ";
        if (type == Birdtype::Eagles)
        {
            cout << "Eagles" << endl;
        }
        else if (type == Birdtype::ostriches)
        {
            cout << "Ostriches" << endl;
        }
        else if (type == Birdtype::penguins)
        {
            cout << "Penguins" << endl;
        }
        else if (type == Birdtype::sparrows)
        {
            cout << "Sparrow" << endl;
        }
        cout << "Colour: " << color << endl;
        cout << "Weight: " << weight << "kg" << endl;
        cout << "Mobility: " << getMadeof() << endl;
        cout << "Sound: " << sound << endl;
    }
};
enum class Fishtype{Salmon, sharks, goldfish, angelfish};
class Fish : public Animals
{
    private:
        Fishtype type;
    public:
    Fish(string _color, double _weight, Mobility _mobility,Fishtype _type): Animals(_color, _weight, _mobility)
    {
        type = _type;
    }
    Fish(string _color, double _weight, Mobility _mobility,Fishtype _type,string _sound) : Animals(_color, _weight, _mobility,_sound)
    {
        type = _type;
    }
    void animalDetails()
    {
        cout << "Details:" << endl;
        cout << "Fish type: ";
        if (type == Fishtype::Salmon)
        {
            cout << "Salmon" << endl;
        }
        else if (type == Fishtype::angelfish)
        {
            cout << "Angelfish" << endl;
        }
        else if (type == Fishtype::goldfish)
        {
            cout << "Goldfish" << endl;
        }
        else if (type == Fishtype::sharks)
        {
            cout << "Sharks" << endl;
        }
        cout << "Colour: " << color << endl;
        cout << "Weight: " << weight <<"kg"<< endl;
        cout << "Mobility: " << getMadeof() << endl;
        cout << "Sound: " << sound << endl;
    }
};
enum class Reptiletype{Snakes,turtles, crocodiles, lizards};
class Reptile : public Animals
{
    private:
        Reptiletype type;
    public:
        Reptile(string _color, double _weight, Mobility _mobility,Reptiletype _type): Animals(_color, _weight, _mobility)
        {
            type  = _type;
        }
        Reptile(string _color, double _weight, Mobility _mobility,Reptiletype _type,string _sound) : Animals(_color, _weight, _mobility,_sound)
        {
            type  = _type;
        }
        void animalDetails()
    {
        cout << "Details:" << endl;
        cout << "Reptile type: ";
        if (type == Reptiletype::crocodiles)
        {
            cout << "Salmon" << endl;
        }
        else if (type == Reptiletype::lizards)
        {
            cout << "Lizards" << endl;
        }
        else if (type == Reptiletype::Snakes)
        {
            cout << "Snakes" << endl;
        }
        else if (type == Reptiletype::turtles)
        {
            cout << "Turtles" << endl;
        }
        cout << "Colour: " << color << endl;
        cout << "Weight: " << weight << "kg" << endl;
        cout << "Mobility: " << getMadeof() << endl;
        cout << "Sound: " << sound << endl;
    }
};

/**task 4
sort_furniture_discount will sort the array in descending order based on their discount price.
You may need to add some member functions
**/

void sortAnimalWeight(Animals *animals[], int no_of_animals)
{
    for(int i = 0; i< no_of_animals;i++)
    {
        for(int j =0;j<no_of_animals-1;j++)
        {
            if(animals[j]->getweight()<animals[j+1]->getweight())
            {
                Animals* temp = animals[j];
                animals[j] = animals[j+1];
                animals[j+1] = temp;
            }
        }
    }
    return;
}

int main()
{
    Animals *f_list[100];

    /**
        task 1
        So that following lines can be executed without error
    */
    
    f_list[0] = new Mammal("Brown", 50, Mobility::Walking, MammalType::Dog);
    f_list[1] = new Fish("Brown", 30, Mobility::Walking,Fishtype::sharks);
    f_list[2] = new Bird("Brown", 40, Mobility::Walking,Birdtype::Eagles);
    f_list[3] = new Reptile("Brown", 20, Mobility::Walking,Reptiletype::crocodiles);
    /**task 1 ends here*/

    /**
        task 2
        So that following lines can be executed without error

        task 3 (Modify productDetails)
    */
    for (int i = 0; i < 4; i++)
    {
        f_list[i]->animalDetails();
    }

    f_list[0] = new Mammal("Brown", 50, Mobility::Walking, MammalType::Dog,"Bark");
    f_list[1] = new Fish("Brown", 30, Mobility::Walking,Fishtype::sharks,"No sound");
    f_list[2] = new Bird("Brown", 40, Mobility::Walking,Birdtype::Eagles,"cheeee");
    f_list[3] = new Reptile("Brown", 20, Mobility::Walking,Reptiletype::crocodiles,"crunch");
    /**task 2 ends here*/
    /**task 3 ends here*/

    /**task 4
    So that following lines can be executed without error
    */
    sortAnimalWeight(f_list, 4);

    cout << "########after sort####" <<endl;
    for (int i = 0; i < 4; i++)
    {
        f_list[i]->animalDetails();
    }
    /**task 4 ends here*/
}

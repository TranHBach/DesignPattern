#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Beverage
{
public:
    string description = "Unknown beverage";

    string getDescription()
    {
        return description;
    }

    virtual double cost() = 0;
};

class CondimentsDecorator : public Beverage
{
public:
    virtual string getDescription() = 0;
};

class DarkRoast : public Beverage
{
public:
    DarkRoast()
    {
        description = "Dark Roast Coffee";
    }

    double cost()
    {
        return .99;
    }
};

class Decaf : public Beverage
{
public:
    Decaf()
    {
        description = "Decaf";
    }

    double cost()
    {
        return 1.05;
    }
};

class Espresso : public Beverage
{
public:
    Espresso()
    {
        description = "Espresso";
    }

    double cost()
    {
        return 1.99;
    }
};

class HouseBlend : Beverage
{
public:
    HouseBlend()
    {
        description = "House Blend Coffee";
    }

    double cost()
    {
        return .89;
    }
};

class Discounts : public CondimentsDecorator
{
public:
    Beverage *beverage;

    Discounts(Beverage *beverage)
    {
        this->beverage = beverage;
    }

    string getDescription()
    {
        return beverage->getDescription() + " + Mocha";
    }

    double cost()
    {
        return beverage->cost() * 0.9;
    }
};

class Mocha : public CondimentsDecorator
{
public:
    Beverage *beverage;

    Mocha(Beverage *beverage)
    {
        this->beverage = beverage;
    }

    string getDescription()
    {
        return beverage->getDescription() + " + Mocha";
    }

    double cost()
    {
        return .20 + beverage->cost();
    }
};

class Soy : public CondimentsDecorator
{
public:
    Beverage *beverage;

    Soy(Beverage *beverage)
    {
        this->beverage = beverage;
    }

    string getDescription()
    {
        return beverage->getDescription() + " + Soy";
    }

    double cost()
    {
        return .15 + beverage->cost();
    }
};

int main()
{
    Beverage *beverage1 = new DarkRoast();
    beverage1 = new Discounts(beverage1);
    beverage1 = new Mocha(beverage1);
    beverage1 = new Soy(beverage1);
    cout << "Beverage 1 costs " << beverage1->cost() << endl;
    Beverage *beverage2 = new Decaf();
    beverage2 = new Soy(beverage2);
    beverage2 = new Mocha(beverage2);
    cout << "Beverage 2 costs " << beverage2->cost() << endl;

}

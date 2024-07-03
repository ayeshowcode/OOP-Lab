#include <iostream>
using namespace std;
class Box
{
protected:
    float price;
    int capacity;

public:
    Box(float price, int capacity) : price(price), capacity(capacity) {}
    int getCapacity()
    {
        return capacity;
    }
    float getCost()
    {
        return price;
    }
};
class SmallBox : public Box
{
public:
    SmallBox() : Box(0.6, 5) {}
};
class MediumBox : public Box
{
public:
    MediumBox() : Box(1.0, 10) {}
};
class LargeBox : public Box
{
public:
    LargeBox() : Box(1.8, 20) {}
};
class CoffeOutlet : public SmallBox, public MediumBox, public LargeBox
{
    int orderquantity;

public:
    CoffeOutlet(int orderquantity) : orderquantity(orderquantity) {}
    void calculateNumBoxes()
    {
        int LargeBoxes = orderquantity / LargeBox::getCapacity();
        int remaining = orderquantity % LargeBox::getCapacity();

        int MediumBoxes = remaining / MediumBox::getCapacity();
        remaining = remaining % MediumBox::getCapacity();

        int SmallBoxes = (remaining + SmallBox::getCapacity() - 1) / SmallBox::getCapacity();
        display(LargeBoxes, MediumBoxes, SmallBoxes);
    }
    void display(int LargeBoxes, int MediumBoxes, int SmallBoxes)
    {
        cout << "Number of boxes ordered: " << orderquantity << endl;
        cout << "The Cost of Order: $ " << orderquantity * 5.5 << endl;
        cout << "Boxes Used: " << endl;
        cout << LargeBoxes << " large Boxes- " << LargeBoxes * LargeBox::getCost() << endl;
        cout << MediumBoxes << " Medium Boxes- " << MediumBoxes * MediumBox::getCost() << endl;
        cout << SmallBoxes << " Small Boxes- " << SmallBoxes * SmallBox::getCost() << endl;
        cout << "Your Total cost: " << orderquantity * 5.5 + LargeBoxes * LargeBox::getCost() + MediumBoxes * MediumBox::getCost() + SmallBoxes * SmallBox::getCost() << endl;
    }
};
int main()
{
    CoffeOutlet Coffee(52);
    Coffee.calculateNumBoxes();
}
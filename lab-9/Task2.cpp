#include <iostream>
#include <cmath>
using namespace std;
class DessertItem
{
    string name;

public:
    DessertItem(string name) : name(name) {}
    virtual float getCost() const = 0;
    string getName() const
    {
        return name;
    }
};
class Candy : public DessertItem
{
    float weight, priceperpound;

public:
    Candy(string name, float weight, float priceperpound) : DessertItem(name), weight(weight), priceperpound(priceperpound) {}
    float getCost() const
    {
        return round(weight * priceperpound);
    }
};
class Cookie : public DessertItem
{
    int number;
    float costPerDozen;

public:
    Cookie(string name, int number, float costPerDozen) : DessertItem(name), number(number), costPerDozen(costPerDozen) {}
    float getCost() const
    {
        return round(number * costPerDozen / 12);
    }
};
class IceCream : public DessertItem
{
    float cost;

public:
    IceCream(string name, float cost) : DessertItem(name), cost(cost) {}
    float getCost() const
    {
        return cost;
    }
};
class Sundae : public IceCream
{
    float cost;
    float topping;

public:
    Sundae(string name, float cost, float topping) : topping(topping), IceCream(name, cost) {}
    float getCost()
    {
        return round(topping + IceCream::getCost());
    }
};

class Checkout
{
private:
    DessertItem *items[4]; // // Abstract class cannot be instantiated (means you cannot create an object directly)
    int itemCount;
    float taxRate;

public:
    Checkout(float taxRate = 0.0) : taxRate(taxRate), itemCount(0) {}

    ~Checkout()
    {
        for (int i = 0; i < itemCount; ++i)
        {
            delete items[i];
            items[i] = nullptr;
        }
    }

    void enterItem( DessertItem &item)
    {
        if (itemCount < 4)
        {
            items[itemCount++] = &item;
        }
    }

    void clear()
    {
        for (int i = 0; i < itemCount; ++i)
        {
            delete items[i];
        }
        itemCount = 0;
    }

    int numberOfItems() const
    {
        return itemCount;
    }

    int totalCost() const
    {
        int totalCost = 0;
        for (int i = 0; i < itemCount; ++i)
        {
            totalCost += items[i]->getCost();
        }
        return totalCost;
    }

    int totalTax() const
    {
        return static_cast<int>(round(totalCost() * taxRate));
    }

    void setTax(float newTaxRate)
    {
        taxRate = newTaxRate;
    }

    float getTax() const
    {
        return taxRate;
    }

    void printReceipt() const
    {
        cout << "Receipt:" << endl;
        cout << "Total Items: " << itemCount << endl;
        for (int i = 0; i < itemCount; ++i)
        {
            std::cout << items[i]->getName() << ": $" << items[i]->getCost() / 100.0f << endl;
        }
        float total = totalCost() / 100.0f;
        float tax = totalTax() / 100.0f;
        float totalWithTax = total + tax;
        cout << "Subtotal: $" << total << endl;
        cout << "Tax: $" << tax << endl;
        cout << "Total: $" << totalWithTax << endl;
    }
};
int main()
{
    Checkout checkout(0.06);
    
    Candy candy("My Candy", 2.25, 3.99);
    Cookie cookie("Cookies", 4, 3.99);
    IceCream icecream("chocolate Ice Cream", 3.05);
    Sundae sundae("Sundae", 4.05, 0.85);

    checkout.enterItem(candy);
    checkout.enterItem(cookie);
    checkout.enterItem(icecream);
    checkout.enterItem(sundae);

    checkout.printReceipt();
    checkout.clear();

    return 0;
}
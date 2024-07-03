#include <iostream>
#include <string>

using namespace std;

class Pizza
{
private:
    string size;
    int cheeseToppings;
    int pepperoniToppings;
    int hamToppings;

public:
    Pizza(const string &sz, int cheese, int pepperoni, int ham)
        : size(sz), cheeseToppings(cheese), pepperoniToppings(pepperoni), hamToppings(ham) {}

    Pizza(const Pizza &other)
        : size(other.size), cheeseToppings(other.cheeseToppings),
          pepperoniToppings(other.pepperoniToppings), hamToppings(other.hamToppings) {}

    void setSize(const string &sz)
    {
        size = sz;
    }
    void setCheeseToppings(int count)
    {
        cheeseToppings = count;
    }
    void setPepperoniToppings(int count)
    {
        pepperoniToppings = count;
    }
    void setHamToppings(int count)
    {
        hamToppings = count;
    }

    string getSize() const
    {
        return size;
    }
    int getCheeseToppings() const
    {
        return cheeseToppings;
    }
    int getPepperoniToppings() const
    {
        return pepperoniToppings;
    }
    int getHamToppings() const
    {
        return hamToppings;
    }

    double calcCost() const
    {
        int baseCost = 0;
        if (size == "small")
            baseCost = 1000;
        else if (size == "medium")
            baseCost = 1200;
        else if (size == "large")
            baseCost = 1400;
        return baseCost + (cheeseToppings + pepperoniToppings + hamToppings) * 200;
    }
    string getDescription() const
    {
        return size + " pizza with " +
               to_string(cheeseToppings) + " cheese, " +
               to_string(pepperoniToppings) + " pepperoni, " +
               to_string(hamToppings) + " ham.";
    }
    void display() const
    {
        cout << getDescription() << " Should cost a total of " << calcCost() << "." << endl;
    }
};

int main()
{
    Pizza pizzaOrder1("large", 1, 1, 2);
    pizzaOrder1.display();

    Pizza pizzaOrder2 = pizzaOrder1;
    pizzaOrder2.setCheeseToppings(2);
    pizzaOrder2.setPepperoniToppings(2);

    // Display both orders
    cout << "First Order: ";
    pizzaOrder1.display();
    cout << "Updated Order: ";
    pizzaOrder2.display();

    int choice;
    cout << "Enter 1 to choose the first order, or 2 for the updated order: ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "Final Order: ";
        pizzaOrder1.display();
    }
    else
    {
        cout << "Final Order: ";
        pizzaOrder2.display();
    }
    return 0;
}
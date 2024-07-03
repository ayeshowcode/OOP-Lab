#include <iostream>
using namespace std;
class Burgers
{
protected:
    string ingredients, taste;
    float price;

public:
    Burgers(string ingredients, string taste, float price) : ingredients(ingredients), taste(taste), price(price) {}
    void display()
    {
        cout << "Ingredients: " << ingredients << endl;

        cout << "Taste: " << taste << endl;
        cout << "Price: " << price << endl;
    }
};
class ChickenBurger : public Burgers
{
    bool extracheese;
public:
    ChickenBurger(string ingredients, string taste, float price) : Burgers(ingredients, taste, price)
    {
        extracheese = false;
    }
    void addExtraCheese()
    {
        if (!extracheese)
        {
            extracheese = true;
            price += 500;
        }
    }
    void display(){
        Burgers:: display();
        if (extracheese)
        {
            cout << "Extra Cheese: yes"<< endl;
        }
        else 
        {
            cout << "Extra cheese: No" << endl;
        }
    }
};
class BeefBurger : public Burgers
{
    bool extracheese;
public:
    BeefBurger(string ingredients, string taste, float price) : Burgers(ingredients, taste, price) {
        extracheese=false;
    }

    void addExtraCheese()
    {
        if (!extracheese)
        {
            extracheese = true;
            price += 500;
        }
    }
    void display(){
        Burgers:: display();
        if (extracheese)
        {
            cout << "Extra Cheese: yes"<< endl;
        }
        else 
        {
            cout << "Extra cheese: No" << endl;
        }
    }
};
int main()
{
    ChickenBurger cb("chicken paty, sauces, cheese", "mild", 1000);
    BeefBurger bb("Beef, cheese, sauces", "spicky", 1000);
    cb.addExtraCheese();
    cb.display();
}
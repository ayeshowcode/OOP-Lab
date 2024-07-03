// i have assumed that the cars classification will be based on the model no provided in the addCar(int model, int year) function

#include <iostream>
using namespace std;
class Car
{
protected:
    int model, year;

public:
    Car(int model, int year) : model(model), year(year) {}

    virtual float calculateSalesPrice() const = 0;
    virtual string getCarType() const = 0; // extra function ik

    int getModel()
    {
        return model;
    }
    int getYear()
    {
        return year;
    }
};
class Sports : public Car
{
    float tax;
    float salesPrice;

public:
    Sports(int model, int year, float tax, float salesPrice) : Car(model, year), tax(tax), salesPrice(salesPrice) {}
    float calculateSalesPrice() const
    {
        return salesPrice + tax;
    }
    string getCarType() const
    {
        return "Sports" ;
    }
};
class Classic : public Car
{
    float salesPrice;

public:
    Classic(int model, int year, float salesPrice) : Car(model, year), salesPrice(salesPrice) {}
    float calculateSalesPrice() const
    {
        if (year > 2000)
        {
            return 0.75 * salesPrice;
        }
        else if (year > 1995 && year <= 2000)
        {
            return 0.5 * salesPrice;
        }
        else
        {
            return 0.25 * salesPrice;
        }
    }
        string getCarType() const
    {
        return "Classic" ;
    }

    
};
class Sedan : public Car
{
    float discount, salesPrice;

public:
    Sedan(int model, int year, float discount, float salesPrice) : Car(model, year), discount(discount), salesPrice(salesPrice) {}
    float calculateSalesPrice() const 
    {
        return salesPrice;
    }
        string getCarType() const
    {
        return "Seden" ;
    }
};


class CarExhibition
{
    int yearExhibition;
    Car *cars[3]; // Abstract class cannot be instantiated (means you cannot create an object directly)
    int carCount;

public:
    CarExhibition(int yearExhibition) : yearExhibition(yearExhibition), carCount(0) {
    }

    void addCar(int model, int year)
    {
        if (carCount < 3)
        {
            if (model > 2000)
            {                                                            
                cars[carCount++] = new Sports(model, year, 3000, 25000); 
            }
            else if (model > 1995)
            {                                                         
                cars[carCount++] = new Sedan(model, year, 2000, 20000); 
            }
            else
            {                                                       
                cars[carCount++] = new Classic(model, year, 15000);
            }
        }
    }
    void display()
    {
        for (int i= 0; i< carCount; i++)
        {
           cout << "Model: " <<  cars[i]->getModel() << "    Car Type: " << cars[i]->getCarType() << endl;
           cout << "Year: " <<  cars[i]->getYear() << endl;
           cout << "Sales Price: "<< cars[i]->calculateSalesPrice() << endl << endl;
        }
     }
};
int main()
{
    CarExhibition exhibition(2024);
    exhibition.addCar(2001, 2002); // sports
    exhibition.addCar(1996, 2001); // sedan 
    exhibition.addCar(1990, 1993); // classic

    exhibition.display();
}
#include <iostream>
#include <string>
using namespace std;
class Product
{
protected:
    string barcode;
    string name;

public:
    Product(string barcode, string name) : barcode(barcode), name(name) {}
    Product()
    {
        barcode = "212";
        name = "ayesh";
    }
    void setBarcode(string barcode)
    {
        this->barcode = barcode;
    }
    string getBarcode()
    {
        return barcode;
    }
    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }
    void scanner()
    {
        cout << "Enter the Barcode: ";
        getline(cin, barcode);
        cout << "Enter the Name: ";
        getline(cin, name);
    }
    void printer()
    {
        cout << "Barode: " << barcode << endl;
        cout << "Name: " << name << endl;
    }
};
class PrepackedFood : public Product

{
    float unitPrice;

public:
    PrepackedFood(string barcode, string name, float unitPrice) : Product(barcode, name), unitPrice(unitPrice) {}
    PrepackedFood()
    {
        unitPrice = 100.0;
    }

    void scanner()
    {
        Product::scanner();
        cout << "Unit Price: ";
        cin >> unitPrice;
    }
    void printer()
    {
        Product::printer();
        cout << "Unit Price: " << unitPrice << endl;
    }
    float calculate()
    {
        return unitPrice;
    }
};
class FreshFood : public Product
{
    float weight, priceperkilo;

public:
    FreshFood(string barcode, string name, float weight, float priceperkilo) : Product(barcode, name), weight(weight), priceperkilo(priceperkilo) {}
    FreshFood()
    {
        weight = 100.0;
        priceperkilo = 100.0;
    }
    void scanner()
    {
        Product::scanner();
        cout << "Weight: ";
        cin >> weight;
        cout << "Price per kilo: ";
        cin >> priceperkilo;
    }
    void printer()
    {
        Product::printer();
        cout << "Weight: " << weight;
        cout << "Price per Kilo: " << priceperkilo << endl;
    }
    float calculate()
    {
        return weight * priceperkilo;
    }
};
int main()
{
    Product p("314", "AYESH");

    PrepackedFood pf;
    FreshFood ff;
    cout << "PRODUCT CLASS" << endl;
    cout << "Barcode: " << p.getBarcode() << endl;
    cout << "Name: " << p.getName() << endl
         << endl;

    pf.scanner();
    cout << "PREPACKED FOOD CLASS" << endl;
    cout << "Barcode: " << pf.getBarcode() << endl;
    cout << "Name: " << pf.getName() << endl;
    cout << "price: " << pf.calculate() << endl
         << endl;

    ff.setBarcode("1213");
    ff.setName("notayesh");

    cout << "Barcode: " << ff.getBarcode() << endl;
    cout << "Name: " << ff.getName() << endl;
    cout << "Price: " << ff.calculate() << endl;
}
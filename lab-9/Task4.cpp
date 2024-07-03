#include <iostream>
#include <string>
using namespace std;

class Stock
{
protected:
    string symbol, companyName;
    double price;
    int availableQuantity, maxQuantityPerInvestor, stockCategoryQuantity;

public:
    Stock(string symbol, string companyName, double price, int availableQuantity, int maxQuantityPerInvestor, int stockCategoryQuantity)
        : symbol(symbol), companyName(companyName), price(price), availableQuantity(availableQuantity),
          maxQuantityPerInvestor(maxQuantityPerInvestor), stockCategoryQuantity(stockCategoryQuantity) {}
    int getstockCategoryQuantity() { return stockCategoryQuantity; }
    virtual ~Stock() {}

    string getSymbol() const
    {
        return symbol;
    }

    string getCompanyName() const
    {
        return companyName;
    }

    double getPrice() const
    {
        return price;
    }

    virtual bool isEligibleToBuy(int purchaseQuantity) const
    {
        return purchaseQuantity <= maxQuantityPerInvestor;
    }

    virtual void displayInfo() const
    {
        cout << "Symbol: " << symbol << endl;
        cout << "Company Name: " << companyName << endl;
        cout << "Price: $" << price << endl;
        cout << "Available Quantity: " << availableQuantity << endl;
        cout << "Max Quantity Per Investor: " << maxQuantityPerInvestor << endl;
        cout << "Stock Category Quantity: " << stockCategoryQuantity << endl;
    }
};

class PharmaStock : public Stock
{
public:
    PharmaStock(string symbol, string companyName, double price, int availableQuantity, int maxQuantityPerInvestor, int stockCategoryQuantity)
        : Stock(symbol, companyName, price, availableQuantity, maxQuantityPerInvestor, stockCategoryQuantity) {}
    bool isEligibleToBuy(int purchasequantity) const
    {
        if (purchasequantity <= maxQuantityPerInvestor)
        {
            return true;
        }
        else
            return false;
    }
};

class TechStock : public Stock
{
public:
    TechStock(string symbol, string companyName, double price, int availableQuantity, int maxQuantityPerInvestor, int stockCategoryQuantity)
        : Stock(symbol, companyName, price, availableQuantity, maxQuantityPerInvestor, stockCategoryQuantity) {}
    bool isEligibleToBuy(int purchasequantity) const
    {
        if (purchasequantity <= maxQuantityPerInvestor)
        {
            return true;
        }
        else
            return false;
    }
};

class Market
{
private:
    Stock *stocks[5];
    int numStocks;
    int capacity;

public:
    Market(int capacity) : numStocks(0), capacity(capacity) {}

    ~Market()
    {
        for (int i = 0; i < numStocks; ++i)
        {
            delete stocks[i];
        }
    }

    void addStock(Stock *stock)
    {
        if (numStocks < capacity)
        {
            stocks[numStocks++] = stock;
        }
        else
        {
            cout << "Market is full, cannot add more stocks." << endl;
            delete stock; 
        }
    }
    void tradestock()
    {
        if (numStocks > 0)
        {
            cout << "stocks traded are:" << stocks[numStocks - 1]->getstockCategoryQuantity() << endl;
        }
        else
        {
            cout << "No stocks available to trade." << endl;
        }
    }
    void displayMarket() const
    {
        for (int i = 0; i < numStocks; ++i)
        {
            stocks[i]->displayInfo();
            cout << endl;
        }
    }
};

int main()
{
    Market market(5);

    Stock *pharma = new PharmaStock("PHRM", "Pharma Inc.", 150.00, 1000, 50, 100);
    Stock *tech = new TechStock("TECH", "Tech Corp.", 300.00, 500, 25, 200);

    market.addStock(pharma);
    market.addStock(tech);

    market.displayMarket();
    market.tradestock();

    return 0;
}
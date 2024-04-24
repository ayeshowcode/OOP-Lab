#include <iostream>
using namespace std;
typedef struct FeelInvoice
{
    string PartNo;
    string PartDes;
    int quantity;
    float price;
      float GetInvoiceAmount(){ 
         if (quantity< 0){
            quantity=0;
         }
         if (price< 0){
            price = 0;
         }
         return price * quantity;
      }
} FeelInvoice;
int main()
{
    int n;
    cout << "Enter the no of items: ";
    cin >> n;
    cin.ignore();
    float Total_invoice_amount = 0;

    FeelInvoice *f = new FeelInvoice[n];
    for (int i = 0; i < n; i++)
    {
        cout << "ITEM -" << i + 1 << ": " << std::endl;
        cout << "Enter the part No : ";
        getline(cin, f[i].PartNo);

        cout << "Enter the part description: ";
        getline(cin, f[i].PartDes);

        cout << "Enter the quantity: ";
        cin >> f[i].quantity;
        if (f[i].quantity < 0)
        {
            f[i].quantity = 0;
        }
        cout << "Enter the price: ";
        cin >> f[i].price;
        if (f[i].price < 0)
        {
            f[i].price = 0;
        }
        float IndInvoice= f[i].GetInvoiceAmount();
        cout << "INVOICE AMOUNT FOR ITEM-"<< i+1 << ": " << IndInvoice << endl;
        Total_invoice_amount+=IndInvoice;

        cin.ignore();
    }
    cout << "Your invoice amount : " << Total_invoice_amount;
}
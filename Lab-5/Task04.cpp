#include <iostream>

class Product {
private:
    int pro_code;
    double pro_price;
    static int count;

public:
    Product() {
        pro_code = 0;
        pro_price = 0.0;
        count++;
    }

    static int getCount() {
        return count;
    }

    void getproduct() {
        std::cout << "Enter product code: ";
        std::cin >> pro_code;
        std::cout << "Enter product price: ";
        std::cin >> pro_price;
    }

    static void displaysum(Product products[], int size) {
        double total = 0.0;
        for (int i = 0; i < size; ++i) {
            total += products[i].pro_price;
        }
        std::cout << "Total sum of product prices: " << total << std::endl;
    }

    void display() const {
        std::cout << "Product Code: " << pro_code
                  << ", Product Price: " << pro_price << std::endl;
    }
};

int Product::count = 0;

int main() {
    const int numProducts = 5;
    Product *productArray = new Product[numProducts];

    bool exitProgram = false;
    int choice;
    
    while (!exitProgram) {
        std::cout << "\nProduct Management System\n";
        std::cout << "1. Enter product details\n";
        std::cout << "2. Display sum of product prices\n";
        std::cout << "3. Display all products\n";
        std::cout << "4. Display product count\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                for (int i = 0; i < numProducts; ++i) {
                    std::cout << "Enter details for product " << (i + 1) << std::endl;
                    productArray[i].getproduct();
                }
                break;
            case 2:
                Product::displaysum(productArray, numProducts);
                break;
            case 3:
                std::cout << "\nProduct Details:\n";
                for (int i = 0; i < numProducts; ++i) {
                    productArray[i].display();
                }
                break;
            case 4:
                std::cout << "\nTotal number of product objects created: "
                          << Product::getCount() << std::endl;
                break;
            case 5:
                exitProgram = true;
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    delete[] productArray;

    return 0;
}
#include <iostream>
#include <map>


using namespace std;

class Payment {
public:
    virtual void Pay() = 0;
};

class Cash : public Payment {
public:
    void Pay() {
        cout << "Payed with cash" << endl;
    }
};

class Product {
private:
    string productName;
    int productAmount;
public:
    Product(string name, int amount) {
        productName = name;
        productAmount = amount;
    }
    string getProductName() {
        return productName;
    }
    int getProductAmount() {
        return productAmount;
    }
};

class User{
private:
    float userMoney;
    string userName;
    Payment* chosenPayment;
public:
    User(float money, string name, Payment* payment) {
        userMoney = money;
        userName = name;
        chosenPayment = payment;
    }
    float getMoney() {
        return userMoney;
    }
    void decreaseMoney(float price) {
        userMoney -= price;
    }
    Payment* getChosenPayment() {
        return chosenPayment;
    }
    void getInfo() {
        cout << userName << " | " << userMoney << " PLN | ";
        return getChosenPayment()->Pay();
    }
};

class VendingMachine{
private:
    map<int, Product*> products;
public:
    void AddProduct(Product* prod) {
        products[products.size()+1] = prod;
    }
    void BuyProduct(int index, User* chosenUser) {
        int price = products[index]->getProductAmount();
        if(chosenUser->getMoney() >= price) {
            chosenUser->decreaseMoney(price);
            cout << "You bought: " << products[index]->getProductName() << " for " << products[index]->getProductAmount() << " PLN" << endl;
            products.erase(index);
        }
    }
    void ShowProducts() {
        cout << "Products: " << endl;
        cout << "ID | Name | Amount" << endl;
        for(map<int, Product*>::iterator it = products.begin(); it != products.end(); it++) {
            cout << it->first << " | ";
            cout << it->second->getProductName() << " | ";
            cout << it->second->getProductAmount() << " PLN" << endl;
        }
    }
};



int main()
{
    VendingMachine V;
    V.AddProduct(new Product("PWR", 70));
    V.AddProduct(new Product("Creatine", 50));
    V.AddProduct(new Product("WPC", 60));
    V.ShowProducts();
    
    cout << "-------------" << endl;
    Cash* Payment = new Cash();
    User* Anrzej = new User(500, "Anrzej", Payment);
    Anrzej->getInfo();
    
    cout << "-------------" << endl;
    
    V.BuyProduct(2, Anrzej);
    
    cout << "-------------" << endl;
    
    Anrzej->getInfo();
    
    cout << "-------------" << endl;
    
    V.ShowProducts();
    
    

    return 0;
}
# Vending Machine System

This simple C++ program simulates a vending machine system that allows users to view available products, make purchases, and choose different payment methods.

## Classes

### Payment
- **Description**: Abstract base class representing different payment methods.
- **Methods**:
  - `virtual void Pay()`: Pure virtual function to be implemented by derived classes.

### Cash
- **Description**: Concrete class inheriting from Payment, representing a cash payment method.
- **Methods**:
  - `void Pay()`: Implementation of the Pay method for cash payments.

### Product
- **Description**: Class representing a product available in the vending machine.
- **Properties**:
  - `string productName`: Name of the product.
  - `int productAmount`: Price of the product in PLN.
- **Methods**:
  - `Product(string name, int amount)`: Constructor to initialize the product with a name and price.
  - `string getProductName()`: Getter for the product name.
  - `int getProductAmount()`: Getter for the product price.

### User
- **Description**: Class representing a user of the vending machine.
- **Properties**:
  - `float userMoney`: Amount of money the user has.
  - `string userName`: Name of the user.
  - `Payment* chosenPayment`: Pointer to the selected payment method.
- **Methods**:
  - `User(float money, string name, Payment* payment)`: Constructor to initialize user details and chosen payment method.
  - `float getMoney()`: Getter for the user's money.
  - `void decreaseMoney(float price)`: Decreases the user's money by a specified amount.
  - `Payment* getChosenPayment()`: Getter for the chosen payment method.
  - `void getInfo()`: Displays user information and triggers the chosen payment method's Pay function.

### VendingMachine
- **Description**: Class representing the vending machine itself.
- **Properties**:
  - `map<int, Product*> products`: Map storing products with unique IDs.
- **Methods**:
  - `void AddProduct(Product* prod)`: Adds a product to the vending machine.
  - `void BuyProduct(int index, User* chosenUser)`: Allows a user to buy a product, updating their money and removing the purchased product from the machine.
  - `void ShowProducts()`: Displays the available products in the vending machine.

## Example Usage in `main()`

1. Create a VendingMachine instance.
2. Add products to the vending machine.
3. Display available products.
4. Create a Cash payment instance.
5. Create a User instance with initial money, name, and chosen payment method.
6. Display user information.
7. Buy a product using the VendingMachine and update user information.
8. Display updated user information.
9. Display remaining products in the vending machine.

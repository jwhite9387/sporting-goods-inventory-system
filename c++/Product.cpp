#include "Product.h"

// Product class implementation
Product::Product(string n, double p, int s) : name(n), price(p), stock(s) {}
// Destructor
Product::~Product() {}

//setters and getters for base product details
string Product::getName() const { return name; }
void Product::setName(const string& n) { name = n; }
double Product::getPrice() const { return price; }
void Product::setPrice(double p) { price = p; }
int Product::getStock() const { return stock; }
void Product::setStock(int s) { stock = s; }

//function to update inventory
void Product::updateStock(int quantity) {
    if (quantity > stock) {
        cout << "Not enough in stock..\n";
    } else {
        stock -= quantity;
    }
}

//function to display product details, can be overridden
void Product::display() const {
    cout << "Product: " << name << "\nPrice: $" << price << "\nStock: " << stock << "\n";
}

// Derived classes implementation
Volleyball::Volleyball(string n, double p, int s, string m, int sz)
    : Product(n, p, s), material(m), size(sz) {}

//override display method
void Volleyball::display() const {
    Product::display();
    cout << "Material: " << material << "\nSize: " << size << " inches\n\n";
}

volleyballNet::volleyballNet(string n, double p, int s, string t)
    : Product(n, p, s), type(t) {}

void volleyballNet::display() const {
    Product::display();
    cout << "Type: " << type << "\n\n";
}

Paddle::Paddle(string n, double p, int s, string st)
    : Product(n, p, s), style(st) {}

void Paddle::display() const {
    Product::display();
    cout << "Style: " << style << "\n\n";
}

Table::Table(string n, double p, int s, string m)
    : Product(n, p, s), material(m) {}

void Table::display() const {
    Product::display();
    cout << "Material: " << material << "\n\n";
}

Ball::Ball(string n, double p, int s)
    : Product(n, p, s) {}

Tent::Tent(string n, double p, int s, string sz, string d, string wr)
    : Product(n, p, s), size(sz), durability(d), weatherRating(wr) {}

void Tent::display() const {
    Product::display();
    cout << "Size: " << size << "\nDurability: " << durability << "\nWeather Rating: " << weatherRating << "\n\n";
}

SleepingBag::SleepingBag(string n, double p, int s, string sz)
    : Product(n, p, s), size(sz) {}

void SleepingBag::display() const {
    Product::display();
    cout << "Size: " << size << "\n\n";
}

SoccerBall::SoccerBall(string n, double p, int s, string m)
    : Product(n, p, s), material(m) {}

void SoccerBall::display() const {
    Product::display();
    cout << "Material: " << material << "\n\n";
}

GoalNet::GoalNet(string n, double p, int s, string sz)
    : Product(n, p, s), size(sz) {}

void GoalNet::display() const {
    Product::display();
    cout << "Size: " << size << "\n\n";
}

//displays product details by extracting info from pointer to product
void displayProductDetails(Product* product) {
    if (product == nullptr) {
        cout << "Invalid Product.\n";
        return;
    }
    product->display();
}

//function to handle purchasing from user
bool handlePurchase(Product* product, int quantity) {
    //check if product is in stock
    if (product->getStock() >= quantity) {
        //calculate total price
        double totalPrice = product->getPrice() * quantity;
        cout << "\nTotal Price: $" << totalPrice << "\n";
        //update stock inventory
        product->updateStock(quantity);
        cout << "Updated Stock: " << product->getStock() << " remaining\n";
        return true;
    } else {
        cout << "Sorry, not enough stock available..\n";
        return false;
    }
}

void productChoice(const string& section, vector<Product*>& products) {
    int prodChoice;
    int qty;

    //ask user which product they want
    cout << "\nWhich  would you like to buy? (type 1 or 2): ";
    cin >> prodChoice;

    //ask user how many they want
    cout << "\nHow many would you like to buy? ";
    cin >> qty;

    //handle user input
    if (prodChoice >= 1 && prodChoice <= products.size()) {
        //vector count starts at 0 so whichever product they choose, subtract one
        //to get correct product from vector
        handlePurchase(products[prodChoice - 1], qty);
    }
    else {
        cout << "Invalid Choice, please enter a valid number..\n";
    }
}
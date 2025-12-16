#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product {
protected:
    string name;
    double price;
    int stock;

public:
    Product(string n, double p, int s);
    virtual ~Product();
    
    string getName() const;
    void setName(const string& n);
    double getPrice() const;
    void setPrice(double p);
    int getStock() const;
    void setStock(int s);
    void updateStock(int quantity);
    virtual void display() const;
};

class Volleyball : public Product {
private:
    string material;
    int size;

public:
    Volleyball(string n, double p, int s, string m, int sz);
    void display() const override;
};

class volleyballNet : public Product {
private:
    string type;

public:
    volleyballNet(string n, double p, int s, string t);
    void display() const override;
};

class Paddle : public Product {
private:
    string style;

public:
    Paddle(string n, double p, int s, string st);
    void display() const override;
};

class Table : public Product {
private:
    string material;

public:
    Table(string n, double p, int s, string m);
    void display() const override;
};

class Ball : public Product {
public:
    Ball(string n, double p, int s);
};

class Tent : public Product {
private:
    string size;
    string durability;
    string weatherRating;

public:
    Tent(string n, double p, int s, string sz, string d, string wr);
    void display() const override;
};

class SleepingBag : public Product {
private:
    string size;

public:
    SleepingBag(string n, double p, int s, string sz);
    void display() const override;
};

class SoccerBall : public Product {
private:
    string material;

public:
    SoccerBall(string n, double p, int s, string m);
    void display() const override;
};

class GoalNet : public Product {
private:
    string size;

public:
    GoalNet(string n, double p, int s, string sz);
    void display() const override;
};

void displayProductDetails(Product* product);
bool handlePurchase(Product* product, int quantity);
void productChoice(const string& section, vector<Product*>& products);
void showVolleyBallSect();
void showTableTennisSect();
void showIndoorSect();
void showCampingSect();
void showSoccerSect();
void showOutdoorSect();

#endif
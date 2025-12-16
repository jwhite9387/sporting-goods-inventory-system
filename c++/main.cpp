#include <iostream>
#include <string>
#include <algorithm>
#include "Product.h"

using namespace std;

//Declare all the functions
void showIndoorSect();
void showOutdoorSect();
void showVolleyBallSect();
void showTableTennisSect();
void showCampingSect();
void showSoccerSect();

int main() {
    string choice;
    //while loop to stay in app until user is ready to quit
    while (true) {
        cout << "Welcome to the Sporting Goods Store\n";
        cout << "\nWould you like to view the indoor or outdoor section? (type 'exit' to quit): ";
        cin >> choice;
        //change user input to lowercase
        transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
        
        //kill command
        if (choice == "exit") {
            break;
        } 
        else if (choice == "indoor") {
            bool inIndoorSect = true;
            //check if user wants to go back to main menu
            while (inIndoorSect) {
                showIndoorSect();
                cout << "Would you like to keep shopping in the indoor section? (Y/N): ";
                string contChoice;
                cin >> contChoice;
                if (contChoice == "n" || contChoice == "N") {
                    inIndoorSect = false;   //leave indoor section
                } 
                else if (contChoice == "y" || contChoice == "Y") {
                    continue;
                }
            }
        } 
        else if (choice == "outdoor") {
            bool inOutdoorSect = true;
            //check if user wants to go back to main menu
            while (inOutdoorSect) {
                showOutdoorSect();
                cout << "Would you like to keep shopping in the outdoor section? (Y/N): ";
                string contChoice;
                cin >> contChoice;
                if (contChoice == "n" || contChoice == "N") {
                    inOutdoorSect = false;  //leave outdoor section
                } 
                else if (contChoice == "y" || contChoice == "Y") {
                    continue;
                }
            }
        } 
        else {
            cout << "Invalid input. Please enter indoor, outdoor, or exit.\n";
        }
    }

    return 0;
}

void toLower(string &str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

void showIndoorSect() {
    cout << "\nIndoor Section:\n";
    cout << "1. Volleyball\n";
    cout << "2. Table Tennis\n";

    string subChoice;
    cout << "\nWould you like to see the Volleyball or Table Tennis section? (type 'Volleyball' or 'Table Tennis'): ";
    
    cin.ignore();
    getline(cin, subChoice);
    //change user input to lowercase
    toLower(subChoice);

    if (subChoice == "volleyball") {
        showVolleyBallSect();   //go to function to display volleyball section
        cout << "\n";
    } else if (subChoice == "table tennis") {
        showTableTennisSect();  //go to function to display table tennis section
        cout << "\n";
    } else {
        cout << "Invalid input..Please enter Volleyball or Table Tennis\n";
    }
}

void showOutdoorSect() {
    cout << "\nOutdoor Section:\n";
    cout << "1. Camping\n";
    cout << "2. Soccer\n";

    string subChoice;
    cout << "Would you like to view the Camping or Soccer section? (type 'Camping' or 'Soccer'): ";
    cin >> subChoice;
    //change user input to lowercase
    transform(subChoice.begin(), subChoice.end(), subChoice.begin(), ::tolower);

    if (subChoice == "camping") {
        showCampingSect();  //go to function to display camping section
    } else if (subChoice == "soccer") {
        showSoccerSect();   //go to function to display soccer section
    } else {
        cout << "Invalid input..Please enter Camping or Soccer\n";
    }
}

void showVolleyBallSect() {
    cout << "\nVolleyball Section:\n";
    cout << "1. Volleyballs\n";
    cout << "2. Nets\n";

    string itemChoice;
    
    cout << "\nWhich Section Would Like To View? (type 'Volleyballs' or 'Nets'): ";
    cin >> itemChoice;
    transform(itemChoice.begin(), itemChoice.end(), itemChoice.begin(), ::tolower);

    if (itemChoice == "volleyballs") {
        //create vector to store volleyball objects
        vector<Product*> volleyballs;
        //dynamically create objects
        volleyballs.push_back(new Volleyball("Volleyball", 29.99, 30, "Leather", 18));
        volleyballs.push_back(new Volleyball("Volleyball", 24.99, 20, "Synthetic Leather", 20));

        cout << "\n";

        //loop through vector to display product details
        for (Product* p : volleyballs) {
            displayProductDetails(p);
        }

        //go to function to get user choice for product
        productChoice("volleyballs", volleyballs);

        //free up dynamically allocated memory
        for (Product* p : volleyballs) {
            delete p;
        }
    }
    else if (itemChoice == "nets") {
        //create vector to store net objects
        vector<Product*> nets;
        //dynamically create objects
        nets.push_back(new volleyballNet("Volleyball Net", 59.99, 25, "Professional"));
        nets.push_back(new volleyballNet("Volleyball Net", 49.99, 35, "Training"));

        cout << "\n";

        //loop through vector to store product details
        for (Product* p : nets) {
            displayProductDetails(p);
        }

        //go to function to get user choice for product
        productChoice("nets", nets);

        //free up dynamically allocated memory
        for (Product* p : nets) {
            delete p;
        }
    }
    else {
        cout << "Invalid input..Please enter 'volleyballs' or 'nets'\n";
    }
}

void showTableTennisSect() {
    cout << "\nTable Tennis Section:\n";
    cout << "1. Paddles\n";
    cout << "2. Tables\n";
    cout << "3. Balls\n";

    string itemChoice;

    cout << "\nWhich Section would you like to view? (Type 'Paddles', 'Tables', or 'Balls'): ";
    cin >> itemChoice;
    transform(itemChoice.begin(), itemChoice.end(), itemChoice.begin(), ::tolower);


    if (itemChoice == "paddles") {

        vector<Product*> paddles;
        paddles.push_back(new Paddle("Table Tennis Paddle", 39.99, 10, "Professional"));
        paddles.push_back(new Paddle("Table Tennis Paddle", 19.99, 15, "Standard"));

        cout << "\n";
        for (Product* p : paddles) {
            displayProductDetails(p);
        }

        productChoice("paddles", paddles);

        for (Product* p : paddles) {
            delete p;
        }
    }
    else if (itemChoice == "tables") {

        vector<Product*> tables;
        tables.push_back(new Table("Table Tennis Table", 199.99, 3, "Plywood"));
        tables.push_back(new Table("Table Tennis Table", 149.99, 5, "Laminate"));

        cout << "\n";
        for (Product* p : tables) {
            displayProductDetails(p);
        }

        productChoice("tables", tables);

        for (Product* p : tables) {
            delete p;
        }
    }
    else if (itemChoice == "balls") {

        vector<Product*> balls;
        balls.push_back(new Ball("Table Tennis Balls", 9.99, 30));
        balls.push_back(new Ball("Pro Table Tennis Balls", 19.99, 15));

        cout << "\n";
        for (Product* p : balls) {
            displayProductDetails(p);
        }

        productChoice("balls", balls);

        for (Product* p : balls) {
            delete p;
        }
    }
    else {
        cout << "Invalid Input, Please Enter 'Paddles', 'Tables', or 'Balls'..\n";
        return;
    }
}

void showCampingSect() {
    cout << "\nCamping Section:\n";
    cout << "1. Tents\n";
    cout << "2. Sleeping Bags\n";

    string itemChoice;

    cout << "Which section would you like to view? (type 'Tents' or 'Sleeping Bags'): ";
    cin >> itemChoice;
    transform(itemChoice.begin(), itemChoice.end(), itemChoice.begin(), ::tolower);

    if (itemChoice == "tents") {
        vector<Product*> tents;
        tents.push_back(new Tent("Camping Tent", 149.99, 10, "Large", "Standard", "Rain-Proof"));
        tents.push_back(new Tent("Explorer Tent", 199.99, 8, "Extra Large", "Strong", "All Weather-Proof"));

        cout << "\n";
        for (Product* p : tents) {
            displayProductDetails(p);
        }

        productChoice("tents", tents);

        for (Product* p : tents) {
            delete p;
        }
    }
    else if (itemChoice == "sleeping bags") {
        
        vector<Product*> sleepBags;
        sleepBags.push_back(new SleepingBag("Sleeping Bag", 49.99, 12, "Large"));
        sleepBags.push_back(new SleepingBag("Sleeping Bag", 29.99, 16, "Medium"));
        
        cout << "\n";
        for (Product* p : sleepBags) {  
            displayProductDetails(p);
        }

        productChoice("sleeping bags", sleepBags);
        
        for (Product* p : sleepBags) {
            delete p;
        }
    }
    else {
        cout << "Invalid input..Please enter 'tents' or 'sleeping bags'\n";
    }
}

void showSoccerSect() {
    cout << "\nSoccer Section:\n";
    cout << "1. Balls\n";
    cout << "2. Nets\n";

    string itemChoice;
    
    cout << "Which section would you like to view? (type 'Balls' or 'Nets'): ";
    cin >> itemChoice;
    transform(itemChoice.begin(), itemChoice.end(), itemChoice.begin(), ::tolower);

    if (itemChoice == "balls") {
        
        vector<Product*> socBalls;
        socBalls.push_back(new SoccerBall("Soccer Ball", 44.99, 14, "Leather"));
        socBalls.push_back(new SoccerBall("Soccer Ball", 39.99, 12, "Polyurethane"));
        
        cout << "\n";
        for (Product* p : socBalls) {
            displayProductDetails(p);
        }

        productChoice("balls", socBalls);

        for (Product* p : socBalls) {
            delete p;
        }
    }
    else if (itemChoice == "nets") {

        vector<Product*> socNets;
        socNets.push_back(new GoalNet("Soccer Net", 99.99, 5, "Standard"));
        socNets.push_back(new GoalNet("Soccer Net", 59.99, 8, "Little League"));

        cout << "\n";
        for (Product* p : socNets) {
            displayProductDetails(p);
        }

        productChoice("nets", socNets);

        for (Product* p : socNets) {
            delete p;
        }
    }
    else {
        cout << "Invalid input..Please enter 'balls' or 'nets'\n";
    }
}
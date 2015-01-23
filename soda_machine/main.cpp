//
//  main.cpp
//  soda_machine
//
//  Created by Amber Woodrow on 1/8/15.
//  Copyright (c) 2015 Amber Woodrow. All rights reserved.
//

#include <iostream>
// #include <thread>
// #include <chrono>
#include <iomanip>
using namespace std;

// Functions
void init();
void money_menu();
void currency_handler();
void else_currency();
void soda_menu();
void soda_choice();
void else_vend();
void change_return();
void soda_vend();

// Global Variables
double subtotal;
string soda;

int main() {
    init();
}

//Function initiates soda machine with message and allows the user to only press enter to start.
void init(){
    cout << "Hi, I'm a soda machine here to vend you a soda of your choosing.\n"
            "I accept 1 dollar bills, and change, but no pennies.\n"
            "Each soda is 75 cents.\n"
            "When you've paid me 75 cents or more you can claim the soda you'd like.\n";
    
    printf("Press ENTER to continue.\n");
    char c = getchar();
    while(c != '\n'){
        c = getchar();
    }
    money_menu();
}

// Give the user the currency options.
void money_menu(){
    cout << "\n"
            "1. nickel\n"
            "2. dime\n"
            "3. quarter\n"
            "4. dollar\n";
    currency_handler();
}

// Handles the money recieved from user.
void currency_handler(){
    cout << "Insert money into the slot below by selecting a number from the money menu\n"
            "that is next to the amount of money you have for me.\n"
            "Enter money until you reach 75 cents or more.\n"
            "[=========================]\n"
            "-- ^^INSERT MONEY HERE^^ --\n";
    
    //loop until the user has entered 75 cents or more.
    while(subtotal < .75){
        int money;
        bool cin_failed = cin.fail();
        if(!cin_failed){
            cin >> money;
            double money_recieved = 0;
            string inserted = " inserted.\n";
    
                if(money == 1){
                    money_recieved = .05;
                    cout << money_recieved << inserted;
                }
                else if(money == 2){
                    money_recieved = .10;
                    cout << money_recieved << inserted;
                }
                else if(money == 3){
                    money_recieved = .25;
                    cout << money_recieved << inserted;
                }
                else if(money == 4){
                    money_recieved = 1;
                    cout << money_recieved << inserted;
                }
                else{
                    else_currency();
                }
            if(money_recieved != 0){
                subtotal = money_recieved + subtotal;
                cout << "Your subtotal is $" << fixed << setprecision(2) << subtotal << endl;
            }
        }
        else{
            else_currency();
        }
    }
    soda_menu();
}

// Keeps code dry, deals with the else statement.
void else_currency(){
    cout << "Invalid currency selection, please enter a number 1 - 4.\n";
    cin.clear();
    cin.ignore();
}

// Soda options for user.
void soda_menu(){
    cout << "\n"
            "Please press the number button next to the soda you'd like.\n"
            "-- SODA MENU --\n"
            "[1] <- Coke\n"
            "[2] <- Sprite\n"
            "[3] <- Dr. Pepper\n"
            "[4] <- Diet Coke\n"
            "[5] <- Water\n"
            "[6] <- I want my money back! I don't like my options!\n";
    soda_choice();
}

// Validates and handles user's soda selection
void soda_choice(){
    
    int soda_selected;
    cin >> soda_selected;
    bool cin_failed = cin.fail();
    if(!cin_failed){
        if(soda_selected <= 6 && soda_selected >= 0){
            if(soda_selected == 1){
                soda = "Coke";
                change_return();
            }
            else if(soda_selected == 2){
                soda = "Sprite";
                change_return();
            }
            else if(soda_selected == 3){
                soda = "Dr.Pepper";
                change_return();
            }
            else if(soda_selected == 4){
                soda = "Diet Coke";
                change_return();
            }
            else if(soda_selected == 5){
                soda = "Water";
                change_return();
            }
            else if(soda_selected == 6){
                cout << "Your $" << subtotal << " been returned, please remove it from the slot below\n"
                        "[============================]\n";
            }

        }
        else{
            else_vend();
        }
    }
    else{
        else_vend();
    }
}

// Keeps code dry, handles else statements for soda choice.
void else_vend(){
    cout << "Invalid soda selection, please enter a number 1 - 5.\n";
    cin.clear();
    cin.ignore();
    soda_menu();
}

// If there is any change it gets returned and handled here.
void change_return(){
    double change;
    if(subtotal > .75){
        change = subtotal - .75;
        cout << "CLING...\n"
                "Your change is $"
                << change <<
                ".\nGrab your change or donate it to the next lucky soda buyer by leaving it behind :P!\n";
        soda_vend();
    }
    else{
        soda_vend();
    }
}

// Soda is vended here.
void soda_vend(){
    cout << "...\n"
            "*gears grinding*\n"
            "CLING CLONG CLING\n"
            "Please grab your " + soda + " from the vending area\nNice doing business with you!\n";
}
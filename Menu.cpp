//
// Created by Dusan Boljevic on 18/2/25.
//
#include "Menu.h"
#include <iostream>
#include <limits>

using namespace std;

void displayMenu() {
    cout << "===============================================\n"
         << "USER MENU: SOCIAL MEDIA CONTEST DATA STATISTICS\n"
         << "===============================================\n"
         << "1. Read and display contest stats\n"
         << "2. Calculate and display per post data\n"
         << "3. Filter and sort by likes/post\n"
         << "4. Display sorted data by new metric\n"
         << "5. Parametrized sorting and save\n"
         << "6. Exit\n"
         << "Enter choice: ";
}

int getMenuChoice() {
    int choice;
    cin >> choice;
    while (cin.fail() || choice < 1 || choice > 6) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter 1-6: ";
        cin >> choice;
    }
    return choice;
}
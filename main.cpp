#include <iostream>
#include <thread> // Add this line to include the <thread> header
#include "usertypes.h"

using namespace std;

void exit() {
    cout << "Exiting..." << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    exit(0);
}

void mainMenu() {
    while (true) {
        cout << "Login as:" << endl;
        cout << "1. Manager" << endl;
        cout << "2. Employee" << endl;
        cout << "3. Customer" << endl;
        cout << endl;
        cout << "4. Exit" << endl;

        string str;
        getline(cin, str);
        int choice = atoi(str.c_str());

        if (choice == 1) {
            Manager manager; // Create a Manager object
            manager.menu(); // Initialize the Manager object inside the if statement
        } else if (choice == 2) {
            Employee employee; // Create an Employee object
            employee.menu(); // Initialize the Employee object inside the if statement
        } else if (choice == 3) {
            Customer customer; // Create a Customer object
            customer.menu(); // Initialize the Customer object inside the if statement
        } else if (choice == 4) {
            return;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

int main() {
    mainMenu();
    exit();
    return 0;
}
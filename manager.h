#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "mySQLInterface.h"

using namespace std;

class Manager {



public:
void menu() {
    while (true) {
        cout << endl;
        cout << "*** Manager Menu ***" << endl;
        cout << "1. View" << endl;
        cout << "2. Add" << endl;
        cout << "3. Update" << endl;
        cout << "4. Delete" << endl;
        cout << endl;
        cout << "5. Back" << endl;
        cout << endl;

        string str;
        getline(cin, str);
        int choice = atoi(str.c_str());

        if (choice == 1) { // View
            ViewCommands();
        } else if (choice == 2) { // Add
            AddCommands();
        } else if (choice == 3) { // Update
            //UpdateCommands();
        } else if (choice == 4) { // Delete
            //DeleteCommands();
        } else if (choice == 5) { // Back
            cout << "back called" << endl;
            return;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void ViewCommands() {
    while (true) {
        cout << endl;
        cout << "*** Manager View Menu ***" << endl;
        cout << "1. Tables..." << endl;
        cout << "2. Queries..." << endl;
        cout << endl;
        cout << "3. Back" << endl;
        cout << endl;

        string str;
        getline(cin, str);
        int choice = atoi(str.c_str());

        if (choice == 1) { // View Table
            ViewTable();
        } else if (choice == 2) { // Search For
            UseQueries();
        } else if (choice == 3) { // Back
            return;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void AddCommands() {
    while (true) {
        cout << endl;
        cout << "*** Manager Add Menu ***" << endl;
        cout << "1. Add new Customer" << endl;
        cout << "2. Add new Employee" << endl;
        cout << "3. Add new Book" << endl;
        cout << endl;
        cout << "4. Back" << endl;
        cout << endl;

        string str;
        getline(cin, str);
        int choice = atoi(str.c_str());

        if (choice == 1) { //Add new Customer
            // The new customer will have a Name, Address, and Bank Card type
            cout << "Enter Customer Name: ";
            string name;
            getline(cin, name);
            cout << "Enter Customer Address: ";
            string address;
            getline(cin, address);
            cout << "Enter Customer Bank Card Type: ";
            string cardType;
            getline(cin, cardType);
            sql.WriteFile("INSERT INTO CUSTOMER (Name, Shipping_information, Payment_method) VALUES ('" + name + "', '" + address + "', '" + cardType + "');");
        }
    }
}

void ViewTable() {
    while (true) {
        cout << endl;
        cout << "* Manager View Table *" << endl;
        cout << "1. Authors" << endl;
        cout << "2. Books" << endl;
        cout << "3. Customers" << endl;
        cout << "4. Employees" << endl;
        cout << "5. Publishers" << endl;
        cout << "6. Work Schedules" << endl;
        cout << "7. Wishlists" << endl;
        cout << "8. Reviews" << endl;
        cout << endl;
        cout << "9. Back" << endl;

        string str;
        getline(cin, str);
        int choice = atoi(str.c_str());

        if (choice == 1) { // Authors
            cout << "* Viewing Authors *" << endl;
            sql.WriteFile("select * from AUTHOR;");
            sql.ReadFile();
        } else if (choice == 2) { // Books
            cout << "* Viewing Books *" << endl;
            sql.WriteFile("select * from BOOK;");
            sql.ReadFile();
        } else if (choice == 3) { // Customers
            cout << "* Viewing Customers *" << endl;
            sql.WriteFile("select * from CUSTOMER;");
            sql.ReadFile();
        } else if (choice == 4) { // Employees
            cout << "* Viewing Employees *" << endl;
            sql.WriteFile("select * from EMPLOYEE;");
            sql.ReadFile();
        } else if (choice == 5) { // Publishers
            cout << "* Viewing Publishers *" << endl;
            sql.WriteFile("select * from PUBLISHER;");
            sql.ReadFile();
        } else if (choice == 6) { // Work Schedules
            cout << "* Viewing Work Schedules *" << endl;
            sql.WriteFile("select * from WORK_SCHEDULE;");
            sql.ReadFile();
        } else if (choice == 7) { // Wishlists
            cout << "* Viewing Wishlists *" << endl;
            sql.WriteFile("select * from WISHLIST;");
            sql.ReadFile();
        } else if (choice == 8) { // Reviews
            cout << "* Viewing Reviews *" << endl;
            sql.WriteFile("select * from REVIEWS;");
            sql.ReadFile();
        } else if (choice == 9) { // Back
            return;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void UseQueries() {
    while (true) {
        cout << endl;
        cout << "* Manager Queries *" << endl;
        cout << "1. Find books by Author" << endl;
        cout << "2. Search reviews by book name" << endl;
        cout << endl;
        cout << "3. Back" << endl;

        string str;
        getline(cin, str);
        int choice = atoi(str.c_str());

        if (choice == 1) {
            cout << "* Find books by Author *" << endl;
            cout << "Enter Author Name: ";
            string userInput;
            getline(cin, userInput);
            sql.WriteFile("SELECT B.Name AS BookName, P.Name AS PublisherName FROM BOOK B JOIN AUTHOR A ON B.Aname = A.Name JOIN PUBLISHER P ON B.Pname = P.Name WHERE A.Name = '" + userInput + "';");
            sql.ReadFile();
        } else if (choice == 2) {
            cout << "* List customers who have reviewed book by book name *" << endl;
            cout << "Enter Book Name: ";
            string userInput;
            getline(cin, userInput);
            sql.WriteFile("SELECT C.Name AS CustomerName, R.Date AS ReviewDate, R.Comment AS ReviewComment FROM CUSTOMER C JOIN REVIEWS R ON C.CustomerID = R.CustomerID JOIN BOOK B ON R.BookID = B.BookID WHERE B.Name = '" + userInput + "';");
            sql.ReadFile();
        } else if (choice == 3) {
            return;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

private:
    mySQLInterface sql;
};
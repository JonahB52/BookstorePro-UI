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
            UpdateCommands();
        } else if (choice == 4) { // Delete
            DeleteCommands();
        } else if (choice == 5) { // Back
            cout << "back called" << endl;
            return;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

// Choose to view a whole table or use a query
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

// Adding data to tables as manager
void AddCommands() {
    while (true) {
        cout << endl;
        cout << "*** Manager Add Menu ***" << endl;
        cout << "1. Add new Customer" << endl;
        cout << "2. Add new Employee" << endl;
        cout << "3. Add new Book" << endl;
        cout << "4. Add new Employee Shift" << endl;
        cout << endl;
        cout << "5. Back" << endl;
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
        else if (choice == 2) { //Add new Employee
            // The new employee will have a Name, phone number, and and role
            cout << "Enter Employee Name: ";
            string name;
            getline(cin, name);
            cout << "Enter Employee Phone Number (e.g. 1234567890): ";
            string phone;
            getline(cin, phone);
            cout << "Enter Employee Role: ";
            string role;
            getline(cin, role);
            sql.WriteFile("INSERT INTO EMPLOYEE (Name, Phone, Role) VALUES ('" + name + "', '" + phone + "', '" + role + "');");
        }
        // more
        else if (choice == 3) { //Add new Book
            // The new book will have a name, location, genre, quantity, price, publisher, and author
            cout << "Enter Book Name: ";
            string name;
            getline(cin, name);
            cout << "Enter Book Location (e.g. C1): ";
            string location;
            getline(cin, location);
            cout << "Enter Book Genre: ";
            string genre;
            getline(cin, genre);
            cout << "Enter Book Quantity: ";
            string quantity;
            getline(cin, quantity);
            cout << "Enter Book Price: ";
            string price;
            getline(cin, price);
            cout << "Enter Book Publisher: ";
            string publisher;
            getline(cin, publisher);
            cout << "Enter Book Author: ";
            string author;
            getline(cin, author);
            sql.WriteFile("INSERT INTO BOOK (Name, Location, Genre, Quantity, Price, Pname, Aname) VALUES ('" + name + "', '" + location + "', '" + genre + "', '" + quantity + "', '" + price + "', '" + publisher + "', '" + author + "');");
        }
        else if (choice == 4) { //Add new Employee Shift
            // The new employee shift will have an employee id, date, and time.
            cout << "Enter Employee ID: ";
            string id;
            getline(cin, id);
            cout << "Enter Shift Date (e.g. 2023-12-02): ";
            string date;
            getline(cin, date);
            cout << "Enter Shift Time (e.g. 9:14:53): ";
            string time;
            getline(cin, time);
            sql.WriteFile("INSERT INTO WORK_SCHEDULE (EempID, Date, Time) VALUES ('" + id + "', '" + date + "', '" + time + "');");
        }
        else if (choice == 5) { // Back
            return;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

// Updating data from tables as manager
void UpdateCommands() {
    while (true) {
        cout << endl;
        cout << "*** Manager Update Menu ***" << endl;
        cout << "1. Update Employee Information" << endl;
        cout << "2. Update Book Information" << endl;
        cout << endl;
        cout << "3. Back" << endl;
        cout << endl;

        string str;
        getline(cin, str);
        int choice = atoi(str.c_str());

        if (choice == 1) { // Update Employee Information
            cout << "Enter Employee ID: ";
            string id;
            getline(cin, id);
            cout << "Enter Employee Name: ";
            string name;
            getline(cin, name);
            cout << "Enter Employee Phone Number (e.g. 1234567890): ";
            string phone;
            getline(cin, phone);
            cout << "Enter Employee Role: ";
            string role;
            getline(cin, role);
            sql.WriteFile("UPDATE EMPLOYEE SET Name = '" + name + "', Phone = '" + phone + "', Role = '" + role + "' WHERE EmpID = '" + id + "';");
        } else if (choice == 2) { // Update Book Information
            cout << "Enter Book ID: ";
            string id;
            getline(cin, id);
            cout << "Enter Book Name: ";
            string name;
            getline(cin, name);
            cout << "Enter Book Location (e.g. C1): ";
            string location;
            getline(cin, location);
            cout << "Enter Book Genre: ";
            string genre;
            getline(cin, genre);
            cout << "Enter Book Quantity: ";
            string quantity;
            getline(cin, quantity);
            cout << "Enter Book Price: ";
            string price;
            getline(cin, price);
            cout << "Enter Book Publisher: ";
            string publisher;
            getline(cin, publisher);
            cout << "Enter Book Author: ";
            string author;
            getline(cin, author);
            sql.WriteFile("UPDATE BOOK SET Name = '" + name + "', Location = '" + location + "', Genre = '" + genre + "', Quantity = '" + quantity + "', Price = '" + price + "', Pname = '" + publisher + "', Aname = '" + author + "' WHERE BookID = '" + id + "';");
        } else if (choice == 3) { // Back
            return;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

// Deleting data from tables as manager
void DeleteCommands() {
    while (true) {
        cout << endl;
        cout << "*** Manager Delete Menu ***" << endl;
        cout << "1. Delete Employee" << endl;
        cout << "2. Delete Book" << endl;
        cout << endl;
        cout << "3. Back" << endl;
        cout << endl;

        string str;
        getline(cin, str);
        int choice = atoi(str.c_str());

        if (choice == 1) { // Delete Employee
            cout << "Enter Employee ID: ";
            string id;
            getline(cin, id);
            sql.WriteFile("DELETE FROM WORK_SCHEDULE WHERE EempID = '" + id + "';");
            sql.WriteFile("DELETE FROM EMPLOYEE WHERE EmpID = '" + id + "';");
        } else if (choice == 2) { // Delete Book
            cout << "Enter Book ID: ";
            string id;
            getline(cin, id);
            sql.WriteFile("DELETE FROM REVIEWS WHERE BookID = '" + id + "';");
            sql.WriteFile("DELETE FROM BOOK WHERE BookID = '" + id + "';");
        } else if (choice == 3) { // Back
            return;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

// Viewing all data fromm a specific table as manager
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

// Queries for viewing data as a manager
void UseQueries() {
    while (true) {
        cout << endl;
        cout << "* Manager Queries *" << endl;
        cout << "1. List book, author, and review count for the book with the highest price and most reviews" << endl;
        cout << "2. List customers who have reviewed book by book name" << endl;
        cout << endl;
        cout << "3. Back" << endl;

        string str;
        getline(cin, str);
        int choice = atoi(str.c_str());
        if (choice == 1) {
            cout << "* List book, author, and review count for the book with the highest price and most reviews *" << endl;
            sql.WriteFile("SELECT BookName, AuthorName, MaxPrice, ReviewCount FROM (SELECT B.Name AS BookName, A.Name AS AuthorName, B.Price AS MaxPrice, COUNT(R.ReviewID) AS ReviewCount FROM BOOK B JOIN REVIEWS R ON B.BookID = R.BookID JOIN AUTHOR A ON B.Aname = A.Name GROUP BY B.BookID ORDER BY MaxPrice DESC, ReviewCount DESC LIMIT 1) AS MaxBookInfo;");
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

class Employee {
public:

// Employee menu
void menu() {
    while (true) {
        cout << endl;
        cout << "*** Employee Menu ***" << endl;
        cout << "1. Lists customers who have reviewed book by book name" << endl;
        cout << endl;
        cout << "2. Back" << endl;
        cout << endl;

        string str;
        getline(cin, str);
        int choice = atoi(str.c_str());

        if (choice == 1) { // View
            cout << "* Find customers who have reviewed book by book name *" << endl;
            cout << "Enter Book Name: ";
            string userInput;
            getline(cin, userInput);
            sql.WriteFile("SELECT B.Name AS BookName, C.Name AS CustomerName FROM BOOK B JOIN REVIEWS R ON B.BookID = R.BookID JOIN CUSTOMER C ON R.CustomerID = C.CustomerID WHERE B.Name = '" + userInput + "' GROUP BY B.Name, C.Name;");
            sql.ReadFile();
        } else if (choice == 2) { // Back
            return;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

private:
    mySQLInterface sql;
};

class Customer {
public:
// Customer menu
void menu() {
    while (true) {
        cout << endl;
        cout << "*** Customer Menu ***" << endl;
        cout << "1. Search books and publishers by Author" << endl;
        cout << endl;
        cout << "2. Back" << endl;
        cout << endl;
        
        string str;
        getline(cin, str);
        int choice = atoi(str.c_str());

        if (choice == 1) { // View
            cout << "* Find books and publishers by Author *" << endl;
            cout << "Enter Author Name: ";
            string userInput;
            getline(cin, userInput);
            sql.WriteFile("SELECT B.Name AS BookName, P.Name AS PublisherName FROM BOOK B JOIN AUTHOR A ON B.Aname = A.Name JOIN PUBLISHER P ON B.Pname = P.Name WHERE A.Name = '" + userInput + "';");
            sql.ReadFile();
        } else if (choice == 2) { // Back
            cout << "back called" << endl;
            return;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

private:
    mySQLInterface sql;
};
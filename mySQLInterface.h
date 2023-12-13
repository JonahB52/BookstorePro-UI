#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class mySQLInterface {
public:
    // Execute a SQL command and write the output to a file via mysqlsh
    void WriteFile(string sql) {
        // Create the mysqlsh command to connect to our remote database in the correct mode
        string s1 = "mysqlsh -u admin -h database-1.cveqjvpusgj7.us-east-2.rds.amazonaws.com -P 3306 -D UITesting --sql --table -e \"";
        string s2 = "\" > output.txt";

        // Place the SQL command inside the mysqlsh command
        string command = s1 + sql + s2;
        // Execute the command
        system(command.c_str());
    }
    // Read the output file and output the contents to the terminal
    void ReadFile() {
        string line;
        ifstream myfile("output.txt");
        if (myfile.is_open()) {
            while (getline(myfile, line)) {
                cout << line << endl;
            }
            myfile.close();
        } else {
            cout << "Unable to open file" << endl;
        }
    }

private:
    string filename;
};
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class mySQLInterface {
public:
    void WriteFile(string sql) {
        string s1 = "mysqlsh -u admin -h database-1.cveqjvpusgj7.us-east-2.rds.amazonaws.com -P 3306 -D UITesting --sql --table -e \"";
        string s2 = "\" > output.txt";
        string command = s1 + sql + s2;
        system(command.c_str());
    }
    void ReadFile() {
        // Read all lines from the file and output them to the terminal.
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
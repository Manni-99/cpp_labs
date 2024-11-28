#include "UserTable.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
int main()
{
    UserTable table;
    std::ifstream userFile("users.txt");
    if (!userFile) {
        std::cerr << "Error opening users.txt for reading." << std::endl;
        return 1;
    }
    string line;
    while(getline(userFile, line)){
        stringstream ss(line);

        string username;
        int cardNbr;

        ss >> cardNbr ;
        getline(ss, username);

        User user(cardNbr, username);
        table.addUser(user);
    }

    cout << table.getNbrUsers() << endl; 

    cout << table.find(21330) << endl;
    cout << table.find(21331) << endl;
    cout << table.find(" Jens Holmgren") << endl;
    
    User newUser(1234, "Kristmann Thorsteinsson");
    table.addUser(newUser);
    cout << table.getNbrUsers() << endl;  

    cout << testFindNbr(table) << endl;

    userFile.close();
    return 0;
}
#include <iostream>
#include <iomanip> // for setw and setfill
#include "date.h"

using std::cin;
using std::cout;
using std::endl;

/*
 * Main function to test the Date class.
 */
int main()
{
    double d = 1.234;
    Date today;

    // Convert double and Date to strings using the toString template function
    std::string sd = toString(d);
    std::string st = toString(today);

    // Print the string representations
    std::cout << "Double as string: " << sd << std::endl;
    std::cout << "Date as string: " << st << std::endl;
    // Test input and output of dates

    try
    {
        int i = string_cast<int>("123kalle");
        double d = string_cast<double>("12.34");
        Date date = string_cast<Date>("2015-01-10");
        cout << i << "\n"
             << d << "\n"
             << date << endl;
    }
    catch (std::invalid_argument &e)
    {
        cout << "Error: " << e.what() << endl;
    }
    bool cont = true;

    // Check 'next' functionality
    cout << "--- Today and more than a month ahead:" << endl;
    Date d1;
    cout << d1 << endl; // Use overloaded operator<<
    for (int i = 1; i <= 35; ++i)
    {
        d1.next();
        cout << d1 << endl; // Use overloaded operator<<
    }

    // Check year transition
    cout << "--- New Year's Eve and the next day:" << endl;
    Date d2(2013, 12, 31);
    cout << d2 << endl; // Use overloaded operator<<
    d2.next();
    cout << d2 << endl; // Use overloaded operator<<'
    
    while (cont)
    {
        try
        {
            cout << "Type a date (yyyy-mm-dd): ";
            Date aDate;
            cin >> aDate;

            if (cin.eof())
            {
                cont = false; // Exit the loop on EOF
            }
            else if (!cin.good())
            {
                cout << "Wrong input format" << endl;
                cin.clear();             // Restore stream state
                cin.ignore(10000, '\n'); // Ignore invalid input
            }
            else
            {
                cout << "Output: " << aDate << endl;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    return 0;
}

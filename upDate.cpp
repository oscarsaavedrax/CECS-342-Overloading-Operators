// Oscar Saavedra
// CECS 342-07
// Program 2 - Overloading Operators
// September 29, 2022
//
// I certify that this program is my own original work. I did not copy any part of this 
// program from any other source. I further certify that I typed each and every line of 
// code in this program.

#include "upDate.h"
#include <iostream>
using namespace std;

// Default constructor
upDate::upDate()
{
    // Dynamically allocate new integer array to hold date
    date_ptr = new int[3];
    cout << "New date pointer created." << endl;

    date_ptr[0] = 5;
    date_ptr[1] = 11;
    date_ptr[2] = 1959;
}// end upDate default constructor

// Overloaded constructor
upDate::upDate(int m, int d, int y)
{
    // Dynamically allocate new integer array to hold date
    date_ptr = new int[3];
    cout << "New date pointer created." << endl;

    // Verify date is valid
    if(validDate(m, d, y))
    {
        date_ptr[0] = m;
        date_ptr[1] = d;
        date_ptr[2] = y;
    }
    else
    {
        date_ptr[0] = 5;
        date_ptr[1] = 11;
        date_ptr[2] = 1959;
    }
}// end upDate overloaded constructor

// Overloaded constructor
upDate::upDate(int J)
{
    // Create variables
    int temp_m, temp_d, temp_y;

    J2G(J, temp_m, temp_d, temp_y);

    date_ptr = new int[3];
    cout << "New date pointer created." << endl;

    date_ptr[0] = temp_m;
    date_ptr[1] = temp_d;
    date_ptr[2] = temp_y;
}// end upDate overloaded constructor

// Function to verify the entered date is valid
bool upDate::validDate(int m, int d, int y)
{
    // Create variables
    int temp_m, temp_d, temp_y;
    bool valid_date = false;

    // Assign date to be tested to temporary variables
    temp_m = m;
    temp_d = d;
    temp_y = y;

    // Get Julian date
    int JD = G2J(m, d, y);

    // Change JD back to Gregorian date
    J2G(JD, m, d, y);

    // Compare Gregorian dates
    if(temp_m == m && temp_d == d && temp_y == y)
        valid_date = true;

    return valid_date;
}// end validDate

// Convert Gregorian date to Julian date
int upDate::G2J(int m, int d, int y)
{
    int JD;

    JD = d - 32075 + 1461 * (y + 4800 + (m - 14) / 12) / 4 + 367 * (m - 2 - (m - 14) /12 * 12)
        / 12 - 3 * ((y + 4900 + (m - 14) / 12) / 100) / 4;
    
    return JD;   
}// end G2J

// Convert Julian date to Gregorian date
void upDate::J2G(int JD, int &m, int &d, int &y)
{
    // Create tempory integer variables
    int i, j, k, l, n;
    
    l = JD + 68569;
    n = 4 * l / 146097;
    l = l - (146097 * n + 3) / 4;
    i = 4000 * (l + 1) / 1461001;
    l = l - 1461 * i / 4 + 31;
    j = 80 * l / 2447;
    k = l - 2447 * j / 80;
    l = j / 11;
    j = j + 2 - 12 * l;
    i = 100 * (n - 49) + i + l;

    m = j;
    d = k;
    y = i;
}// end J2G

// Getter for month variable
int upDate::getMonth() const
{
    return date_ptr[0];
}// end getMonth

// Getter for day variable
int upDate::getDay() const
{
    return date_ptr[1];
} // end getDay

// Getter for year variable
int upDate::getYear() const
{
    return date_ptr[2];
}// end getYear

// Destructor
upDate::~upDate()
{
    delete []date_ptr;
    cout << "Date pointer destroyed." << endl;
}// end upDate destructor
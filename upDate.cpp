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
#include <string>
using namespace std;

// Default constructor
upDate::upDate()
{
    // Dynamically allocate new integer array to hold date
    date_ptr = new int[3];

    date_ptr[0] = 5;
    date_ptr[1] = 11;
    date_ptr[2] = 1959;

    date_count += 1;
}// end upDate default constructor

// Overloaded constructor
upDate::upDate(int m, int d, int y)
{
    // Dynamically allocate new integer array to hold date
    date_ptr = new int[3];

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

    date_count += 1;
}// end upDate overloaded constructor

// Overloaded constructor
upDate::upDate(int J)
{
    // Create variables
    int temp_m, temp_d, temp_y;

    J2G(J, temp_m, temp_d, temp_y);

    date_ptr = new int[3];

    date_ptr[0] = temp_m;
    date_ptr[1] = temp_d;
    date_ptr[2] = temp_y;

    date_count += 1;
}// end upDate overloaded constructor

// Copy constructor
upDate::upDate(const upDate &D)
{
    date_ptr = new int[3];

    date_ptr[0] = D.getMonth();
    date_ptr[1] = D.getDay();
    date_ptr[2] = D.getYear();

    date_count += 1;
}// end copy constructor

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

// Return the Julian integer of the date
int upDate::julian()
{
    //Create temporary variable
    upDate temp(*this);

    int JD = G2J(temp.date_ptr[0], temp.date_ptr[1], temp.date_ptr[2]);

    return JD;
}// end julian

// Overloaded assignment operator
upDate upDate::operator=(const upDate &D)
{
    //Create temporary variable
    upDate temp(*this);

    // Deep copy
    temp.date_ptr[0] = D.date_ptr[0];
    temp.date_ptr[1] = D.date_ptr[1];
    temp.date_ptr[2] = D.date_ptr[2];

    return temp;
}// end operator=

// Overloaded addition with assignment operator
upDate upDate::operator+=(int n)
{
    //Create temporary variable
    upDate temp(*this);

    // Convert to Julian and add n 
    int JD = G2J(temp.date_ptr[0], temp.date_ptr[1], temp.date_ptr[2]) + n;

    // Convert back to Gregorian
    J2G(JD, temp.date_ptr[0], temp.date_ptr[1], temp.date_ptr[2]);

    return temp;
}// end operator+=

// Overloaded subtraction with assignment operator
upDate upDate::operator-=(int n)
{
    //Create temporary variable
    upDate temp(*this);

    // Convert to Julian and subtract n 
    int JD = G2J(temp.date_ptr[0], temp.date_ptr[1], temp.date_ptr[2]) - n;

    // Convert back to Gregorian
    J2G(JD, temp.date_ptr[0], temp.date_ptr[1], temp.date_ptr[2]);

    return temp;
}// end operator-=

// Overloaded addition operator
upDate upDate::operator+(int n)
{
    //Create temporary variable
    upDate temp(*this);

    // Convert to Julian and add n 
    int JD = G2J(temp.date_ptr[0], temp.date_ptr[1], temp.date_ptr[2]) + n;

    // Convert back to Gregorian
    J2G(JD, temp.date_ptr[0], temp.date_ptr[1], temp.date_ptr[2]);

    return temp;
}// end operator+

// Overloaded subtraction operator
upDate upDate::operator-(int n)
{
    //Create temporary variable
    upDate temp(*this);

    // Convert to Julian and subtract n 
    int JD = G2J(temp.date_ptr[0], temp.date_ptr[1], temp.date_ptr[2]) - n;

    // Convert back to Gregorian
    J2G(JD, temp.date_ptr[0], temp.date_ptr[1], temp.date_ptr[2]);

    return temp;
}// end operator-

// Overloaded postfix operator increment operator
upDate upDate::operator++(int)
{
    //Create temporary variable
    upDate temp(*this);

    // Increment by one
    temp.date_ptr[1] = date_ptr[1]++;

    return temp;
}// end operator++(int)

// Overloaded prefix increment operator
upDate upDate::operator++()
{
    //Create temporary variable
    upDate temp(*this);

    // Increment by one
    temp.date_ptr[1] = ++date_ptr[1];

    return temp;
}// end operator++()

// Overloaded postfix decrement operator
upDate upDate::operator--(int)
{
    //Create temporary variable
    upDate temp(*this);

    // Decrement by one
    temp.date_ptr[1] = date_ptr[1]--;

    return temp;
    
}// end operator--(int)

// Overloaded prefix decrement operator
upDate upDate::operator--()
{
    //Create temporary variable
    upDate temp(*this);

    // Decrement by one
    temp.date_ptr[1] = --date_ptr[1];

    return temp;

}// end operator--()

// Overloaded equality operator
bool upDate::operator==(const upDate &D)
{
    //Create temporary variable
    upDate temp(*this);

    bool flag = false;

    // Convert to Julian
    int temp_JD = G2J(temp.date_ptr[0], temp.date_ptr[1], temp.date_ptr[2]);
    int other_JD = G2J(D.date_ptr[0], D.date_ptr[1], D.date_ptr[2]);

    // Compare Julian dates
    if (temp_JD == other_JD)
        flag = true;

    return flag;
}// end operator==

// Overloaded less than operator
bool upDate::operator<(const upDate &D)
{
    //Create temporary variable
    upDate temp(*this);

    bool flag = false;

    // Convert to Julian
    int temp_JD = G2J(temp.date_ptr[0], temp.date_ptr[1], temp.date_ptr[2]);
    int other_JD = G2J(D.date_ptr[0], D.date_ptr[1], D.date_ptr[2]);

    // Compare Julian dates
    if (temp_JD < other_JD)
        flag = true;

    return flag;
}// end operator<

// Overloaded greater than operator
bool upDate::operator>(const upDate &D)
{
    //Create temporary variable
    upDate temp(*this);

    bool flag = false;

    // Convert to Julian
    int temp_JD = G2J(temp.date_ptr[0], temp.date_ptr[1], temp.date_ptr[2]);
    int other_JD = G2J(D.date_ptr[0], D.date_ptr[1], D.date_ptr[2]);

    // Compare Julian dates
    if (temp_JD > other_JD)
        flag = true;

    return flag;
}// end operator>

//Overloaded subtraction operator with objects
int upDate::operator-(const upDate &D)
{
    //Create temporary variable
    upDate temp(*this);

    // Convert to Julian dates
    int temp_JD = G2J(temp.date_ptr[0], temp.date_ptr[1], temp.date_ptr[2]);
    int D_JD = G2J(D.date_ptr[0], D.date_ptr[1], D.date_ptr[2]);

    return (temp_JD - D_JD);
}// end operator-(const upDate)

// Overloaded cout operator
ostream& operator<<(ostream& out, const upDate &D)
{
    out << D.date_ptr[0] << "/" << D.date_ptr[1] << "/" << D.date_ptr[2];

    return out;
}// end cout operator

// Overloaded addition operator
upDate operator+(int n, const upDate &D)
{
    upDate temp(D);
    int JD = temp.G2J(temp.date_ptr[0], temp.date_ptr[1], temp.date_ptr[2]) + n;

    temp.J2G(JD, temp.date_ptr[0], temp.date_ptr[1], temp.date_ptr[2]);
    
    return temp;
}// end overloaded addition operator

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

// Get month name
string upDate::getMonthName() const
{
    // Create string array to hold the month names
    string months[12] = { "January", "Febuary", "March", "April", 
                            "May", "June", "July", "August", "September", 
                            "October", "November", "December" };
    
    return months[date_ptr[0] - 1];
}// end getMonthName

// Static method to get number of date objects
int upDate::GetDateCount()
{
    return date_count;
}// end GetDateCount

// Deconstructor
upDate::~upDate()
{
    delete []date_ptr;
    date_count -= 1;
}// end upDate deconstructor
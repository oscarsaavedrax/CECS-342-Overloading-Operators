// Oscar Saavedra
// CECS 342-07
// Program 2 - Overloading Operators
// September 29, 2022
//
// I certify that this program is my own original work. I did not copy any part of this 
// program from any other source. I further certify that I typed each and every line of 
// code in this program.

#include "upDate.h"

// Default constructor
upDate::upDate()
{
    month = 5;
    day = 11;
    year = 1959;
}

// Overloaded constructor
upDate::upDate(int m, int d, int y)
{
    month = m;
    day = d;
    year = y;
}

// Convert Gregorian date to Julian date
int upDate::G2J(int m, int d, int y)
{
    int JD;

    JD = d - 32075 + 1461 * (y + 4800 + (m - 14) / 12) / 4 + 367 * (m - 2 - (m - 14) /12 * 12)
        / 12 - 3 * ((y + 4900 + (m - 14) / 12) / 100) / 4;
    
    return JD;
        
}

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
    
}

// Getter for month variable
int upDate::getMonth() const
{
    return month;
}

// Getter for day variable
int upDate::getDay() const
{
    return day;
}

// Getter for year variable
int upDate::getYear() const
{
    return year;
}

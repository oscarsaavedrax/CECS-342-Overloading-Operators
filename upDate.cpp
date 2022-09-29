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

upDate::upDate(int m, int d, int y)
{
    month = m;
    day = d;
    year = y;
}

int upDate::G2J(int m, int d, int y)
{
    int JD;

    JD = d - 32075 + 1461 * (y + 4800 + (m - 14) / 12) / 4 + 367 * (m - 2 - (m - 14) /12 * 12)
        / 12 - 3 * ((y + 4900 + (m - 14) / 12) / 100) / 4;
    
    return JD;
        
}
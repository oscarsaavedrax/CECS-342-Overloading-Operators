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
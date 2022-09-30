// Oscar Saavedra
// CECS 342-07
// Program 2 - Overloading Operators
// September 29, 2022
//
// I certify that this program is my own original work. I did not copy any part of this 
// program from any other source. I further certify that I typed each and every line of 
// code in this program.

#include <iostream>
#include <string>
using namespace std;

class upDate
{
    private:
        int *date_ptr;  // Pointer to a integer date array
        static int date_count;
        bool validDate(int m, int d, int y);   // Verify the entered date is valid
    public:
        upDate();   // Default constructor
        upDate(int m, int d, int y);    // Overloaded constructor
        upDate(int J); // Overloaded constructor
        upDate(const upDate &D); // Copy constructor

        int G2J(int m, int d, int y);   // Convert Gregorian date to Julian date
        void J2G(int JD, int &m, int &d, int &y);   // Convert Julian date to Gregorian date
        int julian(); // Return the Julian integer of the date

        upDate operator=(const upDate &D); // Overloaded assignment operator
        upDate operator+=(int n); // Overloaded addition with assignment operator
        upDate operator-=(int n); // Overloaded subtraction with assignment operator
        upDate operator+(int n);  // Overloaded addition operator
        upDate operator-(int n); // Overloaded subtraction operator
        upDate operator++(int); // Overloaded postfix increment operator
        upDate operator++(); // Overloaded prefix increment operator
        upDate operator--(int); // Overloaded postfix decrement operator
        upDate operator--(); // Overloaded prefix decrement operator

        bool operator==(const upDate &D); // Overloaded equality operator
        bool operator<(const upDate &D); // Overloaded less than operator
        bool operator>(const upDate &D); // Overloaded greater than operator

        int operator-(const upDate &D); // Overloaded subtraction operator with objects

        friend ostream& operator<<(ostream& out, const upDate &D); // Overloaded cout operator
        friend upDate operator+(int n, const upDate &D); // Overloaded addition operator

        int getMonth() const;   // Get month
        int getDay() const;     // Get day
        int getYear() const;    // Get year
        string getMonthName() const; // Get month name 

        static int GetDateCount();  // Static method to get number of date objects

        ~upDate();// Deconstructor
};

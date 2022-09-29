// Oscar Saavedra
// CECS 342-07
// Program 2 - Overloading Operators
// September 29, 2022
//
// I certify that this program is my own original work. I did not copy any part of this 
// program from any other source. I further certify that I typed each and every line of 
// code in this program.

#pragma

class upDate
{
    private:
        int month;
        int day;
        int year;
    public:
        // Default constructor
        upDate();
        // Overloaded constructor
        upDate(int m, int d, int y);
        // Overloaded addition operator
        upDate operator+(int);

        // Convert Gregorian date to Julian date
        int G2J(int m, int d, int y);

        // Convert Julian date to Gregorian date
        void J2G(int JD, int &m, int &d, int &y);

        int getMonth() const;
        int getDay() const;
        int getYear() const;


};

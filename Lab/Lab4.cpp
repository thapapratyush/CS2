/*
Your lab assignment is to get the following code working. 

 

Use the file below. Name it "infile.txt".

January 31
February 28
March 31
April 30
May 31
June 30
July 31
August 31
September 30
October 31
November 30
December 31

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <conio.h>
 
using namespace std;
   
class DateType
{
 
public:
    void Initialize(int newMonth, int newDay, int newYear);
    void setYear(int);
    void setMonth(int);
    void setDay(int);
    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;
private:
    int year;
    int month;
    int day;
};
 
void DateType::Initialize(int newMonth, int newDay, int newYear) {
    year = newYear;
    month = newMonth;
    day = newDay;
}
 
void DateType::setYear(int Yr)
{
    year = Yr;
}
void DateType::setMonth(int Month)
{
    month = Month;
}
void DateType::setDay(int Day)
{
    day = Day;
}
 
int DateType::GetYear() const
{
    return year;
}
int DateType::GetMonth() const
{
    return month;
}
int DateType::GetDay() const
{
    return day;
}
class monthType
{
public:
    int month_num;
    int dates[6][7];
    monthType(); // constructor
    void printMonth();
    void setMonthName(string);
    string getMonthName();
private:
    string month_name;
};
monthType::monthType()
{
    for (int row=0; row<6; row++)
    {
        for (int col=0; col<7; col++)
            dates[row][col] = 0;
    }
}
void monthType::setMonthName(string mon_name)
{
    month_name = mon_name;
}
string monthType::getMonthName()
{
    return month_name;
}
 
void monthType::printMonth()
{
    cout << endl << setw(12) << month_name << endl << endl;
    for (int row=0; row<6; row++)
    {
        for (int col=0; col<7; col++)
        {
            cout << setw(6) << dates[row][col];
             
        }
        cout << endl; // skip a line between weeks
    }
}
class yearType
{
public:
    monthType months[12];
    yearType(); //constructor
    void printYear()
    {
        for (int month_index=0; month_index<12; month_index++)
        {
            months[month_index].printMonth();
        }
    }
};
yearType::yearType()
{
    for (int i=0; i<12; i++)
        months[i].month_num = i;
}
class calendar
{
    public:
    void printCalendar(yearType);
};
 
int get_year();
int get_starting_day();
void print_heading(int);
string read_month_name(ifstream&);
int read_num_days(ifstream&);
int print_month(int, int, string, int, yearType); //function
int main()
{
    yearType thisYear;
    string dummy;
    ifstream myfile; //declare file input
    myfile.open("infile.txt"); //open file 
    int year; //define variables
    int starting_day;
    string month_name;
    int num_days;
    int month_counter;
    month_counter = 0; //used to keeps track of months for while loop
    int last_day;
    year = get_year();
    print_heading(year);//print heading for calendar
    starting_day = get_starting_day(); //calculate starting day for month of january 
    while (month_counter < 12) //loop will only run till december and then it will fail 
    {
        month_name = read_month_name(myfile); //read month name from input file using referencing 
        thisYear.months[month_counter].setMonthName(month_name); // set the month name in each month
        num_days = read_num_days(myfile); //read max num of days in selected month using referencing 
        last_day = print_month(starting_day, num_days, 
            month_name, month_counter, thisYear); //the last day of the previous month 
        starting_day = last_day;
        month_counter++; //must be increased so the loop wont read past the number of months in a year 
        cout << endl;
    }
    thisYear.printYear();
    system("pause");
    cin >> dummy;
    return 0;
}
int get_year()
{
    int year;
    cout << "Enter the year : ";
    cin >> year;
    return year;
}
int get_starting_day()
{
    int start_day;
    cout << "Enter the start date (0 = Sun, 1 = Mon, 2 = Tues, 3 = Wed, 4 = Thurs, 5 = Fri, 6 = Sat) : ";
    cin >> start_day;
    return start_day;
}
void print_heading(int year)
{
    cout << " YEAR -- " << year << endl; //print year at the top of the calendar
}
string read_month_name(ifstream& myfile) //using referencing to read from myfile which was opened in main
{
    string month_name;
    myfile >> month_name; //read month name from input file
    return month_name;
}
int read_num_days(ifstream& myfile) //using referencing to read from myfile which was opened in main
{
    int num_days;
    myfile >> num_days; //read num of days from input file 
    return num_days;
}
int print_month(int first_day, int num_of_days, 
    string month_name, int mon_num, yearType thisYr) //returns the LAST DAY OF THE MONTH 
{
    cout << endl << endl << month_name << endl;
    cout << setw(6) << "Sun :" << setw(6) << "Mon :" << setw(6) << "Tue :" << setw(6) << "Wed :" << setw(6) << "Thu :" << setw(6) << "Fri :" << setw(6) << "Sat :" << endl;
    int days; //keeps tracks of integers to print for days
    days = 0;
    int wk = 0;
    int day_of_week;
    day_of_week = first_day; //will keep track of which day of the week is being printed 
    int day_count;
    day_count = 0; // keeps track of the placement of the first day of each month 
    while (day_count < first_day) //if the day count is anything but 0 the number of tabs equal to the first day will be printed
    {
        cout << setw(6) << "";
        day_count++;
    }
    while (days < num_of_days) //will only print integers less than or equal to the max number of days of that month
    {
        days++;
        cout << setw(6) << days;
        thisYr.months[mon_num].dates[wk][day_of_week] = days;
        day_of_week++;
        if (day_of_week > 6) //if saturday integer is printed then the line should end the and the next integer will be printed under sunday
        {
            cout << endl;
            day_of_week = 0;
            wk++;
        }
        if (wk > 5)
        {
            wk = 0;
        }
    }
    return day_of_week;
}

*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <conio.h>
 
using namespace std;
   
class DateType
{
 
public:
    void Initialize(int newMonth, int newDay, int newYear);
    void setYear(int);
    void setMonth(int);
    void setDay(int);
    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;
private:
    int year;
    int month;
    int day;
};
 
void DateType::Initialize(int newMonth, int newDay, int newYear) {
    year = newYear;
    month = newMonth;
    day = newDay;
}
 
void DateType::setYear(int Yr)
{
    year = Yr;
}
void DateType::setMonth(int Month)
{
    month = Month;
}
void DateType::setDay(int Day)
{
    day = Day;
}
 
int DateType::GetYear() const
{
    return year;
}
int DateType::GetMonth() const
{
    return month;
}
int DateType::GetDay() const
{
    return day;
}
class monthType
{
public:
    int month_num;
    int dates[6][7];
    monthType(); // constructor
    void printMonth();
    void setMonthName(string);
    string getMonthName();
private:
    string month_name;
};
monthType::monthType()
{
    for (int row=0; row<6; row++)
    {
        for (int col=0; col<7; col++)
            dates[row][col] = 0;
    }
}
void monthType::setMonthName(string mon_name)
{
    month_name = mon_name;
}
string monthType::getMonthName()
{
    return month_name;
}
 
void monthType::printMonth()
{
    cout << endl << setw(12) << month_name << endl;
    cout << setw(6) << "Sun :" << setw(6) << "Mon :" << setw(6) << "Tue :" << setw(6) << "Wed :" << setw(6) << "Thu :" << setw(6) << "Fri :" << setw(6) << "Sat :" << endl <<endl;
    for (int row=0; row<6; row++)
    {
        for (int col=0; col<7; col++)
        {
            if (dates[row][col] == 0)
            {
                cout << setw(6) << " ";
            }
            else
            {
                cout << setw(6) << dates[row][col];
            }
        }
        cout << endl; // skip a line between weeks
    }
}
class yearType
{
public:
    monthType months[12];
    yearType(); //constructor
    void printYear()
    {
        for (int month_index=0; month_index<12; month_index++)
        {
            months[month_index].printMonth();
        }
    }
};
yearType::yearType()
{
    for (int i=0; i<12; i++)
        months[i].month_num = i;
}
class calendar
{
    public:
    void printCalendar(yearType);
};
 
int get_year();
int get_starting_day();
void print_heading(int);
string read_month_name(ifstream&);
int read_num_days(ifstream&);
int print_month(int, int, string, int); //function
yearType thisYear;
 
int main()
{
    ifstream myfile; //declare file input
    myfile.open("infile.txt"); //open file 
    int year; //define variables
    int starting_day;
    string month_name;
    int num_days;
    int month_counter;
    month_counter = 0; //used to keeps track of months for while loop
    int last_day;
    year = get_year();
    print_heading(year);//print heading for calendar
    starting_day = get_starting_day(); //calculate starting day for month of january 
    while (month_counter < 12) //loop will only run till december and then it will fail 
    {
        month_name = read_month_name(myfile); //read month name from input file using referencing 
        thisYear.months[month_counter].setMonthName(month_name); // set the month name in each month
        num_days = read_num_days(myfile); //read max num of days in selected month using referencing 
        last_day = print_month(starting_day, num_days, 
            month_name, month_counter); //the last day of the previous month 
        starting_day = last_day;
        month_counter++; //must be increased so the loop wont read past the number of months in a year 
        cout << endl;
    }
    thisYear.printYear();
    system("pause");
    return 0;
}
int get_year()
{
    /*prompt user to enter year*/
    int year;
    cout << "Enter the year : ";
    cin >> year;
    return year;
}
int get_starting_day()
{
    /*The day of the week for the first day of the year (January 1st)
    is entered by the user during the execution of the get_starting_date function*/
    int start_day;
    cout << "Enter the start date (0 = Sun, 1 = Mon, 2 = Tues, 3 = Wed, 4 = Thurs, 5 = Fri, 6 = Sat) : ";
    cin >> start_day;
    return start_day;
}
void print_heading(int year)
{
    cout << " YEAR -- " << year << endl; //print year at the top of the calendar
}
string read_month_name(ifstream& myfile) //using referencing to read from myfile which was opened in main
{
    string month_name;
    myfile >> month_name; //read month name from input file
    return month_name;
}
int read_num_days(ifstream& myfile) //using referencing to read from myfile which was opened in main
{
    int num_days;
    myfile >> num_days; //read num of days from input file 
    return num_days;
}
int print_month(int first_day, int num_of_days, 
    string month_name, int mon_num) //returns the LAST DAY OF THE MONTH 
{
    cout << endl << endl << month_name << endl;
    cout << setw(6) << "Sun :" << setw(6) << "Mon :" << setw(6) << "Tue :" << setw(6) << "Wed :" << setw(6) << "Thu :" << setw(6) << "Fri :" << setw(6) << "Sat :" << endl;
    int days; //keeps tracks of integers to print for days
    days = 0;
    int wk = 0;
    int day_of_week;
    day_of_week = first_day; //will keep track of which day of the week is being printed 
    int day_count;
    day_count = 0; // keeps track of the placement of the first day of each month 
    while (day_count < first_day) //if the day count is anything but 0 the number of tabs equal to the first day will be printed
    {
        cout << setw(6) << "";
        day_count++;
    }
    while (days < num_of_days) //will only print integers less than or equal to the max number of days of that month
    {
        days++;
        cout << setw(6) << days;
        thisYear.months[mon_num].dates[wk][day_of_week] = days;
        day_of_week++;
        if (day_of_week > 6) //if saturday integer is printed then the line should end the and the next integer will be printed under sunday
        {
            cout << endl;
            day_of_week = 0;
            wk++;
        }
        if (wk > 5)
        {
            wk = 0;
        }
    }
    return day_of_week;
}

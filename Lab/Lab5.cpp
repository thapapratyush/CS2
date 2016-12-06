/*
The lab today is to modify Assignment 5 from last semester to use what we have learned thus far in this course.  You are asked to:

(1) get the Assignment 5 program given below working

(2) add the USDollarCents class  (also given below).

(3) add the implementation code for the following two overloaded operators 

              <  less than

              == equality relation operator 

(4) get the resulting program working and paste the code and its output below.

Assignment 5 (from last semester)

A bank in your town updates its customers' accounts at the end of each month. The bank offers two types of accounts: savings and checking. Every customer must maintain a minimum balance. If a customer's balance falls below the minimum balance, there is a service charge of $10.00 for savings accounts and $25.00 for checking accounts. If the balance at the end of the month is at least the minimum balance, the account receives interest as follows:
a. Savings accounts receive 4% interest.
b. Checking accounts with balances of up to $5,000 more than the minimum balance receive 3% interest; otherwise, the interest is 5%.
Write a program that reads a customer's account number (int type), account type (char s for savings, c for checking), minimum balance that the account should maintain, and current balance. The program should then prints a report with (1) an appropriate heading and (2) that shows the account number, account type, and current balance for each customer in the file.

INPUT FILE:

46728 S 1000 2700
87324 C 1500 7689
79873 S 1000 800
89832 C 2000 3000
98322 C 1000 750
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
 
using namespace std;
 
//USDollarCents CLASS SPECIFICATION
 
class USDollarCents
{
private:
    int dollars;
    int cents;
     
    // ****** USDollarCents Normalize ******
    void normalize();
 
     
public:
    USDollarCents (int dollars = 0, int cents = 0);
    USDollarCents Length(void) const; // USDollarCents length
    void CopyUSDollarCents(USDollarCents* t) const; // copy USDollarCents 
     
    // *****Stream I/O *****
/*
A friend function is a function that is not a member of a 
class but has access to the class's private and protected 
members. Friend functions are not considered class members; 
they are normal external functions that are given special 
access privileges. Friends are not in the class's scope, and 
they are not called using the member-selection operators (. 
and ->) unless they are members of another class. A friend 
function is declared by the class that is granting 
access.*/  
    // Write USDollarCentss
    friend ostream& operator<< (ostream& ostr, const USDollarCents& s);
    // Read USDollarCentss
    friend istream& operator>> (istream& istr, USDollarCents& s);
     
    // ***** relational operator *****
     
    // USDollarCents == USDollarCents 
    int operator== ( const USDollarCents& s) const;
    // USDollarCents < USDollarCents 
    int operator< ( const USDollarCents& s) const;
    // USDollarCents > USDollarCents 
    int operator> ( const USDollarCents& s) const;
    // USDollarCents <= USDollarCents 
    int operator<= ( const USDollarCents& s) const;
    // USDollarCents >= USDollarCents 
    int operator>= ( const USDollarCents& s) const;
    // USDollarCents != USDollarCents 
    int operator!= ( const USDollarCents& s) const;
     
    // ***** USDollarCents Arithmetic operators ****
     
    // ***** USDollarCents addition *****
    USDollarCents operator+ ( const USDollarCents& s) const;
     
    // ***** USDollarCents addition equal *****
    void operator+= ( const USDollarCents& s);
     
    // ***** USDollarCents subtraction *****
    USDollarCents operator- ( const USDollarCents& s) const;
     
    // ***** USDollarCents subtraction equal *****
    void operator-= ( const USDollarCents& s);
     
    // ***** USDollarCents mutiplication *****
    USDollarCents operator* (double) const;
     
    // ***** USDollarCents mutiplication equal *****
    void operator*= (int);
     
    // ***** USDollarCents division *****
    USDollarCents operator/ (int) const;
     
    // *******  USDollarCents absolute value ***
    USDollarCents absolute() const;
         
    // ******* USDollarCents divided by 100 ***
    USDollarCents divideby100() const;
     
};
 
 
//If a customer's balance falls below the minimum balance, there is a service charge of $10.00 for savings accounts and $25.00 for checking accounts.
USDollarCents Compute_Service_Charge(char acc_type, USDollarCents min_bal, USDollarCents acc_bal) // function header
{
    if ((acc_type == 'S') && (acc_bal < min_bal)) // if condition
        return 10.00;
    else
        if ((acc_type == 'C') && (acc_bal < min_bal)) // if condition
            return 25.00;
        else // this else goes with the first if statement
            return 0;
}
 
 
//If the balance at the end of the month is at least the minimum balance, the account receives interest as follows
//a. Savings accounts receive 4% interest.
//b. Checking accounts with balances of up to $5,000 more than the minimum balance receive 3% interest; otherwise, the interest is 5%.
USDollarCents Compute_Interest(char acc_type, USDollarCents min_bal, USDollarCents acc_bal) // funciton header
{
    if ((acc_type == 'S') && (acc_bal > min_bal)) // if condition
        return acc_bal * .04; // return interest
    else
        if ((acc_type == 'C') && (acc_bal > min_bal)) // else if condition
        {
            if (acc_bal < (min_bal + 5000.00)) // nested if condition
                return acc_bal * .03; // return interest
            else
                return acc_bal * .05; // return interest
        }
        else
            return 0;
}
 
 
void Print_Line(char acc_type, int acc_num, USDollarCents acc_bal) // funciton header
{
    string account_type; // variable declaration
    if (acc_type == 'S') // if condition
        account_type = "Savings"; // variable assignment
    else
        account_type = "Checking"; // variable assignment
    cout << "************************************"<<endl; // output header
    cout << "\tBank Account Report"<<endl << endl; // output header
    cout << "Account Number:" << setw(9) <<right << acc_num << endl<<endl; // output info
    cout << "Account Type:"<< setw(12) <<right <<  account_type <<endl<<endl; // output info
    cout << "Account Balance: $" << setw(6) << right << setprecision(2)<< acc_bal << endl<<endl; // output info
}
 
 
///**********************************************************
//      CLASS USDollarCents IMPLEMENTATION 
//**********************************************************
 
USDollarCents::USDollarCents(int dd, int cc ) : dollars(dd), cents(cc)
{
    while (cents >= 100)
    { 
        cents = cents - 100;
        dollars++;
    } 
}
 
ostream& operator<< (ostream& ostr, const USDollarCents& s)
{
    ostr << "$" << s.dollars << "." << s.cents;
    return ostr;
}
 
istream& operator>> (istream& istr, USDollarCents& s)
{
    char char1;
    istr >> s.dollars >> char1 >> s.cents;
    return istr;
}
 
int USDollarCents::operator< ( const USDollarCents& s) const
{
    if (dollars < s.dollars)
        return 1;
    else
        if (dollars == s.dollars)
            if (cents < s.cents)
                return 1;
            else
                return 0;   
        else
            return 0;
}
int USDollarCents::operator> ( const USDollarCents& s) const
{
    if (dollars > s.dollars)
        return 1;
    else
        if (dollars == s.dollars)
            if (cents > s.cents)
                return 1;
            else
                return 0;   
        else
            return 0;
}
 
int USDollarCents::operator== ( const USDollarCents& s) const
{
    if (dollars == s.dollars && cents == s.cents)
        return 1;
    return 0;
}
 
USDollarCents USDollarCents::operator+ ( const USDollarCents& s) const
{
    int h = dollars + s.dollars;
    int m = cents + s.cents;
    USDollarCents D(h, m);
    D.normalize();
    return D;
}
 
void USDollarCents::operator+= ( const USDollarCents& s) 
{
    dollars += s.dollars;
    cents += s.cents;
    if (cents >= 100)
    { 
        cents = cents - 100;
        dollars++;
    }
    normalize();
}
 
 
USDollarCents USDollarCents::operator- ( const USDollarCents& s) const
{
    int h = dollars - s.dollars;
    int m = cents - s.cents;
    if (m < 0)
    {
        m = m + 100;
        h--;
    }
    USDollarCents D(h, m);
    D.normalize();
    return D;
}
 
void USDollarCents::operator-= ( const USDollarCents& s) 
{
    dollars -= s.dollars;
    cents -= s.cents;
    if (cents < 0 )
    { 
        cents = cents + 100;
        dollars--;
    } 
    normalize();
}
 
USDollarCents USDollarCents::operator* (double x) const
{
    int h = dollars * x;
    int m = cents * x;
    if (m < 0)
    {
        m = m + 100;
        h--;
    }
    USDollarCents D(h, m);
    D.normalize();
    return D;
}
 
void USDollarCents::operator*= (int x) 
{
    dollars *= x;
    cents *= x;
    while (cents >= 100)
    { 
        cents = cents - 100;
        dollars++;
    } 
    normalize();
}
 
USDollarCents USDollarCents::absolute() const
{
    int h = abs(dollars);
    int m = abs(cents);
    USDollarCents D(h, m);
    return D;   
}
 
USDollarCents USDollarCents::divideby100() const
{
    int m = cents;
    int h = dollars;
     
    m = h * 100 + m ;
    h = m / 10000;
    m = (( m / 10000.0 )  - h + .005)  * 100;
 
    USDollarCents D(h, m);
    D.normalize();
    return D;
}
 
void  USDollarCents::normalize() 
{
    if (( dollars != 0 ) && ( cents != 0 ))
    {
        if  (( dollars < 0 ) && ( cents > 0 )) 
        {
            if ( cents > 0 )
            {
                cents = cents - 100;
                dollars++;
            }
        }
         
        if (( dollars > 0 ) && ( cents < 0 ))     
        {
            if ( cents < 0)
            { 
                cents = cents + 100;
                dollars--;
            }
        }
    }
}
 
USDollarCents Compute_Service_Charge(char,USDollarCents,USDollarCents);// function prototypes
USDollarCents Compute_Interest(char, USDollarCents,USDollarCents);
void Print_Line(char, int, USDollarCents);
 
 
int main()
{
    cout << fixed << showpoint; // turns floats into decimals
    char account_type; // variable declarations
    int account_number;
    USDollarCents minimum_balance;
    USDollarCents account_balance;
    USDollarCents service_charge;
    USDollarCents interest;
    ifstream myfile;
    myfile.open("infile.txt"); // open file
    myfile >> account_number >> account_type >> minimum_balance >> account_balance; // extract input
    while (myfile) // while loop condition
    {
        service_charge = Compute_Service_Charge(account_type, minimum_balance, account_balance); // service charge calculation
        interest = Compute_Interest(account_type, minimum_balance, account_balance); // interest calculation
        account_balance -= service_charge; // subtraction of service charge
        account_balance += interest; // addition of interest
        Print_Line(account_type, account_number, account_balance); // print report line
        myfile >> account_number >> account_type >> minimum_balance >> account_balance; // extract input
    }
    myfile.close(); // close file
    return 0;
}
 
/*
 
************************************
        Bank Account Report
 
Account Number:    46728
 
Account Type:     Savings
 
Account Balance: $     $2808.0
 
************************************
        Bank Account Report
 
Account Number:    87324
 
Account Type:    Checking
 
Account Balance: $     $8073.0
 
************************************
        Bank Account Report
 
Account Number:    79873
 
Account Type:     Savings
 
Account Balance: $     $790.0
 
************************************
        Bank Account Report
 
Account Number:    89832
 
Account Type:    Checking
 
Account Balance: $     $3090.0
 
************************************
        Bank Account Report
 
Account Number:    98322
 
Account Type:    Checking
 
Account Balance: $     $725.0
 
Press any key to continue . . .
 
 
 
*/

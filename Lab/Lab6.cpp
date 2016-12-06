/*
This lab builds on the following labs and quizes:

Lab 3 - PersonType (Base class) and MembershipType

Lab 4  - yearType, monthType and DateType

Lab 5 - USDollarCents

Now, for Lab 6 you are to revise Lab 3 to work exactly as it did before with the following changes:

(1) Use a linked-list to store the membershipTypes instead of an array

(2) Add the following two data members to the membershipType class 

       A) yearType memberCalendar;

       B) USDollarCents memberAccount;

These data members do not have to get data from the file nor do they have to be printed.  We will handle these and other features in the next lab.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <iomanip>
 
using namespace std;
 
//implementation file
class addressType {
public:
    string streetAddressNum;
    string streetAddress;
    string streetAdType;
    string streetDec;
    string state;
    string stateInitials;
    string zipCode;
};
class personType {
public:
    personType(); //constructor
    string lastName;
    string firstName;
    int personNum;
    int personID;
    char gender;
    addressType address;
    /********MEMBER FUNCTIONS********/
    string getInterest1();
    string getInterest2();
    void setInterest1(string);
    void setInterest2(string);
    void print();
private:
    string interest1;
    string interest2;
};
 
class DateType {
 
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
 
void DateType::setYear(int Yr) {
    year = Yr;
}
void DateType::setMonth(int Month) {
    month = Month;
}
void DateType::setDay(int Day) {
    day = Day;
}
 
int DateType::GetYear() const {
    return year;
}
int DateType::GetMonth() const {
    return month;
}
int DateType::GetDay() const {
    return day;
}
class monthType {
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
monthType::monthType() {
    for (int row = 0; row<6; row++)
    {
        for (int col = 0; col<7; col++)
            dates[row][col] = 0;
    }
}
void monthType::setMonthName(string mon_name) {
    month_name = mon_name;
}
string monthType::getMonthName() {
    return month_name;
}
 
void monthType::printMonth() {
    cout << endl << setw(12) << month_name << endl << endl;
    for (int row = 0; row<6; row++)
    {
        for (int col = 0; col<7; col++)
        {
            cout << setw(6) << dates[row][col];
 
        }
        cout << endl; // skip a line between weeks
    }
}
class yearType {
public:
    monthType months[12];
    yearType(); //constructor
    void printYear()
    {
        for (int month_index = 0; month_index<12; month_index++)
        {
            months[month_index].printMonth();
        }
    }
};
yearType::yearType() {
    for (int i = 0; i<12; i++)
        months[i].month_num = i;
}
class calendar {
public:
    void printCalendar(yearType);
};
 
class USDollarCents {
private:
    int dollars;
    int cents;
 
    // ****** USDollarCents Normalize ******
    void normalize();
 
 
public:
    USDollarCents(int dollars = 0, int cents = 0);
    USDollarCents Length(void) const; // USDollarCents length
    void CopyUSDollarCents(USDollarCents* t) const; // copy USDollarCents
                                                    // Write USDollarCentss
    friend ostream& operator<< (ostream& ostr, const USDollarCents& s);
    // Read USDollarCentss
    friend istream& operator>>(istream& istr, USDollarCents& s);
 
    // USDollarCents == USDollarCents
    int operator== (const USDollarCents& s) const;
    // USDollarCents < USDollarCents
    int operator< (const USDollarCents& s) const;
    // USDollarCents > USDollarCents
    int operator> (const USDollarCents& s) const;
    // USDollarCents <= USDollarCents
    int operator<= (const USDollarCents& s) const;
    // USDollarCents >= USDollarCents
    int operator>= (const USDollarCents& s) const;
    // USDollarCents != USDollarCents
    int operator!= (const USDollarCents& s) const;
 
    // ***** USDollarCents Arithmetic operators ****
 
    // ***** USDollarCents addition *****
    USDollarCents operator+ (const USDollarCents& s) const;
 
    // ***** USDollarCents addition equal *****
    void operator+= (const USDollarCents& s);
 
    // ***** USDollarCents subtraction *****
    USDollarCents operator- (const USDollarCents& s) const;
 
    // ***** USDollarCents subtraction equal *****
    void operator-= (const USDollarCents& s);
 
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
 
///**********************************************************
//      CLASS USDollarCents IMPLEMENTATION
//**********************************************************
 
USDollarCents::USDollarCents(int dd, int cc) : dollars(dd), cents(cc) {
    while (cents >= 100)
    {
        cents = cents - 100;
        dollars++;
    }
}
 
ostream& operator<< (ostream& ostr, const USDollarCents& s) {
    ostr << "$" << s.dollars << "." << s.cents;
    return ostr;
}
 
istream& operator>>(istream& istr, USDollarCents& s) {
    char char1;
    istr >> s.dollars >> char1 >> s.cents;
    return istr;
}
 
int USDollarCents::operator< (const USDollarCents& s) const {
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
 
int USDollarCents::operator> (const USDollarCents& s) const {
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
 
int USDollarCents::operator== (const USDollarCents& s) const {
    /******YOUR CODE GOES HERE *******/
    if ((dollars == s.dollars) && (cents == s.cents)) {
        return 1;
    }
    return 0;
}
 
USDollarCents USDollarCents::operator+ (const USDollarCents& s) const {
    int h = dollars + s.dollars;
    int m = cents + s.cents;
    USDollarCents D(h, m);
    D.normalize();
    return D;
}
 
void USDollarCents::operator+= (const USDollarCents& s) {
    dollars += s.dollars;
    cents += s.cents;
    if (cents >= 100)
    {
        cents = cents - 100;
        dollars++;
    }
    normalize();
}
 
 
USDollarCents USDollarCents::operator- (const USDollarCents& s) const {
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
 
void USDollarCents::operator-= (const USDollarCents& s) {
    dollars -= s.dollars;
    cents -= s.cents;
    if (cents < 0)
    {
        cents = cents + 100;
        dollars--;
    }
    normalize();
}
 
USDollarCents USDollarCents::operator* (double x) const {
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
 
void USDollarCents::operator*= (int x) {
    dollars *= x;
    cents *= x;
    while (cents >= 100)
    {
        cents = cents - 100;
        dollars++;
    }
    normalize();
}
 
USDollarCents USDollarCents::absolute() const {
    int h = abs(dollars);
    int m = abs(cents);
    USDollarCents D(h, m);
    return D;
}
 
USDollarCents USDollarCents::divideby100() const {
    int m = cents;
    int h = dollars;
 
    m = h * 100 + m;
    h = m / 10000;
    m = ((m / 10000.0) - h + .005) * 100;
 
    USDollarCents D(h, m);
    D.normalize();
    return D;
}
 
void  USDollarCents::normalize() {
    if ((dollars != 0) && (cents != 0))
    {
        if ((dollars < 0) && (cents > 0))
        {
            if (cents > 0)
            {
                cents = cents - 100;
                dollars++;
            }
        }
 
        if ((dollars > 0) && (cents < 0))
        {
            if (cents < 0)
            {
                cents = cents + 100;
                dollars--;
            }
        }
    }
}
 
class membershipType :public personType {
public:
    char membership_type;
    char membership_status;
    yearType memberCalendar;
    USDollarCents memberAccount;
    membershipType();  // 1st constructor
    membershipType(char, char);  // 2nd constructor
    void print_member_type();
};
 
 
//specification file
personType::personType() {
    firstName = "";
    lastName = "";
    personNum = 0;
    personID = 0;
    gender = ' ';
    this->address.streetAddressNum = "";
    this->address.streetAddress = "";
    this->address.streetAdType = "";
    this->address.state = "";
    this->address.zipCode = "";
    this->address.streetDec = "";
}
 
membershipType::membershipType() {
    membership_type = ' ';
    membership_status = ' ';
}
 
membershipType::membershipType(char mType, char mStatus) {
    membership_type = mType;
    membership_status = mStatus;
}
 
 
void personType::setInterest1(string i1) {
    interest1 = i1;
}
void personType::setInterest2(string i2) {
    interest2 = i2;
}
string personType::getInterest1() {
    return interest1;
}
string personType::getInterest2() {
    return interest2;
}
 
void personType::print() {
    cout << lastName << firstName << "\t\t" << personNum << "\t" << personID << "\t" << address.streetAddressNum << "\t" << address.streetAddress << "\t" << address.streetAdType << "\t" << address.streetDec << "\t" << address.state << "\t" << address.zipCode << "\t" << gender << "\t" << getInterest1() << "\t" << getInterest2() << " ";
}
 
void membershipType::print_member_type() {
    print();
    cout << membership_type << " " << membership_status << endl;
}
 
struct nodeType {
    membershipType members;
    nodeType* next;
};
 
//Driver file
int main() {
    membershipType members;
    string int1, int2;
    ifstream file;
    file.open("infile.txt");
    nodeType* firstPtr;
    nodeType* current;
    firstPtr = new nodeType;
    file >> firstPtr->members.lastName;
    file >> firstPtr->members.firstName;
    file >> firstPtr->members.personNum;
    file >> firstPtr->members.personID;
    file >> firstPtr->members.address.streetAddressNum;
    file >> firstPtr->members.address.streetAddress;
    file >> firstPtr->members.address.streetAdType;
    file >> firstPtr->members.address.streetDec;
    file >> firstPtr->members.address.state;
    file >> firstPtr->members.address.zipCode;
    file >> firstPtr->members.gender;
    file >> int1 >> int2;
    firstPtr->members.setInterest1(int1);
    firstPtr->members.setInterest2(int2);
    file >> firstPtr->members.membership_type;
    file >> firstPtr->members.membership_status;
    firstPtr->members.print_member_type();
    firstPtr->next = NULL;
    current = firstPtr;
    for (int i = 0; i < 5; i++)
    {
        file >> current->members.lastName;
        file >> current->members.firstName;
        file >> current->members.personNum;
        file >> current->members.personID;
        file >> current->members.address.streetAddressNum;
        file >> current->members.address.streetAddress;
        file >> current->members.address.streetAdType;
        file >> current->members.address.streetDec;
        file >> current->members.address.state;
        file >> current->members.address.zipCode;
        file >> current->members.gender;
        file >> int1 >> int2;
        current->members.setInterest1(int1);
        current->members.setInterest2(int2);
        file >> current->members.membership_type;
        file >> current->members.membership_status;
        current->members.print_member_type();
        current->next = new nodeType;
        current = current->next;
    }
    current->next = NULL;
    file.close();
}
 
/*
Herold,Jill    1  2234  123  Main  St.  Washington,  DC  20019  F  yoga  facebook 1 2
Jackson,Stan    2  3748  12  Douglas  Ave.  Baltimore,  MD  30229  M  sports  movies 2 4
Jerry,Francis    3  6666  2345  6th  Street  Woodbridge,  VA  44040  M  movies  roadtrips 1 1
Joan,Wilson    4  1234  12  Georgia  Ave.  Washington,  DC  20019  F  romance  dining 2 3
Smith,Stanley    5  3456  56  D  Street  Baltimore,  MD  30229  M  movies  dining 2 1
Claire,Claude    6  2311  66  32nd  Street  Woodbridge,  VA  44040  F  cooking  facebook 1 1
Program ended with exit code: 0
*/

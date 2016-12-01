#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <vector>
 
template <typename T, typename StackVector = std::vector<T> >
 
class StackType
{
public:
    StackType(int);
    void MakeEmpty();      
    bool IsEmpty() const;
    bool IsFull() const;
    void Push (T const&) ;
    int Size() const;      
    void Pop();
    T Top() const;
private:
    int top;
    int size;
    StackVector datingData;
};
 
 
 
class StackTypeException: public std::logic_error {
public:
    StackTypeException(const std::string& message = "Stack Error")
        :logic_error(message.c_str())
        {}
};
 
template <typename T, typename vector>
StackType<T, vector>::StackType(int s){
    datingData.resize(s);
    size = s;
    top = -1;
}
 
template <typename T, typename vector>
bool StackType<T, vector>::IsEmpty() const{
    return (top==-1);
}
 
template <typename T, typename vector>
bool StackType<T, vector>::IsFull() const{
    return (top == size-1);
}
 
template <typename T, typename vector>
void StackType<T, vector>::MakeEmpty(){
    datingData.resize(0);
    size=0;
    top=-1;
}
 
template <typename T, typename vector>
void StackType<T, vector>::Pop(){
    if (IsEmpty()){
        throw StackTypeException("Stack is Empty");
    }
    else{
        top--;
    }
}
 
template <typename T, typename vector>
void StackType<T, vector>::Push(T const& newDatingData){
    if (IsFull()){
        throw StackTypeException("Stack is Full, can't Push");
    }
    else{
        top+=1;
        datingData[top]=newDatingData;
    }
}
 
template <typename T, typename vector>
T StackType<T, vector>::Top() const{
    if (IsEmpty()){
        throw StackTypeException("Stack is Empty");
    }
    else{
        return datingData[top];
    }
}
 
template <typename T, typename vector>
int StackType<T, vector>::Size() const{
    return(size);
}
 
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
public:
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
   
    void print();
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
    int h = dollars;
    int m = cents;
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
  
void USDollarCents::print(){
    cout << " $" << dollars <<"." << cents << endl;
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
    bool operator<(const membershipType &rhs) const
    {
      return personID < rhs.personID;
    }
}; 
   
//specification file
personType::personType() {
    firstName = "";
    lastName = "";
    personNum = 0;
    personID = 0;
    gender = ' ';
    address.streetAddressNum = "";
    address.streetAddress = "";
    address.streetAdType = "";
    address.state = "";
    address.zipCode = "";
    address.streetDec = "";
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
    cout << lastName << firstName << "\t\t" << personNum << "\t" << personID << "\t" << address.streetAddressNum << "\t" << address.streetAddress << "\t" << address.streetAdType << "\t" << address.streetDec << "\t" << address.state << "\t" << address.zipCode << "\t\t" << gender << "\t" << getInterest1() << "\t" << getInterest2() << " ";
}
   
void membershipType::print_member_type() {
    print();
    cout << membership_type << " " << membership_status;
    memberAccount.print();
}
   
//Driver file
int main() {
    StackType <membershipType> MemberStack(6);
    membershipType temp;
    string int1, int2;
    ifstream file;
    file.open("infile.txt");
    int tempDollar, tempCents;
    for (int i=0; i<6;i++){
        file >> temp.lastName;
        file >> temp.firstName;
        file >> temp.personNum;
        file >> temp.personID;
        file >> temp.address.streetAddressNum;
        file >> temp.address.streetAddress;
        file >> temp.address.streetAdType;
        file >> temp.address.streetDec;
        file >> temp.address.state;
        file >> temp.address.zipCode;
        file >> temp.gender;
        file >> int1 >> int2;
        temp.setInterest1(int1);
        temp.setInterest2(int2);
        file >> temp.membership_type;
        file >> temp.membership_status;
        file >> tempDollar;
        file >> tempCents;
        temp.memberAccount = USDollarCents(tempDollar, tempCents);
        MemberStack.Push(temp);
    }
 
    for(int i=0;i<MemberStack.Size();i++){
        MemberStack.Top().print_member_type();
        MemberStack.Pop();
    }
    file.close();
}
   
/*
Claire,Claude       6   2311    66  32nd    Street  Woodbridge, VA  44040       F   cooking facebook 1 1 $332.99
Smith,Stanley       5   3456    56  D   Street  Baltimore,  MD  30229       M   movies  dining 2 1 $876.25
Joan,Wilson     4   1234    12  Georgia Ave.    Washington, DC  20019       F   romance dining 2 3 $190.10
Jerry,Francis       3   6666    2345    6th Street  Woodbridge, VA  44040       M   movies  roadtrips 1 1 $611.33
Jackson,Stan        2   3748    12  Douglas Ave.    Baltimore,  MD  30229       M   sports  movies 2 4 $200.0
Herold,Jill     1   2234    123 Main    St. Washington, DC  20019       F   yoga    facebook 1 2 $231.12
 
 
  
*/
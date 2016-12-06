/*
Lab 9 - Introduction to Recursion
 

Recursion is the process of defining a problem (or the solution to a problem) in terms of (a simpler version of) itself.

For example, we can define the operation "find your way home" as:

          If you are at home, stop moving.

          Take one step toward home.

          "find your way home".

Here the solution to finding your way home is two steps (three steps). First, we don't go home if we are already home. 

Simply put, recursion is when a function calls itself. That is, in the course of the function definition there is a call to that very same function. At first this may seem like a never ending loop, or like a dog chasing its tail. It can never catch it. So too it seems our function will never finish. This might be true is some cases, but in practice we can check to see if a certain condition is true and in that case exit (return from) our function. The case in which we end our recursion is called a base case . Additionally, just as in a loop, we must change some value and incremently advance closer to our base case.

Consider this function. 

void myFunction( int counter)
{
     if(counter == 0)           //Base Case
       return;
     else
     {
       cout <<counter<<endl;
       myFunction(--counter);   //General Case
       return;
     }
}
This recursion is not infinite, assuming the function is passed a positive integer value. If this function was called with the integer 6 as a parameter, what will the output be? 
Consider this function:


void myFunction( int counter)
{
     if(counter == 0)    //Base Case
       return;
     else
     {
       cout<<counter<<endl;
       myFunction(--counter);   //General Case
       cout<<counter<<endl;
       return;
     }
}
If the function is called with the value 4, what will the output be? 


4 3 2 1 0
Score:  
3
 of 3 points.
The correct answer was:
43210
Comment: 
 
The above recursion is essentially a loop like a for loop or a while loop. When do we prefer recursion to an iterative loop? We use recursion when we can see that our problem can be reduced to a simpler problem that can be solved after further reduction.

Every recursion should have the following characteristics.

A simple base case which we have a solution for and a return value. Sometimes there are more than one base cases.
A way of getting our problem closer to the base case. I.e. a way to chop out part of the problem to get a somewhat simpler problem.
A recursive call which passes the simpler problem back into the function.
The key to thinking recursively is to see the solution to the problem as a smaller version of the same problem. The key to solving recursive programming requirements is to imagine that your function does what its name says it does even before you have actually finish writing it. You must pretend the function does its job and then use it to solve the more complex cases. Here is how.

Identify the base case(s) and what the base case(s) do. A base case is the simplest possible problem (or case) your function could be passed. Return the correct value for the base case. Your recursive function will then be comprised of an if-else statement where the base case returns one value and the non-base case(s) recursively call(s) the same function with a smaller parameter or set of data. Thus you decompose your problem into two parts: (1) The simplest possible case which you can answer (and return for), and (2) all other more complex cases which you will solve by returning the result of a second calling of your function. This second calling of your function ( recursion ) will pass on the complex problem but reduced by one increment. This decomposition of the problem will actually be a complete, accurate solution for the problem for all cases other than the base case. Thus, the code of the function actually has the solution on the first recursion.

Let's consider writing a function to find the factorial of an integer. For example 7! equals 7*6*5*4*3*2*1 . 
But we are also correct if we say 7! equals 7*6!.
In seeing the factorial of 7 in this second way we have gained a valuable insight. We now can see our problem in terms of a simpler version of our problem and we even know how to make our problem progressively more simple. We have also defined our problem in terms of itself. I.e. we defined 7! in terms of 6!. This is the essence of recursive problem solving. Now all we have left to do is decide what the base case is. What is the simplest factorial? 1!. 1! equals 1.

Let's write the factorial function recursively.

int myFactorial( int integer)
{
if( integer == 1)  //Base Case
     return 1;
else
       {
       return (integer * (myFactorial(integer-1)));  //General Case
       }
}
Note that the base case ( the factorial of 1 ) is solved and the return value is given. Now let us imagine that our function actually works. If it works we can use it to give the result of more complex cases. If our number is 7 we will simply return 7 * the result of factorial of 6. So we actaully have the exact answer for all cases in the top level recursion. Our problem is getting smaller on each recursive call because each time we call the function we give it a smaller number. Try running this program in your head with the number 2. Does it give the right value? If it works for 1 then it must work for two since 2 merely returns 2 * factorial of 1. Now will it work for 3? Well, 3 must return 3 * factorial of 2. Now since we know that factorial of 2 works, factorial of 3 also works. We can prove that 4 works in the same way, and so on and so on. 

Note: make it your habit of writing the base case in the function as the first statement.

Note: Forgetting the base case leads to infinite recursion. 


However, in fact, your code won't run forever like an infinite loop, instead, you will eventually run out of stack space (memory) and get a run-time error or exception called a stack overflow. 



PROBLEM
 

You are asked in this lab to rewrite the print function that used in the last assignment to print the linked-list implementation of a queueType.  Most students used a loop and the dequeue method to print the members data.  Instead, write a print function that calls itself. 
*/

#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <iostream>
#include <stdexcept>
 
using namespace std;
 
template <typename T>
struct Node {
    T info;
    Node<T>* next;
};
 
 
template <typename T>
class MyQueue
{
public:
    MyQueue(int );
    bool isFull() const;
    bool isEmpty() const;
    void Enqueue(T const&);
    int Size() const;
    void makeEmpty();
    Node<T>* getFirstPointer();
    T Dequeue();
private:
    int size;
    int current;
    Node<T>* start;
    Node<T>* end;
};
 
 
 
class QueueException: public std::logic_error {
public:
    QueueException(const std::string& message = "Queue")
    :logic_error(message.c_str())
    {}
};
 
template <typename T>
Node<T>* MyQueue<T>::getFirstPointer() {
    return (start);
}
 
template <typename T>
MyQueue<T>::MyQueue(int s){
    size = s;
    current = 0;
    Node<T>* start;
    Node<T>* end;
    end = NULL;
    start = NULL;
}
 
template <typename T>
bool MyQueue<T>::isFull() const {
    return (size == current);
}
 
template <typename T>
bool MyQueue<T>::isEmpty() const {
    return (current == 0);
}
 
template <typename T>
void MyQueue<T>::makeEmpty(){
    start = NULL;
    end = NULL;
    current = 0;
}
 
template <typename T>
int MyQueue<T>::Size() const {
    return current;
}
 
template <typename T>
void MyQueue<T>::Enqueue(T const& newItem){
    if (isFull()){
        throw QueueException("The Queue is Full");
    };
    current++;
    Node<T>* temp = new Node<T>;
    temp->info = newItem;
    temp->next = NULL;
    if (start == NULL){
        start = temp;
    } else {
        end->next = temp;
    }
    end = temp;
};
 
template <typename T>
T MyQueue<T>::Dequeue() {
    if (isEmpty()){
        throw QueueException("The queue is empty");
    } else {
        Node<T>* front;
        front = start;
        T dequeuedItem;
        dequeuedItem = front->info;
        start = start->next;
        delete front;
        current--;
        return dequeuedItem;
    }
}
 
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
        cout << endl;
    }
}
class yearType
{
public:
    monthType months[12];
    yearType();
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
    /******YOUR CODE GOES HERE *******/
    if (dollars == s.dollars && cents == s.cents)
        return 1;
    else
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
 
 
//Class declaration and the prototypes
class addressType
{
public:
    string streetAddressNum;
    string streetAddress;
    string streetDec;
    string city;
    string stateInitials;
    string zipCode;
};
 
//Class personType and the prototypes
class personType
{
public:
    personType(); //constructor
    string endName;
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
 
//personType
personType::personType()
{
    firstName ="";
    endName = "";
    personNum =0;
    personID = 0;
    gender = ' ';
    this->address.streetAddressNum = "";
    this->address.streetAddress = "";
    this->address.city = "";
    this->address.zipCode="";
    this->address.streetDec="";
}
 
string personType::getInterest1()
{
    return interest1;
}
 
string personType::getInterest2()
{
    return interest2;
}
 
//Setter functions
void personType::setInterest1(string in1)
{
    interest1 = in1;
}
 
void personType::setInterest2(string in2)
{
    interest2 = in2;
}
 
//Print functions
void personType::print()
{
    cout << endName << " " << firstName << "\t"
    << getInterest1() << "\t" << getInterest2() << gender << endl;
}
 
class membershipType:public personType
{
public:
    char membership_type;
    char membership_status;
    yearType memberCalendar;
    USDollarCents memberAccount;
    membershipType();
    membershipType(char,char);
    void print_member_type();
};
 
membershipType::membershipType()
{
    membership_type = ' ';
    membership_status = ' ';
}
 
 
membershipType::membershipType(char member_type, char member_status)
{
    membership_type = member_type;
    membership_status = member_status;
}
 
void membershipType::print_member_type()
{
    cout << endName << " " << firstName << "\t\t" << gender << "\t" << address.city << " " << address.zipCode <<  "\t"
    << getInterest1() << "\t" << getInterest2()
    << "\t\t\t\t\t" << membership_type << "\t\t" << membership_status << "\t"
    << endl;
}
 
 
struct nodeType
{
    membershipType info;
    nodeType* next;
};
 
void printQueue(MyQueue<membershipType> &datingQueue){
    if (datingQueue.getFirstPointer() == NULL){
        return;
    } else {
        datingQueue.Dequeue().print_member_type();
        printQueue(datingQueue);
    }
};
 
int main(){
    string int1, int2;
    int dollars, cents;
    ifstream file;
    file.open("infile.txt");
    membershipType instance;
    MyQueue <membershipType> datingQueue(6);
    for (int i = 0; i < 6; i++){
        file >> instance.endName;
        file >> instance.firstName;
        file >> instance.personNum;
        file >> instance.personID;
        file >> instance.address.streetAddressNum;
        file >> instance.address.streetAddress;
        file >> instance.address.streetDec;
        file >> instance.address.city;
        file >> instance.address.stateInitials;
        file >> instance.address.zipCode;
        file >> instance.gender;
        file >> int1 >> int2;
        file >> instance.membership_type;
        file >> instance.membership_status;
        instance.setInterest1(int1);
        instance.setInterest2(int2);
        file >> dollars;
        file >> cents;
        instance.memberAccount = USDollarCents(dollars, cents);
        datingQueue.Enqueue(instance);
    }
    file.close();
    printQueue(datingQueue);
    return 0;
}
/*
 Herold, Jill       F   Washington, 20019   yoga    facebook                    1       2
 Jackson, Stan      M   Baltimore, 30229    sports  movies                  2       4
 Jerry, Francis     M   Woodbridge, 44040   movies  roadtrips                   1       1
 Joan, Wilson       F   Washington, 20019   romance dining                  2       3
 Smith, Stanley     M   Baltimore, 30229    movies  dining                  2       1
 Claire, Claude     F   Woodbridge, 44040   cooking facebook                    1       1   
 */

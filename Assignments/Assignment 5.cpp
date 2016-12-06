/*
CIRCULAR LINKED-LISTS
A circular linked-list is a list in which every node has a successor: the "last" element is succeeded by the "first" element.



We can create a circular linked-list by making the pointer in the next member of the last node point back to the first node instead of containing NULL.

We can start at any node in the list and traverse the entire list.  If we let an external pointer listData point to the last item in the last node rather than the first, we have direct access to both the first and the last nodes in the list.



With a circular linked-list we can implement a queType that needs only one data member (rather than two) that points to the rear of the queue.

Rewrite the program you wrote for Assignment 4 using a circular linked-list impementation.  The output should be the same.*/

#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <stdexcept>
  
template <typename T>
struct Node {
    T info;
    Node<T>* next;
};
  
template <typename T>
class QueueType
{
public:
    QueueType(int);
    void MakeEmpty();      
    bool IsEmpty() const;
    int Size() const; 
    void Enqueue (T const&);
    T Dequeue();
    bool IsFull() const;
private:
    int maxSize;
    int currentSize;
    Node<T>* root;
};
  
  
  
class QueueTypeException: public std::logic_error 
{
public:
    QueueTypeException(const std::string& message = "QueueType Error")
        :logic_error(message.c_str())
        {}
};
  
template <typename T>
QueueType<T>::QueueType(int s)
{
    maxSize=s;
    currentSize=0;
    root=NULL;
}
  
template <typename T>
bool QueueType<T>::IsEmpty() const
{
    return (currentSize==0);
}
  
template <typename T>
bool QueueType<T>::IsFull() const
{
    return (maxSize==currentSize);
}
  
template <typename T>
void QueueType<T>::MakeEmpty()
{
    Node<T>* current = root;
      
    while (current != NULL) {
        root = root->next;
        delete current;
        current = root;
    }
    root  = NULL;
}
  
template <typename T>
void QueueType<T>::Enqueue(T const& newItem)
{
    if (IsFull()){
        throw QueueTypeException("Queue Full");
    }
    else{
        Node<T>* temp = new Node<T>;
        currentSize++;
        temp->info=newItem;
        temp->next=root;
        if(root==NULL){
            root = temp;
            root->next=root;
        }
        else{
            Node<T>* firstNode;
            firstNode = root->next;
            root->next = temp;
            temp->next = firstNode;
            root = temp;
        }
    }
}
  
template <typename T>
T QueueType<T>::Dequeue()
{
    if (IsEmpty()){
        throw QueueTypeException("Queue Empty");
    }
    else{
        Node<T>* firstNode;
        firstNode = root->next;
        T returnVal;
        returnVal = firstNode->info;
        root->next = root->next->next;
        currentSize--;
        delete firstNode;
        return returnVal;
    }
}
  
template <typename T>
int QueueType<T>::Size() const
{
    return(currentSize);
}
  
using namespace std;
    
//implementation file
class addressType 
{
public:
    string streetAddressNum;
    string streetAddress;
    string streetAdType;
    string streetDec;
    string state;
    string stateInitials;
    string zipCode;
};
class personType 
{
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
    
void DateType::Initialize(int newMonth, int newDay, int newYear) 
{
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
    for (int row = 0; row<6; row++)
    {
        for (int col = 0; col<7; col++)
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
    for (int row = 0; row<6; row++)
    {
        for (int col = 0; col<7; col++)
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
    
USDollarCents::USDollarCents(int dd, int cc) : dollars(dd), cents(cc) 
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
    
istream& operator>>(istream& istr, USDollarCents& s) 
{
    char char1;
    istr >> s.dollars >> char1 >> s.cents;
    return istr;
}
    
int USDollarCents::operator< (const USDollarCents& s) const
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
    
int USDollarCents::operator> (const USDollarCents& s) const
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
    
int USDollarCents::operator== (const USDollarCents& s) const
{
  
    if ((dollars == s.dollars) && (cents == s.cents)) {
        return 1;
    }
    return 0;
}
    
USDollarCents USDollarCents::operator+ (const USDollarCents& s) const
{
    int h = dollars + s.dollars;
    int m = cents + s.cents;
    USDollarCents D(h, m);
    D.normalize();
    return D;
}
    
void USDollarCents::operator+= (const USDollarCents& s) 
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
    
    
USDollarCents USDollarCents::operator- (const USDollarCents& s) const
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
    
void USDollarCents::operator-= (const USDollarCents& s) 
{
    dollars -= s.dollars;
    cents -= s.cents;
    if (cents < 0)
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
    int h = dollars;
    int m = cents;
    USDollarCents D(h, m);
    return D;
}
    
USDollarCents USDollarCents::divideby100() const
{
    int m = cents;
    int h = dollars;
    
    m = h * 100 + m;
    h = m / 10000;
    m = ((m / 10000.0) - h + .005) * 100;
    
    USDollarCents D(h, m);
    D.normalize();
    return D;
}
    
void  USDollarCents::normalize() 
{
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
   
void USDollarCents::print()
{
    cout << " $" << dollars <<"." << cents << endl;
}
  
class membershipType :public personType 
{
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
personType::personType() 
{
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
    
membershipType::membershipType() 
{
    membership_type = ' ';
    membership_status = ' ';
}
    
membershipType::membershipType(char mType, char mStatus) 
{
    membership_type = mType;
    membership_status = mStatus;
}
    
    
void personType::setInterest1(string i1) 
{
    interest1 = i1;
}
void personType::setInterest2(string i2) 
{
    interest2 = i2;
}
string personType::getInterest1() 
{
    return interest1;
}
string personType::getInterest2() 
{
    return interest2;
}
    
void personType::print() 
{
    cout << lastName << firstName << "\t\t" << personNum << "\t" << personID << "\t" << address.streetAddressNum << "\t" << address.streetAddress << "\t" << address.streetAdType << "\t" << address.streetDec << "\t" << address.state << "\t" << address.zipCode << "\t\t" << gender << "\t" << getInterest1() << "\t" << getInterest2() << " ";
}
    
void membershipType::print_member_type() 
{
    print();
    cout << membership_type << " " << membership_status;
    memberAccount.print();
}
    
//Driver file
int main() 
{
    QueueType <membershipType> datingQueue(7);
    membershipType tempObj;
    string int1, int2;
    ifstream myfile;
    myfile.open("infile.txt");
    int tempDollar, tempCents;
    for (int i=0; i<6;i++){
        myfile >> tempObj.lastName;
        myfile >> tempObj.firstName;
        myfile >> tempObj.personNum;
        myfile >> tempObj.personID;
        myfile >> tempObj.address.streetAddressNum;
        myfile >> tempObj.address.streetAddress;
        myfile >> tempObj.address.streetAdType;
        myfile >> tempObj.address.streetDec;
        myfile >> tempObj.address.state;
        myfile >> tempObj.address.zipCode;
        myfile >> tempObj.gender;
        myfile >> int1 >> int2;
        tempObj.setInterest1(int1);
        tempObj.setInterest2(int2);
        myfile >> tempObj.membership_type;
        myfile >> tempObj.membership_status;
        myfile >> tempDollar;
        myfile >> tempCents;
        tempObj.memberAccount = USDollarCents(tempDollar, tempCents);
        datingQueue.Enqueue(tempObj);
    }
  
    for(int i=0;i<datingQueue.Size();){
        datingQueue.Dequeue().print_member_type();
    }
    myfile.close();
}
    
/*
Herold,Jill     1   2234    123 Main    St. Washington, DC  20019       F   yoga    facebook 1 2 $231.12
Jackson,Stan        2   3748    12  Douglas Ave.    Baltimore,  MD  30229       M   sports  movies 2 4 $200.0
Jerry,Francis       3   6666    2345    6th Street  Woodbridge, VA  44040       M   movies  roadtrips 1 1 $611.33
Joan,Wilson     4   1234    12  Georgia Ave.    Washington, DC  20019       F   romance dining 2 3 $190.10
Smith,Stanley       5   3456    56  D   Street  Baltimore,  MD  30229       M   movies  dining 2 1 $876.25
Claire,Claude       6   2311    66  32nd    Street  Woodbridge, VA  44040       F   cooking facebook 1 1 $332.99
*/

/*
DOUBLY LINKED-LISTS
A doubly linked-list is a list in which every node is linked both to its successor and its predecessor. In a doubly linked-list, the node are linked in both directions.  Each node of a doubly linked-list contains three parts: previous, info and next.



As noted previously, we can use circular linked-lists to reach any node in the list from any starting point.  Although the structure offers advantages over a simple linear linked list, it remains too limited for certain types of applications.  Suppose we want to delete a particular node in a list, given only a pointer to that node (current).  This task involves changing the next member of the node preceding node. As we have seen, given only a current pointer we cannot access its predecessor in the list.

Another task that is difficult to preform on a linear linked-list is traversing the list in reverse.  For instance, suppose we have a list of student records, sorted in grade point (GPA) from lowest to highest.  The Dean might want a printout of the students' records, sorted from highest to lowest, to use in preparing the Dean's List.  In such a case, where we need to access the node that precedes a given node, a doubly linked-list is useful.  

Write a program that reads the file below and stores its contents in a doubly-linked list.

Write two print functions. One to print the list in ascending order and another print function to print the list in descending order.  Print the list in both orders.  Label your output.

Use the file below.  Name it "infile.txt".
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
 
using namespace std;
 
struct studentType{
    string lastName;
    string firstName;
    float gpa;
};
 
struct Node{
    studentType data;
    Node* previous;
    Node* next;
};
 
class doublyLL{
public:
    void insert(studentType);
    void printDescending();
    void printAscending();
    doublyLL();
private:
    Node* firstptr;
    void insert(Node*&, studentType);
    void printAscending(Node*);
    void printDescending(Node*);
};
 
doublyLL::doublyLL(){
    firstptr = NULL;
}
 
void doublyLL::insert(Node*& firstptr, studentType info){
    Node* temp = new Node;
    temp->data = info;
    temp->previous = NULL;
    temp->next = NULL;
    if (firstptr == NULL){
        firstptr = temp;
    }
    else
    {
        Node* current;
        current = firstptr;
        if (temp->data.gpa<firstptr->data.gpa)
        {
            firstptr->previous = temp;
            temp->next = firstptr;
            firstptr = temp;
            return;
        }
        if (current->next == NULL)
        {
            if(temp->data.gpa > current->data.gpa){
                temp->previous = current;
                current->next = temp;
                return;
            }
            else if (temp->data.gpa < current->data.gpa){
                temp->next = current;
                current->previous = temp;
                current = temp;
                firstptr = current;
                return;
            }
        }
         
        while (current->next != NULL)
        {
            if (temp->data.gpa > current->data.gpa && temp->data.gpa < current->next->data.gpa)
            {
                temp->next = current->next;
                temp->previous = current;
                current->next->previous = temp;
                current->next = temp;
            }
            current = current->next;
        }
        if (temp->data.gpa > current->data.gpa)
        {
            temp->previous = current;
            current->next = temp;
        }
    }
}
 
void doublyLL::printAscending(Node* firstptr){
    Node* current = firstptr;
    cout << "Ascending Order Print" << endl<<endl;
    cout << setw(10) << "Last Name" << setw(20) << "FirstName" << setw(20) << "GPA" << endl;
    while (current != NULL){
        cout << setw(10) << current->data.lastName << setw(20) << current->data.firstName << setw(20) << current->data.gpa << endl;
        current = current->next;
    }
    cout << endl << endl;
    return;
}
 
void doublyLL::printDescending(Node* firstptr){
    Node* current = firstptr;
    cout << "Descending Order Print" << endl <<endl;
    cout << setw(10)<<"Last Name"<< setw(20) << "FirstName" << setw(20) << "GPA" << endl;
    while (current->next != NULL){
        current = current->next;
    }
    while (current != NULL){
        cout << setw(10) << current->data.lastName << setw(20) << current->data.firstName << setw(20) << current->data.gpa << endl;
        current = current->previous;
    }
    cout << endl << endl;
    return;
}
 
void doublyLL::insert(studentType info){
    insert(this->firstptr, info);
    return;
}
 
void doublyLL::printAscending(){
    printAscending(this->firstptr);
}
 
void doublyLL::printDescending(){
    printDescending(this->firstptr);
}
 
int main(){
    doublyLL printList;
    ifstream file;
    file.open("infile.txt");
    studentType data;
    while (!file.eof()){
        file >> data.lastName >> data.firstName >> data.gpa;
        printList.insert(data);
    }
    printList.printAscending();
    printList.printDescending();
    return 0;
}
/*
Ascending Order Print
 
 Last Name           FirstName                 GPA
   Herold,                Jill                 0.3
  Jackson,                Stan                   1
    Jerry,             Francis                1.67
     Joan,              Wilson                   2
    Smith,             Stanley                2.17
   Claire,              Claude                 2.4
Rodriguez,                 San                2.89
 Robinson,                Mary                 3.2
   Elliot,              Amelia                3.34
  Remeaux,                 Sol                 3.7
    Bacon,             Francis                   4
 
 
Descending Order Print
 
 Last Name           FirstName                 GPA
    Bacon,             Francis                   4
  Remeaux,                 Sol                 3.7
   Elliot,              Amelia                3.34
 Robinson,                Mary                 3.2
Rodriguez,                 San                2.89
   Claire,              Claude                 2.4
    Smith,             Stanley                2.17
     Joan,              Wilson                   2
    Jerry,             Francis                1.67
  Jackson,                Stan                   1
   Herold,                Jill                 0.3
 
 
  
*/

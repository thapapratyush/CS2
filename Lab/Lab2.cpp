/*
Today's lab is to create the beginning of an application called "HU Dating Service" that we will build over the next several weeks.  First we must define a class called personType.  A personType has the folllowing data members: PUBLIC - name, person_no, address(of type addressType), PRIVATE - interest1, interest2.

You will need to define a class called addressType.  You can combine the implementation and specification files for these classes.  I have provided constructors for each class. Write accessor (get )and mutator (set) for the private data members.  Write and test a printPerson() member function.

In your driver file, paste your specification file and your implementation file.  In main() declare an array of 6 personTypes called members.

Read the data from the file below.  Name the file "infile.txt".  The code you will need to read this file to populate this array is provided for you.

You must write your own printPerson() member function.  Test your code, paste the output at the end as a comment.  Paste this entire working program in the Driver FIle box and submit your code. 

INFILE:

Herold, Jill     1     2234 123 Main St.      Washington, DC   20019 F yoga facebook
Jackson, Stan    2     3748 12 Douglas Ave.   Baltimore, MD    30229 M sports movies
Jerry, Francis   3     6666 2345 6th Street   Woodbridge, VA   44040 M movies roadtrips
Joan, Wilson     4     1234 12 Georgia Ave.   Washington, DC   20019 F romance dining
Smith, Stanley   5     3456 56 D Street       Baltimore, MD    30229 M movies dining
Claire, Claude  6     2311 66 32nd Street    Woodbridge, VA   44040 F cooking facebook

*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>    
 
using namespace std;
 
//Class declaration
class addressType
{
public:
    string streetAddressNum;
    string streetName;
    string streetAddress;
    string streetType;
    string city;
    string state;
    string zipcode;
};
 
class personType
{
public:
    personType(); //constructor
    string lname;
    string fname;
    int personNum;
    int personID;
    char gender;
    addressType address;
    /********MEMBER FUNCTIONS********/
    string getInterest1();
    string getInterest2();
    void setInterest1(string);
    void setInterest2(string);
    void printPerson();
private:
    string interest1;
    string interest2;
};
 
int main() {
    ifstream myfile;
    myfile.open("infile.txt");
    personType members[6];
    string interest1, interest2;
    for (int i = 0; i < 6; i++)
    {
        myfile >> members[i].lname;
        myfile >> members[i].fname;
        myfile >> members[i].personNum;
        myfile >> members[i].personID;
        myfile >> members[i].address.streetAddressNum;
        myfile >> members[i].address.streetAddress;
        myfile >> members[i].address.streetType;
        myfile >> members[i].address.city;
        myfile >> members[i].address.state;
        myfile >> members[i].address.zipcode;
        myfile >> members[i].gender;
        myfile >> interest1 >> interest2;
        members[i].setInterest1(interest1);
        members[i].setInterest2(interest2);
    };
    for (int i = 0; i < 6;i++) {
        members[i].printPerson();
    };
    return 0;
};
 
//personType
personType::personType()
{
    fname = "";
    lname = "";
    personNum = 0;
    personID = 0;
    gender = ' ';
    this->address.streetAddressNum = "";
    this->address.streetName = "";
    this->address.streetAddress = "";
    this->address.streetType = "";
    this->address.city = "";
    this->address.state = "";
    this->address.zipcode = "";
};
 
string personType::getInterest1(){
    return interest1;
};
 
string personType::getInterest2(){
    return interest2;
};
 
void personType::setInterest1(string int1) {
    interest1 = int1;
};
 
void personType::setInterest2(string int2) {
    interest2 = int2;
};
 
void personType::printPerson() {
    cout << lname << " " << fname << " " << personNum << " " << personID << " " << address.streetAddressNum << " " << address.streetAddress << " " << address.streetType << " " << address.city << " " << address.state << " " << address.zipcode << " " << gender << " " << getInterest1() << " " << getInterest2() << " " << endl << endl;
};
 
/*
Herold, Jill 1 2234 123 Main St. Washington, DC 20019 F yoga facebook
 
Jackson, Stan 2 3748 12 Douglas Ave. Baltimore, MD 30229 M sports movies
 
Jerry, Francis 3 6666 2345 6th Street Woodbridge, VA 44040 M movies roadtrips
 
Joan, Wilson 4 1234 12 Georgia Ave. Washington, DC 20019 F romance dining
 
Smith, Stanley 5 3456 56 D Street Baltimore, MD 30229 M movies dining
 
Claire, Claude 6 2311 66 32nd Street Woodbridge, VA 44040 F cooking facebook
 
Press any key to continue . . .
 
 
*/

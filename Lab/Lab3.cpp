/*
In this quiz we are going to expand on the program we created in last week's lab.  You will remember that we began the HU Dating Service application by defining a base class called personType.

Now, you are being asked to add three modifications to your code.

1)  You should add another class to the implementation and specification files.  This derived class will add membershipType and member_ship_status (both char) data members.  both of these data memebers should be public.  Also, write two constructors for this derived class.

2) define two (2) additional constructors for the membership Type class.  One will not have any parameters and simply initialize the data members of the class.  The second constructor will take a list of parameters, one for each data member.  This constructor will simply set the values of the data members to the values of the parameters.

The specification for the derived membershipType class is below:

?
1
2
3
4
5
6
7
8
9
10
//define membershipType class
class membershipType:public personType
{
public:
    char membership_type;
    char membership_status;
    membershipType();  // 1st constructor
    membershipType(char,char);  // 2nd constructor
    void print_member_type();
};
3) Write a print function for the membershipType class that prints out the values of all of the data members, including the data members from the base class (personType).

Test your code in the driver file by reading the data file, putting this data in an array of membershipTypes.  Then loop through this array printing the data in eachmembershipType object.

These two new data members should get their data from the last two characters that have been added to the file below.  Remember to name the file "infle.txt".

Paste your code in the spaces below.

?
1
2
3
4
5
6
Herold, Jill     1     2234 123 Main St.      Washington, DC   20019 F yoga facebook 1 2
Jackson, Stan    2     3748 12 Douglas Ave.   Baltimore, MD    30229 M sports movies 2 4
Jerry, Francis   3     6666 2345 6th Street   Woodbridge, VA   44040 M movies roadtrips 1 1
Joan, Wilson     4     1234 12 Georgia Ave.   Washington, DC   20019 F romance dining 2 3
Smith, Stanley   5     3456 56 D Street       Baltimore, MD    30229 M movies dining 2 1
Claire, Claude  6     2311 66 32nd Street    Woodbridge, VA   44040 F cooking facebook 1 1
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
 
//define membershipType class
class membershipType:public personType
{
public:
    char membership_type;
    char membership_status;
    membershipType();  // 1st constructor
    membershipType(char, char);  // 2nd constructor
    void print_member_type();
};
 
int main() {
    ifstream myfile;
    myfile.open("infile.txt");
    membershipType members[6];
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
        myfile >> members[i].membership_type;
        myfile >> members[i].membership_status;
    };
    for (int i = 0; i < 6;i++) { 
        members[i].print_member_type();
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
 
membershipType::membershipType() {
    membership_type = ' ';
    membership_status = ' ';
};
 
membershipType::membershipType(char t, char s) {
    membership_type = t;
    membership_status = s;
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
    cout << lname << " " << fname << " " << personNum << " " << personID << " " << address.streetAddressNum << " " << address.streetAddress << " " << address.streetType << " " << address.city << " " << address.state << " " << address.zipcode << " " << gender << " " << getInterest1() << " " << getInterest2() << " ";
};
 
void membershipType::print_member_type() {
    printPerson();
    cout << membership_type<< " " << membership_status << endl << endl;
};
 
/*
Herold, Jill 1 2234 123 Main St. Washington, DC 20019 F yoga facebook 1 2
 
Jackson, Stan 2 3748 12 Douglas Ave. Baltimore, MD 30229 M sports movies 2 4
 
Jerry, Francis 3 6666 2345 6th Street Woodbridge, VA 44040 M movies roadtrips 1 1
 
Joan, Wilson 4 1234 12 Georgia Ave. Washington, DC 20019 F romance dining 2 3
 
Smith, Stanley 5 3456 56 D Street Baltimore, MD 30229 M movies dining 2 1
 
Claire, Claude 6 2311 66 32nd Street Woodbridge, VA 44040 F cooking facebook 1 1
 
Press any key to continue . . .
 
*/

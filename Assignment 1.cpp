/*Part 1
As explained in class, your first assignment is to get the code presented in the Inheritance slides to work.

 

Paste your working source code below with your test output as a comment. 

*/

#include<iostream>
 
using namespace std;
 
class arithmetic        //class arithmetic
{
protected:
    int num1, num2;         //declaring the variables 
public:
    void getdata()          //method getdata to get the number from the user    
    {
        cout << "For Addition:";
        cout << "\nEnter the first number: ";
        cin >> num1;      //input the number and store it in num1 
        cout << "\nEnter the second number: ";
        cin >> num2;
    }
};
class myplus :public arithmetic     //derived class that adds num1 and num2
{
protected:
    int sum;
public:
    void add()
    {
        sum = num1 + num2;
    }
};
class myminus         //derived class that subtracts n1 and n2
{
protected:
    int n1, n2, diff;
public:
    void sub()          //sub method that takes in the two numbers and takes the difference
    {
        cout << "\nFor Subtraction:";
        cout << "\nEnter the first number: ";
        cin >> n1;
        cout << "\nEnter the second number: ";
        cin >> n2;
        diff = n1 - n2;
    }
};
class result :public myplus, public myminus         //the hybrid class that displays the output
{
public:
    void display()
    {
        cout << "\nSum of " << num1 << " and " << num2 << "= " << sum;
        cout << "\nDifference of " << n1 << " and " << n2 << "= " << diff << endl;
    }
};
void main()
{
    result z;       //creating an instance of the hybrid class
    z.getdata();    //calling the getdata() method
    z.add();
    z.sub();
    z.display();
    system("pause");
}
/*
For Addition:
 
Enter the first number: 24 
Enter the second number: 13
 
For Subtraction:
 
Enter the first number: 76
Enter the second number: 5
 
Sum of 24 and 13= 37
 
Difference of 76 and 5= 71          
Press any key to continue . . .     */


/*

Part 2
Next, write a program that you design to illustrate hybrid inheritance.

Paste your working source code below with your test output as a comment. 
*/

#include<iostream>
 
using namespace std;
 
class body          //body class
{
protected:
    int weight;
public:
    void getphysique()          //method getphysique of class body that inputs the weight
    {
        cout << "\nEnter your weight in pounds: ";
        cin >> weight;
    }
};
 
class bodyweight:public body        //body weight subclass that inherits body class
{
protected:
    float weightInKilograms;
public:
    void convertWeight()        //convert weight method to convert the weight to kilograms
    {
        weightInKilograms = float(weight *0.453592);
    }
};
 
class bodyheight            //body height subclass that inherits body class 
{
protected:
    int height;
public:
    void getheight()            //get height method to get the height to kilograms
    {
        cout << "\nTyope your height in meters:";
        cin >> height;        //input the height and store it in the variable height
    }
};
 
class result :public bodyheight, public bodyweight          //the hybrid inherited class that displays the BMI and other information
{
public:
    void display()      //display method
    {
        cout << "\n The BMI of your body with height " << height << " meters and weight of " << weightInKilograms << " kilograms" << "= " << float(weightInKilograms / height) << endl;
    }
};
 
void main()
{
    result z;           //declaring an instance of the hybrid class
    z.getphysique();
    z.getheight();
    z.convertWeight();
    z.display();        //invoking the display method
    system("pause");
    //getch(); 
}
 
/*
 
Enter your weight in pounds: 124
 
Tyope your height in meters:2.3
 
The BMI of your body with height 2 meters and weight of 56.2454 kilograms= 28.1227
Press any key to continue . . .
 
*/
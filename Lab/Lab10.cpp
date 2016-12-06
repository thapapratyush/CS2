/*

GENERIC PROGRAMMING
 

What is the meaning of generic programming?
 

Generic Programming is a programming paradigm for developing efficient, reusable software libraries. Pioneered by Alexander Stepanov and David Musser, Generic Programming obtained its first major success when the Standard Template Library became part of the ANSI/ISO C++ standard.

Why do we need generic programming?


Templates are the foundation of generic programming, which involves writing code in a way that is independent of any particular type.

A template is a blueprint or formula for creating a generic class or a function. The library containers like iterators and algorithms are examples of generic programming and have been developed using template concept.

There is a single definition of each container, such as vector, but we can define many different kinds of vectors for example, vector <int> or vector <string>.

You can use templates to define functions as well as classes, let us see how do they work:

Let's write a generic function




Make up your own names. Include your name.

Write the first example program presented in the video and paste your code and your output as a comment below:

*/

#include <iostream>
#include <string>
 
using namespace std;
 
void display(int[], int);
void displayStr(string[], int);
 
int main(){
    const int size = 10;
    int numbers[size];
    for (int i = 0; i < size; i++){
        numbers[i] = i + 1;
    }
    display(numbers, size);
    string names[] = { "Alfie","Marques","Dana","Dylan","Cody","Tyson","Jalebi","Hu","Lizza","Ashley" };
    displayStr(names, size);
    return 0;
}
 
void display(int arr[], int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
 
void displayStr(string arr[], int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
 
/*
1 2 3 4 5 6 7 8 9 10
Ashley Marques Dana Dylan Cody Tyson Jalebi Hu Lizza Ashley
Press any key to continue . . .
*/

/*Write the second example program presented in the video and paste your code and your output as a comment below:*/

#include <iostream>
#include <string>
 
using namespace std;
 
template <typename T>
void display(T[],int);
template <typename T>
T max(T&, T&);
 
int main(){
    int a = 12;
    int b = 24;
    cout << max(a, b) << endl;
    double x = 2.25;
    double y = 0.25;
    cout << max(x, y) << endl;
    string w1 = "apple";
    string w2 = "aardvark";
    cout << max(w1, w2)<<endl;
    return 0;
}
 
template <typename T>
void display(T arr[], int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
 
template <typename T>
T max(T &arg1, T &arg2){
    if (arg1 > arg2){
        return arg1;
    }
    else{
        return arg2;
    }
}
/*
24
2.25
apple
Press any key to continue . . .
*/

/*
Let's write a generic class

Make up your own numbers
Write the program presented in the video and paste your code and your output as a comment below:*/

#include <iostream>
#include <string>
 
using namespace std;
 
template <typename T>
 
class Stack {
private:
    T datastore[100];
    int top;
public:
    Stack() {
        top = -1;
    }
    void push(int num) {
        ++top;
        datastore[top] = num;
    }
    T pop() {
        int val = datastore[top];
        datastore[top] = 0;
        --top;
        return val;
    }
    T peek() {
        return datastore[top];
    }
};
 
int main(){
    Stack<double> numbers;
    numbers.push(12);
    numbers.push(22);
    cout << numbers.peek() << endl;
    int value = numbers.pop();
    cout << numbers.peek() << endl;
    return 0;
}
/*
22
12
Press any key to continue . . .
  
*/

/*Let's learn how to use TEMPLATE SPECIALIZATION


Write the example program presented in the video and paste your code and your output as a comment below:*/

#include <iostream>
#include <string>
 
using namespace std;
 
template <typename T>
class Stack {
private:
    T datastore[100];
    int top;
public:
    Stack() {
        top = -1;
    }
    void push(int num) {
        ++top;
        datastore[top] = num;
    }
    T pop() {
        int val = datastore[top];
        datastore[top] = 0;
        --top;
        return val;
    }
    T peek() {
        return datastore[top];
    }
};
 
template<>
class Stack<string> {
private:
    string datastore[100];
    int top;
public:
    Stack() {
        top = -1;
    }
    void push(string val) {
        ++top;
        datastore[top] = val;
    }
    string pop() {
        string val = datastore[top];
        datastore[top] = "";
        --top;
        return val;
    }
    string peek() {
        return datastore[top];
    }
};
 
int main(){
    Stack<string> names;
    names.push("Mary");
    names.push("Joe");
    cout << names.peek() << endl;
    string name = names.pop();
    cout << names.peek() << endl;
    return 0;
}
/*
Joe
Mary
Press any key to continue . . .
*/

/*The current server time is 3:06 PM

Do you have suggestions for improving AssessTrack? Please email them to suggestions@assesstrack.com!

Submission Details for Pratyush Thapa's Assignment 2
Click here to Submit this assignment again.

Submitted on 10/11/2016 9:33:49 PM
Score: 20
Graded By: Travon Speller
Other Submissions for this Assessment (only the highest scoring submission will be counted):
Submission on 10/6/2016 7:59:10 AM (Score: 0) Click here to view
1) [20 pts]
Assignment 2
Today you are asked to convert a program that you wrote last semester for the second exam to an object oriented application.  The specification and implementation of the examType class should be in an .h file called examType.h.   The array must be converted to a linked-list.

You are a grader in your History class. The professor has asked you to prepare the following statistics for the final exams for each of the last five (5) semesters: number of student grades, the class average exam grade, number of grades above the average and the number of grades below the average.  You decide to write a program to read the data, perform the needed calculations and print the report.

Use the structure chart below to write this program:

Use the following input file called "infile.txt":

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
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
Fall 2013 17
54
96
68
99
35
81
93
32
12
23
45
55
66
77
88
99
100
Spring 2014 10
99
48
22
41
66
80
91
55
83
92
Fall 2014 12
32
12
23
45
51
62
97
38
59
80
91
98
Spring 2015 20
93
41
60
80
90
55
88
99
32
12
23
45
55
66
77
88
99
100
99
98
Fall 2015 15
92
45
61
86
90
55
82
92
32
12
23
45
53
61
73
Requirements
 

Define an examType struct to store the data for each final exam. Each instance of this user-define type should contain thesemester_name, the semester_year, the no_of _grades, the average_grade, the no_of_grades_above_average,  no_of_grades_below_average and a grades_array of 35 integers that will store up to 35 student grades for the semester final exam. (See data file above)

The main() function must define an array (statistics_array) of five (5) examType structs. Then call the three (3) functions indicated in the structure chart above.

The input_data() function takes in two parameters, the infile and the statistics_array. This function reads (loops) through the five sets of semester final exam data and populates a portion of the statistics_array.

The calculate_statistics() function takes in the statistics_array and then loops five times calling the calculate_average(), calculate_above_average() and calculate_below_average() functions sending the semester_index (0 -4) and the statistics_array  to each function.  The result is that these computed statistics are stored in each of member structs in the statistics_array.

The calculate_average() function takes in the statistics_array and a semester_index. This function loops through the grades_array in the struct indicated by the semester_index and sums all  the grades.  This sum is divided by the no_of _grades  in the member struct (indexed by semester_index) to compute the average grade for that semester's final exam.  Finally, this average is stored in the average_grade member of the struct indexed by the semester_index .

The calculate_above_average() function takes in the statistics_array and a semester_index. This function loops through the grades_array in the struct indexed by the semester_index and counts all the grades that are above the average_grade member of the struct indexed by the semester_index.  Finally, this count is stored in the no_of_grades_above_average member of the  struct indexed by the semester_index.

The calculate_below_average() function takes in the statistics_array and a semester_index. This function loops through the grades_array in the struct indexed by the semester_index and counts all the grades that are below the average_grade member of the struct indicated by the semester_index.  Finally, this count is stored in the no_of_grades_below_average member of the struct indexed by the semester_index.

The print_results() function takes in the statistics_array  and loops through it printing the exam information stored for each semester.  This function prints the report show below: 

*/
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "ExamType.h"
 
using namespace std;
 
 
void Input_Data(ifstream&, nodeType*); // funciton prototypes
void Calculate_Statistics(nodeType*);
void Print_Results(nodeType*);
void Calculate_Average(nodeType*);
void Calculate_Above_Average(nodeType*);
void Calculate_Below_Average(nodeType*);
 
/*The main() function must define an array (statistics_array) of five (5) examType structs. Then call the three (3) functions indicated in the structure chart above.
*/
int main() {
    nodeType* firstptr;
    nodeType* exam_data;
    firstptr = new nodeType;
    ifstream file;
    file.open("infile.txt");
    file >> firstptr->info.semester_name;
    file >> firstptr->info.semester_year;
    file >> firstptr->info.num_of_grades;
    for (int i = 0; i < firstptr->info.num_of_grades; i++) {
        file >> firstptr->info.grades_array[i];
    }
    firstptr->next = NULL;
    exam_data = firstptr;
    //for loop to read through the others sets of data and populate the next node in linked list
    for (int i = 0; i < 5; i++) {
        Input_Data(file, exam_data);            // function calls: input data into nodes
        Calculate_Statistics(exam_data);                    //calculate statistics based on node    
        Print_Results(exam_data);                       //print the result based on node
        exam_data = exam_data->next;
    }
    file.close(); // closing file
    return 0;
}
 
/*
The input_data() function takes in two parameters, the infile and the statistics_array. This function reads (loops) through the five sets of semester final exam data and populates a portion of the statistics_array.
*/
 
void Input_Data(ifstream& file, nodeType* exam_data) {
    exam_data->next = new nodeType;
    file >> exam_data->next->info.semester_name;
    file >> exam_data->next->info.semester_year;
    file >> exam_data->next->info.num_of_grades;
    for (int grades_index = 0; grades_index < exam_data->next->info.num_of_grades; grades_index++) {
        file >> exam_data->next->info.grades_array[grades_index];
    }
    exam_data = exam_data->next;
}
 
/*
The calculate_statistics() function takes in the statistics_array and then loops five times calling the calculate_average(), calculate_above_average() and calculate_below_average() functions sending the semester_index (0 -4) and the statistics_array  to each function.  The result is that these computed statistics are stored in each of member structs in the statistics_array.
*/
 
void Calculate_Statistics(nodeType* exam_data){
    Calculate_Average(exam_data);
    Calculate_Above_Average(exam_data);
    Calculate_Below_Average(exam_data);
}
/*
The calculate_average() function takes in the statistics_array and a semester_index. This function loops through the grades_array in the struct indicated by the semester_index and sums all  the grades.  This sum is divided by the no_of _grades  in the member struct (indexed by semester_index) to compute the average grade for that semester's final exam.  Finally, this average is stored in the average_grade member of the struct indexed by the semester_index .
*/
void Calculate_Average(nodeType* exam_data){
    float grade_total = 0;
    float grade_average = 0;
    int number_of_grades = exam_data->info.num_of_grades;
    for (int grade_index = 0; grade_index < number_of_grades; grade_index++) {
        grade_total += exam_data->info.grades_array[grade_index];
    }
    grade_average = grade_total / number_of_grades;
    exam_data->info.average_grade = grade_average;
}
 
/*The calculate_above_average() function takes in the statistics_array and a semester_index. This function loops through the grades_array in the struct indexed by the semester_index and counts all the grades that are above the average_grade member of the struct indexed by the semester_index.  Finally, this count is stored in the no_of_grades_above_average member of the  struct indexed by the semester_index.
*/
void Calculate_Above_Average(nodeType* exam_data){
    int number_above_average = 0;
    float average_grade = exam_data->info.average_grade;
    int number_of_grades = exam_data->info.num_of_grades;
    for (int grade_index = 0; grade_index < number_of_grades; grade_index++) {
        if (exam_data->info.grades_array[grade_index] > average_grade)
            number_above_average++;
    }
    exam_data->info.number_of_grades_above_average = number_above_average;
}
/*
The calculate_below_average() function takes in the statistics_array and a semester_index. This function loops through the grades_array in the struct indexed by the semester_index and counts all the grades that are below the average_grade member of the struct indicated by the semester_index.  Finally, this count is stored in the no_of_grades_below_average member of the struct indexed by the semester_index.
*/
void Calculate_Below_Average(nodeType* exam_data){
    int number_below_average = 0;
    float average_grade = exam_data->info.average_grade;
    int number_of_grades = exam_data->info.num_of_grades;
    for (int grade_index = 0; grade_index < number_of_grades; grade_index++) {
        if (exam_data->info.grades_array[grade_index] < average_grade)
            number_below_average++;
    }
    exam_data->info.number_of_grades_below_average = number_below_average;
}
/*The print_results() function takes in the statistics_array  and loops through it printing the exam information stored for each semester.  This function prints the report show below:*/
void Print_Results(nodeType* exam_data){
    cout << "Analysis of exams in " << exam_data->info.semester_name << " " << exam_data->info.semester_year << endl << endl;
    cout << "The number of grades is " << exam_data->info.num_of_grades << endl;
    cout << "The average grade is " << fixed << showpoint << setprecision(2) << exam_data->info.average_grade << endl;
    cout << "The number of grades above the average is " << exam_data->info.number_of_grades_above_average << endl;
    cout << "The number of grades below the average is " << exam_data->info.number_of_grades_below_average << endl;
    cout << endl << endl;
}
 
/*
Analysis of exams in Fall 2013
 
The number of grades is 17
The average grade is 66.06
The number of grades above the average is 9
The number of grades below the average is 8
 
 
Analysis of exams in Spring 2014
 
The number of grades is 10
The average grade is 67.70
The number of grades above the average is 5
The number of grades below the average is 5
 
 
Analysis of exams in Fall 2014
 
The number of grades is 12
The average grade is 57.33
The number of grades above the average is 6
The number of grades below the average is 6
 
 
Analysis of exams in Spring 2015
 
The number of grades is 20
The average grade is 70.00
The number of grades above the average is 11
The number of grades below the average is 9
 
 
Analysis of exams in Fall 2015
 
The number of grades is 15
The average grade is 60.13
The number of grades above the average is 8
The number of grades below the average is 7
 
 
Press any key to continue . . .
*/
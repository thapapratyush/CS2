#include <iostream>
#include <string>
 
using namespace std;
 
 
class DateType
{
public:
    void Initialize(int newMonth, int NewDay, int newYear);
    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;
    void SetYear(int);
    void SetMonth(int);
    void SetDay(int);
 
private:
    int year;
    int month;
    int day;
};
 
int main() {
    DateType today;
    today.SetYear(2016);
    today.SetMonth(8);
    today.SetDay(30);
    cout << today.GetDay() << " ";
    cout << today.GetMonth() << " ";
    cout << today.GetYear() << endl;
    return 0;
};
 
int DateType::GetYear() const { 
    return year; 
};
 
int DateType::GetMonth() const { 
    return month; 
};
 
int DateType::GetDay() const { 
    return day; 
};
 
void DateType::SetYear(int thisYear) {
    year = thisYear;
};
 
void DateType::SetMonth(int thisMonth) {
    month = thisMonth;
};
 
void DateType::SetDay(int thisDay) {
    day = thisDay;
};
 
/*
30 8 2016
Press any key to continue.
*/

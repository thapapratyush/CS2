/*Lab 12
Lab 12 asks you to create a linked-list representation of asortedListType template class. Write an insertInOrder function to add nodes to this list.  The list should be sorted in last-name ascending order.

Use the model code below.

template <class T>
class sortedListType 
{
public:
      sortedListType();   // Class constructor
      ~sortedListType();   // Class destructor 
      void insertinOrder (T const&); 
      nodeType* head;
      int length;
};
template <class T>
void sortedListType<T>::insertinOrder (T const& elem)
{
          // INSERT YOUR CODE HERE
}
Use the input file below named "infile.txt".  The fields are first_name, last_name, team_code and home_city.

Remington Holt   2  Detriot
Adegboyega Akinsiku   4  Topeka
Alyssa Bullock   6  Baltimore
Dhuel Fisher   8  Richmord
Kendall Keeling   3  Miami
Joanna Phillip   1  Tampa
Jonnetta Bratcher   3  Charleston
Charles Brown   0  Bowie
Kerisha Burke   7  Washington
Allee Clark    4  Pittsburg
Brionna Huskey   1  Sacramento
Brittany Jackson   5  Denver
Matthew Jacobs   8  Nashville
Kourtnei Langley   9  Louisville
Crepin Mahop   2  Bolder
Ashlee McKinney   3  Houston
Blanche Mahop   6  Austin
Jennifer Ojie   7 Arlington
Kareem Parris-Baptiste   8  Princeton
Michael Phillips   3  Boston
Ranjay Salmon   2  Trenton
Aja Walton   3  Boise
Kyle Ward   5  Germantown
Illium Williams   8  Juray
Saboor Salaam   1  Reston
Malcolm Williams   2  Winchester
Cherith-Eden Clements   5  Hagerstown
Isa Edwards-El   3  Greensburg
Victor Foreman 4  Earlsville
Jaleesa Harrigan   1  Harrisonburg
Candace Ross   0  Rockville
Susan Angus   3  Burke
Terrance Ellis   6  Columbia
Johan Lingani   8  Woodbridge
Rashad Rose   7  Fredricksburg
Theodore Santos-Gaffney   9  Towson
Write a print function that will print your linked-list in last_name ascending order. */

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
 
using namespace std;
 
class InputType{
public:
    string first_name;
    string last_name;
    int team_code;
    string home_city;
};
 
 
struct nodeType {
    InputType info;
    nodeType* next;
};
 
template <class T>
class sortedListType 
{
public:
      sortedListType();   // Class constructor
      //~sortedListType();   // Class destructor 
      void insertinOrder (T const&); 
      nodeType* head;
      int length;
};
 
 
template <typename T>
sortedListType<T>::sortedListType(){
    length = 0;
    head = NULL;
}
 
template <class T>
void sortedListType<T>::insertinOrder (T const& elem)
{
    nodeType* temp = new nodeType;
    temp->info = elem;
    if (head==NULL){
        head = new nodeType;
        temp->next = head;
        head = temp;
        length++;
    }
    else if(elem.last_name < head->info.last_name){
        temp->next = head;
        head = temp;
        length++;
    } else{
    nodeType* current = new nodeType;
    nodeType* previous = new nodeType;
    current=head;
    while ((elem.last_name>current->info.last_name) && (current->next!=NULL)){
        previous=current;
        current=current->next;
    }
    previous->next = temp;
    temp->next= current;
    length++;
}
}
 
template <class T>
void printsortedLinkedlist(T instance){
    for (int i=0; i<instance.length;i++){
        cout <<setw(20)<<instance.head->info.first_name<< setw(20)<< instance.head->info.last_name<< setw(20)<< instance.head->info.team_code<< setw(20)<< instance.head->info.home_city<<endl;
        instance.head = instance.head->next;
    }
}
 
int main(){
    ifstream file;
    InputType mydata;
    sortedListType<InputType> instance;
    file.open("infile.txt");
    for (int i = 0; i < 36; i++){
        file >> mydata.first_name;
        file >> mydata.last_name;
        file >> mydata.team_code;
        file >> mydata.home_city;
        instance.insertinOrder(mydata);
    }
    printsortedLinkedlist(instance);
    return 0;
}
 
/*          
            Adegboyega            Akinsiku                 4              Topeka
               Susan               Angus                   3               Burke
            Jonnetta            Bratcher                   3          Charleston
             Charles               Brown                   0               Bowie
              Alyssa             Bullock                   6           Baltimore
             Kerisha               Burke                   7          Washington
               Allee               Clark                   4           Pittsburg
        Cherith-Eden            Clements                   5          Hagerstown
                 Isa          Edwards-El                   3          Greensburg
            Terrance               Ellis                   6            Columbia
               Dhuel              Fisher                   8            Richmord
              Victor             Foreman                   4          Earlsville
             Jaleesa            Harrigan                   1        Harrisonburg
           Remington                Holt                   2             Detriot
             Brionna              Huskey                   1          Sacramento
            Brittany             Jackson                   5              Denver
             Matthew              Jacobs                   8           Nashville
             Kendall             Keeling                   3               Miami
            Kourtnei             Langley                   9          Louisville
               Johan             Lingani                   8          Woodbridge
             Blanche               Mahop                   6              Austin
              Crepin               Mahop                   2              Bolder
              Ashlee            McKinney                   3             Houston
            Jennifer                Ojie                   7           Arlington
              Kareem     Parris-Baptiste                   8           Princeton
              Joanna             Phillip                   1               Tampa
             Michael            Phillips                   3              Boston
              Rashad                Rose                   7       Fredricksburg
             Candace                Ross                   0           Rockville
              Saboor              Salaam                   1              Reston
              Ranjay              Salmon                   2             Trenton
            Theodore      Santos-Gaffney                   9              Towson
                 Aja              Walton                   3               Boise
                Kyle                Ward                   5          Germantown
             Malcolm            Williams                   2          Winchester
              Illium            Williams                   8               Juray
*/

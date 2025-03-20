#include <iostream>
// Pointer and Structure
using namespace std;

struct student{
    int id;
    char name[25];
};
student s, *p;

int main()
{
    // \creating three Student variables
    p = &s;
    cout<<"\n Enter Student Id: ";
    cin>>p->id;
    cout<<"\n Enter Student name: ";
    cin>>p->name;
    cout<<"\n\n StudentInformation";
    cout<<"\nStudent_Id \t Student_Name \n";
    cout<<""<<p->id<<"\t\t"<<p->name;
    return 0;
}

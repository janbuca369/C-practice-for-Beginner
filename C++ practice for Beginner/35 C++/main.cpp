#include <iostream>
// struct
using namespace std;
struct student{
    int roll;
    char name[25];
    float mark;
}a, b;
// or struct student a, b;



int main()
{
    cout<<"Enter the all student information! \n";
    cout<<" Enter the first Student Roll: ";
    cin>>a.roll;
    cout<<"\n Enter the first Student name: ";
    cin>>a.name;
    cout<<"\n Enter the first Student Mark: ";
    cin>>a.mark;

    cout<<"\n \n Enter the Second Student Roll: ";
    cin>>b.roll;
    cout<<"\n Enter the Second Student name: ";
    cin>>b.name;
    cout<<"\n Enter the Second Student Mark: ";
    cin>>b.mark;
    cout<<endl<<endl;


    cout<<"You enter the all student information is: \n";
    cout<<"\t The first Student roll: "<<a.roll<<"\t Student name: "<<a.name<<"\t Student mark: "<<a.mark<<endl;
    cout<<"\t The second Student roll: "<<b.roll<<"\t Student name: "<<b.name<<"\t Student mark: "<<b.mark<<endl;

    return 0;
}

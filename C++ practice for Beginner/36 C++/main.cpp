#include <iostream>
// Array of struct
using namespace std;
struct student{
    int roll;
    char name[25];
    float mark;
}a[10];

int main()
{
    cout<<"Enter the all student information! \n";
    for (int i =0; i<3; i++){
    cout<<"\t Enter the first Student Roll: ";
    cin>>a[i].roll;
    cout<<"\t Enter the first Student name: ";
    cin>>a[i].name;
    cout<<"\t Enter the first Student Mark: ";
    cin>>a[i].mark;
    cout<<endl<<endl;
    }

    cout<<"You enter the all student information is: \n";
    cout<<"\t The Student Roll \t"<<"The Student Name \t"<<"The Student Marks \n";
    for(int i=0; i<3; i++){
        cout<<"\t\t"<<a[i].roll<<"\t\t"<<a[i].name<<"\t\t\t"<<a[i].mark<<endl;
    }
    return 0;
}

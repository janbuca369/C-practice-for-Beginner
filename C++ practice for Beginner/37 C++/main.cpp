#include <iostream>

using namespace std;
struct address{;
     int kebele;
     char kefle_ketema[20];
     char roadname[20];
};

struct student{
    int id;
    char name[25];
    char section[9];
    address stuAddress;

};
int main()
{
    student s1;
    cout<<"\n Enter student Id: ";
    cin>>s1.id;
    cout<<" Enter student name: ";
    cin>>s1.name;
    cout<<" Enter student Section: ";
    cin>>s1.section;

    //Reading address
    cout<<"\n"<<endl;
    cout<<"\n Enter Kebele: ";
    cin>>s1.stuAddress.kebele;
    cout<<"\n Enter kefle ketema: ";
    cin>>s1.stuAddress.kefle_ketema;
    cout<<"\n Enter Road-Name: ";
    cin>>s1.stuAddress.roadname;

    cout<<"\n\n****************************** \n";
    cout<<s1.id<<"\t"<<s1.name<<"\t"<<s1.section<<"\n";
    cout<<s1.stuAddress.kebele<<"\t";
    cout<<s1.stuAddress.kefle_ketema<<"\t";
    cout<<s1.stuAddress.roadname<<"\t";


    return 0;
}

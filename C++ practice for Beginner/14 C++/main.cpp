#include <iostream>

/*
    - Writing a C++ program which reads a number and display the day
    - Example : If the number is 1 display Monday, 2 it is display Tuesday and so on

*/

using namespace std;

int main()
{
    int d;
    count<<"Enter the number"<<endl;
    cin>>d;
    switch(d){
    case 1:
        cout<<"Monday"<<endl;
        break;

    case 2:
        cout<<"Tuesday"<<endl;
        break;

    case 3:
        cout<<"Wednesday"<<endl;
        break;

    case 4:
        cout<<"Thursday"<<endl;
        break;

    case 5:
        cout<<"Friday"<<endl;

    default:
        cout<<"Your entry number is Wrong"<<endl;
    }


    return 0;
}

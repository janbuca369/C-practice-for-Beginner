#include <iostream>
// The new Operator
using namespace std;

int main()
{
    /*
    int *p1=new int;
    cin>>*p1;
    *p1=*p1+7;
    cout<<p1<<endl<<*p1;
    */

    //Basic memory management

    int *p1=new int;
    cin>>*p1;
    *p1=*p1+7;
    cout<<p1<<endl<<*p1;
    int d;
    cin>>d;
    if(d==9){
        delete p1;
        cout<<*p1;
    }

    return 0;
}

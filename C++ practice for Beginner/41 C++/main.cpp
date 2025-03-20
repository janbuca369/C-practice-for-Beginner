#include <iostream>
// Pointers and Arrays
using namespace std;

int main()
{
    /*
    int num[5];
    int *p;
    p = num;
    *p = 10;
    p =&num[2];
    *p=30;
    p =num + 3;
    *p = 40;
    p = num;
    *(p +4) = 50;
    for(int n=0; n<5; n++){
        cout<<num[n]<<", ";
    }
    */


    /*
    int a[5] = {1, 3, 5, 7, 9}, *p;
    p = &a[0];
    for(int i=0; i<5; i++){
        cout<<*(p+i)<<", ";
    }
    */

    // Array name is pointer, therefore, the above program can be written as follows
    int a[5] = {1, 3, 5, 7, 9}, *p;
    p = &a[0];
    for(int i=0; i<5; i++){
        cout<<*(a+i)<<", ";
    }

    return 0;
}

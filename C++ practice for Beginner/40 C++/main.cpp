#include <iostream>
// Pointer to Pointer
/*
    A Pointer to a value that is itself a pointer can be declared using multiple levels of * Symbols
*/
using namespace std;

int main()
{
    /*
    int i = 7;
     const int *p = &i;         // Pointer to a constant int
     int *const q = &i;         // Constant pointer.
     //*p=8;
     *q=8;
     p=q;
     //q=p;
     */


     // Void *Pointers
     double d;
     int f;
     double *dp = &d;
     //dp=&f;
     void *p = dp;
     p=&d;
     p=&f;
     /*

     */
    return 0;
}

#include <iostream>

/*
    Loops
        • Loops are iterative statements
        • Block of statements are repeatedly executed as long as condition is true
        • Condition given in loop must become false after some finite iterations otherwise its a
        infinite loop
        • Values used in condition must update inside the body of finite loop
        • Four types of loops
        •
        • pre-tested loop while()
        • post-tested loop do..while()
        • counter controlled loop for()
        • for each loop for Collections for()

*/

using namespace std;
/*
    for loop
        for(initial ization; condition; updation)
*/


int main()
{
    // Write a C++ program and display number 5 up to 10.
    for (int n=5; n<=10; n++){
        cout<<n<<" ";
        }
        cout<<endl;

    // Write a C++ program and display 20 up to 5.
    for(int k=20; k>=5; k--){
        cout<<k<<" ";
    }
    cout<<endl;

    //Write a C++ program and display 15, 20, 25, 30, 35, 40, 45, 50
    for (int y=25; y<=50; y=y+5){
        cout<<y<<endl;
    }



    return 0;
}

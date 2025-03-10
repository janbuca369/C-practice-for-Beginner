#include <iostream>

/*
    Compound assignment operators (+=, -=, *=, /=)
*/

using namespace std;

int main()
{
    int sum = 10, pro = 5, dif = 15, quo = 25, rem = 35;
    sum +=10; // sum = sum + 10
    pro *=3;  // pro = pro * 3
    dif -=5;  // dif = dif - 5
    quo /=5;  // quo = quo / 5
    rem %=4;  // rem = rem % 4
    cout <<sum<< endl;
    cout <<pro<< endl;
    cout <<dif<< endl;
    cout <<quo<< endl;
    cout <<rem<< endl;
    return 0;
}

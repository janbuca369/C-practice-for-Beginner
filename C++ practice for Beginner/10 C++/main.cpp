#include <iostream>

using namespace std;

int main()
{
    cout << "Please enter two natural number"<<endl;
    int a, b, sum, sub, pro, div, rem;
    cin>>a;
    cin>>b;

    sum = a + b;
    sub = a - b;
    pro = a * b;
    div = a / b;
    rem = a % b;
    cout <<"The Addtion of two number: "<<sum<<endl;
    cout <<"The Subtraction of two number: "<<sub<<endl;
    cout <<"The Multiplication of two number: "<<pro<<endl;
    cout <<"The Divsion of two number: "<<div<<endl;
    cout <<"The Modulo of two number: "<<rem<<endl;
    return 0;
}

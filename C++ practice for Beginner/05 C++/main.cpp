#include <iostream>
/*
 Relation Operator (==, !=, >, <, <=, >=)
    - The relation operator is a booliean value that can only be true or false

 */
using namespace std;

int main()
{
    int x = 10, y = 20, a, b, c, d, e, f;
    a = (x == y);
    b = (x != y);
    c = (x > y);
    d = (x < y);
    e = (x <= y);
    f = (x >= y);

    cout <<a<< endl;
    cout <<b<< endl;
    cout <<c<< endl;
    cout <<d<< endl;
    cout <<e<< endl;
    cout <<f<< endl;
    return 0;
}

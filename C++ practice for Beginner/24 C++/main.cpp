#include <iostream>

// Simple project

using namespace std;

double add(double x, double y);
double dif(double x, double y);
double mul(double x, double y);
int quo(int x, int y);
int rem(int x, int y);
void menu();

int main()
{
    int choice, a, b, a1, b1, a2, b2, a3, b3, a4, b4, s, d, m, q, r;
    menu();

    cout<<"Enter your choice\n";
    cin>>choice;
    while(choice != -1){
        if(choice == -1)
            cout<<"Good Bay! \n";

    switch(choice){
    case 1:{
        cout<<"Enter two numbers for addition \n";
        cin>>a>>b;
        s=add(a, b);
        cout<<"The sum of two number is: "<<s<<endl;
    }
    break;

    case 2:{
        cout<<"Enter two numbers for show the differnces \n";
        cin>>a1>>b1;
        d=dif(a1, b1);
        cout<<"The Differences of two number is: "<<d<<endl;
    }
    break;

    case 3:{
        cout<<"Enter two numbers for Product \n";
        cin>>a2>>b2;
        m=mul(a2, b2);
        cout<<"The Product of two number is: "<<m<<endl;
    }
    break;

    case 4:{
        cout<<"Enter two numbers to show Quotient \n";
        cin>>a3>>b3;
        q=quo(a3, b3);
        cout<<"The Quotient when the first is divided by the second is:"<<q<<endl;
    }
    break;

    case 5:{
        cout<<"Enter two numbers to show  Remainder \n";
        cin>>a4>>b4;
        r=rem(a4, b4);
        cout<<"The remainder when the first is divided by the second is: "<<r<<endl;
    }

    default:{
        cout<<"Your Choice is wrong number! \n";
    }
    }
    cout<<"Enter your choice again\n";
    cin>>choice;
    }
    return 0;
}

double add(double x, double y){
    double sum = x + y;
    return sum;
}

double dif(double x, double y){
    double sum = x - y;
    return sum;
}

double mul(double x, double y){
    double sum = x * y;
    return sum;
}

int quo(int x, int y){
    int sum = x / y;
    return sum;
}

int rem(int x, int y){
    int sum = x % y;
     return sum;
}

void menu(){
    cout<<"Press 1  to add           \n";
    cout<<"Press 2  to subtraction   \n";
    cout<<"Press 3  to multiply      \n";
    cout<<"Press 4  to divide        \n";
    cout<<"Press 5  to get remainder \n";
    cout<<"Press -1 to Exit          \n";
}


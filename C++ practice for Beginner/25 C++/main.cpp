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
    int choice;
    menu();

    cout<<"Enter your choice\n";
    cin>>choice;
    while(choice != -1){
        if(choice == -1)
            cout<<"Good Bay! \n";

    switch(choice){
    case 1:{
        // program for multiplication table using for loop
        int n, i;
        cout<<"Enter any natural number: ";
        cin>>n;
        for(i=1; i<=10; i++){
            cout<<n<<"x"<<i<<" = "<<i*n<<endl;
            cout<<endl;
            }
        }
    break;

    case 2:{
        //program for sum of natural numbers using for loops
        int n, i, sum=0; // for loop
        //int n, i=1, sum=0; // while loop
        cout<<"Enter any Natural Number: ";
        cin>>n;

        for(i=1; i<=n; i++){
            sum=sum+i;
        }

        cout<<"Sum Natural number up given number: "<<sum<<endl;
        /*
        while(i<=n){
            sum=sum+i;
            i++;
        }
        cout<<"The Sum Natural number Starting from "<<0<<" up to "<<n<<" be come :"<<sum<<endl;
        */

    }
    break;

    case 3:{
        //program for finding factorial of a number
        int n, i, fact=1;
        cout<<"Enter any natural number: ";
        cin>>n;
        for(i=1; i<=n; i++){
            fact*=i;
        }
        cout<<"Factorial of "<<n<<" is "<<fact<<endl;
        cout<<n<<"! = is "<<fact<<endl;
    }
    break;

    case 4:{
        //program for finding factors of a number
        int n, i;
        cout<<"Enter any natural number: ";
        cin>>n;
        for(i=1; i<=n; i++){
            if(n%i == 0){
                cout<<i<<endl;
            }
        }
    }
    break;

    case 5:{
        //Practice Problem Perfect number
        int n, i, sum=0;
        cout<<"Enter any natural number: ";
        cin>>n;
        for(i=1; i<=n; i++){
            if(n%i == 0){
                sum=sum+i;
            }
        }
        if(2*n == sum){
            cout<<"Perfect number!! \n";
        }else{
            cout<<"Not perfect number! \n";
        }
    }
    break;

    case 6:{
        //program for finding prime number
        int n, i, coun=0;
        cout<<"Enter any natural number: ";
        cin>>n;
        for(i=1; i<=n; i++){
            if(n%i == 0){
                coun++;
            }
        }
        if(coun == 2){
            cout<<"It is prime number! \n";
        }else{
            cout<<"Not prime number! \n";
        }

    }
    break;

    case 7:{
       //program for display digits of a number reverse
        int n, r;
        cout<<"Enter any natural number: ";
        cin>>n;
        while(n>0){
            r=n%10;
            n=n/10;
            cout<<r<<endl;
        }


    }
    break;

    case 8:{
        //program for finding Armstrong number
        int n, r, m ,sum=0;
        cout<<"Enter any natural number: ";
        cin>>n;
        m=n;
        while(n>0){
            r=n%10;
            n=n/10;
            sum=sum+r*r*r;
        }
        if(sum == m){
            cout<<"It's Armstrong Number \n";
        }else{
            cout<<"It's not Armstrong Number \n";
        }

    }
    break;

    case 9:{
        //program for reversing a number
        int n, r, rev=0;
        cout<<"Enter any natural number: ";
        cin>>n;
        while(n>0){
            r=n%10;
            n=n/10;
            rev=rev*10+r;
        }
        cout<<" The Revers number is: "<<rev<<endl;
    }
    break;

    case 10:{
        //program for finding GCD of 2 number
        int m, n;
        cout<<"Enter any natural number: ";
        cin>>m>>n;
        while(m!=n){
            if(m>n){
                m = m-n;
            }else if(n>m){
                n=n-m;
            }
        }
        cout<<m<<endl;
    }
    break;


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
    cout<<"Press  1  To multiplication table            \n";
    cout<<"Press  2  To sum of natural numbers           \n";
    cout<<"Press  3  To finding factorial of a number     \n";
    cout<<"Press  4  To finding factors of a number        \n";
    cout<<"Press  5  To finding perfect number              \n";
    cout<<"Press  6  To finding prime number                 \n";
    cout<<"Press  7  To display digits of a number reverse    \n";
    cout<<"Press  8  To finding Armstrong number               \n";
    cout<<"Press  9  To for reversing a number                  \n";
    cout<<"Press 10  To finding GCD of 2 number                  \n";
    cout<<"Press -1  Exit                                         \n";
}





/*
    int n, num, digit, rev = 0;

    cout << "Enter a Positive Number: ";
    cin >> num;
    n = num;

    do
    {
        digit = num % 10;
        rev = (rev * 10) + digit;
        num = num / 10;
    } while (num != 0);

    cout << " The Reverse of the Number is: " << rev << endl;

    if (n == rev)
        cout << " The Number is a Palindrome";
    else
        cout << " The Number is Not a Palindrome";

*/


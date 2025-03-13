#include <iostream>
/*
    1 Example ->
    n * i = i*n

    6 * 1 = 6
    6 * 2 = 12
    6 * 3 = 18
    6 * 4 = 24
    6 * 5 = 30
    6 * 6 = 36


*/

using namespace std;

int main()
{
    cout<<" 1.To Solve Problem Multiplication               \n";
    cout<<" 2. Sum of Natural numbers                         \n";
    cout<<" 3. Sum of even number 1 through 10                       \n";
    cout<<" 4. Check if the first number is multiple of the second   \n";
    cout<<" 5. Display the larger number                              \n";
    cout<<"-1. To Exit                                                \n";

    int c;
    cout<<"Enter your choice, Please \n";
    cin>>c;

    while(1){
    if(c== -1){
       cout<<"Good bye Bay!!! \n";
    }

    break;
    switch(c){
    case 1:{
        int n, i;
        cout<<"Enter any number \n";
        cin>>n;
        for(i=1; i<=10; i++){
            cout<<n<<"x"<<i<<"="<<i*n<<endl;
        }
    }
        break;

    case 2:{
        int a, b, pro;
        cout<<"Enter Two number \n";
        cin>>a>>b;
        pro = a*b;
        cout<<"The Product of a and b is "<<pro<<endl;
    }
        break;

    case 3:{
        int sum = 0;
        for(int i=1; i<=10; i++){
            sum+=i;
            cout<<"The Sum of numbers 1 through 10 is "<<sum<<endl;
        }
    }
        break;

    case 4:{
        int x, y;
        cout<<"Enter two numbers \n";
        cin>>x>>y;
        if(x%y == 0){
            cout<<"The first is multiple of the second \n";
        }else{
            cout<<"The first is not multiple of the second \n";
        }
    }
        break;


    case 5:{
        int x, y;
        cout<<"Enter two numbers \n";
        cin>>x>>y;
        if(x>y){
            cout<<x<<" is Larger than "<<y<<endl;
        }else if(x<y){
            cout<<x<<" is Less than "<<y<<endl;
        }else{
            cout<<"They are equal \n";
        }
    }

    default:
        cout<<"Wrong Choice, Enter your choice again \n";
    }
    cout<<"Enter your choice \n";
    cin>>c;
}
    return 0;
}

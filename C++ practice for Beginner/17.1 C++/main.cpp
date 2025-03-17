#include <iostream>

using namespace std;

int main()
{
    /*
    int i = 0;
    while(i<3){
        int j = 0;
        while(j < 3){
            cout <<"i = "<<i<<" and j = "<<j<<endl;
            j++;
        }
        i++;
    }
    */


    /*
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            cout <<"i = "<<i<<" and j = "<<j<<endl;
        }
    }
    */


    int i=1, j;
    while(i<=10){
        j=1;
        while(j<=i){
            cout<<j<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }

    return 0;
}

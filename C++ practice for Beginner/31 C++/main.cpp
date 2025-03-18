#include <iostream>
// Multidimensional arrays

using namespace std;

int main()
{
    /*
    //Initializing Multidimensional arry
   // int ar[5][3]={1, 2, 3, 4, 5, 6, 7, 8, 9,10, 11, 12, 13, 14, 15};
    int ar[5][3]={{1, 2, 3}, {4, 5, 6},{7, 8, 9},{10, 11, 12},{13, 14, 15}};

    // Accessing of individual element of the 2D array.
    cout<<ar[1][1]<<endl;
    cout<<ar[4][2]<<endl;
    */

    /*
    int someArray[3][3] = {{0, 00, 000}, {1, 11, 111},{2, 22, 222}};
    for(int i=0; i<3; i++){ // This loop is used to display the columns or groups
        for(int j=0; j<3;j++){ // This loop used to display in individual elements of the group
            cout<<someArray[i][j]<<"\t";
        }
        cout<<endl;
    }
    */


    /*
    int someArray[3][3];
    cout<<"Enter some Matrices number 3*3: \n";
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>someArray[i][j];
        }
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<someArray[i][j]<<"\t";
        }
        cout<<endl;
    }

    */


    int matrix[2][2], matrix1[2][2], sumMatrix[2][2];
    cout<<"Enter some first Matrices number 2*2: \n";
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>matrix[i][j];
        }
    }


     for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }


    cout<<"Enter some second Matrices number 2*2: \n";
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>matrix1[i][j];
        }
    }


     for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cout<<matrix1[i][j]<<"\t";
        }
        cout<<endl;
    }
    sumMatrix[i][j] = matrix[i][j] + matrix1[i][j];
     for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cout<<sumMatrix[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}

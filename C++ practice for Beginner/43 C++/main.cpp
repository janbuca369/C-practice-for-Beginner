#include <iostream>
// String with a pointer notation as a function arguments

using namespace std;
void display(char *str);
void copy(char *, char *);

int main()
{
    char *str = "I Love Ethiopia!!";
    display(str);
    cout<<endl;
    char str1[] = "Hello Hero!";
    char str2[80];
    copy(str2, str1);
    cout<<str2;


    return 0;
}

void display(char *str){
    while(*str){
        cout<<*str++;
    }
}

void copy(char *str2, char *str1){
    while(*str1){
        *str2++= *str1++;
        *str2='\0';
    }
}

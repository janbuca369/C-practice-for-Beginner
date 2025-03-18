#include <iostream>
#include <cstring> // Corrected the include directive

using namespace std;

int main()
{
    /*
    const int max = 80;
    char str[] = "Hey Janbuca";
    char str1[max];
    int i;

    // Copying the string from str to str1
    for(i = 0; i < strlen(str); i++) {
        str1[i] = str[i];
    }
    str1[i] = '\0'; // Null-terminate the copied string

    // Output the copied string
    cout << str1 << endl; // Corrected to use str1 instead of str2
    */
    /*

    char me[20] = "David";
    cout<<me<<endl;
    strcpy(me, "YouAreNotMe");
    cout<<me<<endl;
    */

    char str1[] = "String test";
    char str2[] = "Janbuca";

    char one[10];
    strncpy(one, str1, '$');
    one[9] = '\0';
    cout<< one<<endl;
    return 0;
}

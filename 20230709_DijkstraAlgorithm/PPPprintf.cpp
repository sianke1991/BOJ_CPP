#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;


int main() {
    char* str0 = "hello, world!";
    string str1 = "hello, world!";

    //1. printf
    printf("%s\n", str0); //hello, world!
    printf("%s\n", str1); //ðýa

    //2. cout
    cout << str0 << '\n'; //hello, world!
    cout << str1 << '\n'; //hello, world!

    return 0;
}

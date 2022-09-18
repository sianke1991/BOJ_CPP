#include <iostream>
#include <string>

using namespace std;

string removeA(string str) {
    return str.substr(0, str.length()-1); //remove the last character from the string str.
}

string removeB(string str) {
    string result = str.substr(0, str.length()-1);
    int len = result.length();
    for (int i=0; i<len/2; i++) { //reverse the string result.
        char tmp       = result[i];
        result[i]       = result[len-1-i];
        result[len-1-i] = tmp;
    } //i loop
    return result;
}

string removeLast(string str) {
    char last = str[str.length()-1];
    switch (last) {
        case 'A':
            return removeA(str);
        case 'B':
            return removeB(str);
        default:
            return "";
    }
}

int main() {
    string lsA, lsB;
    cin >> lsA >> lsB;

    while (lsB.length() > lsA.length()) {
        lsB = removeLast(lsB);
    }

    if (lsA == lsB) cout << '1';
    else            cout << '0';

    return 0;
}

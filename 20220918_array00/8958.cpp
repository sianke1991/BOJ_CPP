#include <string>
#include <iostream>


using namespace std;

int getScore(string str){
    int numConsecutiveOs = 0;
    int result = 0;
    for (char ch:str) {
        if (ch=='O') {
            numConsecutiveOs++;
            result += numConsecutiveOs;
        } else
            numConsecutiveOs = 0;
    }
    return result;
}


int main() {
    int numCases;
    cin >> numCases;
    int result[numCases];
    for (int i=0; i<numCases; i++) {
        string lsInput;
        cin >> lsInput;
        result[i] = getScore(lsInput);
    }

    for (int num:result) {
        cout << num << '\n';
    }

    return 0;
}

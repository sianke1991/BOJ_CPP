#include <bits/stdc++.h>

using namespace std;
int passwordLength;
int numCharacters;
char availableCharacters[15];
char selectedCharacters[15];
bool isUsed[15];

bool validity() {
    int numVowels = 0;
    int numConsonants = 0;
    for (int i=0; i<passwordLength; i++) {
        switch (selectedCharacters[i]) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
                numVowels++;
                break;
            default:
                numConsonants++;
                break;
        } //switch
    } //i loop
    return numVowels>=1 && numConsonants>=2;
}

void backtrack(int depth) {
    if (depth==passwordLength) {
        if (validity()) {
            for (int i=0; i<passwordLength; i++) {
                cout << selectedCharacters[i];
            }
            cout << '\n';
        }
        return;
    } //base case

    for (int j=0; j<numCharacters; j++) { //j: ���� �߰��ϱ� ���� ���캸�� �ִ� ������ ��ġ(�ε���), depth: ��ȣ�� ������ �߰��ؾ� �� ��ġ(�ε���)
        if (isUsed[j]) continue;
        if (depth>0 && availableCharacters[j]<=selectedCharacters[depth-1]) continue;
        selectedCharacters[depth] = availableCharacters[j];
        isUsed[j] = true;
        backtrack(depth+1);
        isUsed[j] = false;
    } //j loop
}



int main() {
    cin >> passwordLength >> numCharacters;
    for (int i=0; i<numCharacters; i++) {
        cin >> availableCharacters[i];
    }
    sort(availableCharacters, availableCharacters+numCharacters);
    backtrack(0);
    return 0;
}

#include <iostream>
#include <string>
#include <vector>


using namespace std;


//패턴pat의 실패함수
vector<int> failure(string& s) {
    vector<int> f(s.size());

    int j = 0;
    for (int i=1; i<s.size(); i++) {
        while (j>0 && s[i]!=s[j]) j = f[j-1];
        if (s[i]==s[j]) f[i] = ++j;
    } //i loop

    return f;
}


int main() {
    string str, pat;
    cin >> str >> pat;

    vector<int> f = failure(pat);
    int j = 0;
    for (int i=0; i<str.size(); i++) { //i: str에서 문자를 가리키는 인덱스, j: pat에서 문자를 가리키는 인덱스
        if (str[i]>= '0' && str[i]<= '9') continue; //str에서 숫자는 무시한다.
        while (j>0 && str[i] != pat[j]) j = f[j-1];
        if (str[i] == pat[j]) j++;
        if (j == pat.size()) {
            cout << 1;
            return 0;
        }
    } //i loop
    cout << 0;
    return 0;
}

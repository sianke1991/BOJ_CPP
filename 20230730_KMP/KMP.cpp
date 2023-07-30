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
    for (int i=0; i<str.size(); i++) {
        while (j>0 && str[i] != pat[j]) j = f[j-1];
        if (str[i] == pat[j]) j++;
        if (j == pat.size()) {
            cout << 1;
            return 0; //str에서 pat을 여러 번 찾아야 한다면 이 return 문을 주석 처리한다.
        }
    } //i loop
    cout << 0;
    return 0;
}

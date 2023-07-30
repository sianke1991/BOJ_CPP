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
    getline(cin, str); //띄어쓰기를 포함한 문자열 입력
    getline(cin, pat); //띄어쓰기를 포함한 문자열 입력

    vector<int> f = failure(pat);
    vector<int> positions; //str 내에 pat이 등장하는 위치들을 담은 벡터 (인덱스와 달리 맨 왼쪽 문자의 위치를 1로 잡는다.)

    int j = 0;
    for (int i=0; i<str.size(); i++) { //i: str에서 문자를 가리키는 인덱스, j: pat에서 문자를 가리키는 인덱스
        while (j>0 && str[i] != pat[j]) j = f[j-1];
        if (str[i] == pat[j]) j++;
        if (j == pat.size()) { //str에 pat이 들어있다고 인정된 경우-
            positions.push_back(i-j+2); //pat의 인덱스는 i-j+1라고 볼 수 있으나 위치는 1부터 시작하므로 i-j+2 값을 사용한다.
            //pat의 길이가 3일 때 j가 3에 도달할 때 str에 pat이 포함되었다고 판단한다.
            //str에 pat이 여러 번 등장할 수 있으므로 pat을 한 번 찾았다고 반복을 중단하지 않는다.
        }
    } //i loop
    cout << positions.size() << '\n';
    for (int position:positions) {
        cout << position << '\n';
    }

    return 0;
}

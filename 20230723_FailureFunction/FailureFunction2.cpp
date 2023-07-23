#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> failure(string s) {
    vector<int> f(s.size());
    int j = 0;
    for (int i=1; i<s.size(); i++) { //i: 새로 추가되는 문자의 인덱스, j: i번째 문자와 비교해야 하는 문자의 인덱스
        while (j>0 && s[i]!=s[j]) j = f[j-1]; //문자열에서 새로 추가되는 문자가 접두사 바로 다음 문자와 다를 경우 더 짧은 접두사를 찾는다.
        if (s[i]==s[j]) f[i] = ++j; //문자열에서 새로 추가되는 문자가 접두사 바로 다음 문자와 일치하게 되는 경우 실패함수 값은 (접두사 길이+1)이 된다.
        // while loop를 빠져나가는 조건은
        // 1. j가 0 이하가 되거나 - 또는 -
        // 2. s[i]==s[j]를 만족하는 것
        // 인데 j가 0 이하가 되는 경우 if (s[i]==s[j]) 를 실행하지 않는다.
        // 즉, 접두사를 점점 줄여 나가다가 접두사의 길이가 0이 되는 경우 while loop를 빠져 나가지만 if 문은 실행하지 않는다.
        // vector 내 해당 위치의 값은 0 인 상태로 그대로 남는다.
    } //i loop
    return f;
}

int main() {





}

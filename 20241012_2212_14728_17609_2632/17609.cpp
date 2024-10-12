#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>

using namespace std;

//회문 여부를 점검할 문자열 개수
int numStrings;
//각 테스트 케이스에 따른 문자열 정보
char strs[31][100001];
//각 테스트 케이스의 문자열 길이
int lens[31] = {0};
char reversed[100001];

void input() {
    scanf("%d", &numStrings);
    for (int tc=0; tc<numStrings; tc++)
        scanf("%s", strs[tc]);
}

bool checkPalindrome(int tc) {
    if (!lens[tc])
        lens[tc] = strlen(strs[tc]);
    const int len = lens[tc];
    stack<char> st;
    //step a. 첫 절반의 문자를 스택에 넣는다.
    for (int i=0, lim=len>>1; i<lim; i++) {
        st.push(strs[tc][i]);
    }
    //step b. 마지막 절반의 문자를 스택에서 꺼내면서 비교한다. => 비교 결과 일치하지 않은 것이 있으면 바로 false를 반환한다.
    for (int i=(len+1)>>1; i<len; i++) {
        if (st.top()!=strs[tc][i])
            return false;
        st.pop();
    }
    return true;
}

bool checkPseudoPalindrome(int tc) {
    if (!lens[tc])
        lens[tc] = strlen(strs[tc]);
    //printf("tc: %d, len: %d\n", tc, lens[tc]);
    const int len = lens[tc];
    stack<char> st0;
    //step a. 첫 절반의 문자를 스택에 넣는다.
    for (int i=0, lim=(len-1)>>1; i<lim; i++) {
        st0.push(strs[tc][i]);
    }
    //step b. 마지막 절반의 문자를 스택에서 꺼내면서 비교한다. => 불일치 최대 한 번을 허용한다.
    int flag0 = 0; //불일치 문자가 감지되었는지 여부
    for (int i=len>>1; i<len; i++) {
        //회문을 만들기 위해 제거해야 할 문자가 문자열 맨 마지막에 있는 경우,
        //반복문이 끝나기 전에 st0이 비게 된다. 이 경우 반복을 종료시킨다.
        if (st0.empty()) break;
        if (st0.top()!=strs[tc][i]) {
            if (flag0) {
                flag0 = 2;
                break;
            }
            flag0 = 1;
            continue;
        }
        st0.pop();
    }
    //printf("flag0: %d\n", flag0);
    if (flag0 != 2)
        return true;


    //위 과정을 문자열을 뒤집어서 한 번 더 수행한다.
    for (int i=0; i<len; i++) {
        reversed[i] = strs[tc][len-1-i];
    }
    //printf("reversed: %s\n", reversed);
    stack<char> st1;
    for (int i=0, lim=(len-1)>>1; i<lim; i++) {
        st1.push(reversed[i]);
    }
    bool flag1 = false; //불일치 문자가 감지되었는지 여부
    for (int i=len>>1; i<len; i++) {
        //회문을 만들기 위해 제거해야 할 문자가 문자열 맨 마지막에 있는 경우,
        //반복문이 끝나기 전에 st1이 비게 된다. 이 경우 반복을 종료시킨다.
        if (st1.empty()) break;
        if (st1.top()!=reversed[i]) {
            if (flag1) return false;
            flag1 = true;
            continue;
        }
        st1.pop();
    }
    return true;
}

int main() {
    input();
    vector<int> results;
    for (int tc=0; tc<numStrings; tc++) {
        if (checkPalindrome(tc)) results.push_back(0);
        else if (checkPseudoPalindrome(tc)) results.push_back(1);
        else results.push_back(2);
    }
    for (int result:results)
        printf("%d\n", result);
    return 0;
}

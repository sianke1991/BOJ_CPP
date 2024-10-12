#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>

using namespace std;

//ȸ�� ���θ� ������ ���ڿ� ����
int numStrings;
//�� �׽�Ʈ ���̽��� ���� ���ڿ� ����
char strs[31][100001];
//�� �׽�Ʈ ���̽��� ���ڿ� ����
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
    //step a. ù ������ ���ڸ� ���ÿ� �ִ´�.
    for (int i=0, lim=len>>1; i<lim; i++) {
        st.push(strs[tc][i]);
    }
    //step b. ������ ������ ���ڸ� ���ÿ��� �����鼭 ���Ѵ�. => �� ��� ��ġ���� ���� ���� ������ �ٷ� false�� ��ȯ�Ѵ�.
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
    //step a. ù ������ ���ڸ� ���ÿ� �ִ´�.
    for (int i=0, lim=(len-1)>>1; i<lim; i++) {
        st0.push(strs[tc][i]);
    }
    //step b. ������ ������ ���ڸ� ���ÿ��� �����鼭 ���Ѵ�. => ����ġ �ִ� �� ���� ����Ѵ�.
    int flag0 = 0; //����ġ ���ڰ� �����Ǿ����� ����
    for (int i=len>>1; i<len; i++) {
        //ȸ���� ����� ���� �����ؾ� �� ���ڰ� ���ڿ� �� �������� �ִ� ���,
        //�ݺ����� ������ ���� st0�� ��� �ȴ�. �� ��� �ݺ��� �����Ų��.
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


    //�� ������ ���ڿ��� ����� �� �� �� �����Ѵ�.
    for (int i=0; i<len; i++) {
        reversed[i] = strs[tc][len-1-i];
    }
    //printf("reversed: %s\n", reversed);
    stack<char> st1;
    for (int i=0, lim=(len-1)>>1; i<lim; i++) {
        st1.push(reversed[i]);
    }
    bool flag1 = false; //����ġ ���ڰ� �����Ǿ����� ����
    for (int i=len>>1; i<len; i++) {
        //ȸ���� ����� ���� �����ؾ� �� ���ڰ� ���ڿ� �� �������� �ִ� ���,
        //�ݺ����� ������ ���� st1�� ��� �ȴ�. �� ��� �ݺ��� �����Ų��.
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

#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

char str[50001];
int len;
vector<int> bkLegs; //뒷다리 위치 목록
vector<int> ftLegs; //앞다리 위치 목록


void input() {
    scanf("%s", str);
    len = strlen(str);

    for (int i=0, lim=len-1; i<lim; i++) {
        if (str[i]=='(' && str[i+1]=='(') {
            bkLegs.push_back(i);
        } else if (str[i]==')' && str[i+1]==')') {
            ftLegs.push_back(i);
        }
    } //i loop
}

int main() {
    input();
    long long result = 0LL;
    for (auto bkLeg:bkLegs) {
        auto ub = upper_bound(ftLegs.begin(), ftLegs.end(), bkLeg);
        //printf("%d\n", ftLegs.end()-ub);
        result += ftLegs.end()-ub;
    }
    printf("%lld", result);
    return 0;
}

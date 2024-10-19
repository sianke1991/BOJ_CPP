#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

vector<long long> descNumbers;

void buildDescNumbers() {
    queue<long long> q;
    //step a. q에 한 자리 감소하는 수를 넣는다.
    for (long long num=0LL; num<=9LL; num++) {
        q.push(num);
    } //num loop

    //step b. 너비 우선 탐색을 적용한다.
    //트리에 대해 너비 우선 탐색을 적용하면 [감소하는 수]를 오름차순으로 방문할 수 있다.
    //이 트리에 대해 너비 우선 탐색을 할 때 [방문 처리]는 불필요 한다.
    while (!q.empty()) {
        long long currentNumber = q.front();
        q.pop();
        descNumbers.push_back(currentNumber);
        long long lastDigit = currentNumber%10LL;
        for (long long additionalDigit=0; additionalDigit<lastDigit; additionalDigit++) {
            long long nextNumber = currentNumber*10LL + additionalDigit;
            q.push(nextNumber);
        } //additionalDigit loop (currentNumber의 마지막 숫자보다 작은 숫자를 덧붙여서 감소하는 수를 만들 수 있다.)
    } //while loop
}

int main() {
    buildDescNumbers();
    int idx;
    scanf("%d", &idx);
    int sz = descNumbers.size();
    if (idx>=sz) printf("-1");
    else printf("%lld", descNumbers[idx]);
    return 0;
}

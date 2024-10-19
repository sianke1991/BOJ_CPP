#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

vector<long long> descNumbers;

void buildDescNumbers() {
    queue<long long> q;
    //step a. q�� �� �ڸ� �����ϴ� ���� �ִ´�.
    for (long long num=0LL; num<=9LL; num++) {
        q.push(num);
    } //num loop

    //step b. �ʺ� �켱 Ž���� �����Ѵ�.
    //Ʈ���� ���� �ʺ� �켱 Ž���� �����ϸ� [�����ϴ� ��]�� ������������ �湮�� �� �ִ�.
    //�� Ʈ���� ���� �ʺ� �켱 Ž���� �� �� [�湮 ó��]�� ���ʿ� �Ѵ�.
    while (!q.empty()) {
        long long currentNumber = q.front();
        q.pop();
        descNumbers.push_back(currentNumber);
        long long lastDigit = currentNumber%10LL;
        for (long long additionalDigit=0; additionalDigit<lastDigit; additionalDigit++) {
            long long nextNumber = currentNumber*10LL + additionalDigit;
            q.push(nextNumber);
        } //additionalDigit loop (currentNumber�� ������ ���ں��� ���� ���ڸ� ���ٿ��� �����ϴ� ���� ���� �� �ִ�.)
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

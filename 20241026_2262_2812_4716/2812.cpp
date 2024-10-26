#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;


int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    char str[500001];
    scanf("%s", str);
    deque<char> result;
    deque<char> input;

    //step a. str을 input에 넣는다.
    for (int i=0; i<N; i++)
        input.push_back(str[i]);

    int numRemovedDigits = 0;
    //step b. 차례에 맞게 input의 값을 result에 옮긴다.
    while (!input.empty()) {
        if (result.empty()) {
            result.push_back(input.front());
            input.pop_front();
            continue;
        }
        if (numRemovedDigits==K) { //이미 충분한 개수의 숫자가 지워진 경우-
            result.push_back(input.front());
            input.pop_front();
            continue;
        }
        char lastDigit = result.back();
        if (input.front()>lastDigit) { //이번에 넣을 숫자가 직전에 넣은 숫자보다 큰 경우, 직전에 넣은 숫자를 빼야 한다.
            result.pop_back();
            numRemovedDigits++;
            continue;
        } else {
            result.push_back(input.front());
            input.pop_front();
            continue;
        }
    } //while loop

    while (numRemovedDigits<K) { //아직 숫자가 충분하게 지워지지 않은 경우-
        result.pop_back();
        numRemovedDigits++;
    }

    while (!result.empty()) {
        printf("%c", result.front());
        result.pop_front();
    }

    return 0;
}

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

    //step a. str�� input�� �ִ´�.
    for (int i=0; i<N; i++)
        input.push_back(str[i]);

    int numRemovedDigits = 0;
    //step b. ���ʿ� �°� input�� ���� result�� �ű��.
    while (!input.empty()) {
        if (result.empty()) {
            result.push_back(input.front());
            input.pop_front();
            continue;
        }
        if (numRemovedDigits==K) { //�̹� ����� ������ ���ڰ� ������ ���-
            result.push_back(input.front());
            input.pop_front();
            continue;
        }
        char lastDigit = result.back();
        if (input.front()>lastDigit) { //�̹��� ���� ���ڰ� ������ ���� ���ں��� ū ���, ������ ���� ���ڸ� ���� �Ѵ�.
            result.pop_back();
            numRemovedDigits++;
            continue;
        } else {
            result.push_back(input.front());
            input.pop_front();
            continue;
        }
    } //while loop

    while (numRemovedDigits<K) { //���� ���ڰ� ����ϰ� �������� ���� ���-
        result.pop_back();
        numRemovedDigits++;
    }

    while (!result.empty()) {
        printf("%c", result.front());
        result.pop_front();
    }

    return 0;
}

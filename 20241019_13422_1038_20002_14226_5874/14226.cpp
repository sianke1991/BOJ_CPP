#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

// ��ǥ ���(ȭ�鿡 �ִ� �̸�Ƽ���� ������ ��ǥ ������ ���� ���)�� �����ϱ� ���� �ִ� ��θ� ã�� ����
// �׷����� �ʺ� �켱 Ž���� �����Ѵ�.
int main() {
    int targetNumber;
    scanf("%d", &targetNumber);
    queue<pair<int, int>> q; //q�� ���� ���� {ȭ�鿡 �ִ� �̸�Ƽ�� ����, Ŭ�����忡 �ִ� Ŭ������ ����}
    q.push({1, 0});
    set<pair<int, int>> s;
    s.insert({1, 0});
    int result = 0;

    while (!q.empty()) {
        int sz = q.size();
        for (int i=0; i<sz; i++) {
            int currentScreen = q.front().first;
            int currentClipboard = q.front().second;
            q.pop();
            if (currentScreen==targetNumber) {
                printf("%d", result);
                return 0;
            }

            //Ŭ������ ����
            pair<int, int> nextPair0 = {currentScreen, currentScreen};
            if (s.find(nextPair0)==s.end()) { //nextPair0�� ���� �湮���� ���� ���-
                s.insert(nextPair0);
                q.push(nextPair0);
            }
            //ȭ�� �ٿ��ֱ�
            pair<int, int> nextPair1 = {currentScreen+currentClipboard, currentClipboard};
            if (s.find(nextPair1)==s.end()) {
                s.insert(nextPair1);
                q.push(nextPair1);
            }
            //ȭ�� �̸�Ƽ�� �ϳ� ����
            if (currentScreen>0) {
                pair<int, int> nextPair2 = {currentScreen-1, currentClipboard};
                if (s.find(nextPair2)==s.end()) {
                    s.insert(nextPair2);
                    q.push(nextPair2);
                }
            }
        } //i loop
        result++;
    } //while loop

    return 0;
}

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

// 목표 노드(화면에 있는 이모티콘의 개수가 목표 개수와 같은 노드)에 도달하기 위한 최단 경로를 찾기 위해
// 그래프에 너비 우선 탐색을 적용한다.
int main() {
    int targetNumber;
    scanf("%d", &targetNumber);
    queue<pair<int, int>> q; //q에 들어가는 값은 {화면에 있는 이모티콘 개수, 클립보드에 있는 클립보드 개수}
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

            //클립보드 저장
            pair<int, int> nextPair0 = {currentScreen, currentScreen};
            if (s.find(nextPair0)==s.end()) { //nextPair0에 아직 방문하지 않은 경우-
                s.insert(nextPair0);
                q.push(nextPair0);
            }
            //화면 붙여넣기
            pair<int, int> nextPair1 = {currentScreen+currentClipboard, currentClipboard};
            if (s.find(nextPair1)==s.end()) {
                s.insert(nextPair1);
                q.push(nextPair1);
            }
            //화면 이모티콘 하나 삭제
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

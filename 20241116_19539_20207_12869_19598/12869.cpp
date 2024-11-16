#include <stdio.h>
#include <bits/stdc++.h>

/*
    더 높은 체력의 scv에게 더 높은 대미지를 주는 방식으로는
    해당 문제를 풀 수 없다.
    예외) 12, 10, 4 -> 3, 7, 3 -> 0, -2, 2 -> -3, -3, -7 (3 번 공격으로 전 scv를 죽일 수 있다고 판단하게 된다,)
    너비 우선 탐색을 사용하여 더 낮은 체력에 더 높은 대미지를 주는 방식도 고려할 수 있다.
    너비 우선 탐색에 사용할 노드는 세 scv가 가지고 있는 남은 체력이다.
    이 때 세 scv가 가지고 있는 남은 체력의 순서는 중요하지 않다,
    예) {1, 2, 3} 노드와 {3, 2, 1} 노드는 같은 것으로 간주할 수 있다.
    따라서 노드를 생성할 때 체력값을 정렬하는 방법을 사용할 수 있다.
    실제 게임에서는 뮤탈리스크가 죽은 scv를 더 이상 때리지 않지만,
    이 문제에서는 그 점을 고려할 필요는 없다.
*/

using namespace std;

int numScvs;
int hitPoints[3];

void input() {
    scanf("%d", &numScvs);
    for (int i=0; i<numScvs; i++)
        scanf("%d", &hitPoints[i]);
}

int max(int num0, int num1) {
    return num0 > num1 ? num0 : num1;
}

int min(int num0, int num1) {
    return num0 < num1 ? num0 : num1;
}

// 세 정수를 입력 받아 세 수를 내림차순 정렬한 결과를 tuple로 만들어 반환한다.
tuple<int, int, int> makeTuple(int num0, int num1, int num2) {
    int _max = max(max(num0, num1), num2);
    int _min = min(min(num0, num1), num2);
    int _mid = num0+num1+num2 - _max - _min;
    return {_max, _mid, _min};
}

int main() {
    input();
    tuple<int, int, int> initialTuple = makeTuple(hitPoints[0], hitPoints[1], hitPoints[2]);
    set<tuple<int, int, int>> visitedNodes;
    visitedNodes.insert(initialTuple);
    queue<tuple<int, int, int>> q;
    q.push(initialTuple);
    int result = 0;
    while (!q.empty()) {
        int sz = q.size();
        for (int i=0; i<sz; i++) {
            tuple<int, int, int> currentNode = q.front();
            q.pop();
            int hp0 = get<0>(currentNode);
            int hp1 = get<1>(currentNode);
            int hp2 = get<2>(currentNode);
            //printf("%d %d %d\n", hp0, hp1, hp2);
            if (hp0<=0) { //가장 체력이 많은 scv가 0 이하로 떨어진 경우-
                printf("%d", result);
                return 0;
            }
            tuple<int, int, int> nextNode = makeTuple(hp0-9, hp1-3, hp2-1);
            if (visitedNodes.find(nextNode)==visitedNodes.end()) {
                visitedNodes.insert(nextNode);
                q.push(nextNode);
            }
            nextNode = makeTuple(hp0-9, hp1-1, hp2-3);
            if (visitedNodes.find(nextNode)==visitedNodes.end()) {
                visitedNodes.insert(nextNode);
                q.push(nextNode);
            }
            nextNode = makeTuple(hp0-3, hp1-9, hp2-1);
            if (visitedNodes.find(nextNode)==visitedNodes.end()) {
                visitedNodes.insert(nextNode);
                q.push(nextNode);
            }
            nextNode = makeTuple(hp0-3, hp1-1, hp2-9);
            if (visitedNodes.find(nextNode)==visitedNodes.end()) {
                visitedNodes.insert(nextNode);
                q.push(nextNode);
            }
            nextNode = makeTuple(hp0-1, hp1-9, hp2-3);
            if (visitedNodes.find(nextNode)==visitedNodes.end()) {
                visitedNodes.insert(nextNode);
                q.push(nextNode);
            }
            nextNode = makeTuple(hp0-1, hp1-3, hp2-9);
            if (visitedNodes.find(nextNode)==visitedNodes.end()) {
                visitedNodes.insert(nextNode);
                q.push(nextNode);
            }
        } //i loop
        result++;
    } //while loop

    return 0;
}

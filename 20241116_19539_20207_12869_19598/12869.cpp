#include <stdio.h>
#include <bits/stdc++.h>

/*
    �� ���� ü���� scv���� �� ���� ������� �ִ� ������δ�
    �ش� ������ Ǯ �� ����.
    ����) 12, 10, 4 -> 3, 7, 3 -> 0, -2, 2 -> -3, -3, -7 (3 �� �������� �� scv�� ���� �� �ִٰ� �Ǵ��ϰ� �ȴ�,)
    �ʺ� �켱 Ž���� ����Ͽ� �� ���� ü�¿� �� ���� ������� �ִ� ��ĵ� ����� �� �ִ�.
    �ʺ� �켱 Ž���� ����� ���� �� scv�� ������ �ִ� ���� ü���̴�.
    �� �� �� scv�� ������ �ִ� ���� ü���� ������ �߿����� �ʴ�,
    ��) {1, 2, 3} ���� {3, 2, 1} ���� ���� ������ ������ �� �ִ�.
    ���� ��带 ������ �� ü�°��� �����ϴ� ����� ����� �� �ִ�.
    ���� ���ӿ����� ��Ż����ũ�� ���� scv�� �� �̻� ������ ������,
    �� ���������� �� ���� ����� �ʿ�� ����.
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

// �� ������ �Է� �޾� �� ���� �������� ������ ����� tuple�� ����� ��ȯ�Ѵ�.
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
            if (hp0<=0) { //���� ü���� ���� scv�� 0 ���Ϸ� ������ ���-
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

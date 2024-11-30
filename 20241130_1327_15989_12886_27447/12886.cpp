#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int max(int num0, int num1) {
    return num0 > num1 ? num0 : num1;
}

int min(int num0, int num1) {
    return num0 < num1 ? num0 : num1;
}

// 세 수를 입력 받아
// 큰 수에서 작은 수로 정렬된 tuple를 생성한다.
tuple<int, int,int> makeTuple(int num0, int num1, int num2) {
    int _max = max(max(num0, num1), num2);
    int _min = min(min(num0, num1), num2);
    int _mid = num0 + num1 + num2 - _max - _min;
    return {_max, _mid, _min};
}

//입력받은 상태에서 다음 단계 목록을 반환한다.
vector<tuple<int, int, int>> adjNodesOf(tuple<int, int, int> node) {
    vector<tuple<int, int,int>> result;
    int _max = get<0>(node);
    int _mid = get<1>(node);
    int _min = get<2>(node);
    //_max와 _mid간의 교환
    result.push_back(makeTuple(
                     _max-_mid,
                     _mid+_mid,
                     _min
    ));
    //_max와 _min간의 교환
    result.push_back(makeTuple(
                    _max-_min,
                    _mid,
                    _min+_min
    ));
    //_mid와 _min간의 교환
    result.push_back(makeTuple(
                    _max,
                    _mid-_min,
                    _min+_min

    ));
    return result;
}


int main() {
    int num0, num1, num2;
    scanf("%d %d %d", &num0, &num1, &num2);
    tuple<int, int, int> initNode = makeTuple(num0, num1, num2);
    set<tuple<int, int, int>> visitedNodes;
    queue<tuple<int, int, int>> q;
    visitedNodes.insert(initNode);
    q.push(initNode);
    while (!q.empty()) {
        tuple<int, int, int> currentNode = q.front();
        q.pop();
        if (get<0>(currentNode) == get<2>(currentNode)) { //현재 가장 작은 그룹과 가장 큰 그룹이 동일하다면-
            printf("1");
            return 0;
        }
        for (auto nextNode:adjNodesOf(currentNode)) {
            if (visitedNodes.find(nextNode)==visitedNodes.end()) {
                visitedNodes.insert(nextNode);
                q.push(nextNode);
            }
        } //nextNode loop
    } //while loop
    printf("0");
    return 0;
}

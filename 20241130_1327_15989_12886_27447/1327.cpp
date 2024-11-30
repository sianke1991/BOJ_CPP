#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

void print(vector<int> v) {
    printf("[");
    for (int i=0, lim=v.size()-1; i<lim; i++) {
        printf("%d ", v[i]);
    }
    printf("%d]", v[v.size()-1]);
}

//전체 순열의 길이
int N;
//한 번에 뒤집어야 하는 수의 개수
int K;
//뒤집기 전 배열
vector<int> originalArray;

vector<int> rev(vector<int> arr, int initIndex, int length) {
    vector<int> result = arr;
    for (int i=initIndex, lim=initIndex+length/2; i<lim; i++) {
        int j = 2*initIndex+length-1-i;
        int tmp = result[i];
        result[i] = result[j];
        result[j] = tmp;
    } //i loop
    return result;
}

bool checkSort(vector<int> arr) {
    for (int i=0, lim=arr.size()-1; i<lim; i++) {
        if (arr[i]>arr[i+1])
            return false;
    }
    return true;
}


int main() {
    scanf("%d %d", &N, &K);
    for (int i=0; i<N; i++) {
        int elem;
        scanf("%d", &elem);
        originalArray.push_back(elem);
    }


    set<vector<int>> visitedNodes;
    queue<vector<int>> q;
    visitedNodes.insert(originalArray);
    q.push(originalArray);
    int result = 0;
    while (!q.empty()) {
        int sz = q.size();
        for (int i=0; i<sz; i++) {
            vector<int> currentNode = q.front();
            //print(currentNode);
            //puts("");
            q.pop();
            if (checkSort(currentNode)) {
                printf("%d", result);
                return 0;
            }
            for (int initIndex=0; initIndex<=N-K; initIndex++) {
                vector<int> nextNode = rev(currentNode, initIndex, K);
                if (visitedNodes.find(nextNode)==visitedNodes.end()) {
                    visitedNodes.insert(nextNode);
                    q.push(nextNode);
                }
            } //initIndex loop
        } //i loop
        result++;
    } //while loop
    printf("-1");
    return 0;
}

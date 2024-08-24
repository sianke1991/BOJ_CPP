#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

bool isNotPrime[10001] = {true, true};
vector<int> primes;

//1000 이상 10000 미만의 소수를 구해서 primes에 넣는다.
void getPrimes() {
    for (int i=2; i<100; i++) {
        if (isNotPrime[i]) continue;
        for (int j=2*i; j<10000; j+=i) isNotPrime[j] = true;
    } //i loop
    for (int i=1000; i<10000; i++) {
        if (!isNotPrime[i]) primes.push_back(i);
    }
}

//인접 리스트: 네자리 소수에 대해서 숫자 하나를 바꿔 만들 수 있는 다른 네 자리 소수 목록
vector<int> adjList[10001];

//네자리 자연수 두 개를 입력 받아 숫자가 정확하게 하나 차이가 나는지 여부를 반환한다.
//num0 에서 숫자 하나를 바꿔 num1을 만들 수 있는지 여부를 반환한다.
bool checkConnectivityOf(int num0, int num1) {
    int diff = 0;
    for (int i=0; i<4; i++) {
        if (num0%10 != num1%10) diff++;
        num0/=10;
        num1/=10;
    }
    return diff==1;
}

//인접 리스트 구성
void getAdjList() {
    int sz = primes.size();
    for (int i=0; i<sz; i++) {
        for (int j=i+1; j<sz; j++) {
            if (checkConnectivityOf(primes[i], primes[j])) {
                adjList[primes[i]].push_back(primes[j]);
                adjList[primes[j]].push_back(primes[i]);
            }
        } //j loop
    } //i loop
}

//너비 우선 탐색
//from 에서 to로 가기 위해 필요한 변경 횟수를 구해서 반환한다.
//from 에서 to로 갈 수 없는 경우 -1을 반환한다.
int bfs(int from, int to) {
    bool visited[10000] = {false};
    visited[from] = true;
    queue<int> q;
    q.push(from);
    int result = 0;
    while (!q.empty()) {
        int sz = q.size();
        for (int i=0; i<sz; i++) {
            int currentNode = q.front();
            q.pop();
            if (currentNode==to) return result;
            for (int nextNode:adjList[currentNode]) {
                if (visited[nextNode]) continue;
                visited[nextNode] = true;
                q.push(nextNode);
            } //nextNode loop
        } //i loop
        result++;
    } //while loop
    return -1;
}

int main() {
    getPrimes();
    getAdjList();

    //테스트 케이스 입력 받기
    int numTestCases;
    scanf("%d", &numTestCases);
    vector<pair<int, int>> queries;
    for (int i=0; i<numTestCases; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        queries.push_back({from, to});
    } //i loop

    //각 테스트 케이스에 대해서 너비 우선 탐색 사용
    vector<int> results;
    for (auto query:queries) {
        results.push_back(bfs(query.first, query.second));
    } //query loop

    //탐색의 결과 출력
    for (int elem:results) {
        if (elem>=0) printf("%d\n", elem);
        else printf("Impossible\n");
    }
    return 0;
}

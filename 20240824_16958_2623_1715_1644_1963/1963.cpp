#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

bool isNotPrime[10001] = {true, true};
vector<int> primes;

//1000 �̻� 10000 �̸��� �Ҽ��� ���ؼ� primes�� �ִ´�.
void getPrimes() {
    for (int i=2; i<100; i++) {
        if (isNotPrime[i]) continue;
        for (int j=2*i; j<10000; j+=i) isNotPrime[j] = true;
    } //i loop
    for (int i=1000; i<10000; i++) {
        if (!isNotPrime[i]) primes.push_back(i);
    }
}

//���� ����Ʈ: ���ڸ� �Ҽ��� ���ؼ� ���� �ϳ��� �ٲ� ���� �� �ִ� �ٸ� �� �ڸ� �Ҽ� ���
vector<int> adjList[10001];

//���ڸ� �ڿ��� �� ���� �Է� �޾� ���ڰ� ��Ȯ�ϰ� �ϳ� ���̰� ������ ���θ� ��ȯ�Ѵ�.
//num0 ���� ���� �ϳ��� �ٲ� num1�� ���� �� �ִ��� ���θ� ��ȯ�Ѵ�.
bool checkConnectivityOf(int num0, int num1) {
    int diff = 0;
    for (int i=0; i<4; i++) {
        if (num0%10 != num1%10) diff++;
        num0/=10;
        num1/=10;
    }
    return diff==1;
}

//���� ����Ʈ ����
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

//�ʺ� �켱 Ž��
//from ���� to�� ���� ���� �ʿ��� ���� Ƚ���� ���ؼ� ��ȯ�Ѵ�.
//from ���� to�� �� �� ���� ��� -1�� ��ȯ�Ѵ�.
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

    //�׽�Ʈ ���̽� �Է� �ޱ�
    int numTestCases;
    scanf("%d", &numTestCases);
    vector<pair<int, int>> queries;
    for (int i=0; i<numTestCases; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        queries.push_back({from, to});
    } //i loop

    //�� �׽�Ʈ ���̽��� ���ؼ� �ʺ� �켱 Ž�� ���
    vector<int> results;
    for (auto query:queries) {
        results.push_back(bfs(query.first, query.second));
    } //query loop

    //Ž���� ��� ���
    for (int elem:results) {
        if (elem>=0) printf("%d\n", elem);
        else printf("Impossible\n");
    }
    return 0;
}

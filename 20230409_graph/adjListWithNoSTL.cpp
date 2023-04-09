#include <bits/stdc++.h>

using namespace std;

int edge[10][2]; //���� ���� (edge[x][0]: x ��° ������ ��� ���, edge[x][1]: x ��° ������ ���� ���)
int deg[10]; //�� ������ outdegree
int* adj[10]; //adj[x]: ��� x���� ����ϴ� ������ ����
int idx[10]; //adj[i] ���� ���ο� ������ �߰��� ���� ��ġ

int main() {
    int v, e;
    cin >> v >> e;
    for (int i=0; i<e; i++) {
        cin >> edge[i][0] >> edge[i][1];
        deg[edge[i][0]]++; //�� ��忡 ���� �ʿ��� �迭�� ũ�⸦ ����Ѵ�.
    } //i loop

    for (int i=1; i<=v; i++)
        adj[i] = new int[deg[i]]; //�� ��忡 ���� �ʿ��� ũ���� �迭�� �����Ѵ�.
    for (int i=0; i<e; i++) {
        int u = edge[i][0], v = edge[i][1];
        adj[u][idx[u]] = v; //idx[u]�� 0���� �����ؼ� 1�� �����Ѵ�.
        idx[u]++;
    } //i loop (��� ���)
    return 0;
}

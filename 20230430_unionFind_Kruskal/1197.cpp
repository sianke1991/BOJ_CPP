#include <bits/stdc++.h>
using namespace std;

tuple<long long, int, int> edgesInGraph[100005]; //�׷����� �ִ� ����
//pair<int, int> edgesInMST[10000]; //�ּ� ���� Ʈ���� �ִ� ����
int parentOf[100005]; //�ּ� ���� Ʈ���� ���Ե� ������ ���� ���踦 ������ �迭

/**
 * ����� ����� ����Ͽ� �Է¹��� ����� ��Ʈ ��带 ã�´�.
 * Ư�� ��忡 ���� ���� ���� �θ� ��尡 ���� �� ���� �θ� ã�� ���� �ö󰣴�.
 */
int rootOf(int node) {
    if (parentOf[node]==node) {
        return node;
    } else {
        return rootOf(parentOf[node]);
    }
}

/**
 * �� ��带 �Է¹޾�,
 * �� ��尡 �̾��� �ִٸ� false�� ��ȯ�Ѵ�.
 * �� ��尡 �̾��� ���� ������ �� ��尡 ����ǵ��� ó�� �� true�� ��ȯ�Ѵ�.
 * �� ��尡 ����ǵ��� ó���ϱ� ���ؼ� �� ����� ��Ʈ ��� �� ģ�� ���踦 �δ´�.
 * (�� ��尣�� ģ�� ���踦 ���� �ʿ� ����, �� ����� ��Ʈ ��尣�� ģ�� ���踦 �δ´�.)
 *  => �� ó���� �ϸ� ���Ŀ� �� ����� ��Ʈ ���� �����ϰ� �ȴ�.
 */
bool areDifferentGroup(int nodeA, int nodeB) {
    int rootNodeA = rootOf(nodeA);
    int rootNodeB = rootOf(nodeB);
    if (rootNodeA==rootNodeB) return false; //�� ��尡 ����� ���-
    if (rootNodeA<=rootNodeB) {
        parentOf[rootNodeB] = rootNodeA; //�� ��尡 ������� ���� ��� ���� ó��-
    } else {
        parentOf[rootNodeA] = rootNodeB; //�� ��尡 ������� ���� ��� ���� ó��-
    }
    return true;
}

int main() {
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;
    for (int i=1; i<=numEdges; i++) {
        parentOf[i] = i; //���ʿ� �ּ� ���� Ʈ���� ������ �����Ƿ� �� ����� �θ�� �ڱ� �ڽ��� �ȴ�.
    }
    for (int i=0; i<numEdges; i++) {
        int nodeA, nodeB;
        long long weight;
        cin >> nodeA >> nodeB >> weight;
        edgesInGraph[i] = {weight, nodeA, nodeB};
    }
    sort(edgesInGraph, edgesInGraph+numEdges);
    long long MSTweight = 0; //�ּ� ���� Ʈ�� ����ġ
    int numSelectedEdges = 0; //���� �ּ� ���� Ʈ���� �� ������ ����

    for (int i=0; i<numEdges; i++) {
        tuple<long long, int, int> currentEdge = edgesInGraph[i];
        int currentNodeA = get<1>(currentEdge); //�̹��� ���� ������ �����ϴ� �� ��� �� �ϳ� (tuple���� Ư�� ��ġ�� ���� ������ ���� get<idx> �Լ��� ����Ѵ�.)
        int currentNodeB = get<2>(currentEdge); //�̹��� ���� ������ �����ϴ� �� ��� �� �ϳ�
        long long currentWeight = get<0>(currentEdge); //�̹��� ���� ������ ����ġ
        if (areDifferentGroup(currentNodeA, currentNodeB)) { //�̹��� ���� ������ �����ϴ� �� ��尡 [���� ������� ���� ���]�� ���
            MSTweight+=currentWeight; //�ش� ������  MST�� ���Խ�Ų��.
            numSelectedEdges++;
        }
        if (numSelectedEdges==numNodes-1) break; //MST�� ���Ե� ������ ������ (��尳��-1)�� �����ϸ� �ݺ��� �����Ѵ�.
    }

    cout << MSTweight;
    return 0;
}

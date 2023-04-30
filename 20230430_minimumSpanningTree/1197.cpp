#include <bits/stdc++.h>
using namespace std;

tuple<long long, int, int> edgesInGraph[100005]; //�׷����� �ִ� ����
//pair<int, int> edgesInMST[10000]; //�ּ� ���� Ʈ���� �ִ� ����
int parentOf[100005]; //�ּ� ���� Ʈ���� ���Ե� ������ ���� ���踦 ������ �迭
int rootOf[100005]; //�ּ� ���� Ʈ���� ���Ե� �� ����� ������ ������ �迭

int getRootOf(int node) {
    if (parentOf[node]==node) {
        return node;
    } else {
        return parentOf[node];
    }
}

bool areSameGroup(int nodeA, int nodeB) {
    int rootNodeA = getRootOf(nodeA);
    rootOf[nodeA] = rootNodeA;
    int rootNodeB = getRootOf(nodeB);
    rootOf[nodeB] = rootNodeB;
    return rootNodeA==rootNodeB;
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
        tuple<int, int, int> currentEdge = edgesInGraph[i];
        int currentNodeA = get<1>(currentEdge); //�̹��� ���� ������ �����ϴ� �� ��� �� �ϳ� (tuple���� Ư�� ��ġ�� ���� ������ ���� get<idx> �Լ��� ����Ѵ�.)
        int currentNodeB = get<2>(currentEdge); //�̹��� ���� ������ �����ϴ� �� ��� �� �ϳ�
        long long currentWeight = get<0>(currentEdge); //�̹��� ���� ������ ����ġ
        if (!(areSameGroup(currentNodeA, currentNodeB))) { //�̹��� ���� ������ �����ϴ� �� ��尡 [���� ������� ���� ����� ���]
            MSTweight+=currentWeight; //�ش� ������  MST�� ���Խ�Ű��-
            numSelectedEdges++;
            int rootNodeA = rootOf[currentNodeA];
            int rootNodeB = rootOf[currentNodeB];
            if (rootNodeA<=rootNodeB) {
                parentOf[currentNodeB] = currentNodeA; //�ش� �� ���� ģ�� ���踦 �δ´�.
            } else {
                parentOf[currentNodeA] = currentNodeB; //�ش� �� ���� ģ�� ���踦 �δ´�.
            }

            //parentOf[max(currentNodeA, currentNodeB)] = min(currentNodeA, currentNodeB); //�ش� �� ���� ģ�� ���踦 �δ´�.
        }
        if (numSelectedEdges==numNodes-1) break; //MST�� ���Ե� ������ ������ (��尳��-1)�� �����ϸ� �ݺ��� �����Ѵ�.
    }

    cout << MSTweight;
    return 0;
}

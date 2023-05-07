#include <bits/stdc++.h>

using namespace std;

/*
���� ��� ���� 4���� �ִٰ� �Ѵٸ�, 4���� �� [�칰] 1���� �����Ͽ�
�� 5���� ��尡 �ִ� �׷����� �����Ѵ�.
��� ���� ��, ���������� �칰�� ����Ǹ� ��� �� ���� ������ ���̴�.
���� �� ��� �� �칰 ���� �̷���� �׷����� MST�� �����ϸ� ��� �� ���� ��� ���� �ּ� ����� ���� �� �ִ�.
*/

vector<tuple<long long, int, int>> edges; //�׷����� �ִ� ���� {���, ��߳��, �������}
int parentOf[301]; //�ּ� ���� Ʈ���� ���Ե� ������ ���� ���踦 ������ �迭

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
    int numPaddies; //���� ���� (���� ����ϴ� �׷����� ��� ������ numPaddies+1�̴�.
    cin >> numPaddies;
    //���ʿ� �ּ� ���� Ʈ���� ������ �����Ƿ� �� ����� �θ�� �ڱ� �ڽ��� �ȴ�.
    for (int i=0; i<=numPaddies; i++) {
        parentOf[i] = i;
    }
    //�칰�� �ı� ���� �ʿ��� ����� edges�� ���´�.
    for (int i=1; i<=numPaddies; i++) {
        int price;
        cin >> price;
        edges.push_back({price, i, 0});
        edges.push_back({price, 0, i});
    }

    for (int i=1; i<=numPaddies; i++) {
        for (int j=1; j<=numPaddies; j++) {
            int price;
            cin >> price;
            if (i==j) continue;
            edges.push_back({price, i, j});
        } //j loop, ������� ����
    } //i loop, ��߳�� ����

    sort(edges.begin(), edges.end());
    long long sumWeight = 0; //�ּ� ���� Ʈ�� ����ġ
    int numSelectedEdges = 0; //���� �ּ� ���� Ʈ���� �� ������ ����

    for (tuple<long long, int, int> e:edges) {
        int currentNodeA = get<1>(e); //�̹��� ���� ������ �����ϴ� �� ��� �� �ϳ� (tuple���� Ư�� ��ġ�� ���� ������ ���� get<idx> �Լ��� ����Ѵ�.)
        int currentNodeB = get<2>(e); //�̹��� ���� ������ �����ϴ� �� ��� �� �ϳ�
        long long currentWeight = get<0>(e); //�̹��� ���� ������ ����ġ
        if (areDifferentGroup(currentNodeA, currentNodeB)) { //�̹��� ���� ������ �����ϴ� �� ��尡 [���� ������� ���� ���]�� ���
            sumWeight+=currentWeight;
            numSelectedEdges++;
        }
        if (numSelectedEdges==numPaddies) break; //�ּ� ���� Ʈ���� numPaddies ������ ������ ���� �ݺ��� �����Ѵ�.
                                                //(�׷������� (numPaddies+1) ��ŭ�� ��尡 �����Ƿ� ������ �ּ� ���� Ʈ������ numPaddies ��ŭ�� ������ ���� �Ѵ�.)
    }
    cout << sumWeight;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

/*
���� ��� ���� 4���� �ִٰ� �Ѵٸ�, 4���� �� [�칰] 1���� �����Ͽ�
�� 5���� ��尡 �ִ� �׷����� �����Ѵ�.
��� ���� ��, ���������� �칰�� ����Ǹ� ��� �� ���� ������ ���̴�.
���� �� ��� �� �칰 ���� �̷���� �׷����� MST�� �����ϸ� ��� �� ���� ��� ���� �ּ� ����� ���� �� �ִ�.
*/

int main() {
    int numPaddies; //���� ���� (���� ����ϴ� �׷����� ��� ������ numPaddies+1�̴�.
    cin >> numPaddies;
    vector<pair<int, int>> adjList[301]; //���� ����Ʈ {���, �������}
    for (int i=1; i<=numPaddies; i++) { //i ��° �� ���� ��� ����� i��° ���� 0��° ��� ������ ���� ����.
        int price;
        cin >> price;
        adjList[i].push_back({price, 0});
        adjList[0].push_back({price, i});
    }
    for (int i=1; i<=numPaddies; i++) {
        for (int j=1; j<=numPaddies; j++) {
            int price;
            cin >> price;
            if (i==j) continue; //�׷������� �� �ڸ��� ���ƿ��� ������ ���� ����Ʈ�� ����� �ʿ䰡 ����.
            adjList[i].push_back({price, j}); //�� ������ �� �� �Է��� �ֹǷ� �� �ܰ迡�� ���� j��� i���� ������ ���� �ʿ䰡 ����.
        } //j loop (������� ����)
    } //i loop (��߳�� ����)

    bool isNodeSelected[301]; //�ش� ��尡 MST�� ���ԵǾ����� ����
    for (int i=0; i<301; i++) isNodeSelected[i] = false;
    //{���, ��߳��, �������}
    priority_queue< tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > pq;
    int numSelectedEdges = 0;
    long long sumPrices = 0;

    isNodeSelected[0] = true;
    for (pair<int, int> e:adjList[0]) {
        pq.push({e.first, 0, e.second});
    }

    while (numSelectedEdges<numPaddies) { //�׷������� ����� ������ numPaddies+1�̹Ƿ�, MST�� ����ִ� ������ ������ numPaddies�� �Ǿ�� �Ѵ�.
        tuple<int, int, int> selectedEdge = pq.top();
        pq.pop();
        if (isNodeSelected[get<2>(selectedEdge)]) continue; //������ ������ [�̹� MST�� ����� ��带 ���ϴ�] ������ ���-
        isNodeSelected[get<2>(selectedEdge)] = true;
        numSelectedEdges++;
        sumPrices += get<0>(selectedEdge);
        //cout << get<0>(selectedEdge) << ' ' << get<1>(selectedEdge) << ' ' << get<2>(selectedEdge) << '\n';

        for (pair<int, int> e:adjList[get<2>(selectedEdge)]) {
            //if (isNodeSelected[get<2>(selectedEdge)]) continue;
            pq.push({e.first, get<2>(selectedEdge), e.second});
        }
    }
    cout << sumPrices;
    return 0;
}

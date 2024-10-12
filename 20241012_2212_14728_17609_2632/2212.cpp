#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

// ���� ����
int numSensors;
// ������ ����
int numBaseStations;
// ���� ��ġ
vector<int> sensors;

void input() {
    scanf("%d", &numSensors);
    scanf("%d", &numBaseStations);
    for (int i=0; i<numSensors; i++) {
        int loc;
        scanf("%d", &loc);
        sensors.push_back(loc);
    }
}

int main() {
    input();
    //���߱� ������ ���� �������� ������
    //�� ���� ���� ���߱��� ��ġ�� �� �ִ�.
    //�켱���� ť���� ���Ҹ� �� ���� ���ϴ� ��쿡 ����ϱ� ����
    if (numBaseStations>=numSensors) {
        printf("0");
        return 0;
    }
    //������ ��ġ�� �����Ͽ�
    //�̿��� �� ������ ������ ���� �� �ְ� �����.
    sort(sensors.begin(), sensors.end());
    int total_dist = sensors[numSensors-1]-sensors[0];
    //�̿��� ���� �� ������ ��� �켱���� ť
    priority_queue<int> pq;
    for (int i=0, lim=numSensors-1; i<lim; i++)
        pq.push(sensors[i+1]-sensors[i]);
    //�켱���� ť���� (������ ����-1) �� ��ŭ�� ���Ҹ� �̾Ƽ�
    //total_dist���� �� ���� �� �ش�.
    for (int i=0, lim=numBaseStations-1; i<lim; i++) {
        int elem = pq.top();
        pq.pop();
        total_dist -= elem;
    }
    printf("%d", total_dist);
    return 0;
}

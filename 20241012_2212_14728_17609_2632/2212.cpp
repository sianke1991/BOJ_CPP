#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

// 센서 개수
int numSensors;
// 기지국 개수
int numBaseStations;
// 센서 위치
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
    //집중국 개수가 센서 개수보다 많으면
    //각 센서 마다 집중국을 배치할 수 있다.
    //우선순위 큐에서 원소를 빼 내지 못하는 경우에 대비하기 위함
    if (numBaseStations>=numSensors) {
        printf("0");
        return 0;
    }
    //센서의 위치를 정렬하여
    //이웃한 두 센서의 간격을 구할 수 있게 만든다.
    sort(sensors.begin(), sensors.end());
    int total_dist = sensors[numSensors-1]-sensors[0];
    //이웃한 센서 간 간격을 담는 우선순위 큐
    priority_queue<int> pq;
    for (int i=0, lim=numSensors-1; i<lim; i++)
        pq.push(sensors[i+1]-sensors[i]);
    //우선순위 큐에서 (기지국 개수-1) 개 만큼의 원소를 뽑아서
    //total_dist에서 그 값을 빼 준다.
    for (int i=0, lim=numBaseStations-1; i<lim; i++) {
        int elem = pq.top();
        pq.pop();
        total_dist -= elem;
    }
    printf("%d", total_dist);
    return 0;
}

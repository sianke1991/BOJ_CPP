#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

//전자기기 사용 순서
int deviceHistory[102];
//멀티탭에 연결된 전자기기
set<int> hole;
//전자기기를 사용할 타이밍을 정리해 놓은 행렬
int deviceMatrix[102][102];

string toString(set<int> hole) {
    string result = "{";
    for (int elem:hole) {
        result += to_string(elem) + ", ";
    }
    result = result.substr(0, result.length()-2);
    result += "}";
    return result;
}

int main() {
    int numHoles, numDevices;
    scanf("%d %d", &numHoles, &numDevices);
    for (int i=0; i<numDevices; i++) {
        int device;
        scanf("%d", &device);
        deviceHistory[i] = device;
    }

    //기기 행렬의 마지막 행 초기화
    for (int col=1; col<=numDevices; col++)
        deviceMatrix[numDevices][col] = numDevices;

    //행 번호를 1씩 줄여나가면서 기기 행렬을 채워 나감
    for (int row=numDevices-1; row>=0; row--) {
        for (int col=1; col<=numDevices; col++)
            deviceMatrix[row][col] = deviceMatrix[row+1][col];
        int device = deviceHistory[row];
        deviceMatrix[row][device] = row;
    } //row loop

    int numPops = 0;
    for (int time=0; time<numDevices; time++) {
        int deviceWillBeUsed = deviceHistory[time];
        if (hole.size()<numHoles || hole.find(deviceWillBeUsed)!=hole.end()) { //멀티탭에 구멍이 남아있거나, 이미 멀티탭에 연결된 전자기기를 사용하는 경우 전자기기를 제거할 필요가 없다.
            hole.insert(deviceWillBeUsed);
            //cout << "time: " << time << ", hole: " << toString(hole) << "\n";
            continue;
        }
        //멀티탭이 만원일 경우 멀티탭에 연결된 전자기기 중 하나를 제거해야 한다.
        int deviceWillBeRemoved = -1, deviceIndex = -1;
        for (int deviceUsing:hole) {
            if (deviceMatrix[time][deviceUsing]>deviceIndex) {
                deviceIndex = deviceMatrix[time][deviceUsing];
                deviceWillBeRemoved = deviceUsing;
            }
        }
        hole.erase(deviceWillBeRemoved); //현재 사용 중인 전자기기 중에서 가장 나중에 (다시) 사용할 전자기기를 제거한다.
        numPops++;
        hole.insert(deviceWillBeUsed);
        //cout << "time: " << time << ", hole: " << toString(hole) << "\n";
    }

    printf("%d", numPops);
    return 0;
}

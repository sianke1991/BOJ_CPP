#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

//���ڱ�� ��� ����
int deviceHistory[102];
//��Ƽ�ǿ� ����� ���ڱ��
set<int> hole;
//���ڱ�⸦ ����� Ÿ�̹��� ������ ���� ���
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

    //��� ����� ������ �� �ʱ�ȭ
    for (int col=1; col<=numDevices; col++)
        deviceMatrix[numDevices][col] = numDevices;

    //�� ��ȣ�� 1�� �ٿ������鼭 ��� ����� ä�� ����
    for (int row=numDevices-1; row>=0; row--) {
        for (int col=1; col<=numDevices; col++)
            deviceMatrix[row][col] = deviceMatrix[row+1][col];
        int device = deviceHistory[row];
        deviceMatrix[row][device] = row;
    } //row loop

    int numPops = 0;
    for (int time=0; time<numDevices; time++) {
        int deviceWillBeUsed = deviceHistory[time];
        if (hole.size()<numHoles || hole.find(deviceWillBeUsed)!=hole.end()) { //��Ƽ�ǿ� ������ �����ְų�, �̹� ��Ƽ�ǿ� ����� ���ڱ�⸦ ����ϴ� ��� ���ڱ�⸦ ������ �ʿ䰡 ����.
            hole.insert(deviceWillBeUsed);
            //cout << "time: " << time << ", hole: " << toString(hole) << "\n";
            continue;
        }
        //��Ƽ���� ������ ��� ��Ƽ�ǿ� ����� ���ڱ�� �� �ϳ��� �����ؾ� �Ѵ�.
        int deviceWillBeRemoved = -1, deviceIndex = -1;
        for (int deviceUsing:hole) {
            if (deviceMatrix[time][deviceUsing]>deviceIndex) {
                deviceIndex = deviceMatrix[time][deviceUsing];
                deviceWillBeRemoved = deviceUsing;
            }
        }
        hole.erase(deviceWillBeRemoved); //���� ��� ���� ���ڱ�� �߿��� ���� ���߿� (�ٽ�) ����� ���ڱ�⸦ �����Ѵ�.
        numPops++;
        hole.insert(deviceWillBeUsed);
        //cout << "time: " << time << ", hole: " << toString(hole) << "\n";
    }

    printf("%d", numPops);
    return 0;
}

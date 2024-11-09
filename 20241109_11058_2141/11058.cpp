#include <stdio.h>
#include <bits/stdc++.h>
#define TEXT_LENGTH first
#define BUFF_LENGTH second

using namespace std;

priority_queue<pair<long long, long long>> pq[101]; //{ȭ�鿡 �ִ� ���ڿ��� ����, ���ۿ� ��� ���ڿ��� ����} ������ ��� �켱���� ť (�ִ���)
int maxNumInputs;

long long max(long long num0, long long num1) {
    return num0 > num1 ? num0 : num1;
}

int main() {
    scanf("%d", &maxNumInputs);
    pq[0].push({0, 0}); //0�� �Է��� ������ {0, 0} ���¸��� �����ϴ�.
    for (int numInputs=0; numInputs<maxNumInputs; numInputs++) {
        //printf("numInputs: %d\n", numInputs);
        long long maxBuffLength = -1LL;
        while (!pq[numInputs].empty()) {
            pair<long long, long long> currentState = pq[numInputs].top();
            pq[numInputs].pop();
            if (currentState.BUFF_LENGTH<=maxBuffLength) continue; //�������� ���� ���¿� ���ؼ��� ������ ġ�� �ʴ´�.
                                                                    //�켱���� ť���� �� ���߿� ������ ���°� ������ ���� �����Ƿ� break ��� continue�� ����Ѵ�.
            maxBuffLength = currentState.BUFF_LENGTH;
            pq[numInputs+1].push({currentState.TEXT_LENGTH+1, currentState.BUFF_LENGTH}); //ȭ�鿡 A�� �߰��ϴ� �Է�
            pq[numInputs+1].push({currentState.TEXT_LENGTH+currentState.BUFF_LENGTH, currentState.BUFF_LENGTH}); //ȭ�鿡 �ٿ��ֱ� �ϴ� �Է�
            if (numInputs<maxNumInputs-1)
                pq[numInputs+2].push({currentState.TEXT_LENGTH, currentState.TEXT_LENGTH}); //ȭ���� ������ �����ϴ� �Է�
        } //while loop
    } //numInputs loop (�Է� Ƚ���� ���� �ݺ�)

    printf("%lld", pq[maxNumInputs].top().TEXT_LENGTH);
    return 0;
}



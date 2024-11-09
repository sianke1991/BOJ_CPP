#include <stdio.h>
#include <bits/stdc++.h>
#define TEXT_LENGTH first
#define BUFF_LENGTH second

using namespace std;

priority_queue<pair<long long, long long>> pq[101]; //{화면에 있는 문자열의 길이, 버퍼에 담긴 문자열의 길이} 정보를 담는 우선순위 큐 (최대힙)
int maxNumInputs;

long long max(long long num0, long long num1) {
    return num0 > num1 ? num0 : num1;
}

int main() {
    scanf("%d", &maxNumInputs);
    pq[0].push({0, 0}); //0번 입력할 때에는 {0, 0} 상태만이 가능하다.
    for (int numInputs=0; numInputs<maxNumInputs; numInputs++) {
        //printf("numInputs: %d\n", numInputs);
        long long maxBuffLength = -1LL;
        while (!pq[numInputs].empty()) {
            pair<long long, long long> currentState = pq[numInputs].top();
            pq[numInputs].pop();
            if (currentState.BUFF_LENGTH<=maxBuffLength) continue; //유망하지 않은 상태에 대해서는 가지를 치지 않는다.
                                                                    //우선순위 큐에서 더 나중에 나오는 상태가 유망할 수도 있으므로 break 대신 continue를 사용한다.
            maxBuffLength = currentState.BUFF_LENGTH;
            pq[numInputs+1].push({currentState.TEXT_LENGTH+1, currentState.BUFF_LENGTH}); //화면에 A를 추가하는 입력
            pq[numInputs+1].push({currentState.TEXT_LENGTH+currentState.BUFF_LENGTH, currentState.BUFF_LENGTH}); //화면에 붙여넣기 하는 입력
            if (numInputs<maxNumInputs-1)
                pq[numInputs+2].push({currentState.TEXT_LENGTH, currentState.TEXT_LENGTH}); //화면의 내용을 복사하는 입력
        } //while loop
    } //numInputs loop (입력 횟수에 대해 반복)

    printf("%lld", pq[maxNumInputs].top().TEXT_LENGTH);
    return 0;
}



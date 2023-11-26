#include <stdio.h>

using namespace std;

int sequence[200002]; //입력 받을 수열
int subSeqProfile[100002]; //부분 수열에서 선택한 수의 분포

int max(int num0, int num1) {
    return num0>num1 ? num0 : num1;
}

int main() {
    int seqLength, dupleUpperLimit;
    scanf("%d %d", &seqLength, &dupleUpperLimit);

    for (int i=0; i<seqLength; i++) {
        scanf("%d", &sequence[i]);
    }

    int optResult = 0;
    int to=0;
    for (int from=0; from<seqLength; from++) {
        while (to<seqLength && subSeqProfile[sequence[to]]<dupleUpperLimit) {
            subSeqProfile[sequence[to]]++;
            to++;
        }
        optResult = max(optResult, to-from); //현재 인덱스 to에 있는 원소는 부분 수열에 포함이 안되었다.
                                                //부분 수열에 포함된 수는 인덱스 from 이상 to 미만이다.
        subSeqProfile[sequence[from]]--; //from 인덱스를 1 증가시키기 전에 from 인덱스에 해당하는 수의 개수를 1 감소시킨다.
    } //from loop

    printf("%d", optResult);
    return 0;
}

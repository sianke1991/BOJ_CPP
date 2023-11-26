#include <stdio.h>

int sequence[1000001]; //입력받을 수열

int max(int num0, int num1) {
    return num0>num1 ? num0 : num1;
}

int main() {
        //전체 수열의 길이 및 수열에 포함될 수 있는 홀수의 개수
    int seqLength, oddsUpperLimit;
    //수열에서 특정 원소 몇 개를 삭제하여 연속인 짝수 부분 수열을 만든다는 것은
    //몇 개까지 홀수를 포팜한 부분 수열을 만드는 것과 같다.

    scanf("%d %d", &seqLength, &oddsUpperLimit);
    for (int i=0; i<seqLength; i++) {
        scanf("%d", &sequence[i]);
    }
                //부분 수열에 포함된 홀수의 개수
    int to=0, numSelectedOdds = 0;
    int optResult = 0;
    for (int from=0; from<seqLength; from++) {
        while (to<seqLength) {
            numSelectedOdds += sequence[to]%2; //인덱스 to에 해당하는 수가 홀수라면 1만큼 증가한다.
            if (numSelectedOdds>oddsUpperLimit) { //인덱스 to에 해당하는 수를 넣어서 홀수 한계를 넘겨버린 경우, 인덱스 to에 해당하는 수를 제거한다.
                numSelectedOdds--;
                break;
            }
            to++;
        }
        optResult = max(optResult, to-from-numSelectedOdds); //현재 선택한 부분 수열 중 홀수는 실제로는 선택하지 않은 것이다.
        numSelectedOdds -= sequence[from]%2; //from을 1 증가시키기 전에 from에 해당하는 수가 홀수인지 여부를 체크한다.
    } //from loop

    printf("%d", optResult);
    return 0;
}

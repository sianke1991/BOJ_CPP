#include <stdio.h>
#define BOTH_ENDS_NOT_SELECTED 0
#define LEFT_END_SELECTED 1
#define RIGHT_END_SELECTED 2
#define BOTH_ENDS_SELECTED 3
#define MOD 1000000003LL

//dpArray[a][b][c] := 색 a개로 구성된 색 띠에서 이웃하지 않고 색 b개를 선택하는 경우의 수
//양 끝의 색(인덱스 0번의 색과 인덱스 a-1개의 색)을 선택하는 여부에 따라 구분하여 경우의 수를 헤아린다.
long long dpArray[1001][1001][4];

int main() {
    //초기값 설정
    dpArray[0][0][BOTH_ENDS_NOT_SELECTED] = 1LL;
    dpArray[1][0][BOTH_ENDS_NOT_SELECTED] = 1LL;
    dpArray[1][1][RIGHT_END_SELECTED] = 1LL;
    dpArray[2][0][BOTH_ENDS_NOT_SELECTED] = 1LL;
    dpArray[2][1][LEFT_END_SELECTED] = 1LL;
    dpArray[2][1][RIGHT_END_SELECTED] = 1LL;

    //입력값
    int numColours, numSelectedColours;
    scanf("%d %d", &numColours, &numSelectedColours);
    for (int colourIndex=3; colourIndex<=numColours; colourIndex++) {
        dpArray[colourIndex][0][BOTH_ENDS_NOT_SELECTED] = 1LL;
        for (int selectedColourIndex=1; selectedColourIndex<=colourIndex; selectedColourIndex++) {
            dpArray[colourIndex][selectedColourIndex][BOTH_ENDS_NOT_SELECTED] = (dpArray[colourIndex-1][selectedColourIndex][BOTH_ENDS_NOT_SELECTED] + dpArray[colourIndex-1][selectedColourIndex][LEFT_END_SELECTED])%MOD;
            dpArray[colourIndex][selectedColourIndex][LEFT_END_SELECTED] = dpArray[colourIndex-1][selectedColourIndex-1][BOTH_ENDS_NOT_SELECTED];
            dpArray[colourIndex][selectedColourIndex][RIGHT_END_SELECTED] = (dpArray[colourIndex-1][selectedColourIndex][RIGHT_END_SELECTED] + dpArray[colourIndex-1][selectedColourIndex][BOTH_ENDS_SELECTED])%MOD;
            dpArray[colourIndex][selectedColourIndex][BOTH_ENDS_SELECTED] = dpArray[colourIndex-1][selectedColourIndex-1][RIGHT_END_SELECTED];
        } //selectedColourIndex loop
    } //colourIndex loop

    printf("%lld\n", (dpArray[numColours][numSelectedColours][BOTH_ENDS_NOT_SELECTED] + dpArray[numColours][numSelectedColours][LEFT_END_SELECTED] + dpArray[numColours][numSelectedColours][RIGHT_END_SELECTED])%MOD);

    /*
    for (int colourIndex=0; colourIndex<=numColours; colourIndex++) {
        for (int selectedColourIndex=0; selectedColourIndex<=colourIndex; selectedColourIndex++) {
            for (int caseIndex=0; caseIndex<4; caseIndex++) {
                printf("%3d %3d %3d: %lld\n", colourIndex, selectedColourIndex, caseIndex, dpArray[colourIndex][selectedColourIndex][caseIndex]);
            }
        }
    } //colourIndex
    */
    return 0;
}

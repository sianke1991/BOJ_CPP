// 탐욕법
// 지금 가장 최적의 답을 근시안적으로 택하는 알고리즘
// 관찰을 통해서 탐색의 범위를 줄이는 알고리즘
// 탐색 범위를 줄여도 올바른 결과(global optimal)이 나오는지 그 여부를 수학적으로 증명해야 한다.
// 그 다음 구현을 통해서 문제를 해결한다.

#include <iostream>

using namespace std;

int scores[101];

int main() {
    int numLevels;
    cin >> numLevels;
    for (int i=numLevels-1; i>=0; i--)
        cin >> scores[i];
    int numDecreases = 0;
    for (int i=1; i<numLevels; i++) {
        if (scores[i]>=scores[i-1]) { // 해당 레벨이 이전 레벨보다 점수가 낮으면 해당 레벨의 점수를 깍을 필요가 없다.
            numDecreases += scores[i]-scores[i-1]+1; //만약 깍는 다면 해당 레벨의 점수를 이전 레벨의 점수-1 까지 깍는게 최적이다.
            scores[i] = scores[i-1]-1;
        }
    } //i loop
    cout << numDecreases;
    return 0;
}

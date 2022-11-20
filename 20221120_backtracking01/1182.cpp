#include <iostream>

using namespace std;

long long numCases = 0;
int numInputs;
int inputNumbers[20];
int targetSum = 0;


/**inputNumbers의 각 수를 선택 또는 선택하지 않음으로 갈라지는 트리를 그린다.*/
void recursion(int depth, int partialSum) {
    //base case
    if (depth == numInputs) {
        if (partialSum == targetSum) numCases++;
        return;
    }

    recursion(depth+1, partialSum); //depth에 해당하는 원소를 선택하지 않는 경우
    recursion(depth+1, partialSum+inputNumbers[depth]); //depth에 해당하는 원소를 선택하는 경우
}

int main() {
    cin >> numInputs >> targetSum;
    for (int i=0; i<numInputs; i++)
        cin >> inputNumbers[i];
    recursion(0, 0);
    if (targetSum==0) { //목표 점수가 0인 경우 inputNumbers를 전부 선택하지 않는 경우도 카운트가 되는데, 이 문제는 그런 경우를 제외해야 하는 듯 하다.
        cout << (numCases-1);
    } else {
        cout << numCases;
    }
    return 0;
}

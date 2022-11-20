#include <iostream>

using namespace std;

int numInputs;
int numsSelectable[11];
int numAdds;
int numSubs;
int numMuls;
int numDivs;
int maxVal = -2147483648;
int minVal = 2147483647;

/**수행 가능한 연산에 대해 가지를 뻗는 트리를 그린다.*/
void recursion(int depth, int currentResult, int numAddsUsed, int numSubsUsed, int numMulsUsed, int numDivsUsed) {
    if (depth==numInputs-1) {
        if (currentResult > maxVal) maxVal = currentResult;
        if (currentResult < minVal) minVal = currentResult;
        return;
    }

    if (numAdds > numAddsUsed) recursion(depth+1, currentResult+numsSelectable[depth+1], numAddsUsed+1, numSubsUsed, numMulsUsed, numDivsUsed); //덧셈이 가능한 경우
    if (numSubs > numSubsUsed) recursion(depth+1, currentResult-numsSelectable[depth+1], numAddsUsed, numSubsUsed+1, numMulsUsed, numDivsUsed); //뺄셈이 가능한 경우
    if (numMuls > numMulsUsed) recursion(depth+1, currentResult*numsSelectable[depth+1], numAddsUsed, numSubsUsed, numMulsUsed+1, numDivsUsed); //곱셈이 가능한 경우
    if (numDivs > numDivsUsed) recursion(depth+1, currentResult/numsSelectable[depth+1], numAddsUsed, numSubsUsed, numMulsUsed, numDivsUsed+1); //나눗셈이 가능한 경우
}

int main() {
	cin >> numInputs;
	for (int i=0; i<numInputs; i++) {
		cin >> numsSelectable[i];
	}
	cin >> numAdds;
	cin >> numSubs;
	cin >> numMuls;
	cin >> numDivs;
	recursion(0, numsSelectable[0], 0, 0, 0, 0);
	cout << maxVal << '\n' << minVal;
	return 0;
}

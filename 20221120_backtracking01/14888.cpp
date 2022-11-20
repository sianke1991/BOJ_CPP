#include <iostream>

using namespace std;


int numInputs;
int numsSelectable[11];
int numAdds;
int numSubs;
int numMuls;
int numDivs;
long long maxVal = -9223372036854775808LL;
long long minVal = 9223372036854775807LL;

void recursion(int depth, int currentResult, int numAddsUsed, int numSubsUsed, int numMulsUsed, int numDivsUsed) {
    if (depth==numInputs-1) {
        if (currentResult > maxVal) maxVal = currentResult;
        if (currentResult < minVal) minVal = currentResult;
        return;
    }

    if (numAdds > numAddsUsed) recursion(depth+1, currentResult+numsSelectable[depth+1], numAddsUsed+1, numSubsUsed, numMulsUsed, numDivsUsed);
    if (numSubs > numSubsUsed) recursion(depth+1, currentResult-numsSelectable[depth+1], numAddsUsed, numSubsUsed+1, numMulsUsed, numDivsUsed);
    if (numMuls > numMulsUsed) recursion(depth+1, currentResult*numsSelectable[depth+1], numAddsUsed, numSubsUsed, numMulsUsed+1, numDivsUsed);
    if (numDivs > numDivsUsed) recursion(depth+1, currentResult/numsSelectable[depth+1], numAddsUsed, numSubsUsed, numMulsUsed, numDivsUsed+1);
}

int main() {
}

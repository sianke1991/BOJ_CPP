#include <bits/stdc++.h>

using namespace std;

int numPeople;
vector<int> statArr;
//vector<pair<int, int>> stats;
int maxStat = 0;

int main() {
    scanf("%d", &numPeople);
    for (int i=0; i<numPeople; i++) {
        int stat;
        scanf("%d", &stat);
        statArr.push_back(stat);
    }
    int left = 0, right = numPeople-1;
    while (left<right) {
        int currStat = min(statArr[left], statArr[right]) * (right-left-1);
        maxStat = max(maxStat, currStat);
        if (statArr[left]<statArr[right])
            left++;
        else
            right--;
    }
    printf("%d", maxStat);
    return 0;
}

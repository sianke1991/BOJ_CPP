#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n;
pair<int, int> p[100001];


int main() {
    scanf("%d", &n);
    double sumPop = 0.0;
    for (int i=0; i<n; i++) {
        int pos, pop;
        scanf("%d %d", &pos, &pop);
        p[i] = {pos, pop};
        sumPop += pop;
    } //i loop

    sort(p, p+n);
    int ans = 0;
    double partialSumPop = 0.0;
    for (int i=0; i<n; i++) {
        partialSumPop += p[i].second;
        if (partialSumPop >= sumPop/2) {
            ans = p[i].first;
            break;
        }
    } //i loop

    printf("%d", ans);
    return 0;

}

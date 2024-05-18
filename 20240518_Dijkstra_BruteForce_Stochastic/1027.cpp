#include <stdio.h>


// 건물의 개수
int numBuilds;
// 각 건물의 높이
int buildingHeights[51];
// 볼 수 있는 건물의 개수: numVisibleBuildings[x]는 x번 건물에서 볼 수 있는 건물의 개수
int numVisibleBuildings[51];

const double NEGATIVE_INFINITY = -1./0.;

int main() {
    scanf("%d", &numBuilds);
    for (int i=0; i<numBuilds; i++)
        scanf("%d", &buildingHeights[i]);

    for (int from=0; from<numBuilds-1; from++) {
        double maxSlope = NEGATIVE_INFINITY;
        for (int to=from+1; to<numBuilds; to++) {
            double slope = ((double)(buildingHeights[to]-buildingHeights[from]))/(to-from);
            if (slope>maxSlope) { //해당 건물이 기존의 건물보다 더 높은 기울기를 가지고 있는 경우-
                numVisibleBuildings[from]++; //from에서 to가 보이고
                numVisibleBuildings[to]++; //to에서 from이 보이는 것이다.
                maxSlope = slope;
            }
        } //to loop
    } //from loop

    int result = 0;
    for (int i=0; i<numBuilds; i++) {
        if (result<numVisibleBuildings[i])
            result = numVisibleBuildings[i];
    }
    printf("%d", result);

    /*
    for (int i=0; i<numBuilds; i++) {
        printf("building number: %d, numVisibleBuildings: %d\n", i, numVisibleBuildings[i]);
    }
    */
    return 0;
}

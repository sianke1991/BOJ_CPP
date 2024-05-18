#include <stdio.h>


// �ǹ��� ����
int numBuilds;
// �� �ǹ��� ����
int buildingHeights[51];
// �� �� �ִ� �ǹ��� ����: numVisibleBuildings[x]�� x�� �ǹ����� �� �� �ִ� �ǹ��� ����
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
            if (slope>maxSlope) { //�ش� �ǹ��� ������ �ǹ����� �� ���� ���⸦ ������ �ִ� ���-
                numVisibleBuildings[from]++; //from���� to�� ���̰�
                numVisibleBuildings[to]++; //to���� from�� ���̴� ���̴�.
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

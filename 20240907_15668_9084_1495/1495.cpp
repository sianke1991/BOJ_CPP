#include <stdio.h>

int main() {
    int arrLength, initialVolume, volumeLimit;
    int arr[51];
    scanf("%d %d %d", &arrLength, &initialVolume, &volumeLimit);
    for (int i=0; i<arrLength; i++)
        scanf("%d", &arr[i]);
    //dp[volume][step] := Ư�� �ܰ迡�� Ư�� volume�� ������ �� �ִ��� ����
    //������ �迭�� Ǫ�� ���� ��� �� �Ұ����ϴ�.
    bool dp[1002][51];
    for (int i=0; i<1002; i++) {
        for (int j=0; j<51; j++) {
            dp[i][j] = false;
        }
    }
    dp[initialVolume][0] = true;
    for (int step=0; step<arrLength; step++) {
        //�̹� step�� �ѱ� �� �ִ��� ����-
        bool check = false;
        for (int volume=0; volume<=volumeLimit; volume++) {
            if (!dp[volume][step]) continue;
            int plusSide = volume+arr[step];
            if (plusSide<=volumeLimit) {
                check = true;
                dp[plusSide][step+1] = true;
            }
            int minusSide = volume-arr[step];
            if (minusSide>=0) {
                check = true;
                dp[minusSide][step+1] = true;
            }
        } //volume loop
        if (!check) {
            printf("-1");
            return 0;
        }
    } //step loop

    for (int volume=volumeLimit; volume>=0; volume--) {
        if (dp[volume][arrLength]) {
            printf("%d", volume);
            return 0;
        }
    }

    return 1;
}

#include <stdio.h>
#include <string.h>

char targetString[11];
char ringStrings[100][21];
int numRings;

int main() {
    scanf("%s", targetString);
    scanf("%d", &numRings);
    for (int i=0; i<numRings; i++)
        scanf("%s", ringStrings[i]);

    /*
        ������ ���� �� ù 9 ����
        ������ ���� �ڿ� ���δ�.
        (������ ������ ��ȸ�ϴ� ���̹Ƿ�)
    */
    for (int ring=0; ring<numRings; ring++) {
        for (int idx=0; idx<9; idx++)
            ringStrings[ring][idx+10] = ringStrings[ring][idx];
    } //ring loop

    const int len = strlen(targetString);
    const int lim = 19-len;
    int result = 0;
    for (int ring=0; ring<numRings; ring++) {
        for (int startIndex=0; startIndex<=lim; startIndex++) {
            bool flag = true;
            for (int duration=0; duration<len; duration++) {
                if (targetString[duration]!=ringStrings[ring][startIndex+duration]) {
                    flag = false;
                    break;
                }
            } //duration loop
            if (flag) {
                //targetString�� ã�� ���, �ش� �������� �� �̻� ���ڿ��� ã�� �ʿ䰡 ����.
                result++;
                break;
            }
        } //startIndex loop
    } //ring loop

    printf("%d", result);
    return 0;
}

/*
    �ְ� �ӵ��� 3���� �� ��� Ű ������ �ּ�ġ��
    1+2+3+2+1 = 9
    �ְ� �ӵ��� 4�� �� ��� Ű ������ �ּ�ġ��
    1+2+3+4+3+2+1 = 16

    ���� Ű ���̰� d�� ��� �ְ� �ӵ��� sqrt(d) �̾�� �Ѵ�.

    �ְ� �ӵ��� v ��ŭ �� ��� �⺻������ (2*v-1 �� ��ŭ�� ��¥�� �Ҹ��Ͽ�) v*v ��ŭ�� Ű ���̸� ������´�.
    ���� Ű r(=d-v*v)�� �ִ� ��� �� Ű�� ������� ���ؼ� �߰��� ceil(r/v) �� ��ŭ�� �ʿ��ϴ�.
*/
#include <stdio.h>
#include <math.h>

int main() {
    int h0, h1;
    scanf("%d %d", &h0, &h1);
    int diff = h1-h0;
    //�ְ� �ӵ�
    int maxSpeed = (int) sqrt(diff);
    if (maxSpeed==0) {
        printf("0");
        return 0;
    }
    //�ְ� �ӵ��� �����ϰ� �ٽ� �����ϱ� ���� �ʿ��� �⺻ ��¥
    int baseDays = 2*maxSpeed-1;
    //�ְ� �ӵ��� �����ϰ� �ٽ� �����ϴ� �������� Ű�� ������µ� ���� �������� ���� ��
    int remainingDiff = diff-maxSpeed*maxSpeed;
    //remainingDiff�� Ű�� ������� ���� �߰��� �ʿ��� ��¥
    int extraDays = (remainingDiff+maxSpeed-1)/maxSpeed;
    printf("%d", baseDays+extraDays);
    return 0;
}

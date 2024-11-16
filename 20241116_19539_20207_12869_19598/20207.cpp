#include <stdio.h>

/*
    �ϳ��� ��ȹ�� ���۵Ǵ� ���� ������ ���� ǥ���Ѵ�.
    �� ǥ�⸦ "�۾��" Ư�� ���� ������ ������ �ľ��� �� �ִ�.
    => �迭�� ����� �۾���
*/

int N;
int beginDates[1001];
int endDates[1001];
int dNumSchedules[367]; //������ ���� ��ȭ �迭 dNumSchedules[i]�� ����� ��� i ��° ���� ������ ������ �����Ѵ�.

void input() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d %d", &beginDates[i], &endDates[i]);
        dNumSchedules[beginDates[i]]++;
        dNumSchedules[endDates[i]+1]--;
    } //i loop
}

int max(int num0, int num1) {
    return num0 > num1 ? num0 : num1;
}

int main() {
    input();
    int result = 0; //������ ����
    int currentNumSchedules = 0; //���� ������ ����
    int localMaxNumSchedules = 0; //���� �������� �����ϴ� �������� ������ ������ �ִ�ġ
    int currentDuration = 0; //���� �������� �����ϴ� �Ⱓ

    //�޷��� "�۾��鼭" ������ ������ ������ ���� �� �ִ�.
    for (int day=0; day<=366; day++) {
        //���� ������ ���� ����
        currentNumSchedules += dNumSchedules[day];
        //���� �������� �ִ� ���
        if (currentNumSchedules) {
            currentDuration++;
            localMaxNumSchedules = max(localMaxNumSchedules, currentNumSchedules);
        }
        //���� �������� �� ������ ���- (���� �� ������������ ��-)
        else if (localMaxNumSchedules) {
            //������ ���� ���
            result += currentDuration * localMaxNumSchedules;
            currentDuration = 0;
            localMaxNumSchedules = 0;
        }
    } //day loop
    printf("%d", result);
    return 0;
}

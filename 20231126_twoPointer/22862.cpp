#include <stdio.h>

int sequence[1000001]; //�Է¹��� ����

int max(int num0, int num1) {
    return num0>num1 ? num0 : num1;
}

int main() {
        //��ü ������ ���� �� ������ ���Ե� �� �ִ� Ȧ���� ����
    int seqLength, oddsUpperLimit;
    //�������� Ư�� ���� �� ���� �����Ͽ� ������ ¦�� �κ� ������ ����ٴ� ����
    //�� ������ Ȧ���� ������ �κ� ������ ����� �Ͱ� ����.

    scanf("%d %d", &seqLength, &oddsUpperLimit);
    for (int i=0; i<seqLength; i++) {
        scanf("%d", &sequence[i]);
    }
                //�κ� ������ ���Ե� Ȧ���� ����
    int to=0, numSelectedOdds = 0;
    int optResult = 0;
    for (int from=0; from<seqLength; from++) {
        while (to<seqLength) {
            numSelectedOdds += sequence[to]%2; //�ε��� to�� �ش��ϴ� ���� Ȧ����� 1��ŭ �����Ѵ�.
            if (numSelectedOdds>oddsUpperLimit) { //�ε��� to�� �ش��ϴ� ���� �־ Ȧ�� �Ѱ踦 �Ѱܹ��� ���, �ε��� to�� �ش��ϴ� ���� �����Ѵ�.
                numSelectedOdds--;
                break;
            }
            to++;
        }
        optResult = max(optResult, to-from-numSelectedOdds); //���� ������ �κ� ���� �� Ȧ���� �����δ� �������� ���� ���̴�.
        numSelectedOdds -= sequence[from]%2; //from�� 1 ������Ű�� ���� from�� �ش��ϴ� ���� Ȧ������ ���θ� üũ�Ѵ�.
    } //from loop

    printf("%d", optResult);
    return 0;
}

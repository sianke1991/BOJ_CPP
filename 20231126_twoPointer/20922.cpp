#include <stdio.h>

using namespace std;

int sequence[200002]; //�Է� ���� ����
int subSeqProfile[100002]; //�κ� �������� ������ ���� ����

int max(int num0, int num1) {
    return num0>num1 ? num0 : num1;
}

int main() {
    int seqLength, dupleUpperLimit;
    scanf("%d %d", &seqLength, &dupleUpperLimit);

    for (int i=0; i<seqLength; i++) {
        scanf("%d", &sequence[i]);
    }

    int optResult = 0;
    int to=0;
    for (int from=0; from<seqLength; from++) {
        while (to<seqLength && subSeqProfile[sequence[to]]<dupleUpperLimit) {
            subSeqProfile[sequence[to]]++;
            to++;
        }
        optResult = max(optResult, to-from); //���� �ε��� to�� �ִ� ���Ҵ� �κ� ������ ������ �ȵǾ���.
                                                //�κ� ������ ���Ե� ���� �ε��� from �̻� to �̸��̴�.
        subSeqProfile[sequence[from]]--; //from �ε����� 1 ������Ű�� ���� from �ε����� �ش��ϴ� ���� ������ 1 ���ҽ�Ų��.
    } //from loop

    printf("%d", optResult);
    return 0;
}

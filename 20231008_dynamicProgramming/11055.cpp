#include <iostream>

using namespace std;
//�Է¹޴� ����
int sequence[1002];
//dpArray[i]:= sequence[i]�� �ִ�ġ�� ���� �κ� ���� ������ ���� �ִ�ġ
int dpArray[1002];
int main() {
    int N;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> sequence[i];
        dpArray[i] = sequence[i];
    } //i loop

    for (int i=0; i<N; i++) {
        for (int j=0; j<i; j++) {
            //sequence[i]�� �ִ�ġ�� ���� �κ� ���� ������ ����ؾ� �ϹǷ�,
            //sequence[j]>=sequence[i]�� �����ϴ� sequence[j]�� �����Ѵ�.
            if (sequence[j]>=sequence[i])
                continue;

            //dpArray[i] = max(dpArray[j]+sequence[i]) (for all j<i, sequence[j]<sequence[i])
            // => �� ��� ����
            // dpArray[j]�� sequence[j]�� �ִ�ġ�� ���� �κ� ���� ������ ���� �ִ�ġ�̴�.
            // j<i�̰�, sequence[j]<sequence[i]�� �����Ѵٸ� dpArray[j]�� sequence[i]�� ���Ͽ�
            // sequence[i]�� �ִ�ġ�� ���� �κ� ���� ������ ���� ���� �� �ִ�.
            // ������ dpArray[i]�� sequence[i]�� �ִ�ġ�� ���� �κ� ���� ������ ���� "�ִ�ġ"�̹Ƿ�,
            // ������ j�� ���� dpArray[j]+sequence[i]�� ��� ���� �� �� �ִ�ġ�� dpArray[i]�� �ȴ�.
            //�� ����� �����ϱ� ���ؼ� �־��� i�� ���� j loop�� �ʿ��ϴ�.
            //�� ���� ��� i�� ���ؼ� ���ؾ� �ϹǷ� �ᱹ 2�� for loop�� �ʿ��ϴ�.
            if (dpArray[i]<dpArray[j]+sequence[i])
                dpArray[i] = dpArray[j]+sequence[i];
        } //j loop
    } //i loop

    int optResult = 0;
    for (int elem:dpArray) {
        if (elem>optResult)
            optResult = elem;
    }
    cout << optResult << '\n';
    return 0;
}

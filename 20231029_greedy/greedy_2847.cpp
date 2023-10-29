// Ž���
// ���� ���� ������ ���� �ٽþ������� ���ϴ� �˰���
// ������ ���ؼ� Ž���� ������ ���̴� �˰���
// Ž�� ������ �ٿ��� �ùٸ� ���(global optimal)�� �������� �� ���θ� ���������� �����ؾ� �Ѵ�.
// �� ���� ������ ���ؼ� ������ �ذ��Ѵ�.

#include <iostream>

using namespace std;

int scores[101];

int main() {
    int numLevels;
    cin >> numLevels;
    for (int i=numLevels-1; i>=0; i--)
        cin >> scores[i];
    int numDecreases = 0;
    for (int i=1; i<numLevels; i++) {
        if (scores[i]>=scores[i-1]) { // �ش� ������ ���� �������� ������ ������ �ش� ������ ������ ���� �ʿ䰡 ����.
            numDecreases += scores[i]-scores[i-1]+1; //���� ��� �ٸ� �ش� ������ ������ ���� ������ ����-1 ���� ��°� �����̴�.
            scores[i] = scores[i-1]-1;
        }
    } //i loop
    cout << numDecreases;
    return 0;
}

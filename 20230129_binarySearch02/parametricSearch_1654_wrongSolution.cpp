#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int K; //������ �ִ� ������ ����
int N; //�ʿ��� ������ ����
vector<int> ownedLines; //������ �ִ� ������ ����
int minOwnedLine = 2147483647;

// �Ű� ���� Ž��
// ������ �����ϴ� �ּ�/�ִ�ġ�� ���ϴ� ���� (����ȭ ����)�� ���� ������ ��ȯ�Ͽ� �̺�Ž���� �����ϴ� ���
// (����ȭ ����) N���� ���� �� �ִ� ������ �ִ� ����
// (���� ����) ������ ���̰� X�� �� ������ N�� �̻��ΰ� ����

//������ ���̸� �Է¹޾� N���� ������ ���� �� �ִ��� ���θ� ��ȯ�Ѵ�.
bool isConstructable(int lineLength) {
    long long numLines = 0;
    for (int ownedLine:ownedLines) {
        numLines += ownedLine/lineLength;
    }
    return numLines >= N;
}

int main() {
    {
        cin >> K >> N;
        int ownedLine;
        for (int i=0; i<K; i++) {
            cin >> ownedLine;
            ownedLines.push_back(ownedLine);
            minOwnedLine = min(minOwnedLine, ownedLine);
        } //i loop
    }
    int from = 0;
    int to = minOwnedLine;
    int mid;
    while (from+1<to) {
        mid = (from+to)/2;
        if (isConstructable(mid)) {
           from = mid;
        } else {
            to = mid-1;
        }
    }
    if (isConstructable(from+1)) cout << from+1;
    else cout << from;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

//��ͷ� ���� Ǯ��
//1. �Լ� ���� (�Ķ����, ��ȯ��)
//2. base case (��Ͱ� ����� ����)
//3. ��ͽ� (��ȭ��)

/**���� �̵� ���*/
vector<pair<int, int>> moveList;

/**�� ��� ��ȣ�� �Է����� �� ���� �ϳ��� ��� ��ȣ�� ��ȯ�Ѵ�.*/
int getTheOtherPole(int poleA, int poleB) {
    switch (poleA*10+poleB) {
        case 12: return 3;
        case 13: return 2;
        case 21: return 3;
        case 23: return 1;
        case 31: return 2;
        case 32: return 1;
        default: return -1;
    }
}

//�Լ� ���� (��� �Լ�)
void howToMove(int from, int to, int numRings) {
    //base cases
    if (numRings==1) {
        moveList.push_back({from, to});
        return;
    } else if (numRings==0) {
        return;
    }

    //��ͽ�
    int theOtherPole = getTheOtherPole(from, to); //�� ���� 6-from-to�� �ۼ��� ���� �ִ�.
    //1. �� �ٴ� ������ ������ ������ ������ �� 3�� ���� �̵���Ų��.
    howToMove(from, theOtherPole, numRings-1);
    //2. �� �ٴ� ���� �ϳ��� ��ǥ ���� �̵���Ų��.
    howToMove(from, to, 1);
    //3. �� �ٴ� ������ ������ ������ ������ �� 3�� ��뿡�� ��ǥ ���� �̵���Ų��.
    howToMove(theOtherPole, to, numRings-1);
}

int main() {
    int N; //the number of rings
    cin >> N;
    howToMove(1, 3, N);
    cout << moveList.size() << '\n';
    for (pair<int, int> p:moveList) {
        cout << p.first << ' ' << p.second << '\n';
    }
    return 0;
}

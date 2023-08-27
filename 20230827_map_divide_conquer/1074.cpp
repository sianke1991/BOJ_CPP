#include <iostream>
// ���� ���� (divide and conquer)
using namespace std;

int N, r, c;
int ans=0;

void Z(int x, int y, int size) {
    //���̽� ���̽�
    if (size==1) { //������ ũ�Ⱑ 1���� �پ����� ��-
        if (x==r && y==c) {
            cout << ans;
            return;
        } else {
            ans++; //�� �Լ��� ���ڸ� Z ������� �湮�ϹǷ� ������ �湮�� ĭ�� ������ ������ �ȴ�.
            return;
        }
    }

    if (!(x<=r && r<x+size && y<=c && c<y+size)) { //���� ���캸�� �ִ� 4�и鿡 ������ ���Ե��� ���� ���
        ans += size*size; //�ش� 4�и��� ������ �湮���� �ʰ� ���� ũ�⸸ŭ ans�� ������Ų��.
        return;
    }

    //4��� �ϴ� �Լ��� �� �� ȣ���Ѵ�.
    int halfSize = size/2;
    Z(x, y, halfSize); //���� ��
    Z(x, halfSize+y, halfSize); //������ ��
    Z(halfSize+x, y, halfSize); //���� �Ʒ�
    Z(halfSize+x, halfSize+y, halfSize); //������ �Ʒ�
}

int main() {
    cin >> N >> r >> c;
    Z(0, 0, 1<<N);
    return 0;
}

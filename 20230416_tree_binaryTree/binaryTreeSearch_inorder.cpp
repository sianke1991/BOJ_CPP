#include <bits/stdc++.h>
//Inorder Traversal ���� ��ȸ
/*
1. ���� ���� Ʈ���� ���� ��ȸ�Ѵ�.
2. ���� ������ �湮�Ѵ�.
3. ������ ���� Ʈ���� ���� ��ȸ�Ѵ�.
*/

using namespace std;

int lc[9] = {0, 2, 4, 6, 0, 0, 0, 0, 0};
int rc[9] = {0, 3, 5, 7, 0, 8, 0, 0, 0};

void inorder(int cur) { //root = 1
    if (lc[cur]!=0) inorder(lc[cur]); //���� �ڽ��� ������ �������� �İ���. (���� �ڽ��� ������ �� ����)
    cout << cur << ' '; //���� ���� �ڽ��� ������ �湮ó��
    if (rc[cur!=0]) inorder(rc[cur]);
}


int main() {


}

#include <bits/stdc++.h>
//Postorder Traversal ���� ��ȸ
/*
1. ���� ���� Ʈ���� ���� ��ȸ�Ѵ�.
2. ������ ���� Ʈ���� ���� ��ȸ�Ѵ�.
3. ���� ������ �湮�Ѵ�.
*/

using namespace std;

int lc[9] = {0, 2, 4, 6, 0, 0, 0, 0, 0};
int rc[9] = {0, 3, 5, 7, 0, 8, 0, 0, 0};

void postorder(int cur) { //root = 1
    if (lc[cur]!=0) postorder(lc[cur]); //���� �ڽ��� ������ �������� �İ���. (���� �ڽ��� ������ �� ����)
    if (rc[cur!=0]) postorder(rc[cur]);
    cout << cur << ' ';
}


int main() {


}

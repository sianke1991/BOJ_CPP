#include <bits/stdc++.h>
//Preorder Traversal ���� ��ȸ
/*
1. ���� ������ �湮�Ѵ�.
2. ���� ���� Ʈ���� ���� ��ȸ�Ѵ�.
3. ������ ���� Ʈ���� ���� ��ȸ�Ѵ�.
*/

using namespace std;

int lc[9] = {0, 2, 4, 6, 0, 0, 0, 0, 0};
int rc[9] = {0, 3, 5, 7, 0, 8, 0, 0, 0};

void preorder(int cur) { //root = 1
    cout << cur << ' ';
    if (lc[cur]!=0) preorder(lc[cur]); //���� �ڽĳ�� ��ȸ/�湮�� ���� ȣ��Ǿ�� �Ѵ�.
    if (rc[cur]!=0) preorder(rc[cur]);
}


int main() {


}

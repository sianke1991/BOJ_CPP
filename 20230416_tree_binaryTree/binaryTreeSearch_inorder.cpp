#include <bits/stdc++.h>
//Inorder Traversal 중위 순회
/*
1. 왼쪽 서브 트리를 중위 순회한다.
2. 현재 정점을 방문한다.
3. 오른쪽 서브 트리를 중위 순회한다.
*/

using namespace std;

int lc[9] = {0, 2, 4, 6, 0, 0, 0, 0, 0};
int rc[9] = {0, 3, 5, 7, 0, 8, 0, 0, 0};

void inorder(int cur) { //root = 1
    if (lc[cur]!=0) inorder(lc[cur]); //왼쪽 자식이 있으면 왼쪽으로 파고든다. (왼쪽 자식이 없어질 때 까지)
    cout << cur << ' '; //만약 왼쪽 자식이 없으면 방문처리
    if (rc[cur!=0]) inorder(rc[cur]);
}


int main() {


}

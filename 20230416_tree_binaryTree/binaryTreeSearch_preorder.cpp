#include <bits/stdc++.h>
//Preorder Traversal 전위 순회
/*
1. 현재 정점을 방문한다.
2. 왼쪽 서브 트리를 전위 순회한다.
3. 오른쪽 서브 트리를 전위 순회한다.
*/

using namespace std;

int lc[9] = {0, 2, 4, 6, 0, 0, 0, 0, 0};
int rc[9] = {0, 3, 5, 7, 0, 8, 0, 0, 0};

void preorder(int cur) { //root = 1
    cout << cur << ' ';
    if (lc[cur]!=0) preorder(lc[cur]); //왼쪽 자식노드 순회/방문이 먼저 호출되어야 한다.
    if (rc[cur]!=0) preorder(rc[cur]);
}


int main() {


}

#include <bits/stdc++.h>
//Postorder Traversal 후위 순회
/*
1. 왼쪽 서브 트리를 후위 순회한다.
2. 오른쪽 서브 트리를 후위 순회한다.
3. 현재 정점을 방문한다.
*/

using namespace std;

int lc[9] = {0, 2, 4, 6, 0, 0, 0, 0, 0};
int rc[9] = {0, 3, 5, 7, 0, 8, 0, 0, 0};

void postorder(int cur) { //root = 1
    if (lc[cur]!=0) postorder(lc[cur]); //왼쪽 자식이 있으면 왼쪽으로 파고든다. (왼쪽 자식이 없어질 때 까지)
    if (rc[cur!=0]) postorder(rc[cur]);
    cout << cur << ' ';
}


int main() {


}

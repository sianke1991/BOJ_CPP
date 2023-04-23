#include <bits/stdc++.h>

using namespace std;
char parentOf[91];
char leftChildOf[91];
char rightChildOf[91];
vector<char> preorders; //전위순회결과
vector<char> inorders; //중위순회결과
vector<char> postorders; //후위순회결과

//전위순회: 현재 노드가 두 자식 노드보다 먼저 방문된다.
void preorder(char currentNode) {
    if (currentNode==0) return; //현재 노드가 없는 경우에는 재귀를 종료한다.
    preorders.push_back(currentNode);
    preorder(leftChildOf[currentNode]);
    preorder(rightChildOf[currentNode]);
}

//,중위순회: 현재 노드가 왼쪽 자식보다는 나중에, 오른쪽 자식보다는 먼저 방문된다.
void inorder(char currentNode) {
    if (currentNode==0) return; //현재 노드가 없는 경우에는 재귀를 종료한다.
    inorder(leftChildOf[currentNode]);
    inorders.push_back(currentNode);
    inorder(rightChildOf[currentNode]);
}

//후위순회: 현재 노드가 두 자식 노드보다 나중에 방문된다.
void postorder(char currentNode) {
    if (currentNode==0) return; //현재 노드가 없는 경우에는 재귀를 종료한다.
    postorder(leftChildOf[currentNode]);
    postorder(rightChildOf[currentNode]);
    postorders.push_back(currentNode);
}

int main() {
    int numNodes;
    cin >> numNodes;
    for (int i=0; i<numNodes; i++) {
        char currentNode, leftChildNode, rightChildNode;
        cin >> currentNode >> leftChildNode >> rightChildNode;
        if (leftChildNode!='.') { //현재 노드가 왼쪽 자식 노드를 가지고 있는 경우-
            leftChildOf[currentNode] = leftChildNode;
            parentOf[leftChildNode] = currentNode;
        }
        if (rightChildNode!='.') { //현재 노드가 오른쪽 자식 노드를 가지고 있는 경우-
            rightChildOf[currentNode] = rightChildNode;
            parentOf[rightChildNode] = currentNode;
        }
    } //input loop
    preorder('A');
    inorder('A');
    postorder('A');
    for (char ch:preorders) {
        cout << ch;
    }
    cout << '\n';
    for (char ch:inorders) {
        cout << ch;
    }
    cout << '\n';
    for (char ch:postorders) {
        cout << ch;
    }
    return 0;
}

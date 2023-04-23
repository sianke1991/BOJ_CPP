#include <bits/stdc++.h>

using namespace std;
char parentOf[91];
char leftChildOf[91];
char rightChildOf[91];
vector<char> preorders; //������ȸ���
vector<char> inorders; //������ȸ���
vector<char> postorders; //������ȸ���

//������ȸ: ���� ��尡 �� �ڽ� ��庸�� ���� �湮�ȴ�.
void preorder(char currentNode) {
    if (currentNode==0) return; //���� ��尡 ���� ��쿡�� ��͸� �����Ѵ�.
    preorders.push_back(currentNode);
    preorder(leftChildOf[currentNode]);
    preorder(rightChildOf[currentNode]);
}

//,������ȸ: ���� ��尡 ���� �ڽĺ��ٴ� ���߿�, ������ �ڽĺ��ٴ� ���� �湮�ȴ�.
void inorder(char currentNode) {
    if (currentNode==0) return; //���� ��尡 ���� ��쿡�� ��͸� �����Ѵ�.
    inorder(leftChildOf[currentNode]);
    inorders.push_back(currentNode);
    inorder(rightChildOf[currentNode]);
}

//������ȸ: ���� ��尡 �� �ڽ� ��庸�� ���߿� �湮�ȴ�.
void postorder(char currentNode) {
    if (currentNode==0) return; //���� ��尡 ���� ��쿡�� ��͸� �����Ѵ�.
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
        if (leftChildNode!='.') { //���� ��尡 ���� �ڽ� ��带 ������ �ִ� ���-
            leftChildOf[currentNode] = leftChildNode;
            parentOf[leftChildNode] = currentNode;
        }
        if (rightChildNode!='.') { //���� ��尡 ������ �ڽ� ��带 ������ �ִ� ���-
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

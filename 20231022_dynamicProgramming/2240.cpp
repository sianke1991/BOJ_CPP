#include <iostream>
#include <string>

using namespace std;

struct Node {
    //���ݱ��� ���� �ڵ��� ����
    int numPlums;
    //���� �ڵ��� ��ġ: 1 �Ǵ� 2
    int currentPosition;
};

int tree[1000]; //�� �ð��� �ڵΰ� �������� �ڵγ��� (1 �Ǵ� 2)
//dpCache[t][0]: �ð� t�� 0�� ��ġ�� �����Ͽ� ���� �� �ִ� �ڵ� ����
//dpCache[t][1]: �ð� t�� 1�� ��ġ�� �����Ͽ� ���� �� �ִ� �ڵ� ����
//dpCache[t][c]: �ð� t�� c�� ��ġ�� �����Ͽ� ���� �� �ִ� �ڵ� ����
Node dpCache[1000][31];




Node makeNode(int numPlums, int currentPosition) {
    Node* result = new Node();
    result->numPlums = numPlums;
    result->currentPosition = currentPosition;
    return *result;
}

string toString(Node node) {
    string result = "(" + to_string(node.numPlums) + ", " + to_string(node.currentPosition) + ")";
    return result;
}

int changePosition(int currentPosition) {
    return 3-currentPosition;
}

Node max(Node node0, Node node1) {
    return node0.numPlums>node1.numPlums ? node0 : node1;
}

int min(int num0, int num1) {
    return num0<num1 ? num0 : num1;
}

int main() {
    int T, W;
    cin >> T >> W;
    for (int i=0; i<T; i++)
        cin >> tree[i];

    //���̽� ���̽�
    dpCache[0][0] = makeNode(tree[0]==1, 1);
    dpCache[0][1] = makeNode(tree[0]==2, 2);

    //��ȭ��
    for (int t=1; t<T; t++) {
        dpCache[t][0] = makeNode(dpCache[t-1][0].numPlums + (tree[t]==1), 1); //0�� �ڸ��� �����ϱ� ���ؼ��� �ٷ� ������ 0�� �ڸ��� ������ ���¿��� ��ġ�� ����ؾ� �Ѵ�.
        for (int c=1; c<=min(t+1, 30); c++) {
            //c�� ��ġ�� �����ϱ� ���ؼ���
            //�ٷ� ������ c-1�� ��ġ�� ������ ���¿��� ��ġ�� �����ϰų�- (node0)
            Node node0 = makeNode(dpCache[t-1][c-1].numPlums + (tree[t]==changePosition(dpCache[t-1][c-1].currentPosition)), changePosition(dpCache[t-1][c-1].currentPosition));
            //if (t==1 && c==1) cout << "LOG0000:: " << toString(node0) << '\n';
            //�ٷ� ������ c�� ��ġ�� ������ ���¿��� ��ġ�� ����ؾ� �Ѵ�. (node1)
            Node node1 = makeNode(dpCache[t-1][c].numPlums + (tree[t]==dpCache[t-1][c].currentPosition), dpCache[t-1][c].currentPosition);
            //if (t==1 && c==1) cout << "LOG0001:: " << toString(node1) << '\n';
            dpCache[t][c] = max(node0, node1);
        }
    }

    Node optResult = dpCache[T-1][0];
    for (int c=1; c<=min(min(T, 30), W); c++) { //�ð� T�� ���� T�� ��ġ�� ������ �� �ִ�. T-1 ��� T�� ���� �Ѵ�.
        optResult = max(optResult, dpCache[T-1][c]);
    }
    cout << optResult.numPlums << '\n';

    /*
    for (int c=0; c<=30; c++) {
        for (int t=0; t<T; t++) {
            cout << toString(dpCache[t][c]) << ' ';
        }
        cout << '\n';
    }
    for (int i=0; i<T; i++) cout << tree[i] << '\n';
    */
    return 0;
}

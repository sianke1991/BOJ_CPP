#include <iostream>
#include <string>

using namespace std;

struct Node {
    //지금까지 모은 자두의 개수
    int numPlums;
    //현재 자두의 위치: 1 또는 2
    int currentPosition;
};

int tree[1000]; //각 시각에 자두가 떨어지는 자두나무 (1 또는 2)
//dpCache[t][0]: 시각 t에 0번 위치를 변경하여 얻을 수 있는 자두 개수
//dpCache[t][1]: 시각 t에 1번 위치를 변경하여 얻을 수 있는 자두 개수
//dpCache[t][c]: 시각 t에 c번 위치를 변경하여 얻을 수 있는 자두 개수
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

    //베이스 케이스
    dpCache[0][0] = makeNode(tree[0]==1, 1);
    dpCache[0][1] = makeNode(tree[0]==2, 2);

    //점화식
    for (int t=1; t<T; t++) {
        dpCache[t][0] = makeNode(dpCache[t-1][0].numPlums + (tree[t]==1), 1); //0번 자리를 변경하기 위해서는 바로 직전에 0번 자리를 변경한 상태에서 위치를 고수해야 한다.
        for (int c=1; c<=min(t+1, 30); c++) {
            //c번 위치를 변경하기 위해서는
            //바로 직전에 c-1번 위치를 변경한 상태에서 위치를 변경하거나- (node0)
            Node node0 = makeNode(dpCache[t-1][c-1].numPlums + (tree[t]==changePosition(dpCache[t-1][c-1].currentPosition)), changePosition(dpCache[t-1][c-1].currentPosition));
            //if (t==1 && c==1) cout << "LOG0000:: " << toString(node0) << '\n';
            //바로 직전에 c번 위치를 변경한 상태에서 위치를 고수해야 한다. (node1)
            Node node1 = makeNode(dpCache[t-1][c].numPlums + (tree[t]==dpCache[t-1][c].currentPosition), dpCache[t-1][c].currentPosition);
            //if (t==1 && c==1) cout << "LOG0001:: " << toString(node1) << '\n';
            dpCache[t][c] = max(node0, node1);
        }
    }

    Node optResult = dpCache[T-1][0];
    for (int c=1; c<=min(min(T, 30), W); c++) { //시간 T에 대해 T번 위치를 변경할 수 있다. T-1 대신 T가 들어가야 한다.
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

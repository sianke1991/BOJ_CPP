#include <iostream>
#include <string>
#include <vector>

using namespace std;
/**�ڿ����� ����*/
int N;
/**������ �ڿ����� ����*/
int M;
/**������ �� �ִ� ��� ��츦 ���� ����Ʈ*/
vector<string> resultList;
int selectedNumbers[8];

void recursion(int depth) {
    //base case
    if (depth == M) {
        string lsCase = "";
        for (int i=0; i<M; i++) {
            lsCase += to_string(selectedNumbers[i])+" ";
        } //i loop
        resultList.push_back(lsCase);
        return;
    }

    int prevNumber = (depth==0) ? 1 : selectedNumbers[depth-1]; //������ ���ϴ� ��� �ٷ� ������ �ִ� �� ���� �����ϸ� �ȴ�. (isUsed �迭�� ������� �ʾƵ� OK)
    for (int i=prevNumber; i<=N; i++) {
        selectedNumbers[depth] = i;
        recursion(depth+1);
    } //i loop
}


int main() {
    cin >> N >> M;
    recursion(0);
    for (string lsCase:resultList) {
        cout << lsCase << '\n';
    }
    return 0;
}

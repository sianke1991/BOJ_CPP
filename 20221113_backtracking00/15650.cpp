#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, M;
int selectedNumbers[10];
bool isUsed[10];
vector<string> resultList;

/**maximum number among the selected number*/
int maxSelected() {
    for (int i=N; i>=0; i--) {
        if (isUsed[i]) return i;
    }
    return 0;
}

void recursion(int depth) {
    //base case
    if (depth == M) {
        string lsCase = "";
        for (int i=0; i<M; i++) {
            lsCase += to_string(selectedNumbers[i])+" ";
        }
        resultList.push_back(lsCase);
        return;
    }

    for (int i=maxSelected()+1; i<=N; i++) { //i가 1 부터 시작할 필요는 없다. [선택된 수 중 최대치+1] 부터 시작해도 OK
        selectedNumbers[depth] = i;
        isUsed[i] = true;
        recursion(depth+1);
        isUsed[i] = false;
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

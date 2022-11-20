#include <iostream>
#include <string>
#include <vector>

using namespace std;
/**자연수의 개수*/
int N;
/**선택할 자연수의 개수*/
int M;
/**선택할 수 있는 모든 경우를 담은 리스트*/
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

    int prevNumber = (depth==0) ? 1 : selectedNumbers[depth-1]; //조합을 구하는 경우 바로 직전에 있는 수 부터 선택하면 된다. (isUsed 배열을 사용하지 않아도 OK)
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

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, M;
int selectedNumbers[10];
bool isUsed[10]={0};
vector<string> resultList;

void recursion(int depth) {
    //base case
    if (depth==M) {
        string lsCase = "";
        for (int i=0; i<M; i++) {
            lsCase += to_string(selectedNumbers[i])+" ";
        }
        resultList.push_back(lsCase);
        return;
    }

    for (int i=1; i<=N; i++) {
        if (isUsed[i]) continue; //if the number is already used (for loop가 중단되어서는 안되므로 return, break 대신에 continue를 사용해야 한다.)
        selectedNumbers[depth] = i;
        isUsed[i] = true;
        recursion(depth+1);
        isUsed[i] = false; //i가 사용되는 경우는 전부 고려한 것이므로 i를 selectedNumbers에서 빼 주어야 한다.
    } //i loop
}

int main() {
    cin >> N >> M;
    //scanf("%d %d", &N, &M);
    recursion(0);
    for (string lsCase:resultList) {
        cout << lsCase << '\n';
        //printf("%s\n", lsCase);
    }
    return 0;

}

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
        if (isUsed[i]) continue; //if the number is already used (for loop�� �ߴܵǾ�� �ȵǹǷ� return, break ��ſ� continue�� ����ؾ� �Ѵ�.)
        selectedNumbers[depth] = i;
        isUsed[i] = true;
        recursion(depth+1);
        isUsed[i] = false; //i�� ���Ǵ� ���� ���� ����� ���̹Ƿ� i�� selectedNumbers���� �� �־�� �Ѵ�.
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

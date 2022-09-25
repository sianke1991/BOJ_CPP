#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<char> positionArr;
int numServedPeople = 0;

void input() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0); //cout.tie(0);
    //위와 같이 설정한 이후에는 printf / scanf를 사용하지 않아야 한다.
    cin >> N >> K;
    char lcTemp;

    for (int i=0; i<N; i++) {
        cin >> lcTemp;
        positionArr.push_back(lcTemp);
    }
}

// 가능한 왼쪽에 있는 햄버거부터 대접한다.
void serve(int idxPerson) {
    for (int i=idxPerson-K; i<= idxPerson+K; i++) {
        if (i<0 || i>=N) continue; //index out of bounds
        if (positionArr[i]=='H') {
            positionArr[i]='h';
            numServedPeople++;
            break;
        }
    } //i loop
}



int main() {

    input();

    for (int i=0; i<N; i++) {
        if (positionArr[i]=='P') serve(i);
    }

    cout << numServedPeople;

    return 0;
}

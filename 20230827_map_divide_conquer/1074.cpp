#include <iostream>
// 분할 정복 (divide and conquer)
using namespace std;

int N, r, c;
int ans=0;

void Z(int x, int y, int size) {
    //베이스 케이스
    if (size==1) { //격자의 크기가 1까지 줄어들었을 때-
        if (x==r && y==c) {
            cout << ans;
            return;
        } else {
            ans++; //이 함수는 격자를 Z 순서대로 방문하므로 이전에 방문한 칸의 개수가 정답이 된다.
            return;
        }
    }

    if (!(x<=r && r<x+size && y<=c && c<y+size)) { //현재 살펴보고 있는 4분면에 정답이 포함되지 않은 경우
        ans += size*size; //해당 4분면은 일일히 방문하지 않고 격자 크기만큼 ans를 증가시킨다.
        return;
    }

    //4등문을 하니 함수를 네 번 호출한다.
    int halfSize = size/2;
    Z(x, y, halfSize); //왼쪽 위
    Z(x, halfSize+y, halfSize); //오른쪽 위
    Z(halfSize+x, y, halfSize); //왼쪽 아래
    Z(halfSize+x, halfSize+y, halfSize); //오른쪽 아래
}

int main() {
    cin >> N >> r >> c;
    Z(0, 0, 1<<N);
    return 0;
}

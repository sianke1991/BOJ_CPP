#include <bits/stdc++.h>
using namespace std;

//재귀로 문제 풀기
//1. 함수 정의 (파라미터, 반환값)
//2. base case (재귀가 종료될 조건)
//3. 재귀식 (점화식)

/**원반 이동 목록*/
vector<pair<int, int>> moveList;

/**두 장대 번호를 입력했을 때 남은 하나의 장대 번호를 반환한다.*/
int getTheOtherPole(int poleA, int poleB) {
    switch (poleA*10+poleB) {
        case 12: return 3;
        case 13: return 2;
        case 21: return 3;
        case 23: return 1;
        case 31: return 2;
        case 32: return 1;
        default: return -1;
    }
}

//함수 정의 (재귀 함수)
void howToMove(int from, int to, int numRings) {
    //base cases
    if (numRings==1) {
        moveList.push_back({from, to});
        return;
    } else if (numRings==0) {
        return;
    }

    //재귀식
    int theOtherPole = getTheOtherPole(from, to); //이 식은 6-from-to로 작성할 수도 있다.
    //1. 맨 바닥 원반을 제외한 나머지 원반을 제 3의 장대로 이동시킨다.
    howToMove(from, theOtherPole, numRings-1);
    //2. 맨 바닥 원반 하나를 목표 장대로 이동시킨다.
    howToMove(from, to, 1);
    //3. 맨 바닥 원반을 제외한 나머지 원반을 제 3의 장대에서 목표 장대로 이동시킨다.
    howToMove(theOtherPole, to, numRings-1);
}

int main() {
    int N; //the number of rings
    cin >> N;
    howToMove(1, 3, N);
    cout << moveList.size() << '\n';
    for (pair<int, int> p:moveList) {
        cout << p.first << ' ' << p.second << '\n';
    }
    return 0;
}

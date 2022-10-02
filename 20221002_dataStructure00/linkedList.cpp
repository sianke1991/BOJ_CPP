#include <iostream>
#include <algorithm>

using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num) {
    dat[unused] = num;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];

    if (nxt[addr] != -1) pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    unused++;
}

void insert_test(){
    insert(0, 10); //10
    insert(0, 30); //30 10
    insert(2, 40); //30 40 10
    insert(1, 20); //30 40 10 20
    insert(4, 70); //30 40 10 20 70
}

void traverse() {
    int cur = nxt[0];
    while (cur != -1) {
        cout << dat[cur] << ' ';
        cur = nxt[cur];
    }
    cout << "\n\n";
}


int main() {
    fill(pre, pre+MX, -1); //pre 부터 pre+MX-1 까지 위치의 값을 -1로 설정한다.
    fill(nxt, nxt+MX, -1);

    insert_test();
    erase_test();

    return 0;
}

/*
연결 리스트
각 노드에 값과 다음 노드의 위치를 저장한다.
조회, 변경에 O(k) 만큼의 시간이, 추가 및 제거에 O(1) 만큼의 시간이 소요된다.

연결 리스트 종류
1. 단일 연결 리스트
2. 이중 연결 리스트 (각 노드에 값, 다음 노드의 위치 및 이전 노드의 위치를 저장한다.)
3. 원형 연결 리스트 (마지막 노드가 맨 처음 노드의 위치를 가리킨다.)

배열 vs. 연결 리스트
    배열  연결리스트
조회 O(1)   O(k)
추가 O(N)   O(1)
메모리 연속  불연속


더미 노드
연결 리스트에서 시작 노드는 고정되어 있다. 즉, 길이가 0인 연결 리스트는 생각하지 않는다.
*/

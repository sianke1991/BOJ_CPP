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
    fill(pre, pre+MX, -1); //처음에는 -1로 채운다.
    fill(nxt, nxt+MX, -1);

    insert_test();
    erase_test();

    return 0;
}

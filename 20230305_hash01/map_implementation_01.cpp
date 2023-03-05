#include <bits/stdc++.h>
using namespace std;

const int M = 1000003;
const int a = 1000;
const int MX = 5000005; //최대 삽입 횟수
int head[M];
int pre[MX];
int nxt[MX];
string key[MX];
int val[MX];
int unused = 0;

int my_hash(string& s) {
    int h=0;
    for (auto x:s) {
        h = (h*a+x)%M;
    }
    return h;
}

//key[idx]==k인 idx를 반환, 만약 k가 존재하지 않을 경우 -1을 반환
//키에 대응되는 값을 반환하는게 아니라 인덱스를 반환함에 주의
int find(string k) {

}

void insert(string k, int v) {

}

void erase(string k) {

}

void test() {

}

int main() {
    fill(head, head+M, -1);
    fill(pre, pre+MX, -1);
    fill(nxt, nxt+MX, -1);
    test();

    return 0;
}

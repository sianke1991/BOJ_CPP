#include <bits/stdc++.h>
using namespace std;

const int M = 1000003;
const int a = 1000;
const int MX = 5000005; //�ִ� ���� Ƚ��
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

//key[idx]==k�� idx�� ��ȯ, ���� k�� �������� ���� ��� -1�� ��ȯ
//Ű�� �����Ǵ� ���� ��ȯ�ϴ°� �ƴ϶� �ε����� ��ȯ�Կ� ����
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

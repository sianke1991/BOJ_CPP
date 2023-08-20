#include <bits/stdc++.h>

using namespace std;


const int ROOT = 1;
int unused = 2;
const int MX = 10000 * 500 + 5;
bool chk[MX];
//int nxt[MX][26];
map<char, int> nxt[MX];

int c2i(char ch) {
    return ch-'a';
}

void Insert(string s) {
    int cur = ROOT;
    for (char ch:s) {
        if (nxt[cur].find(ch)==nxt[cur].end()) {
            nxt[cur][ch] = unused++;
        }
        cur = nxt[cur][ch];
    }
    chk[cur] = true;
}

bool Find(string s) {
    int cur = ROOT;
    for (char ch:s) {
        if (nxt[cur].find(ch)==nxt[cur].end()) return false;
        cur = nxt[cur][ch];
    }
    return chk[cur];
}

int main() {
    int N, M;
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        string str;
        cin >> str;
        Insert(str);
    }
    int numMatches = 0;
    for (int i=0; i<M; i++) {
        string str;
        cin >> str;
        if (Find(str)) numMatches++;
    }
    cout << numMatches;
    return 0;
}

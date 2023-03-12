#include <bits/stdc++.h>
using namespace std;


const int M = 1000003;
const int a = 1000;
const int EMPTY = -1;
const int OCCUPY = 0;
const int DUMMY = 1;
int status[M]; //EMPTY / OCCUPY / DUMMY
string key[M];
int val[M];

int my_hash(string& s) {
    int h = 0;
    for (auto x:s) {
        h = (h*a+x)%M;
        return h;
    }
}

    //key[idx]==k인 idx를 반환, 만약 k가 존재하지 않을 경우 -1을 반환
    //키에 대응되는 값을 반환하는게 아니라 인덱스를 반환함에 주의
int find(string k) {
    int hsh = my_hash(k);
    if (key[hsh]==k && status[hsh]==OCCUPY) return hsh;
    int idx = (hsh+1)%M;
    while (idx!=hsh && status[idx]!=EMPTY) {
        if (key[idx]==k && status[idx]==OCCUPY) return idx;
        idx = (idx+1)%M;
    }
    return -1;
}

void insert(string k, int v) {
    int idx = find(k);
    if (idx>=0) { //if the string key exists in the array key
        val[idx] = v;
        return;
    }
    int hsh = my_hash(k);
    idx = hsh;
    if (status[idx]!=OCCUPY) {
        status[idx] = OCCUPY;
        key[idx] = k;
        val[idx] = v;
        return;
    }
    idx=(idx+1)%M;
    while (idx!=hsh) {
        if (status[idx]!=OCCUPY) {
            status[idx] = OCCUPY;
            key[idx] = k;
            val[idx] = v;
            return;
        }
        idx=(idx+1)%M;
    }
}

void erase(string k) {
    int idx = find(k);
    if (idx>=0) status[idx] = DUMMY;
}

/**
 * 문자열 k에 해당하는 값 정수값 v를 반환한다.
 */
int get(string k) {
    int idx = find(k);
    return idx>=0 ? val[idx] : -1;
}

string toString() {
    string result = "";
    for (int i=0; i<M; i++) {
        if (status[i]!=OCCUPY) continue;
        result += "["+key[i]+": "+to_string(val[i])+"]";
    }
    return result;
}

void test() {
    cout << toString() << '\n';
    insert("Dragoon", 150);
    insert("Overload", 100);
    insert("Goliath", 100);
    cout << toString() << '\n';
    cout << get("Dragoon") << '\n';
    insert("Dragoon", 125);
    cout << toString() << '\n';
    cout << get("Dragoon") << '\n';
    erase("Dragoon");
    cout << toString() << '\n';
}

int main() {
    fill(status, status+M, EMPTY);
    test();
    return 0;
}

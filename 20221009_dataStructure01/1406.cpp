#include <list>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;
    list<char> l;
    for (char ch:str) {
        l.push_back(ch);
    }
    list<char>::iterator t = l.end();
    int M; //명령어 개수
    cin >> M;
    for (int i=0; i<M; i++) {
        char cmd; //명령어 (L, D, B, P)
        cin >> cmd;
        switch (cmd)
        {
            case 'L':
                if (t==l.begin()) continue;
                t--;
                break;
            case 'D':
                if (t==l.end()) continue;
                t++;
                break;
            case 'B':
                if (t==l.begin()) continue;
                t = l.erase(--t);
                break;
            case 'P':
                char ch;
                cin >> ch;
                l.insert(t, ch);
                break;
        } //cmd switch
    } //i loop
    for (list<char>::iterator it = l.begin(); it != l.end(); it++) {
        cout << *it;
    }
    return 0;
}

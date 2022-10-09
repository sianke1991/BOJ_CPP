#include <iostream>
#include <string>

using namespace std;

struct CHAR {
    CHAR* prev;
    char val;
    CHAR* next;
};

int main() {
    string str;
    cin >> str;
    CHAR begin;
    CHAR li[str.length()+1];
    for (int i=0; i<str.length(); i++) {
        li[i].val = str[i];
        if (i==0) {
            li[i].prev = NULL;
            li[i].next = str.length()>0 ? &li[i-1] : NULL;
        } else if (i==str.length()-1) {
            li[i].next = NULL;
            li[i].prev = str.length()>0 ? &li[i-1] : NULL;
        } else {
            li[i].next = &li[i+1];
            li[i].prev = &li[i-1];
        }
    } //i loop

    begin.next = &li[0];
    begin.prev = NULL;
    CHAR cur = li[str.length()];
    cur.next = NULL;
    cur.prev = &(li[str.length()-1]);
    int M;
    cin >> M;
    for (int i=0; i<M; i++) {
        char cmd;
        cin >> cmd;
        switch (cmd) {
            case 'L':
                if (cur.prev==NULL) continue;
                cur = *(cur.prev);
                break;
            case 'D':
                if (cur.next==NULL) continue;
                cur = *(cur.next);
                break;
            case 'B':
                if ((*(cur.prev)).prev==NULL) {
                    begin.next = &cur;
                    cur.prev = NULL;
                } else {
                    (*((*(cur.prev)).prev)).next = &cur;
                    cur.prev = (*(cur.prev)).prev;
                }
                break;
            case 'P':
                char ch;
                cin >> ch;
                if (cur.prev==NULL) {
                    CHAR brand;
                    brand.val = ch;
                    brand.prev = &begin;
                    brand.next = &cur;
                    begin.next = &brand;
                    cur.prev = &brand;
                } else {
                    CHAR brand;
                    brand.val = ch;
                    brand.prev = cur.prev;
                    brand.next = &cur;
                    (*(cur.prev)).next = &brand;
                    cur.prev = &brand;
                }
                break;
        } //cmd switch
    } //i loop

    CHAR print = begin;
    while (print.next!=NULL) {
        print = *(print.next);
        cout << print.val;
    }
    return 0;
}

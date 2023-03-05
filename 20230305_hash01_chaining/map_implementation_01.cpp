#include <bits/stdc++.h>
using namespace std;

const int M = 1000003;
const int a = 1000;
const int MX = 5000005; //최대 삽입 횟수
/*
int head[M];
int pre[MX];
int nxt[MX];
string key[MX];
int val[MX];
int unused = 0;
*/

//LINKED LIST 구현 부분
struct Node {
	Node* prev;
	string key;
	int value;
	Node* next;	
};

Node mmap[M];

bool put(int hash, string key, int value) {
	Node* ptrNode = mmap[hash].next;
	while (ptrNode!=NULL) {
		if (ptrNode->key==key) {
			ptrNode->value = value;
			return false;
		}
		ptrNode = ptrNode->next;
	}
	ptrNode = new Node;
	ptrNode->prev = &mmap[hash];
	ptrNode->key = key;
	ptrNode->value = value;
	ptrNode->next = mmap[hash].next;
	if (mmap[hash].next!=NULL) mmap[hash].next->prev = ptrNode;
	mmap[hash].next = ptrNode;
	return true;
}

bool del(int hash, string key) {
	Node* ptrNode = mmap[hash].next;
	while (ptrNode!=NULL) {
		if (ptrNode->key==key) {
			ptrNode->prev->next = ptrNode->next;
			if (ptrNode->next!=NULL) ptrNode->next->prev = ptrNode->prev;
			return true;
		}
		ptrNode = ptrNode->next;
	}
	return false;
}

bool contains(int hash, string key) {
	Node* ptrNode = mmap[hash].next;
	while (ptrNode!=NULL) {
		if (ptrNode->key==key) return true;
		ptrNode = ptrNode->next;
	}
	return false;
}

int get(int hash, string key) {
	Node* ptrNode = mmap[hash].next;
	while (ptrNode!=NULL) {
		if (ptrNode->key==key) return ptrNode->value;
		ptrNode = ptrNode->next;
	}
	return 0;
}

string toString(int hash) {
	string result = "";
	Node* ptrNode = mmap[hash].next;
	while (ptrNode!=NULL) {
		result+="["+ptrNode->key+", "+to_string(ptrNode->value)+"]";
		ptrNode = ptrNode->next;
	}
	return result;
}

//HASH MAP이 수행할 수 있어야 하는 기능들
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
	return get(my_hash(k), k);
}

void insert(string k, int v) {
	put(my_hash(k), k, v);
}

void erase(string k) {
	del(my_hash(k), k);
}

string toString() {
	string result = "";
	for (int i=0; i<M; i++) {
		result+=toString(i);
	}
	return result;
}

void test() {
	insert("dragoon", 150);
	insert("overload", 100);
	insert("goliath", 100);
	cout << toString() << '\n'; //[overload, 100][goliath, 100][dragoon, 150]
	cout << find("dragoon") << '\n'; //150
	erase("probe");
	cout << toString() << '\n'; //[overload, 100][goliath, 100][dragoon, 150]
	erase("goliath");
	cout << toString() << '\n'; //[overload, 100][dragoon, 150]
	insert("dragoon", 125);
	cout << toString() << '\n'; //[overload, 100][dragoon, 125]
	cout << find("dragoon") << '\n'; //125
}

int main() {
	/*
    fill(head, head+M, -1);
    fill(pre, pre+MX, -1);
    fill(nxt, nxt+MX, -1);
    */
    for (int i=0; i<M; i++) {
    	mmap[i].prev = NULL;
    	mmap[i].key = "";
    	mmap[i].value = 0;
    	mmap[i].next = NULL;
	}
    test();

    return 0;
}

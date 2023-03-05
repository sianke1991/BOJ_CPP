#include <bits/stdc++.h>
using namespace std;


struct Node {
	Node* prev;
	string val;
	Node* next;
};

Node llist = {NULL, "", NULL};

void pushFront(string val) {
	Node* ptrNode = new Node; //구조체 동적 할당
	ptrNode->prev = &llist;
	ptrNode->val = val;
	ptrNode->next = llist.next;
	if (llist.next!=NULL) llist.next->prev = ptrNode; //구조체 변수의 포인터는 점 대신 화살표로 멤버 필드에 접근한다. NULL 포인터로 멤버 필드에 접근하지 않도록 NULL 체크를 해 준다.
	llist.next = ptrNode;
}

bool delElemWith(string val) {
	Node* ptrNode = llist.next;
	while (ptrNode!=NULL) {
		if (ptrNode->val==val) {
			ptrNode->prev->next = ptrNode->next;
			if (ptrNode->next!=NULL) ptrNode->next->prev = ptrNode->prev;
			return true;
		}
		ptrNode = ptrNode->next;
	}
	return false;
}

string toString() {
	string result = "";
	Node* ptrNode = llist.next;
	while (ptrNode!=NULL) {
		result+="["+ptrNode->val+"]";
		ptrNode = ptrNode->next;
	}
	return result;
}



int main() {
	pushFront("abc");
	pushFront("def");
	pushFront("ghi");
	pushFront("jkl");
	cout << toString() << '\n'; //[jkl][ghi][def][abc]
	delElemWith("abc");
	cout << toString() << '\n'; //[jkl][ghi][def]
	delElemWith("abd");
	cout << toString() << '\n'; //[jkl][ghi][def]
	delElemWith("jkl");
	cout << toString() << '\n'; //[ghi][def]
	return 0;
}
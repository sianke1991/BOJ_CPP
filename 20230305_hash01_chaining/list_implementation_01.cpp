#include <bits/stdc++.h>
using namespace std;

struct Node {
	Node* prev;
	string key;
	string value;
	Node* next;
};

Node llist = {NULL, "", "", NULL};

bool put(string key, string value) {
	Node* ptrNode = llist.next;
	while (ptrNode!=NULL) {
		if (ptrNode->key==key) {
			ptrNode->value = value;
			return false;
		}
		ptrNode = ptrNode->next;
	}
	ptrNode = new Node;
	ptrNode->prev = &llist;
	ptrNode->key = key;
	ptrNode->value = value;
	ptrNode->next = llist.next;
	if (llist.next!=NULL) llist.next->prev = ptrNode;
	llist.next = ptrNode;
	return true;
}

bool del(string key) {
	Node* ptrNode = llist.next;
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

bool contains(string key) {
	Node* ptrNode = llist.next;
	while (ptrNode!=NULL) {
		if (ptrNode->key==key) return true;
		ptrNode = ptrNode->next;
	}
	return false;
}

string get(string key) {
	Node* ptrNode = llist.next;
	while (ptrNode!=NULL) {
		if (ptrNode->key==key) return ptrNode->value;
		ptrNode = ptrNode->next;
	}
	return "";
}

string toString() {
	string result = "";
	Node* ptrNode = llist.next;
	while (ptrNode!=NULL) {
		result+="["+ptrNode->key+", "+ptrNode->value+"]";
		ptrNode = ptrNode->next;
	}
	return result;
}

int main() {
	put("dragoon", "protoss");
	put("goliath", "terran");
	put("overload", "zerg");
	cout << toString() << '\n'; //[overload, zerg][goliath, terran][dragoon, protoss]
	cout << get("overload") << '\n'; //zerg
	cout << get("zergling") << '\n';
	put("overload", "Zerg");
	cout << toString() << '\n'; //[overload, Zerg][goliath, terran][dragoon, protoss]
	return 0;
}
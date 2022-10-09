#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MX = 1000002;
int  prv[MX];
char val[MX];
int  nxt[MX];
int  unused = 1;

void init() {
	fill(prv, prv+MX, -1);
	fill(nxt, nxt+MX, -1);
	nxt[0] = 1;
}

void traverse() {
	int liTmp = 0;
	while (nxt[liTmp]!=-1) {
		liTmp = nxt[liTmp];
		cout << val[liTmp];
	}
}

int main() {
	//0. initialize
	init();
	
	//1. convert a string into a linkedlist
	string str;
	cin >> str;
	for (char ch:str) {
		prv[unused] = unused-1;
		val[unused] = ch;
		nxt[unused] = unused+1;
		unused++;
	}
	prv[1] = -1;
	nxt[str.length()] = -1;
	int cursor = MX-1;
	nxt[cursor] = -1;
	prv[cursor] = str.length();
	val[cursor] = 0;
	
	//2. input M consecutive commands
	int M;
	cin >> M;
	for (int i=0; i<M; i++) {
		char cmd;
		cin >> cmd;
		switch (cmd)
		{
			case 'L': //moves the cursor to the left
			{
				int liPrv = prv[cursor];
				if (liPrv<0) continue; //if the cursor locates at the very beginning of the string
				cursor = liPrv;
			}
			break;
			case 'D': //moves the cursor to the right
			{
				if (val[cursor]==0) continue; //if the cursor locates at the very last of the string
				int liNxt = nxt[cursor];
				if (liNxt<0) { //if only one character exists at the right of the cursor
					cursor = MX-1;
				} else {
					cursor = liNxt;
				}
			}
			break;
			case 'B': //delete a character (backspace)
			{
				int liPrv = prv[cursor];
				if (liPrv<0) continue; //if the cursor locates at the very beginning of the string
				int liDblPrv = prv[liPrv];
				if (liDblPrv<0) { //if only one character exists at the left of the cursor
					nxt[0] = cursor;
					prv[cursor] = -1;
				} else {
					nxt[liDblPrv] = cursor;
					prv[cursor] = liDblPrv;
				}
			}
			break;
			case 'P': //insert a character
			{
				char ch;
				cin >> ch;
				
				int liPrv = prv[cursor];
				int liNxt = nxt[cursor];
				
				if (liPrv<0) { //if the cursor locates at the very beginning of the string
					val[unused] = ch;
					prv[unused] = -1;
					nxt[unused] = cursor;
					nxt[0] = unused;
					prv[cursor] = unused;
				} else if (val[cursor]==0) { //if the cursor locates at the very last of the string
					val[unused] = ch;
					prv[unused] = prv[cursor];
					nxt[unused] = -1;
					nxt[prv[cursor]] = unused;
					prv[cursor] = unused;
				} else {
					val[unused] = ch;
					prv[unused] = prv[cursor];
					nxt[unused] = cursor;
					nxt[prv[cursor]] = unused;
					prv[cursor] = unused;
				}
			}
			unused++;
			break;
		} //cmd switch
	} //i loop


	traverse();
	
	return 0;
}
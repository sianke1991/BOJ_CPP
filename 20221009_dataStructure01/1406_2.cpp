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
/*
1. 실제 cursor가 가리키고 있는 문자
  텍스트 에디터에서 커서가 깜박이고 있다면 cursor가 가리키는 문자는 깜박이는 커서 바로 오른쪽에 있는 문자이다.
  커서를 오른쪽으로 움직일 때, 텍스트 에디터에 문자를 넣을 떄는 cursor가 가리키는 문자가 [문자열의 맨 마지막 문자]인지, [그 다음 NULL 문자]인지
  구분할 필요가 있는데 이 경우 다음 순서대로 행한다.
    if (val[cursor]==0) //[현재 cursor가 NULL 문자를 가리키는 경우]
    else if (nxt[cursor]==-1) //[현재 cursor가 마지막 문자를 가리키는 경우]
  NULL 문자 역시 nxt[cursor]==-1 조건을 만족하므로 nxt[cursor]==-1 조건을 먼저 사용하면 두 경우를 구분할 수 없게 된다. 따라서 반드시
  위 순서대로 분기하도록 한다.
2. 문자 삭제 시
  삭제할 문자는 값을 변경할 필요가 없다.
  삭제할 문자 앞뒤의 노드를 서로 연결해준다.
3. 문자 삽입 시
  새로 생성한 문자를 연결해준다.
  생성한 문자 앞에 있는 문자를 먼저 연결해준다.
  커서 문자(새로 생성한 문자 뒤에 있는 문자)를 그 다음에 연결해준다.
*/

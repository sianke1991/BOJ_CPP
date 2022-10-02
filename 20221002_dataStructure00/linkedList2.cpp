#include <iostream>
#include <algorithm>

using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1; //배열 내 아직 값이 채워지지 않은 공간의 인덱스값

void insert(int addr, int num) {
	//1. 배열에 값을 넣는다. (새로운 노드를 생성한다.)
	dat[unused] = num;
	pre[unused] = addr; //새로 추가한 노드는 addr 노드의 다음 노드이다.
	nxt[unused] = nxt[addr]; //addr 노드가 본래 가리키고 있던 값을 가져온다.
	
	//2. 기존에 있던 노드가 가리키고 있는 노드를 변경한다.
	if (nxt[addr]!=-1) pre[nxt[addr]] = unused; //addr 노드가 가리키고 있던 노드가 있었을 경우 해당 노드의 이전 노드를 '이번에 새로 생성한 노드'로 변경한다.
	nxt[addr] = unused; //addr 노드의 다음 노드를 '이번에 새로 생성한 노드'로 변경한다.
	unused++;
}

void del(int addr) {
	//0. 예외 사항 처리
	if (unused<=1) return;
	
	//1. 기존에 있던 노드가 가리키고 있는 노드를 변경한다.
	if (nxt[addr]!=-1) {
		pre[nxt[addr]] = pre[addr]; //addr 노드 다음 노드가 있는 경우 해당 노드의 이전 노드 값을 변경해야 한다.
		nxt[pre[addr]] = nxt[addr]; //addr 노드 다음 노드가 있는 경우 addr 이전 노드의 다음 노드 값을 변경해야 한다.
	} else {
		nxt[pre[addr]] = -1;
	}
}

void insert_test() {
	insert(0, 10); //10
	insert(0, 30); //30 10
	insert(2, 40); //30 40 10
	insert(1, 20); //30 40 10 20
	insert(4, 70); //30 40 10 20 70
}

void delete_test() {
	del(1); //30 40 20 70
	del(3); //30 20 70
}

void traverse() {
	int cur = nxt[0];
	while (cur!=-1) {
		cout << dat[cur] << ' ';
		cur = nxt[cur];
	}
	cout << '\n';
}

void printArray(int arr[]) {
	for (int i=1; i<MX; i++) {
		if (dat[i]==-1) break;
		cout << i << ": " << arr[i] << '\n';
	}
}


int main() {
	fill(dat, pre+MX, -1);
	fill(pre, nxt+MX, -1);
	fill(nxt, nxt+MX, -1);
	
	insert_test();
	traverse();
	delete_test();
	traverse();
	
	return 0;
}
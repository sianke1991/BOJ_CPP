#include <iostream>
#include <algorithm>

using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1; //�迭 �� ���� ���� ä������ ���� ������ �ε�����

void insert(int addr, int num) {
	//1. �迭�� ���� �ִ´�. (���ο� ��带 �����Ѵ�.)
	dat[unused] = num;
	pre[unused] = addr; //���� �߰��� ���� addr ����� ���� ����̴�.
	nxt[unused] = nxt[addr]; //addr ��尡 ���� ����Ű�� �ִ� ���� �����´�.
	
	//2. ������ �ִ� ��尡 ����Ű�� �ִ� ��带 �����Ѵ�.
	if (nxt[addr]!=-1) pre[nxt[addr]] = unused; //addr ��尡 ����Ű�� �ִ� ��尡 �־��� ��� �ش� ����� ���� ��带 '�̹��� ���� ������ ���'�� �����Ѵ�.
	nxt[addr] = unused; //addr ����� ���� ��带 '�̹��� ���� ������ ���'�� �����Ѵ�.
	unused++;
}

void del(int addr) {
/*	
    //0. ���� ���� ó��
	if (unused<=1) return;
	
	//1. ������ �ִ� ��尡 ����Ű�� �ִ� ��带 �����Ѵ�.
	if (nxt[addr]!=-1) {
		pre[nxt[addr]] = pre[addr]; //addr ��� ���� ��尡 �ִ� ��� �ش� ����� ���� ��� ���� �����ؾ� �Ѵ�.
		nxt[pre[addr]] = nxt[addr]; //addr ��� ���� ��尡 �ִ� ��� addr ���� ����� ���� ��� ���� �����ؾ� �Ѵ�.
	} else {
		nxt[pre[addr]] = -1;
	}
*/
    nxt[pre[addr]] = nxt[addr];
    if (nxt[addr]!=-1) pre[nxt[addr]] = pre[addr];	
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

#include <iostream>
#include <algorithm>

using namespace std;

int isSelecting[3002]; //현재 연산중인 loop에서 특정 종류의 초밥이 몇 개 선택되었는지 개수를 담는 배열
int dishes[30000]; //각 원소는 해당 위치에 있는 초밥의 종류를 나타낸다.



int main() {
	int N; //접시 개수(배열 길이)
	int d; //초밥의 종류 개수
	int k; //연속해서 먹는 접수의 개수
	int c; //쿠폰 번호
//	bool isContainingC = false; //초밥 벨트에 초밥 c가 놓여있는지 여부
	cin >> N >> d >> k >> c;
	for (int i=0; i<N; i++) {
		cin >> dishes[i];
//		if (dishes[i]==c) isContainingC = true;
	} //i loop
	
	
	int currentVal = 0; //현재 연산중인 loop에서 선택한 초밥의 가짓수
	int idxSt = 0;
	int idxEd = k-1;
	for (int i=idxSt; i<=idxEd; i++) {
		if (isSelecting[dishes[i]]==0) currentVal++;
		isSelecting[dishes[i]]++;
	} //i loop
	int optVal = isSelecting[c]==0 ? currentVal+1 : currentVal; //주어진 회전 초밥 벨트에서 먹을 수 있는 초밥의 가짓수의 최댓값
	
	for (int i=0; i<N-1; i++) { //회전 초밥의 시작점을 거쳐서 선택하는 경우도 고려해야 하므로 N-k 번이 아닌 N-1 번 루프를 돌아야 한다.
		idxEd = (idxEd+1)%N;
		if (isSelecting[dishes[idxEd]]==0) currentVal++;
		isSelecting[dishes[idxEd]]++;
		if (isSelecting[dishes[idxSt]]==1) currentVal--;
		isSelecting[dishes[idxSt]]--;
		idxSt++;
		optVal = max(optVal, isSelecting[c]==0 ? currentVal+1 : currentVal);
	} //i loop
	
	cout << optVal;
	return 0;
}
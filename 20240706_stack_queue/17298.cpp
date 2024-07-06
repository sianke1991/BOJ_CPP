#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int N;
int inputArray[1000001];
int result[1000001];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d", &inputArray[i]);
	} //i loop

	stack<int> s; //아직 오큰수를 만나지 못한 원소의 인덱스를 담는 스택
	for (int i=0; i<N; i++) {
		while (!s.empty() && inputArray[s.top()]<inputArray[i]) {
			result[s.top()] = inputArray[i];
			s.pop();
		} //while loop
		s.push(i);
	} //i loop

	while (!s.empty()) { //오큰수를 만나지 못하면 해당 수의 오큰수는 -1로 설정한다.
		result[s.top()] = -1;
		s.pop();
	} //while loop

	for (int i=0; i<N; i++) {
		printf("%d ", result[i]);
	}


	return 0;
}

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

	stack<int> s; //���� ��ū���� ������ ���� ������ �ε����� ��� ����
	for (int i=0; i<N; i++) {
		while (!s.empty() && inputArray[s.top()]<inputArray[i]) {
			result[s.top()] = inputArray[i];
			s.pop();
		} //while loop
		s.push(i);
	} //i loop

	while (!s.empty()) { //��ū���� ������ ���ϸ� �ش� ���� ��ū���� -1�� �����Ѵ�.
		result[s.top()] = -1;
		s.pop();
	} //while loop

	for (int i=0; i<N; i++) {
		printf("%d ", result[i]);
	}


	return 0;
}

#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

/**
 ���ڿ��� ���� ���������� AB, BC ���� �����ϴ� ��� - Queue ���
 ���ڿ��� ���� ������ ���� �����Ϸ��� BC ���� �����ϰ� �� �ڿ� AB ���� �����ؾ� �Ѵ�.
 e.g. ABCB
 ���ڿ� ���� ���� AB�� ���� �����ϸ� ���� CB�� ������ �� ����.
 ���ڿ� ���� ���� BC�� ���� �����ϸ� ���� AB�� ������ �� �ִ�.
 */
int main() {
	char input[300001];
	scanf("%s", input);
	int result = 0;
	queue<int> aIndices; //���� 'A'�� �ε����� ��´�. (AB ¦�� ����� �ش� �ε����� ť���� �����Ѵ�.)
	queue<int> bIndices;
	queue<int> cIndices;
	for (int i=0; input[i]!='\0'; i++) {
		switch (input[i]) {
			case 'A': aIndices.push(i); break;
			case 'B': bIndices.push(i); break;
			case 'C': cIndices.push(i); break;
		} //switch-case
	} //i loop

	//remove bc pairs first
	while (!bIndices.empty() && !cIndices.empty()) {
		if (bIndices.front()<cIndices.front()) {
			result++;
			bIndices.pop();
			cIndices.pop();
		} else {
			cIndices.pop(); //c�� �ε����� b�� �ε������� �۴ٸ�, �ش� c�� �ε����� ���ڿ����� ���ŵ� �� ����.
		}
	} //while loop

	//next remove ab pairs
	while (!aIndices.empty() && !bIndices.empty()) {
		if (aIndices.front()<bIndices.front()) {
			result++;
			aIndices.pop();
			bIndices.pop();
		} else {
			bIndices.pop();
		}
	}

	printf("%d", result);
	return 0;
}

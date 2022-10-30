#include <bits/stdc++.h>
using namespace std;

long long A, B, C;
long long result = 1;
stack<char> st; //'a': B to B/2, 'b': B to B-1
/*
지수를 0으로 만들어가는 과정의 역순으로 결과값을 구해나갈 수 있으므로,
지수를 0으로 만드는 과정을 스택에 넣고 이를 꺼내가면서 계산을 수행한다.
*/

void constructStack() {
	while (B!=0) {
		if (B%2) {
			B--;
			st.push('b');
		} else {
			B/=2;
			st.push('a');
		}
	}
}
void calculateMod() {
	while (!st.empty()) {
		switch (st.top()) {
			case 'a':
				result = result*result%C;
				break;
			case 'b':
				result = result*A%C;
				break;
		}
		st.pop();
	}
}
int main() {
	cin >> A >> B >> C;
	constructStack();
	calculateMod();
	cout << result;
	return 0;	
}

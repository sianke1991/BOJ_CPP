#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int heightOf[80001];
int results[80001];

/**
 오친수: 17298번과 비슷한 문제.
 */
int main() {
	int N;
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d", &heightOf[i]);
	} //i loop

	stack<int> s;
	for (int i=0; i<N; i++) {
		while (!s.empty() && heightOf[s.top()]<=heightOf[i]) {
			results[s.top()] = i-s.top()-1;
			s.pop();
		} //while loop
		s.push(i);
	} //i loop

	while (!s.empty()) {
		results[s.top()] = N-s.top()-1;
		s.pop();
	}

	long long result = 0LL;
	for (int elem:results) result+=elem;
	printf("%lld", result);


	return 0;
}

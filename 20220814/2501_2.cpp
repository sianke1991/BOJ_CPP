#include <iostream>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	
	int divisor=0, cnt=0;
	for (int i=1; i<=N; i++){
		if (N%i==0)
			cnt++;
		if (cnt==K){
			divisor = i;
			break;
		}
	}
	
	cout << divisor;
	return 0;
}
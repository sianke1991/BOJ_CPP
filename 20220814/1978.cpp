#include<iostream>

using namespace std;
const char UNDETERMINED = 0;
const char IS_NOT_PRIME = 1;
const char IS_PRIME     = 2;


int main() {
	char isPrime[1001] = {1, 1};
	for (int i=0; i<1001; i++) {
		if (isPrime[i]==IS_NOT_PRIME) continue;
		else if (isPrime[i]==UNDETERMINED) {
			isPrime[i] = IS_PRIME;
			int tempNum = i*2;
			while (tempNum<1001) {
				isPrime[tempNum] = IS_NOT_PRIME;
				tempNum += i;
			} //while loop
		}
	} //i loop
	
	
	int N;
	int numPrimes = 0;
	cin >> N;
	
	int numbers[N];
	for (int i=0; i<N; i++) {
		cin >> numbers[i];
		if (isPrime[numbers[i]]==IS_PRIME) numPrimes++;
	}
	
	cout << numPrimes;
	return 0;
}


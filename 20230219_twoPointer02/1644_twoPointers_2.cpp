#include <iostream>

using namespace std;
char isPrime[4000001]={1, 1, 2}; //0: undetermined, 1: false
int primes[283146]={2};

int main() {
	{
		int primesIdx = 1;
		for (int i=3; i<=4000000; i+=2) {
			if (isPrime[i]==0) {
				primes[primesIdx]=i;
				primesIdx++;
				int j=3*i;
				while (j<=4000000) {
					isPrime[j]=1;
					j+=(2*i);
				} //while loop
			}
		} //i loop
	}
	int N;
	cin >> N;
	int leftIdx = 0;
	int rightIdx = 0;
	int partialSum = primes[0];
	long long numCases = 0;
	while (leftIdx<283146) {
		if (partialSum==N) {
			numCases++;
		}
		if (partialSum>=N) {
			partialSum-=primes[leftIdx];
			leftIdx++;
		} else {
			if (rightIdx>=283145) break;
			rightIdx++;
			partialSum+=primes[rightIdx];
		}
	} //while loop
	cout << numCases;
	return 0;
}
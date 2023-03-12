#include <iostream>

using namespace std;
//int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
int primes[]=

int main() {
	int N;
	cin >> N;
	int numPrimes = sizeof(primes) / sizeof(*primes);
	int leftIdx = 0;
	int rightIdx = 0;
	int partialSum = primes[0];
	long long numCases = 0; 
	while (leftIdx<numPrimes) {
		if (partialSum==N) {
			numCases++;
		}
		if (partialSum>=N) {
			partialSum-=primes[leftIdx];
			leftIdx++;
		} else {
			if (rightIdx>=numPrimes-1) break;
			rightIdx++;
			partialSum+=primes[rightIdx];
		}
	} //while loop
	cout << numCases;
	return 0;	
}
#include <iostream>

using namespace std;

int main() {
	//sumArray <- partialSum
	int numArray[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
	int sumArray[10] = {0}; //1 3 7 15 31 63 127 255 511 1023
	//sumArray는 numArray의 누적값이다.
	//sumArray[n] = Σ numArray[i]
	{
		int partialSum = 0;
		for (int i=0; i<10; i++) {
			partialSum += numArray[i];
			sumArray[i] = partialSum;
		}
	}
	
	//e.g.0 numArray[0] + numArray[1] + numArray[2] + numArray[3]
	cout << sumArray[3] << '\n';
	//e.g.1 numArray[2] + numArray[3] + numArray[4]
	cout << sumArray[4] - sumArray[1] << '\n' ;
	//e.g.2 numArray[3] + numArray[5] + numArray[6] + numArray[7]
	cout << sumArray[7] - sumArray[2] - numArray[4] << '\n';
	
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	
	vector<int> divisor; //without any specific constructor
	for (int i=1; i<=N; i++) {
		if (N%i==0)
			divisor.push_back(i); //add(elem)
	}
	
	if (divisor.size()<K) //size()
		cout << 0;
	else
		cout << divisor.at(K-1); //get(idx)
	
	return 0;
}
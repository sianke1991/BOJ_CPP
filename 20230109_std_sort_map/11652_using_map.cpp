#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<long long, int> profiles; //key: the number in the card, value: the number of cards holing the number key

int main() {
	int N;
	cin >> N;
	for (int i=0; i<N; i++) {
		long long key;
		cin >> key;
		int profile = profiles[key];
		profiles[key] = profile+1;
	} //i loop
	long long optElem;
	int optFreq = 0;
	for (auto iter:profiles) { //range-based loop for map
		if (iter.second>optFreq) {
			optFreq = iter.second;
			optElem = iter.first;
		} else if (iter.second==optFreq && iter.first<optElem) {
			optElem = iter.first;
		}
	}
	cout << optElem;
	return 0;	
}
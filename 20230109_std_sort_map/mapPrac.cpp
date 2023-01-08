#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

string toString(pair<int, int> p) {
	return "["+to_string(p.first)+", "+to_string(p.second)+"]";
}

int main() {
	map<int, pair<int, int>> m;
	pair<int, int> val0 = m[0]; //val0 becomes [0, 0]
	m[0] = {2, 3};
	pair<int, int> val1 = m[0]; //val1 becomes [2, 3]
	m[0] = {7, 8};
	pair<int, int> val2 = m[0]; //val2 becomes [7, 8]
	cout << toString(val0) << toString(val1) << toString(val2);
	cout << '\n';
	
	for (auto iter:m) { //range-based loop for map
		cout << iter.first << ", " << toString(iter.second) << '\n';
	}
	return 0;
}
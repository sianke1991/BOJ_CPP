#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	vector<pair<int, int>> vec;
	pair<int, int> p;
	p.first = 1; p.second = 4;
	vec.push_back(p);
	p.first = 3; p.second = 5;
	vec.push_back(p);
	p.first = 0; p.second = 6;
	vec.push_back(p);
	p.first = 5; p.second = 7;
	vec.push_back(p);
	p.first = 3; p.second = 8;
	vec.push_back(p);
	p.first = 5; p.second = 9;
	vec.push_back(p);
	p.first = 6; p.second = 10;
	vec.push_back(p);
	p.first = 8; p.second = 11;
	vec.push_back(p);
	p.first = 8; p.second = 12;
	vec.push_back(p);
	p.first = 2; p.second = 13;
	vec.push_back(p);
	p.first = 12; p.second = 14;
	vec.push_back(p);	
	for (int i=0; i<vec.size(); i++) {
		cout << vec[i].first << ' ' << vec[i].second << endl;
	}
	//	1 4
	//	3 5
	//	0 6
	//	5 7
	//	3 8
	//	5 9
	//	6 10
	//	8 11
	//	8 12
	//	2 13
	//	12 14
	
	sort(vec.begin(), vec.end());
	for (int i=0; i<vec.size(); i++) {
		cout << vec[i].first << ' ' << vec[i].second << endl;
	}
	//	0 6
	//	1 4
	//	2 13
	//	3 5
	//	3 8
	//	5 7
	//	5 9
	//	6 10
	//	8 11
	//	8 12
	//	12 14
	sort(vec.begin(), vec.end(), greater<pair<int, int>>());
	for (int i=0; i<vec.size(); i++) {
		cout << vec[i].first << ' ' << vec[i].second << endl;
	}
	//	12 14
	//	8 12
	//	8 11
	//	6 10
	//	5 9
	//	5 7
	//	3 8
	//	3 5
	//	2 13
	//	1 4
	//	0 6
	return 0;
}
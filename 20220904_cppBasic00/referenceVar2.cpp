#include<iostream>
#include<vector>
#include<string>
using namespace std;
string toString(vector<int> v){
	string result = "{";
	for (int i=0; i<v.size(); i++) {
		result+="[";
		result+=to_string(i);
		result+="]=";
		result+=to_string(v[i]);
		result+=" ";
	}
	result += "}";
	return result;
}

int chg0(vector<int> v){
	cout << "0: " << toString(v) << endl;
	/*{[0]=0 [1]=2 [2]=4 [3]=6 [4]=8 }*/
	for (int i=0; i<v.size(); i++) {
		v[i]=3*i;
	}
	cout << "1: " << toString(v) << endl;
	/*{[0]=0 [1]=3 [2]=6 [3]=9 [4]=12 }*/
}

int chg1(vector<int> &v){
	cout << "3: " << toString(v) << endl;
	/*{[0]=0 [1]=2 [2]=4 [3]=6 [4]=8 }*/
	for (int i=0; i<v.size(); i++) {
		v[i]=3*i;
	}
	cout << "4: " << toString(v) << endl;
	/*{[0]=0 [1]=3 [2]=6 [3]=9 [4]=12 }*/
}

int main() {
	vector<int> v(5);
	for (int i=0; i<v.size(); i++) {
		v[i]=2*i;
	}
	chg0(v);
	cout << "2: " << toString(v) << endl;
	/*{[0]=0 [1]=2 [2]=4 [3]=6 [4]=8 }*/
	
	vector<int> v2(5);
		for (int i=0; i<v2.size(); i++) {
		v2[i]=2*i;
	}
	chg1(v2);
	cout << "5: " << toString(v2) << endl;
	/*{[0]=0 [1]=3 [2]=6 [3]=9 [4]=12 }*/
	return 0;
}
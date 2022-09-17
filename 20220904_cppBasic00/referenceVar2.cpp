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

// 이 함수를 호출할 경우 인자로 받는 벡터 v 내의 원소는 변경되지 않는다. (함수 내부에서는 임시적으로 원소를 변경시킬 수 있으나,
// 함수 외부에서는 영향을 주지 않는다.)
int chg0(vector<int> v){
	cout << "0: " << toString(v) << endl;
	/*{[0]=0 [1]=2 [2]=4 [3]=6 [4]=8 }*/
	for (int i=0; i<v.size(); i++) {
		v[i]=3*i;
	}
	cout << "1: " << toString(v) << endl;
	/*{[0]=0 [1]=3 [2]=6 [3]=9 [4]=12 }*/
}

// 이 함수를 호출할 경우 인자로 받는 벡터 v 내의 원소를 변경할 수 있다. (함수 내부에서 원소를 변경한 것이 함수 외부에 영향을 준다.)
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

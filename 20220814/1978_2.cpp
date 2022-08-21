#include<iostream>
#include<math.h>

using namespace std;

int main() {
	int N, num, cnt=0;
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> num;
		if (num<=1) continue; //if num is less than 2, num is not a prime
		cnt++;
		double max=sqrt(num);
		for (int j=2; j<=max; j++){
			if (num%j==0) { //if num is not a prime
				cnt--;
				break;
			}
		} //j loop
	} //i loop
	
	cout << cnt;
	return 0;	
}
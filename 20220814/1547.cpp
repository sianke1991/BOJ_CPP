#include<iostream>

using namespace std;

int main() {
	char cup[4] = {0, 1, 0, 0};
	
	int N;
	cin >> N;
	for (int i=0; i<N; i++) {
		int X, Y;
		cin >> X >> Y;
		
		//swap
		char tmp = cup[X];
		cup[X] = cup[Y];
		cup[Y] = tmp;
	} //i loop
	
	if (cup[1]) cout << 1;
	else if (cup[2]) cout << 2;
	else if (cup[3]) cout << 3;
	
	return 0;
}
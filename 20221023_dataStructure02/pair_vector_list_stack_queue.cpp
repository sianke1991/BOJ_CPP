#include <bits/stdc++.h> //includes several various header files
// sianke1991
using namespace std;

int main() {
	//0. pair
	pair<int, int> P;
	P.first = 5;
	P.second = 3;
	cout << P.first << ", " << P.second << "\n";
	P = {1, 7};
	cout << P.first << ", " << P.second << "\n";
	
	//1. vector
	vector<int> V;
	V.push_back(17); //cf. pop_back()
	V.push_back(1);
	V.push_back(5);
	V.push_back(12);
	for (int elem:V) { //vector can be used in range-based for loops
		cout << elem << ' ';
	}
	cout << '\n';
	for (int i=0; i<V.size(); i++) { //size method to get the number of elements in a vector
		cout << V[i] << ' ';
	}
	cout << '\n';
	for (int &elem:V) { //references in for loops
		elem+=1;
	}
	for (int elem:V) {
		cout << elem << ' ';
	}
	cout << '\n';
	sort(V.begin(), V.end()); //sort a vector in ascending order
	for (int elem:V) {
		cout << elem << ' ';
	}
	cout << '\n';
	sort(V.begin(), V.end(), greater<int>()); //sort a vector in descending order //cf. to sort an array, use sort(A, A+size) or sort(A, A+size, greater<>())
	for (int elem:V) {
		cout << elem << ' ';
	}
	cout << '\n';
	
	//2. list (and its iterator)
	list<int> L = {1, 2};
	list<int>::iterator T = L.begin(); //T is pointing the element 1
	L.push_front(10); //L becomes {10, 1, 2}
	cout << *T << '\n'; //Even though an element is added to the list L, T is still pointing the same element, 1.
	L.push_back(5); //L becomes {10, 1, 2, 5}
	L.insert(T, 6); //L becomes {10, 6, 1, 2, 5}. New element 6 are added at the position T is pointing.
	                //Any elements after the new element (including the element T is pointing) shift to the right.
	cout << *T << '\n'; //Even though an element is added to the list L, T is still pointing the same element, 1.
	T++; //Now T is pointing the next element, 2.
	T = L.erase(T); //L becomes {10, 6, 1, 5}
	cout << *T << '\n'; //T is now pointing the element 5.
	
	for (auto elem:L) //list can be used in range-based for loop
		cout << elem << ' ';
	cout << '\n';
	
	for (list<int>::iterator IT=L.begin(); IT!=L.end(); IT++) { //end method returns the very next to the last element of the list
		cout << *IT << ' ';
	}
	cout << '\n';
	cout << L.size() << '\n'; //size method to get the number of elements in a list
	
	//3. stack
	stack<int> S;
	S.push(10); //S becomes {10}
	S.push(25); //S becomes {10, 25}
	S.push(30); //S becomes {10, 25, 30}
	
	cout << S.size() << '\n'; //3, the number of elements in the stack
	cout << S.top() << '\n'; //30, the newest element in the stack
	if (S.empty()) cout << "S is empty\n"; //check whether the stack is empty or not
	else           cout << "S is not empty\n";
	S.pop(); //S becomes {10, 25}, removes the newest element in the stack
	         //Note that pop method does not return the element. If you want the newest element, call top method before calling pop method.
	cout << S.top() << '\n'; //25, the newest element in the stack
	
	//4. queue
	queue<int> Q;
	Q.push(10); //Q becomes {10}
	Q.push(25); //Q becomes {10, 25}
	Q.push(30); //Q becomes {10, 25, 30}
	
	cout << Q.size() << '\n'; //3, the number of elements in the queue
	cout << Q.front() << '\n'; //10, the oldest element in the queue
	if (Q.empty()) cout << "Q is empty\n"; //check whether the queue is empty or not
	else           cout << "Q is not empty\n";
	Q.pop(); //Q becomes {25, 30}, removes the oldest element in the queue
	         //Note that pop method does not return the element. If you want the oldest element, call front method before calling pop method.
	cout << Q.front() << '\n'; //25, the oldest element in the queue	
	
	
	return 0;
}
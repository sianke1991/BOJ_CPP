#include<iostream>
#include<stack>

using namespace std;


int main() {
    stack<int> s;
    s.push(10); //10
    s.push(25); //10 25
    s.push(30); //10 25 30

    cout << s.size() << '\n';
    if (s.empty()) cout << "s is empty\n";
    else           cout << "s is not empty\n";

    s.pop();
    cout << s.top() << '\n';


    return 0;
}

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
/*
stack, FILO 자료형 (= 제일 먼저 들어간 원소가 제일 나중에 나온다.)
추가 및 제거시 O(1)의 시간이 필요하다.
(마지막에 추가되어서) 맨 먼저 나오게 되는 원소만 조회할 수 있다.

C++에서 제공하는 스택에서 주로 사용하는 메서드
push(elem)
pop()
size() - int 반환
empty() - 0 또는 1 반환
top() - elem 자료형 반환

Restricted Structures
  stack
  queue
  deck
*/

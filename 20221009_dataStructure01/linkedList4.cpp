#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> L = {1, 2};
    list<int>::iterator t = L.begin(); //t는 1을 가리키는 중
    L.push_front(10); //10 1 2
    cout << *t <<'\n';
    L.push_back(5); //10 1 2 5
    L.insert(t, 6); //10 6 1 2 5 (t가 가리키는 곳에 6을 넣는다. 그 다음 원소는 뒤로 밀린다.)
    t++; //t가 가리키는 주소값을 1 키운다. (t는 2를 가리키는 중)
    t = L.erase(t); //10 6 1 5 (t는 본래 주소값인 5를 가리키게 된다.) 
    
    //C++ 11 이후의 버전에는 auto 라는 기능이 추가되었다. 
    //auto로 자료형을 선언할 경우 자동으로 자료형이 결정된다. (java의 Object 참조) 
    for (auto i : L) cout << i << ' ';
    
    for (list<int>::iterator it = L.begin(); it != L.end(); it++) {
        cout << *it << ' ';
    } 
    
    return 0;
}

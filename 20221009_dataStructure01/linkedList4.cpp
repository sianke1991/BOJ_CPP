#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> L = {1, 2};
    list<int>::iterator t = L.begin(); //t�� 1�� ����Ű�� ��
    L.push_front(10); //10 1 2
    cout << *t <<'\n';
    L.push_back(5); //10 1 2 5
    L.insert(t, 6); //10 6 1 2 5 (t�� ����Ű�� ���� 6�� �ִ´�. �� ���� ���Ҵ� �ڷ� �и���.)
    t++; //t�� ����Ű�� �ּҰ��� 1 Ű���. (t�� 2�� ����Ű�� ��)
    t = L.erase(t); //10 6 1 5 (t�� ���� �ּҰ��� 5�� ����Ű�� �ȴ�.) 
    
    //C++ 11 ������ �������� auto ��� ����� �߰��Ǿ���. 
    //auto�� �ڷ����� ������ ��� �ڵ����� �ڷ����� �����ȴ�. (java�� Object ����) 
    for (auto i : L) cout << i << ' ';
    
    for (list<int>::iterator it = L.begin(); it != L.end(); it++) {
        cout << *it << ' ';
    } 
    
    return 0;
}

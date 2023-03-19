//�����˻�Ʈ���� ����� �ڷᱸ���� set, multiset, map�̴�.
#include <bits/stdc++.h>

using namespace std;

int main() {
    multiset<int> ms;
    ms.insert(-10); ms.insert(100); ms.insert(15); //{-10, 15, 100}
    ms.insert(-10); ms.insert(15); //{-10, -10, 15, 15, 100}
    cout << ms.size() << '\n'; //5
    for (auto e:ms) cout << e <<' '; cout << '\n';
    cout << ms.erase(15) << '\n'; //{-10, -10, 100}, 2
    ms.erase(ms.find(-10)); //{-10, 100}
    ms.insert(100); //{-10, 100, 100}
    cout <<ms.count(100) << '\n'; //2 //log n �� �ƴ϶� n�� ����Ѵ�.

    auto it1 = ms.begin(); //{-10<-it1, 100, 100}
    auto it2 = ms.upper_bound(100); //{-10, 100, 100} <-it2 //���������� �����Ǵ� ���� ������ �ε���
    auto it3 = ms.find(100); //{-10, 100<-it3, 100} //ms�� ����ִ� 100 �� �ƹ� �ϳ��� ����Ų��. Ư���� ���� ���� idx�� ����Ű�� ������ lower_bound�� ����Ѵ�.
    cout << *it1 << '\n'; //-10
    cout << (it2==ms.end()) << '\n'; //1 //
    cout << *it3 << '\n'; //100
    return 0;


}

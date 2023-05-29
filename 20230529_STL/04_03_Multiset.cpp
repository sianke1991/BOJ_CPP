#include <bits/stdc++.h>

using namespace std;

int main() {
    multiset<int> ms;
    ms.insert(-10); ms.insert(100); ms.insert(15); //{-10, 15, 100}
    ms.insert(-10); ms.insert(15); //{-10, -10, 15, 15, 100} //multiset�� ������ �ߺ��� ����Ѵ�.
    cout << ms.size() << '\n'; //5

    for (int elem:ms) {
        cout << elem << ' '; //-10 -10 15 15 100
    }
    cout << '\n';

    cout << ms.erase(15) << '\n'; //2 //multiset���� ���Ҹ� ����� �޼���� �ߺ��� ���ҿ� ���� ��� ���Ҹ� ����� ���̴�. ���� ������ ������ ��ȯ�Ѵ�.
    for (int elem:ms) {
        cout << elem << ' '; //-10 -10 100
    }
    cout << '\n';

    ms.erase(ms.find(-10)); //{-10, 100} //multiset �� �ߺ��� ���ҿ� ���� �ϳ��� ����� ������ iterator�� erase �޼����� ���ڷ� �ش�.
    ms.insert(100); //{-10, 100, 100}
    for (int elem:ms) {
        cout << elem << ' '; //-10 100 100
    }
    cout << '\n';
    cout << ms.count(100) << '\n'; //2 //multiset�� ���� 100�� ����
    ms.insert(50); //{-10, 50, 100, 100}

    //iterator�� set�� unordered_set�� �����Ǵ� ���̴�.
    multiset<int>::iterator it0 = ms.begin(); //{-10<-it0, 50, 100, 100}
    cout << *it0 << '\n'; //-10

    it0++; //{-10, 50<-it0, 100, 100}
    multiset<int>::iterator it1 = prev(it0); //{-10<-it1, 50<-it0, 100, 100}
    it1 = next(it0); //{-10, 50<-it0, 100<-it1, 100}
    advance(it1, -2); //{-10<-it1, 50<-it0, 100, 100}

    multiset<int>::iterator it2 = ms.lower_bound(40); //{-10<-it1, 50<-it0, it2, 100, 100} //40 �̻��� ���� �� �ּ�ġ�� ����Ų��.
    multiset<int>::iterator it3 = ms.upper_bound(40); //{-10<-it1, 50<-it0, it2, it3, 100, 100} //40 �ʰ��� ���� �� �ּ�ġ�� ����Ų��.

    multiset<int>::iterator it4 = ms.lower_bound(50); //{-10<-it1, 50<-it0, it2, it3, it4, 100, 100} //50 �̻��� ���� �� �ּ�ġ�� ����Ų��.
    multiset<int>::iterator it5 = ms.upper_bound(50); //{-10<-it1, 50<-it0, it2, it3, it4, 100<-it5, 100} //50 �ʰ��� ���� �� �ּ�ġ�� ����Ų��.

    multiset<int>::iterator it6 = ms.find(-10); //{-10<-it1, it6, 50<-it0, it2, it3, it4, 100<-it5, 100}

    cout << *it0 << '\n'; //50
    cout << *it1 << '\n'; //-10
    cout << *it2 << '\n'; //50
    cout << *it3 << '\n'; //50
    cout << *it4 << '\n'; //50
    cout << *it5 << '\n'; //100
    cout << *it6 << '\n'; //-10

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    set<int> s;
    s.insert(-10); s.insert(100); s.insert(15); //{-10, 15, 100} //set�� ���Ұ� ������������ ����.
    cout << s.size() << '\n'; //3
    s.insert(15); //{-10, 15, 100} //set�� �̹� �� ���� �� �̻� ���� �ʴ´�.
    cout << s.size() << '\n'; //3

    for (int elem:s) {
        cout << elem << ' '; //-10 15 100
    }
    cout << '\n';

    cout << s.erase(100) << '\n'; //1 //erase�� set�� ���Ҹ� �����, �����ٸ� 1�� ������ ���ߴٸ� 0�� ��ȯ�Ѵ�. (���� ������ ������ ��ȯ�Ѵ�.)
    cout << s.erase(20) << '\n'; //0

    if (s.find(15) != s.end()) { //find�� ���� ã�Ƽ� iterator�� ��ȯ�ϴµ�, ���� �߰����� ���ߴٸ� end()�� ��ȯ�Ѵ�.
        cout << "15 in s.\n";
    } else {
        cout << "15 not in s.\n";
    }

    cout << s.size() << '\n'; //2
    cout << s.count(50) << '\n'; //0 //set�� ���� 50�� ���� (�ش� ���Ұ� ������ 1��, ������ 0�� ��ȯ�Ѵ�.)
    for (int elem:s) {
        cout << elem << ' '; //-10 15
    }
    cout << '\n';
    s.insert(-40); //{-40, -10, 15}

    //iterator�� set�� unordered_set�� �����Ǵ� ���̴�.
    set<int>::iterator it0 = s.begin(); //{-40<-it0, -10, 15}
    cout << *it0 << '\n'; //-40

    it0++; //{-40, -10<-it0, 15}
    set<int>::iterator it1 = prev(it0); //{-40<-it1, -10<-it0, 15}
    it1 = next(it0); //{-40, -10<-it0, 15<-it1}
    advance(it1, -2); //{-40<-it1, -10<-it0, 15}

    set<int>::iterator it2 = s.lower_bound(-20); //{-40<-it1, -10<-it0, it2, 15} //-20 �̻��� ���� �� �ּ�ġ�� ����Ų��.
    set<int>::iterator it3 = s.upper_bound(-20); //{-40<-it1, -10<-it0, it2, it3, 15} //-20 �ʰ��� ���� �� �ּ�ġ�� ����Ų��.

    set<int>::iterator it4 = s.lower_bound(-10); //{-40<-it1, -10<-it0, it2, it3, it4, 15} //-10 �̻��� ���� �� �ּ�ġ�� ����Ų��.
    set<int>::iterator it5 = s.upper_bound(-10); //{-40<-it1, -10<-it0, it2, it3, it4, 15<-it5} //-10 �ʰ��� ���� �� �ּ�ġ�� ����Ų��.

    set<int>::iterator it6 = s.find(-40); //{-40<-it1, it6, -10<-it0, it2, it3, it4, 15<-it5}

    cout << *it0 << '\n'; //-10
    cout << *it1 << '\n'; //-40
    cout << *it2 << '\n'; //-10
    cout << *it3 << '\n'; //-10
    cout << *it4 << '\n'; //-10
    cout << *it5 << '\n'; //15
    cout << *it6 << '\n'; //-40

    return 0;
}

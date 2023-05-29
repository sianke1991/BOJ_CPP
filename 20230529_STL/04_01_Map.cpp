#include <bits/stdc++.h>

using namespace std;

int main() {
    map<string, int> m;
    m["hi"] = 123;
    m["bkd"] = 1000;
    m["gogo"] = 165; //{("bkd", 1000), ("gogo", 165), ("hi", 123)} //map�� key�� ������������ ����.

    cout << m.size() << '\n'; //3 //map�� ����ִ� key-value ���� ����

    for (pair<string, int> elem:m) {
        cout << '(' << elem.first << ", " << elem.second << ") "; //(bkd, 1000) (gogo, 165) (hi, 123)
    }
    cout << '\n';

    m["hi"] = -7; //{("bkd", 1000), ("gogo", 165), ("hi", -7)}

    if (m.find("hi")!=m.end()) { //find�� ���� ã�Ƽ� iterator�� ��ȯ�ϴµ�, ���� �߰����� ���ߴٸ� end()�� ��ȯ�Ѵ�.
        cout << "hi in m.\n";
        cout << m["hi"] << '\n'; //-7
    } else {
        cout << "hi not in m.\n";
    }

    if (m.find("Hi")!=m.end()) {
        cout << "Hi in m.\n";
        cout << m["Hi"] << '\n';
    } else {
        cout << "Hi not in m.\n";
    }

    //iterator�� map�� unordered_map�� �����Ǵ� ���̴�.
    map<string, int>::iterator it0 = m.begin(); //{("bkd", 1000)<-it0, ("gogo", 165), ("hi", -7)}
    cout << '(' << (*it0).first << ", " << (*it0).second << ")\n"; //(bkd, 1000)


    it0++; //{("bkd", 1000), ("gogo", 165)<-it0, ("hi", -7)}
    map<string, int>::iterator it1 = prev(it0); //{("bkd", 1000)<-it1, ("gogo", 165)<-it0, ("hi", -7)}
    it1 = next(it0); //{("bkd", 1000), ("gogo", 165)<-it0, ("hi", -7)<-it1}

    map<string, int>::iterator it2 = m.lower_bound("go"); //{("bkd", 1000), ("gogo", 165)<-it0, it2, ("hi", -7)<-it1} //"go" �̻��� Ű�� �ּ�ġ�� ����Ų��.
    map<string, int>::iterator it3 = m.upper_bound("go"); //{("bkd", 1000), ("gogo", 165)<-it0, it2, it3, ("hi", -7)<-it1} //"go" �ʰ��� Ű�� �ּ�ġ�� ����Ų��.

    map<string, int>::iterator it4 = m.lower_bound("gogo"); //{("bkd", 1000), ("gogo", 165)<-it0, it2, it3, it4, ("hi", -7)<-it1} //"gogo" �̻��� Ű�� �ּ�ġ�� ����Ų��.
    map<string, int>::iterator it5 = m.upper_bound("gogo"); //{("bkd", 1000), ("gogo", 165)<-it0, it2, it3, it4, ("hi", -7)<-it1, it5} //"gogo" �ʰ��� Ű�� �ּ�ġ�� ����Ų��.

    map<string, int>::iterator it6 = m.find("bkd"); //{("bkd", 1000)<-it6, ("gogo", 165)<-it0, it2, it3, it4, ("hi", -7)<-it1, it5}
    advance(it6, 2); //{("bkd", 1000), ("gogo", 165)<-it0, it2, it3, it4, ("hi", -7)<-it1, it5, it6}

    cout << '(' << (*it0).first << ", " << (*it0).second << ")\n"; //(gogo, 165)
    cout << '(' << (*it1).first << ", " << (*it1).second << ")\n"; //(hi, -7)
    cout << '(' << (*it2).first << ", " << (*it2).second << ")\n"; //(gogo, 165)
    cout << '(' << (*it3).first << ", " << (*it3).second << ")\n"; //(gogo, 165)
    cout << '(' << (*it4).first << ", " << (*it4).second << ")\n"; //(gogo, 165)
    cout << '(' << (*it5).first << ", " << (*it5).second << ")\n"; //(hi, -7)
    cout << '(' << (*it6).first << ", " << (*it6).second << ")\n"; //(hi, -7)

    m.erase("bkd"); //{("gogo", 165), ("hi", -7)} //�Էµ� key�� �ش��ϴ� key-value ���� map���� �����.
    for (pair<string, int>elem:m) {
        cout << '(' << elem.first << ", " << elem.second << ") "; //(gogo, 165) (hi, -7)
    }
    cout << '\n';

    return 0;
}

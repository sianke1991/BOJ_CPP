#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_map<string, int> m;
    m["hi"] = 123;
    m["bkd"] = 1000;
    m["gogo"] = 165; //{("hi", 123), ("bkd", 1000), ("gogo", 165)}
    cout << m.size() << '\n'; //3 //map�� ����ִ� key-value ���� ����

    m["hi"] = -7; //{("hi", -7), ("bkd", 1000), ("gogo", 165)}

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

    m.erase("bkd"); //{("hi", -7), ("gogo", 165)} //�Էµ� key�� �ش��ϴ� key-value ���� map���� �����.

    for (pair<string, int> elem:m) {
        cout << '(' << elem.first << ", " << elem.second << ") "; //(gogo, 165) (hi, -7)
    }
    cout << '\n';

    return 0;
}

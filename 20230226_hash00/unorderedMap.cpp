#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

int main() {
    unordered_map<string, int> m;
    m["hi"] = 123;
    m["bkd"] = 1000;
    m["gogo"] = 165; //("hi", 123), ("bkd", 1000), ("gogo", 165)
    cout << m.size() << '\n'; //3 (map�� ����ִ� key-value ���� ����)
    m["hi"] = -7; //("hi", -7), ("bkd", 1000), ("gogo", 165) //map�� �ش� key�� �̹� ����ִٸ� value ������ �Ͼ��.
    if (m.find("hi") != m.end()) cout << "hi in m\n";
    else cout << "hi not in m\n";
    e.erase("bkd"); //("hi", -7), ("gogo", 165) //�Էµ� key�� �ش��ϴ� key-value ���� �����.
    for (auto e:m) { //auto e�� �ڷ����� pair<string, int>�� �ȴ�.
        cout << e.first() << ' ' << e.second << '\n';
    }
    return 0;
}

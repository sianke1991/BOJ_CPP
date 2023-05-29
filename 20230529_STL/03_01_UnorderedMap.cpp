#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_map<string, int> m;
    m["hi"] = 123;
    m["bkd"] = 1000;
    m["gogo"] = 165; //{("hi", 123), ("bkd", 1000), ("gogo", 165)}
    cout << m.size() << '\n'; //3 //map에 들어있는 key-value 쌍의 개수

    m["hi"] = -7; //{("hi", -7), ("bkd", 1000), ("gogo", 165)}

    if (m.find("hi")!=m.end()) { //find는 값을 찾아서 iterator를 반환하는데, 값을 발견하지 못했다면 end()를 반환한다.
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

    m.erase("bkd"); //{("hi", -7), ("gogo", 165)} //입력된 key에 해당하는 key-value 쌍을 map에서 지운다.

    for (pair<string, int> elem:m) {
        cout << '(' << elem.first << ", " << elem.second << ") "; //(gogo, 165) (hi, -7)
    }
    cout << '\n';

    return 0;
}

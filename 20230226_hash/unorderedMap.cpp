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
    cout << m.size() << '\n'; //3 (map에 들어있는 key-value 쌍의 개수)
    m["hi"] = -7; //("hi", -7), ("bkd", 1000), ("gogo", 165) //map에 해당 key가 이미 들어있다면 value 수정이 일어난다.
    if (m.find("hi") != m.end()) cout << "hi in m\n";
    else cout << "hi not in m\n";
    e.erase("bkd"); //("hi", -7), ("gogo", 165) //입력된 key에 해당하는 key-value 쌍을 지운다.
    for (auto e:m) { //auto e의 자료형은 pair<string, int>가 된다.
        cout << e.first() << ' ' << e.second << '\n';
    }
    return 0;
}

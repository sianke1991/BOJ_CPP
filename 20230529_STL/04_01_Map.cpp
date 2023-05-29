#include <bits/stdc++.h>

using namespace std;

int main() {
    map<string, int> m;
    m["hi"] = 123;
    m["bkd"] = 1000;
    m["gogo"] = 165; //{("bkd", 1000), ("gogo", 165), ("hi", 123)} //map은 key가 오름차순으로 들어간다.

    cout << m.size() << '\n'; //3 //map에 들어있는 key-value 쌍의 개수

    for (pair<string, int> elem:m) {
        cout << '(' << elem.first << ", " << elem.second << ") "; //(bkd, 1000) (gogo, 165) (hi, 123)
    }
    cout << '\n';

    m["hi"] = -7; //{("bkd", 1000), ("gogo", 165), ("hi", -7)}

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

    //iterator는 map이 unordered_map과 구별되는 점이다.
    map<string, int>::iterator it0 = m.begin(); //{("bkd", 1000)<-it0, ("gogo", 165), ("hi", -7)}
    cout << '(' << (*it0).first << ", " << (*it0).second << ")\n"; //(bkd, 1000)


    it0++; //{("bkd", 1000), ("gogo", 165)<-it0, ("hi", -7)}
    map<string, int>::iterator it1 = prev(it0); //{("bkd", 1000)<-it1, ("gogo", 165)<-it0, ("hi", -7)}
    it1 = next(it0); //{("bkd", 1000), ("gogo", 165)<-it0, ("hi", -7)<-it1}

    map<string, int>::iterator it2 = m.lower_bound("go"); //{("bkd", 1000), ("gogo", 165)<-it0, it2, ("hi", -7)<-it1} //"go" 이상의 키의 최소치를 가리킨다.
    map<string, int>::iterator it3 = m.upper_bound("go"); //{("bkd", 1000), ("gogo", 165)<-it0, it2, it3, ("hi", -7)<-it1} //"go" 초과의 키의 최소치를 가리킨다.

    map<string, int>::iterator it4 = m.lower_bound("gogo"); //{("bkd", 1000), ("gogo", 165)<-it0, it2, it3, it4, ("hi", -7)<-it1} //"gogo" 이상의 키의 최소치를 가리킨다.
    map<string, int>::iterator it5 = m.upper_bound("gogo"); //{("bkd", 1000), ("gogo", 165)<-it0, it2, it3, it4, ("hi", -7)<-it1, it5} //"gogo" 초과의 키의 최소치를 가리킨다.

    map<string, int>::iterator it6 = m.find("bkd"); //{("bkd", 1000)<-it6, ("gogo", 165)<-it0, it2, it3, it4, ("hi", -7)<-it1, it5}
    advance(it6, 2); //{("bkd", 1000), ("gogo", 165)<-it0, it2, it3, it4, ("hi", -7)<-it1, it5, it6}

    cout << '(' << (*it0).first << ", " << (*it0).second << ")\n"; //(gogo, 165)
    cout << '(' << (*it1).first << ", " << (*it1).second << ")\n"; //(hi, -7)
    cout << '(' << (*it2).first << ", " << (*it2).second << ")\n"; //(gogo, 165)
    cout << '(' << (*it3).first << ", " << (*it3).second << ")\n"; //(gogo, 165)
    cout << '(' << (*it4).first << ", " << (*it4).second << ")\n"; //(gogo, 165)
    cout << '(' << (*it5).first << ", " << (*it5).second << ")\n"; //(hi, -7)
    cout << '(' << (*it6).first << ", " << (*it6).second << ")\n"; //(hi, -7)

    m.erase("bkd"); //{("gogo", 165), ("hi", -7)} //입력된 key에 해당하는 key-value 쌍을 map에서 지운다.
    for (pair<string, int>elem:m) {
        cout << '(' << elem.first << ", " << elem.second << ") "; //(gogo, 165) (hi, -7)
    }
    cout << '\n';

    return 0;
}

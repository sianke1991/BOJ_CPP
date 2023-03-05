#include <bits/stdc++.h>
#include <string>
using namespace std;
//체이닝을 사용한 해시 맵 구현
const int M = 1000003; //해시 테이블의 크기 (해시 테이블의 크기는 소수로 잡는 것이 좋다.

/**
 * 정수 값에 대한 해시 함수
 */

int hashFunction(int key) {
    return (M+key)%M;
}

/**
 * 문자열 값에 대한 해시 함수
 */
int hashFunction(string key) {
    int result = 0;
    int splitter = 1000;
    for (char ch:key) {
        result = (result*splitter+ch)%M;
    }
    return result;
}

list<pair<string, string>> mmap[M];
int capacity = 0;
/**
 * mmap 내부에 인자로 입력받은 key가 들어있는지 여부를 반환한다.
 */
bool contains(string key) {
    list<pair<string, string>> L = mmap[hashFunction(key)];
    for (pair<string, string> elem:L) {
        if (elem.first==key) return true;
    }
    return false;
}
/**
 * mmap 내부에 인자로 입력받은 key에 해당하는 value를 반환한다.
 */
string get(string key) {
    list<pair<string, string>> L = mmap[hashFunction(key)];
    for (pair<string, string> elem:L) {
        if (elem.first==key) return elem.second;
    }
    return "";
}
/**
 * mmap 내부에 key, value 쌍을 등록하거나 수정한다.
 * 등록하는 경우 true를, 수정하는 경우 false를 반환한다.
 */
bool put(string key, string value) {
    list<pair<string, string>>& L = mmap[hashFunction(key)]; //리스트 L에 원소를 추가할 수 있어야 하므로 참조 변수를 사용한다.
    for (pair<string, string>& elem:L) { //elem의 second를 변경할 수 있어야 하므로 참조 변수를 사용한다.
        if (elem.first==key) {
            elem.second = value;
            return false;
        }
    }
    L.push_front({key, value});
    capacity++;
    return true;
}
/**
 * mmap 내부에 인자로 입력받은 key에 해당하는 key, value쌍을 삭제한다.
 * 삭제가 이루어진 여부를 반환한다.
 */

bool del(string key) {
    list<pair<string, string>>& L = mmap[hashFunction(key)]; //리스트 L에 원소를 제거할 수 있어야 하므로 참조 변수를 사용한다.
    list<pair<string, string>>::iterator T = L.begin(); //리스트의 erase 메서드는 그 인자로 원소 그 자체가 아닌 iterator를 받는다.
    while (T!=L.end()) {
        if ((*T).first==key) {
            L.erase(T);
            capacity--;
            return true;
        }
    }
    return false;
}

int getCapacity() {
    return capacity;
}
/**
 * mmap 내부에 들어있는 key, value 쌍의 정보를 담은 문자열을 반환한다.
 */
string toString() {
    string result = "";
    for (list<pair<string, string>> L:mmap) {
        for (pair<string, string> elem:L) {
            result += "["+elem.first+", "+elem.second+"]";
        }
    }
    return result;
}


int main() {
    //해시 테이블에서 load factor = 원소의 개수 / 테이블의 크기
    //삽입의 최대 횟수가 곧 해시 테이블에 들어있는 원소의 최대 개수를 의미한다.
    //Open Addressing은 loadFactor를 0.75 이하로 둔다. (테이블의 크기를 최대 삽입 횟수의 1.33 배로 둔다.)
    //Chaining은 loadFactor를 1.0 이하로 둔다. (테이블의 크기를 최대 삽입 횟수로 둔다.)
    //테이블의 크기는 소수(prime number)로 설정하는 것이 좋다. (해시 함수와 관련)
    //롤링 해시 함수 (문자열에 대한 해시 함수)
    put("dragoon", "protoss");
    put("overload", "zerg");
    put("goliath", "terran");
    cout << toString() <<'\n'; //[overload, zerg][goliath, terran][dragoon, protoss]
    cout << get("dragoon") << '\n'; //protoss
    del("probe");
    cout << toString() <<'\n'; //[overload, zerg][goliath, terran][dragoon, protoss]
    del("dragoon");
    cout << toString() << '\n'; //[overload, zerg][goliath, terran]
    put("overload", "Zerg");
    cout << toString() << '\n'; //[overload, Zerg][goliath, terran]



    return 0;
}

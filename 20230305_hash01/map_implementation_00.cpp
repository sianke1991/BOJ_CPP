#include <bits/stdc++.h>
#include <string>
using namespace std;
//ü�̴��� ����� �ؽ� �� ����
const int M = 1000003; //�ؽ� ���̺��� ũ�� (�ؽ� ���̺��� ũ��� �Ҽ��� ��� ���� ����.

/**
 * ���� ���� ���� �ؽ� �Լ�
 */

int hashFunction(int key) {
    return (M+key)%M;
}

/**
 * ���ڿ� ���� ���� �ؽ� �Լ�
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
 * mmap ���ο� ���ڷ� �Է¹��� key�� ����ִ��� ���θ� ��ȯ�Ѵ�.
 */
bool contains(string key) {
    list<pair<string, string>> L = mmap[hashFunction(key)];
    for (pair<string, string> elem:L) {
        if (elem.first==key) return true;
    }
    return false;
}
/**
 * mmap ���ο� ���ڷ� �Է¹��� key�� �ش��ϴ� value�� ��ȯ�Ѵ�.
 */
string get(string key) {
    list<pair<string, string>> L = mmap[hashFunction(key)];
    for (pair<string, string> elem:L) {
        if (elem.first==key) return elem.second;
    }
    return "";
}
/**
 * mmap ���ο� key, value ���� ����ϰų� �����Ѵ�.
 * ����ϴ� ��� true��, �����ϴ� ��� false�� ��ȯ�Ѵ�.
 */
bool put(string key, string value) {
    list<pair<string, string>>& L = mmap[hashFunction(key)]; //����Ʈ L�� ���Ҹ� �߰��� �� �־�� �ϹǷ� ���� ������ ����Ѵ�.
    for (pair<string, string>& elem:L) { //elem�� second�� ������ �� �־�� �ϹǷ� ���� ������ ����Ѵ�.
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
 * mmap ���ο� ���ڷ� �Է¹��� key�� �ش��ϴ� key, value���� �����Ѵ�.
 * ������ �̷���� ���θ� ��ȯ�Ѵ�.
 */

bool del(string key) {
    list<pair<string, string>>& L = mmap[hashFunction(key)]; //����Ʈ L�� ���Ҹ� ������ �� �־�� �ϹǷ� ���� ������ ����Ѵ�.
    list<pair<string, string>>::iterator T = L.begin(); //����Ʈ�� erase �޼���� �� ���ڷ� ���� �� ��ü�� �ƴ� iterator�� �޴´�.
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
 * mmap ���ο� ����ִ� key, value ���� ������ ���� ���ڿ��� ��ȯ�Ѵ�.
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
    //�ؽ� ���̺��� load factor = ������ ���� / ���̺��� ũ��
    //������ �ִ� Ƚ���� �� �ؽ� ���̺� ����ִ� ������ �ִ� ������ �ǹ��Ѵ�.
    //Open Addressing�� loadFactor�� 0.75 ���Ϸ� �д�. (���̺��� ũ�⸦ �ִ� ���� Ƚ���� 1.33 ��� �д�.)
    //Chaining�� loadFactor�� 1.0 ���Ϸ� �д�. (���̺��� ũ�⸦ �ִ� ���� Ƚ���� �д�.)
    //���̺��� ũ��� �Ҽ�(prime number)�� �����ϴ� ���� ����. (�ؽ� �Լ��� ����)
    //�Ѹ� �ؽ� �Լ� (���ڿ��� ���� �ؽ� �Լ�)
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

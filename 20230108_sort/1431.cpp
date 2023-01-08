#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int digitSum(string a) {
    int result = 0;
    for (char ch:a) {
        if (ch>='0' && ch<='9')
            result += ch-'0';
    }
    return result;
}

bool cmp(const string& a, const string& b) { //c++������ ���ڷ� �����ڷ����� �޴� ��� ����Ʈ�� deep copy�� �̷������. �̸� �����Ϸ��� reference�� ����Ѵ�.
    if (a.length()!=b.length()) {
        return a.length()<b.length(); //������ ���� ������ ��쿡 true�� ��ȯ�ؾ� �Ѵ�.
    }
    int sumA = digitSum(a);
    int sumB = digitSum(b);
    if (sumA!=sumB) {
        return sumA<sumB; //������ ���� ������ ��쿡 true�� ��ȯ�ؾ� �Ѵ�.
                            //���������� ��� �밳 ������ ���������� ���� ������ �ε�ȣ�� �ַ� ���ȴ�.
    }
    for (int i=0; i<a.length(); i++) {
        if (a[i]!= b[i])
            return a[i]<b[i];
    }
    return true;
}


int main() {
    int N;
    cin >> N;
    string serial[N];
    for (int i=0; i<N; i++) {
        cin >> serial[i];
    } //i loop
    sort(serial, serial+N, cmp);
    for (string str:serial) {
        cout << str << '\n';
    }
    return 0;
}

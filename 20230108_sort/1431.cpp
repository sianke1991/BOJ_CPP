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

bool cmp(const string& a, const string& b) { //c++에서는 인자로 참조자료형을 받는 경우 디폴트는 deep copy가 이루어진다. 이를 방지하려면 reference를 사용한다.
    if (a.length()!=b.length()) {
        return a.length()<b.length(); //왼쪽이 먼저 나오는 경우에 true를 반환해야 한다.
    }
    int sumA = digitSum(a);
    int sumB = digitSum(b);
    if (sumA!=sumB) {
        return sumA<sumB; //왼쪽이 먼저 나오는 경우에 true를 반환해야 한다.
                            //오름차순의 경우 대개 인자의 후자쪽으로 입을 벌리는 부등호가 주로 사용된다.
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

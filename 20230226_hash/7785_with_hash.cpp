#include <unordered_set>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string& a, string &b) {
    return a>b;
}

int main() {
    unordered_set<string> names;
    vector<string> namesVector;

    int n;
    cin >> n;
    string nameInput, actionInput;
    for (int i=0; i<n; i++) {
        cin >> nameInput >> actionInput;
        if (actionInput == "enter")
            names.insert(nameInput);
        else
            names.erase(nameInput);
    }
    for (string name:names)
        namesVector.push_back(name);
    //unordered_set의 내용을 vector에 담기 위해서는 다음과 같은 방법도 가능하다.
    //vector<string> namesVector(names.begin(), names.end());
    sort(namesVector.begin(), namesVector.end(), cmp); //cmp 대신 greater<string>() 도 사용 가능하다. (문자열 역순 정렬)

    for (string name:namesVector) {
        cout << name << '\n';
    }
    return 0;
}

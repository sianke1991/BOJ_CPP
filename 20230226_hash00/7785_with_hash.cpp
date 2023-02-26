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
    //unordered_set�� ������ vector�� ��� ���ؼ��� ������ ���� ����� �����ϴ�.
    //vector<string> namesVector(names.begin(), names.end());
    sort(namesVector.begin(), namesVector.end(), cmp); //cmp ��� greater<string>() �� ��� �����ϴ�. (���ڿ� ���� ����)

    for (string name:namesVector) {
        cout << name << '\n';
    }
    return 0;
}

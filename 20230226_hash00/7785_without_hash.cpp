#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string& a, string &b) {
    return a>b;
}


int main() {
    vector<string> names;
    int n;
    cin >> n;
    string nameInput, actionInput;
    for (int i=0; i<n; i++) {
        cin >> nameInput >> actionInput;
        if (actionInput == "enter") {
            names.push_back(nameInput);
        } else {
            for (string& name:names) {
                if (name==nameInput) {
                    name = "";
                }
            }
        }
    } //i loop

    sort(names.begin(), names.end(), cmp);
    for (string name:names) {
        if (name=="") break;
        cout << name << '\n';
    }
    return 0;
}

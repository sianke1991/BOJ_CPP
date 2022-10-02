#include <iostream>
#include <vector>
#include <string>

using namespace std;


int isValidPS(string str) {
    int liTmp = 0;
    for (int i=0; i<str.length(); i++) {
        switch (str[i])
        {
            case '(':
                liTmp++;
                break;
            case ')':
                liTmp--;
                if(liTmp<0) return 0;
                break;
            default:
                return 0;
        }
    }
    return liTmp==0;
}


int main () {
    int T;
    cin >> T;
    vector<string> result;
    for (int i=0; i<T; i++) {
        string str;
        cin >> str;
        if (isValidPS(str)) result.push_back("YES");
        else                result.push_back("NO");
    } //i loop

    for (int i=0; i<result.size(); i++) {
        cout << result[i] << '\n';
    }

    return 0;
}

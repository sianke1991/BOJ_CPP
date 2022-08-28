#include<iostream>
#include<algorithm>
#include<string>
//#include<math.h>

using namespace std;

bool compare(string x, string y){
    int lenDif = x.size()-y.size();
    if (lenDif>0) return false;
    else if (lenDif<0) return true;
    else return x<y;
}

int cmp (string a, string b) {
    if (a.length() == b.length()) return a<b;
    return a.length()<b.length();
}

int main() {
    int N;
    cin >> N;
    string words[N];

    for (int i=0; i<N; i++) {
        cin >> words[i];
    }

    sort(words, words+N, compare);
    cout << words[0] << endl;
    for (int i=1; i<N; i++) {
        if (words[i]==words[i-1]) continue;
        cout << words[i] << endl;
    }

    return 0;
}

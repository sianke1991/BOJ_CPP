#include<iostream>
#include<algorithm>

using namespace std;

bool compare(int a, int b){
    return a<b;
}

int main() {
    int N;
    cin >> N;
    int num[N];
    for (int i=0; i<N; i++) {
        cin >> num[i];
    }


    sort (num, num+N, compare);
    for (int i=0; i<N; i++){
        cout << num[i] << endl;
    }
    return 0;
}

#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    int A[N], B[N];
    for (int i=0; i<N; i++){
        cin >> A[i];
    }
    for (int i=0; i<N; i++){
        cin >> B[i];
    }
    sort(A, A+N);
    sort(B, B+N, greater<int>()); //내림차순 정렬

    int sum=0;
    for (int i=0; i<N; i++) {
        sum += A[i]*B[i];
    }
    cout << sum;

    return 0;

}

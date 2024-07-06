#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    int heightOf[100001];
    scanf("%d", &N);
    for (int i=1; i<=N; i++) {
        scanf("%d", &heightOf[i]);
    } //i loop

    int result[100001]= {0};
    stack<int> s;
    for (int i=1; i<=N; i++) {
        while (!s.empty() && heightOf[s.top()]<heightOf[i]) {
            result[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    for (int i=1; i<=N; i++)
        printf("%d\n", result[i]);

    return 0;
}

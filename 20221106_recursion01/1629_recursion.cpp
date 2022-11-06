#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//매 스텝마다 지수가 절반 씩 줄어드므로 시간복잡도는 O(log b)가 된다.
ll POW(ll a, ll b, ll m) {      //a**b%m을 반환하되, [b를 낮춰서 구한 결과를 계산에] 이용한다.
    if (b==0) return 1;
    if (b==1) return a%m;
    ll val = POW(a, b/2, m);
    val = val*val%m;            //b가 짝수일 때는 a**b%m이 구해지고, b가 홀수일 때는 a**(b-1)%m이 구해진다.
    if (b%2==0) return val;     //그래서 b가 짝수일 때는 그대로 val을 반환하고,
    return val*a%m;             //b가 홀수일 때는 지수를 1 증가시키는 연산을 수행한 뒤에 반환한다.
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll A, B, C;
    cin >> A >> B >> C;
    cout << POW(a, b, c);
    return 0;
}

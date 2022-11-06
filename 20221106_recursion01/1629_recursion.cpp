#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//�� ���ܸ��� ������ ���� �� �پ��Ƿ� �ð����⵵�� O(log b)�� �ȴ�.
ll POW(ll a, ll b, ll m) {      //a**b%m�� ��ȯ�ϵ�, [b�� ���缭 ���� ����� ��꿡] �̿��Ѵ�.
    if (b==0) return 1;
    if (b==1) return a%m;
    ll val = POW(a, b/2, m);
    val = val*val%m;            //b�� ¦���� ���� a**b%m�� ��������, b�� Ȧ���� ���� a**(b-1)%m�� ��������.
    if (b%2==0) return val;     //�׷��� b�� ¦���� ���� �״�� val�� ��ȯ�ϰ�,
    return val*a%m;             //b�� Ȧ���� ���� ������ 1 ������Ű�� ������ ������ �ڿ� ��ȯ�Ѵ�.
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll A, B, C;
    cin >> A >> B >> C;
    cout << POW(a, b, c);
    return 0;
}

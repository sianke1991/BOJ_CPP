#include <iostream>


using namespace std;

int t[1500005]; //�� ��㿡 �ɸ��� �ð� (��)
int p[1500005]; //�� ��㿡 ���� ����
int d[1500005]; //i ��° �Ͽ� ����� �������� �� ���� �� �ִ� �ִ� ����


int main() {
    int n;
    cin >> n;

    for (int i=1; i<=n; i++) cin >> t[i] >> p[i];

    for (int i=n; i>=1; i--) {
        //i ��° �Ͽ� ����� �� �� �ִ� ���
        if (i+t[i] <= n+1) {
            //i ��° �Ͽ� ����� ���� ���� ����� ���� �ʾ��� �� ���� �� �ִ� ���� �� �ִ� ������ ����
            d[i] = max(d[i+t[i]]+p[i], d[i+1]);
        }
        else d[i] = d[i+1];
    }
    cout << *max_element(d+1, d+n+1);
    return 0;





}

#include <iostream>


using namespace std;

int t[1500005]; //각 상담에 걸리는 시간 (일)
int p[1500005]; //각 상담에 대한 보수
int d[1500005]; //i 번째 일에 상담을 시작했을 때 얻을 수 있는 최대 수익


int main() {
    int n;
    cin >> n;

    for (int i=1; i<=n; i++) cin >> t[i] >> p[i];

    for (int i=n; i>=1; i--) {
        //i 번째 일에 상담을 할 수 있는 경우
        if (i+t[i] <= n+1) {
            //i 번째 일에 상담을 했을 때와 상담을 하지 않았을 때 얻을 수 있는 수익 중 최대 수익을 취함
            d[i] = max(d[i+t[i]]+p[i], d[i+1]);
        }
        else d[i] = d[i+1];
    }
    cout << *max_element(d+1, d+n+1);
    return 0;





}

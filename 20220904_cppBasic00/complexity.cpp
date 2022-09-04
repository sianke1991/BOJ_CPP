#include <iostream>
#include <math.h>

using namespace std;

long long func1(int N)
{ // N������ �ڿ��� �� 3�� ��� �Ǵ� 5�� ����� ��
    long long result(0); //0���� �ʱ�ȭ�Ͽ� ���� ����

    for (int i=1; i<=N; i++) {
        if (i%3 && i%5 ) continue;
        result += i ;
    }
    return result;
}

int func2(int* arr, int len) { //�迭 ���� ������ �� ���Ҹ� �̾Ƽ� ���� 100 �� �� �� �ִ��� ����
    for (int i=0; i<len-1; i++) {
        for (int j=i+1; j<len; j++) {
            if ((*(arr+i)) + (*(arr+j)) == 100) return 1;
        } //j loop
    } //i loop
    return 0;
}

int func3(int n){ //n�� ���������� ���θ� ��ȯ
    if (n < 0) return 0;
    for (int i=0; i*i<=n; i++) {
        if (i*i==n) return 1;
    }
    return 0;
}

int func4(int n){ //n������ �ڿ��� �� ���� ū 2�� �ŵ��������� ��ȯ
    /*
    if (n <= 0) return 0;
    int i;
    for (i=1; i<=n; i*=2) {
    }
    if (i==n) return i;
    else      return i/2;
    */
    int val = 1;
    while (2*val <= n){
        val *= 2;
    }
    return val;
}

int main(){

    /*
    �ð����⵵
    O(N)
    O(N^2) ���� significant �� �׸��� �����.
    O(sqrt(N))
    O(log N)
    */

    /* int �ڷ����� 1.2�ﰳ ���� ����ϸ� 512 MB�� ����ϰ� �ȴ�. */

    /*
    int N;
    cin >> N;
    int arr[N];
    for (int i=0; i<N; i++){
        cin >> arr[i];
    }
    cout << func2(arr, N);
    */

    int N;
    cin >> N;
    cout << func4(N);
    return 0;
}

#include <iostream>

//sliding window: �� �����Ϳ� �����ϵ�, ������ ���̰� ������ ���

using namespace std;


int main() {
    int N; //�迭�� ����
    int K; //�����̵� ������ ��
    cin >> N >> K;
    int temperatures[N];
    for (int i=0; i<N; i++) {
        cin >> temperatures[i];
    }
    int currentVal = 0;
    for (int i=0; i<K; i++) {
        currentVal+=temperatures[i]; //currentVal�� �ʱⰪ�� ù K���� ������ ���Ѵ�.
    }
    int optVal = currentVal;
    for (int i=0; i<N-K; i++) {
        currentVal+=temperatures[i+K]-temperatures[i]; //������ ���������� �ű�鼭 �ش� �µ��� ���ϰ� ����.
        if (currentVal>optVal) optVal = currentVal;
    } //i loop
    cout << optVal;
    return 0;
}

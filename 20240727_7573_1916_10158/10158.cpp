#include <stdio.h>

/**
���� ��ġ x ��ǥ�� �ֱ�� ��ü ������ ���� ������ �� ���̴�.
��ü ������ ���� ���̰� 6�� ��� ���� ��ġ x ��ǥ��
0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1
���� ���ϰ� �� ����Ŭ�� �ݺ��ȴ�.
���� ���� ��ġ x ��ǥ�� ���ϱ� ���� ��ü ���� ���� ������ �� �迡 ���� modular ������ ���ȴ�.
*/


int main() {
    //��ü ������ ���� ����
    long long w;
    //��ü ������ ���� ����
    long long h;
    scanf("%lld %lld", &w, &h);
    //���� �ʱ� ��ġ�� x ��ǥ
    long long p;
    //���� �ʱ� ��ġ�� y ��ǥ
    long long q;
    scanf("%lld %lld", &p, &q);
    //������ �ð�
    long long t;
    scanf("%lld", &t);

    long long resultX = (p+t)%(2*w);
    if (resultX>w) resultX = 2*w-resultX;
    long long resultY = (q+t)%(2*h);
    if (resultY>h) resultY = 2*h-resultY;

    printf("%lld %lld", resultX, resultY);


    return 0;
}

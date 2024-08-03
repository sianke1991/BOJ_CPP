#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
//�Ÿ��� ����: ��⸦ ������ �� �� ��ġ���� 0 �̻� L ������ ������ ��ȿ�ϴ�.
long long L;
//���� ����
int N;
//�� ���� ��ġ
long long lights[300000];
//����ؾ� �� ���� ����
int K;

int main() {
    scanf("%lld", &L);
    scanf("%d", &N);
    scanf("%d", &K);
    for (int i=0; i<N; i++)
        scanf("%lld", &lights[i]);

    //����� ���� �����ϴ� vector
    vector<long long> results;
    //���ε�� ������ �Ÿ�
    long long darkness = 0;
    //���� ���� �������� ��ο� ���� ������ ����� �� �̹� ����� ������ ���� set
    set<long long> pointsConsidered;

    while (results.size()<K) {
        for (int i=0; i<N; i++) {
            //�� ���ε ���ؼ� �������� darkness ������ ����, ���������� darkness ������ ������ results�� �ֵ�,
            //������ �̹� ����� ������ ���� �ʴ´�. => ���ε��� ��ġ�� ���� ���� �ʺ�켱Ž���� �����Ѵ�.

            //i ��° ���ε��� ��ġ
            long long light = lights[i];

            //i ��° ���ε��� ��ġ���� �������� darkness ��ŭ ������ ��ġ
            long long left = light-darkness;
            //left ���� ��� ���� �ƴϰ�, ������ ����� ���� �ƴ� ���-
            if (left>=0 && left<=L && pointsConsidered.find(left)==pointsConsidered.end()) {
                results.push_back(darkness);
                pointsConsidered.insert(left);
            }

            //i ��° ���ε��� ��ġ���� ���������� darkness ��ŭ ������ ��ġ
            long long right = light+darkness;
            //right ���� ��� ���� �ƴϰ�, ������ ����� ���� �ƴ� ���-
            if (right>=0 && right<=L && pointsConsidered.find(right)==pointsConsidered.end()) {
                results.push_back(darkness);
                pointsConsidered.insert(right);
            }
        } //i loop (�� ���� ��ġ�� ��ġ�� ���� ����)
        darkness++;
    } //while loop (results�� K �� ���� ������ �� ���� �ݺ��Ѵ�.)


    //results���� ���� K �� "�̻�" ��������Ƿ�
    //���� ��� for-loop ��� index�� ����ϴ� for-loop�� ����Ѵ�.
    for (int i=0; i<K; i++) {
        printf("%lld\n", results[i]);
    }

    return 0;
}

#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    //n: ����� ��
    //k: ������ ����� ��
    //x: �� ����� ���� �Ŀ� ��ġ�� ���ǵ� ��ġ�� ��
    int n, k, x;
    scanf("%d %d %d", &n, &k, &x);
    //powerOf[i] := i �� �ο��� �Ŀ� ��ġ (�Ŀ� ��ġ�� �˸� ���ǵ� ��ġ�� �ڵ����� ���� �� �ִ�.)
    int powerOf[80];
    int speed_;
    for (int i=0; i<n; i++)
        scanf("%d %d", &powerOf[i], &speed_);

    //dpArray[j][m] := j ���� �ο����� �Ŀ� ��ġ �� m�� ���� �� �ִ��� ����
    bool dpArray[90][17000] = {true};

    for (int participantIndex=0; participantIndex<n; participantIndex++) {
        for (int numSelectedParticipants=k-1; numSelectedParticipants>=0; numSelectedParticipants--) {
            for (int sumPower=x*k; sumPower>=0; sumPower--) {
                if (dpArray[numSelectedParticipants][sumPower]) //participantIndex �ο� ���� numSelectedParticipants������ sumPower ��ġ�� �����ϴٸ�-
                    dpArray[numSelectedParticipants+1][sumPower+powerOf[participantIndex]] = true; //participantIndex �ο��� ���������ν� sumPower+powerOf[participantIndex] �Ŀ� ��ġ�� �����ϴ�.
                /*
                    ��ó�� ��ȭ�Ŀ��� dpArray �迭�� �Ʒ� ��, ������ ���� ��ȭ��Ű�� ������
                    dpArray�� ������ ���ϱͿ��� �»�� �������� �̷������ �Ѵ�.
                    ���� dpArray�� ������ �»�Ϳ��� ���ϱ� �������� �̷�����ٸ�
                    participantIndex �ο��� �����ؾ�  ���������� �Ŀ� ��ġ�� �ٽ� �� �� participantIndex �ο��� �����ϴ�,
                    (�ٽ� ����) �� ����� �Ŀ� ��ġ�� �ߺ��ؼ� ����ϴ� ������ �߻��� �� �ִ�.
                    participantIndex�� �Ŀ� ��ġ�� ������� ���� �������� �о� ������ ���� dpArray�� ���ϱͿ��� �»�� �������� ������ ������.
                */
            } //sumPower loop (���õ� �ο��� �Ŀ� ��ġ �� loop)
        } //numSelectedParticipants loop (���õ� �ο� �� loop)
    } //participantIndex loop (�� ��ȣ�� �ο� loop)

    int result = 0;
    for (int sumPower=0; sumPower<=x*k; sumPower++) {
        if (!dpArray[k][sumPower]) //k �� �ο��� �����Ͽ� sumPower ��ŭ�� �Ŀ� ��ġ�� ���� ���Ѵٸ� �� ���� �����Ѵ�.
            continue;
        //k �� �ο��� �����Ͽ� ���� �� �ִ� sumPower ��ġ�� ����-
        result = max(result, sumPower*(x*k-sumPower)); //sumSpeed�� ����Ͽ� ���� ���� �ɷ�ġ�� ���� �� �ִ�. ���� ���� �ɷ�ġ �� �ִ�ġ�� ���Ѵ�.
    }
    printf("%d", result);

    return 0;
}

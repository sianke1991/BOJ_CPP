#include<stdio.h>
//imos: ����� ���常 ����ϴ� ���
int enterExit[1000002]; //����� 1�� ���ϰ� ����� 1�� ���� �迭
int numOccupies[1000002]; //�ε��� 1���� Ư�� �ε������� enterExit�� �������� ����Ͽ� Ư�� �ð��� �л����� ����� ����� �����ϴ� �迭
                            //enterExit �迭�� 1�� ��ϵǾ� ������ �� �� ������ ���̹Ƿ� �������� ����� �� �� �����ؾ� �Ѵ�.
                            //�ݴ�� enterExit �迭�� -1�� ��ϵǾ� ������ �� �� ������ ���̹Ƿ� �������� ����� �� �� �����ؾ� �Ѵ�.


int main() {
    int numStudents;
    scanf("%d", &numStudents);
    for (int i=0; i<numStudents; i++) {
        int s, e;
        scanf("%d %d", &s, &e);
        enterExit[s]++;
        enterExit[e+1]--; //5�ÿ� ���������� 5�ñ��� ������ �¼��� �����ϴ� ���̴�.
    }
    for (int i=1; i<=1000000; i++) {
        numOccupies[i] = numOccupies[i-1]+enterExit[i];
    }
    int numQueries;
    scanf("%d", &numQueries);
    int queries[numQueries];
    for (int i=0; i<numQueries; i++) {
        scanf("%d", &queries[i]);
    }
    int results[numQueries];
    for (int i=0; i<numQueries; i++) {
        results[i] = numOccupies[queries[i]];
    }
    for (int result:results) {
        printf("%d\n", result);
    }
    return 0;

}

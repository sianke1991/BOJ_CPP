#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

/*
2531: ȸ�� �ʹ� ������ 13144: List of Unique Number�� �޸�
�ϳ��� �������� ���� �� ������ �� �����Ƿ� bool �迭�� �ƴ� int �迭�� ����ؾ� �Ѵ�.
*/

int typeAt[30001]; //�� ���ÿ� �÷��� �ʹ��� ����
int selected[30001]; //�� �ʹ� ������ ���� �ش� �ʹ��� ������ ����
int sz = 0; //���� ���õ� �ʹ� ������ ����

/**
 * ���ڷ� ���� ��ȣ�� �ش��ϴ� �ʹ��� �����Ѵ�.
 */
void add(int typeNumber) {
    if (selected[typeNumber]==0) { //�������� ���� �ʹ��� ������ ���
        selected[typeNumber] = 1;
        sz++;
    } else { //�̹� ������ �ʹ��� �� ������ ���
        selected[typeNumber]++;
    }
}

/**
 * ���ڷ� ���� ��ȣ�� �ش��ϴ� �ʹ��� �����Ѵ�.
 */
void remove(int typeNumber) {
    if (selected[typeNumber]==1) { //�� �ϳ� ������ �ʹ��� ������ ���
        selected[typeNumber] = 0;
        sz--;
    } else if (selected[typeNumber]>1) { //�� �̻� ������ �ʹ��� ������ ���
        selected[typeNumber]--;
    }
}

/**
 * ������ �ʹ��� ���� ������ ��ȯ�Ѵ�. (���� ��ȣ�� �Է¹޴´�.)
 */
int size(int couponNumber) {
    if (selected[couponNumber]!=0) //���� ��ȣ�� �ش��ϴ� �ʹ��� ������ ���
        return sz;
    else //���� ��ȣ�� �ش��ϴ� �ʹ��� �������� ���� ���
        return sz+1;
}

int max(int num0, int num1) {
    return num0 > num1 ? num0 : num1;
}

int main() {
    int numDishes; //ȸ�� �ʹ� ��Ʈ�� ���� ������ ��
    int numTypes; //�ʹ��� ������
    int consecutiveDishSize; //�����ؼ� �Դ� ������ ��
    int couponNumber; //���� ��ȣ

    scanf("%d %d %d %d", &numDishes, &numTypes, &consecutiveDishSize, &couponNumber);

    for (int i=0; i<numDishes; i++) {
        scanf("%d", &typeAt[i]);
    }

    int st=0, ed=consecutiveDishSize-1;
    for (int i=0; i<consecutiveDishSize; i++) {
        add(typeAt[i]);
    }
    int optResult = size(couponNumber);

    for (st=1; st<numDishes; st++) {
        ed = (ed+1)%numDishes;
        add(typeAt[ed]);
        remove(typeAt[st-1]);
        optResult = max(optResult, size(couponNumber));
    } //st loop

    printf("%d", optResult);
    return 0;
}

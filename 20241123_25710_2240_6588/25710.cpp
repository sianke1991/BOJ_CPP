#include <stdio.h>
#include <vector>

using namespace std;

/*
    �迭�� ����(�ִ� 100000)�� ���� �� ���Ұ� ���� �� �ִ� ��(1-999)�� ������ ����.
    �迭 a�� "���� ��ġ�� ����"�� ����.
    �� �ߺ��� �����ϸ� ���� ������ Ƚ���� ���� �� �ִ�.
*/

//�迭 a�� ����: ���� �Է¹޴´�.
int arrLength;
//�迭 a �� �� ������ ����: �ϳ��� ���� �� ���� �ʰ��Ͽ� ���� �ʿ�� ����.
int elemCount[1001];
//�ߺ��� �����Ͽ� �籸���� �迭 a (�ϳ��� ���� ���� �ִ� �� �� ���� �� �ִ�,)
vector<int> arr;

void input() {
    scanf("%d", &arrLength);
    for (int i=0; i<arrLength; i++) {
        int elem;
        scanf("%d", &elem);
        elemCount[elem]++;
        if (elemCount[elem]<3)
            arr.push_back(elem);
    } //i loop
    arrLength = arr.size();
    //printf("==============%d\n", arrLength);
    //printf("input done\n");
}

//�迭 �� �� ���Ҹ� �Է� �޾�, ȹ���� �� �ִ� ������ ����Ͽ� ��ȯ�Ѵ�.
int point(int num0, int num1) {
    int product = num0*num1;
    int result = 0;
    while (product) {
        result += product%10;
        product /= 10;
    } //while loop
    return result;
}

int max(int num0, int num1) {
    return num0 > num1 ? num0 : num1;
}

int main() {
    input();
    int result = 0;
    for (int i=0; i<arrLength; i++) {
        for (int j=i+1; j<arrLength; j++) {
            result = max(result, point(arr[i], arr[j]));
        } //j loop
    } //i loop
    printf("%d", result);
    return 0;
}

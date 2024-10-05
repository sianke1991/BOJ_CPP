#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;


int numHomeWorks;
vector<int> homeWorks[1001]; //�����Ͽ� ���� ������ ������ ����Ѵ�. (e.g. homeWorks[3]:= ������ 3�� ¥���� ������ ���� ���)
priority_queue<int> pq; //���� ������ ��ȿ�� ���� ����

int main() {
    //���� �Է� �ޱ�-
    scanf("%d", &numHomeWorks);
    for (int i=0; i<numHomeWorks; i++) {
        int due, value;
        scanf("%d %d", &due, &value);
        homeWorks[due].push_back(value);
    } //i loop

    int result = 0;
    //�ð��� �����ϸ鼭, ���� ��ȿ�� ���� �߿��� ��ġ�� ���� ������ �ذ��Ѵ�.
    //�ð��� �����ؾ� [��ȿ�� ����]�� ���� �߰��ȴ�.
    //�ð��� �����ϸ� [��ȿ�� ������ �� �̻� ��ȿ���� �ʰ� �Ǵ� ��]�� ����ؾ� �Ѵ�.
    for (int currentDate=1000; currentDate>=1; currentDate--) {
        //step a. �ش� ��¥�� ��ȿ�� ������ pq�� �ִ´�.
        for (auto hw:homeWorks[currentDate]) pq.push(hw);
        //step b. pq�� ������� ���� ��� pq���� ���� ��ġ�� ���� ���� ������ �ذ��Ѵ�.
        if (!pq.empty()) {
            result += pq.top();
            pq.pop();
        }
    } //currentDate loop
    printf("%d", result);
    return 0;
}

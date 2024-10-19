#include <stdio.h>
#include <vector>

using namespace std;


struct TestCase {
    //������ �ִ� ���� ����
    int numHouses;
    //������ ħ���� ���� ����
    int numTargetHouses;
    //�ڵ� ��� ��ġ�� �۵��ϴ� �ּ� ���� ��
    int upperLimit;
    //���� �� �� ���� �����ϴ� ���� ��
    vector<int> houses;
};

int numTestCases;
vector<TestCase> testCases;

void input() {
    scanf("%d", &numTestCases);
    for (int i=0; i<numTestCases; i++) {
        TestCase tc;
        scanf("%d %d %d", &tc.numHouses, &tc.numTargetHouses, &tc.upperLimit);
        for (int j=0; j<tc.numHouses; j++) {
            int house;
            scanf("%d", &house);
            tc.houses.push_back(house);
        } //j loop
        testCases.push_back(tc);
    } //i loop
}

int solve(TestCase tc) {
    int result = 0;
    //�ε��� 0�� ������ �ð� �������� numTargetHouses��ŭ �о��� �� ��� �Ǵ� ���� ���� ����Ѵ�.
    int sumHouses = 0; //numTargetHouses ��ŭ�� ���� �о ���� �� �ִ� ���� ��
    for (int i=0; i<tc.numTargetHouses; i++) {
        sumHouses += tc.houses[i];
    } //i loop
    if (sumHouses<tc.upperLimit) result++;
    //���� �� ��� ���� �ʹ� ���� ��ǥ��� j loop�� �������� �ʴ´�.
    //(���� ���̸� �����ϴ� ���� �� ĭ �� �ű���� ��� ���� ����̹Ƿ� �̵��� �ߺ��Ͽ� ��Ƹ��� �ȵȴ�.)
    //���� �� ������ ���� �ʴ� ���� �ִٸ� j loop�� �����ؾ� �Ѵ�.
    if (tc.numHouses==tc.numTargetHouses)
        return result;
    //���� ���̸� �����ϴ� ���� ���������� �� ĭ �� �Űܰ��鼭 sumHouses�� �����Ѵ�.
    for (int j=1; j<tc.numHouses; j++) {
        sumHouses -= tc.houses[j-1];
        sumHouses += tc.houses[(j+tc.numTargetHouses-1)%tc.numHouses];
        if (sumHouses<tc.upperLimit) result++;
    } //j loop
    return result;
}

int main() {
    input();
    vector<int> results;
    for (auto tc:testCases) {
        results.push_back(solve(tc));
    }
    for (auto result:results) {
        printf("%d\n", result);
    }
    return 0;
}

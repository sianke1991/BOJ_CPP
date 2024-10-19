#include <stdio.h>
#include <vector>

using namespace std;


struct TestCase {
    //마을에 있는 집의 개수
    int numHouses;
    //도둑이 침입할 집의 개수
    int numTargetHouses;
    //자동 방범 장치가 작동하는 최소 돈의 양
    int upperLimit;
    //마을 내 각 집에 보관하는 돈의 양
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
    //인덱스 0번 집부터 시계 방향으로 numTargetHouses만큼 털었을 때 얻게 되는 돈의 양을 계산한다.
    int sumHouses = 0; //numTargetHouses 만큼의 집을 털어서 얻을 수 있는 돈의 양
    for (int i=0; i<tc.numTargetHouses; i++) {
        sumHouses += tc.houses[i];
    } //i loop
    if (sumHouses<tc.upperLimit) result++;
    //마을 내 모든 집을 터는 것이 목표라면 j loop를 수행하지 않는다.
    //(도둑 털이를 시작하는 집이 한 칸 씩 옮기더라도 모두 같은 경우이므로 이들을 중복하여 헤아리면 안된다.)
    //마을 내 집에서 털지 않는 집이 있다면 j loop를 수행해야 한다.
    if (tc.numHouses==tc.numTargetHouses)
        return result;
    //도둑 털이를 시작하는 집을 오른쪽으로 한 칸 씩 옮겨가면서 sumHouses를 갱신한다.
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

#include <bits/stdc++.h>

using namespace std;

const int INFINITE_PRICE = 100000000;
int priceMatrix[101][101]; //priceMatrix[s][t]: s에서 시작하여 t에 도착하는데 필요한 비용
                            //priceMatrix[s][t]의 초기화
                            //priceMatrix[s][t] = 0 if s==t, input value if s and t are connected directly, INFINITE_PRICE otherwise
int nxtMatrix[101][101]; //nxtMatrix[s][t]: s에서 시작하여 t로 도착할 때 s에서 가야할 노드
                            //nxtMatrix[s][t]의 초기화
                            //nxtMatrix[s][t] = t if s and t (s!=t) are connected directly, -1 otherwise
string pathMatrix[101][101]; //pathMatrix[s][t]: s에서 시작하여 t로 도착할 때 거쳐야 할 노드를 공백으로 구분하여 작성된 문자열
                            //pathMatrix의 각 원소는 빈 문자열("")로 초기화 되고, 이 값을 초기값으로 그대로 사용한다.
int pathLengthMatrix[101][101]; //pathLengthMatrix[s][t]: s에서 시작하여 t로 도착할 때 거쳐야 할 노드의 개수
                                //pathLengthMatrix의 각 원소는 0으로 초기화 되고, 이 값을 초기값으로 그대로 사용한다.
//nxtMatrix가 완성한 다음에 pathMatrix와 pathLengthMatrix를 완성할 수 있는데, 재귀함수를 사용할 것이므로,
//함수 수행 중 nxtMatrix의 각 원소에 쉽게 접근하기 위해 nxtMatrix는 전역변수로 만들 필요가 있다.

int Min(int num0, int num1) {
    return num0<num1 ? num0 : num1;
}

/**
 * from에서 to로 가기 위해 거쳐야 할 경로를 반환한다.<br/>
 * 계산 중 pathMatrix의 내용을 참조하고 갱신한다.<br/>
 * 이 함수 호출 전 priceMatrix, nxtMatrix는 전부 완성되어있어야 한다.
 */
string path(int from, int to) {
    if (from==to || priceMatrix[from][to]>=INFINITE_PRICE) { //from에서 to로 가는 것이 불가능한 경우 아무리 재귀 호출을 하더라도 재귀 호출이 종료되지 않는다.
                                                            //즉, from에서 to로 가는 것이 불가능한 경우 재귀 호출을 막아야 한다. from에서 to로 가는 것이 불가능한지
                                                            //여부 판단은 priceMatrix[from][to]을 사용하여 할 수 있다. 즉, priceMatrix[from][to]가 INFINITE_PRICE 이상인 경우
                                                            //from에서 to로 가는 것이 불가능하다고 판단할 수 있다.
        return "";
    }
    if (pathMatrix[from][to]!="") { //from에서 to로 가는 경로를 이미 구한 경우 pathMatrix에 저장된 값을 그대로 반환한다. (메모이제이션)
        return pathMatrix[from][to];
    } else {
        int mid = nxtMatrix[from][to]; //경유 노드
        if (mid==to) { //경유 노드가 도착 노드와 같은 경우 from에서 to로 직접 가는 것이 가장 빠른 것이다. (재귀 호출 종료 조건)
            pathMatrix[from][to] = to_string(from) + " " + to_string(to);
            pathLengthMatrix[from][to] = 2;
            return pathMatrix[from][to];
        } else { //경유 노드가 도착 노드와 다른 경우 from에서 mid를 거쳐서 to로 가야 한다. mid에서 to로 가는 경로는 재귀 호출을 통해서 구한다.
            pathMatrix[from][to] = to_string(from) + " "  + path(mid, to); //mid는 path(mid, to)의 일부이므로 to_string(mid)는 더하면 안된다.
            pathLengthMatrix[from][to] = 1 + pathLengthMatrix[mid][to]; //pathMatrix[from][to]는 pathMatrix[mid][to]의 앞에 from이 붙은 것이다. 즉, 경로 길이는
                                                                        //pathLengthMatrix[from][to]는 pathLengthMatrix[mid][to] 보다 1 큰 값이다.
            return pathMatrix[from][to];
        }
    }
}


int main() {
    int numCities, numBuses;
    cin >> numCities;
    cin >> numBuses;

    //priceMatrix, nxtMatrix 초기화
    for (int i=1; i<=numCities; i++) {
        for (int j=1; j<=numCities; j++) {
            priceMatrix[i][j] = INFINITE_PRICE;
            nxtMatrix[i][j] = -1;
        } //j loop
        priceMatrix[i][i] = 0;
    } //i loop

    //간선 정보 입력
    for (int i=0; i<numBuses; i++) {
        int s, t, p;
        cin >> s >> t >> p;
        priceMatrix[s][t] = Min(priceMatrix[s][t], p); //s에서 시작하여 t에 도착하는 비용이 여러 번 입력될 수 있으므로, 입력값 중 최소를 priceMatrix[s][t]에 넣는다.
        nxtMatrix[s][t] = t; //s노드와 t노드가 직접 연결되었으므로 nxtMatrix[s][t]는 t로 변경한다.
    }

    //플로이드 알고리즘 적용
    //모든 노드 쌍(s, t)에 대해서 s에서 출발하여 t에 도착하는데 필요한 비용을 구해야 하므로 플로이드 알고리즘을 사용한다.
    for (int k=1; k<=numCities; k++) { //k를 경유하는 경우를 고려한다.
        for (int s=1; s<=numCities; s++) {
            for (int t=1; t<=numCities; t++) {
                if (priceMatrix[s][t]>priceMatrix[s][k]+priceMatrix[k][t]) { //만약 s에서 t로 가는데 k를 경유하는 것이 더 효율적인 경우-
                    priceMatrix[s][t] = priceMatrix[s][k]+priceMatrix[k][t]; //k를 경유할 때 비용으로 갱신한다.
                    nxtMatrix[s][t] = nxtMatrix[s][k]; //k를 경유할 때 다음 노드로 갱신한다.
                }
            } //t loop (도착 노드 루프)
        } //s loop (시작 노드 루프)
    } //k loop (경유 노드 루프)

    //경로 배열 구성
    for (int s=1; s<=numCities; s++) {
        for (int t=1; t<=numCities; t++) {
            path(s, t);
        } //t loop (도착 노드 루프)
    } //s loop (시작 노드 루프)

    //비용 행렬 출력
    for (int s=1; s<=numCities; s++) {
        for (int t=1; t<=numCities; t++) {
            cout << (priceMatrix[s][t]>=INFINITE_PRICE ? 0 : priceMatrix[s][t]) << ' ';
        } //t loop (도착 노드 루프)
        cout << '\n';
    } //s loop (시작 노드 루프)

    //경로 출력
    for (int s=1; s<=numCities; s++) {
        for (int t=1; t<=numCities; t++) {
            cout << pathLengthMatrix[s][t] << ' ' << pathMatrix[s][t] << '\n';
        } //t loop (도착 노드 루프)
    } //s loop (시작 노드 루프)

    return 0;
}

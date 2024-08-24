#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <algorithm>
#define INF 10000
using namespace std;

/*
    �Է� ���� ���� �� ���� �̵��ϴµ� �ɸ��� �ð��� ���� ��,
    �÷��̵�-���� �˰����� ����Ͽ�
    Ÿ ���ø� �����ؼ� ���� �� �̵��ϴµ� �ɸ��� �ð��� ���Ѵ�.
    ���� �� ���� �̵��ϴµ� �ɸ��� �ð��� ���� ������
    �ɾ �̵��� �� �ɸ��� �ð���, �ڷ���Ʈ �� �� �Ÿ��� �ð�
    ���� ����ؾ� �Ѵ�.
*/

struct City {
    int special;
    int x;
    int y;
};

int numCities;
int teleportationTime;
int adjMatrix[1002][1002];
int numQueries;
vector<City> cities = {{0, 0, 0}};
vector<pair<int, int>> queries;

//�� ���ø� ���� �̵��ϴµ� �ɸ��� �ð�:
//�� ���ð� ���� Ư���� ���ö�� �ɾ �̵����� Ȥ�� �ڷ���Ʈ�� ��������� �����ؾ� �Ѵ�.
int distanceBetween(City c0, City c1) {
    int result = abs(c0.x-c1.x) + abs(c0.y-c1.y);
    if (c0.special==0 || c1.special==0) return result;
    else return min(result, teleportationTime);
}

int main() {
    scanf("%d %d", &numCities, &teleportationTime);
    for (int i=0; i<numCities; i++) {
        int special, x, y;
        scanf("%d %d %d", &special, &x, &y);
        cities.push_back({special, x, y});
    }
    scanf("%d", &numQueries);
    for (int i=0; i<numQueries; i++) {
        int f, s;
        scanf("%d %d", &f, &s);
        queries.push_back({f, s});
    }

    for (int i=1; i<=numCities; i++) {
        for (int j=1; j<i; j++) {
            int dist = distanceBetween(cities[i], cities[j]);
            adjMatrix[i][j] = dist;
            adjMatrix[j][i] = dist;
        }
        for (int j=i+1; j<=numCities; j++) {
            int dist = distanceBetween(cities[i], cities[j]);
            adjMatrix[i][j] = dist;
            adjMatrix[j][i] = dist;
        }
    } //i loop

    for (int k=1; k<=numCities; k++) {
        for (int s=1; s<=numCities; s++) {
            for (int t=1; t<=numCities; t++) {
                adjMatrix[s][t] = min(adjMatrix[s][t], adjMatrix[s][k]+adjMatrix[k][t]);
            } //t loop
        } //s loop
    } //k loop

    vector<int> result;
    for (auto query:queries) {
        result.push_back(adjMatrix[query.first][query.second]);
    } //query loop
    for (int elem:result)
        printf("%d\n", elem);
    return 0;
}

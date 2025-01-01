#include <stdio.h>
#include <vector>
#define X first
#define Y second
using namespace std;

long long sumArea = 0LL;
int numPolygons;
int numPoints;
vector<pair<long long, long long>> coordinates;

void testCase() {
    scanf("%d", &numPoints);
    coordinates.clear();
    for (int i=0; i<numPoints; i++) {
        long long x, y;
        scanf("%lld %lld", &x, &y);
        coordinates.push_back({x, y});
    }
    coordinates.push_back(coordinates[0]);
    long long result = 0LL;
    for (int i=0; i<numPoints; i++)
        result += coordinates[i].Y*coordinates[i+1].X - coordinates[i].X*coordinates[i+1].Y;
    if (result>=0LL)
        sumArea += result;
    else
        sumArea -= result;
}

int main() {
    scanf("%d", &numPolygons);
    for (int i=0; i<numPolygons; i++)
        testCase();
    printf("%lld", sumArea/2);
    return 0;
}

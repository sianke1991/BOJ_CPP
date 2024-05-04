#include <bits/stdc++.h>

using namespace std;

/*
    1. 점을 나타내는 방법: 점을 나타낼 때는 6자리 십진수를 사용한다. 앞 세 자리는 x 좌표의 값, 뒷 세 자리는 y 좌표의 값을 사용한다.
       예를 들어 x=51, y= 48의 점은 10진수 051048로 나타낸다. (int 사용 가능)
    2. 좌표 (c, d)를 중심으로 좌표 (x, y)가 시계 방향으로 90도 회전한 좌표는 (-y+c+d, x-c+d) 이다. (중심 좌표 (c, d)는 회전에 의해 변하지 않는다.)
*/

/**
 * 각 방향에 따른 점 변화
 */
const int dPoint[] = {1000, -1, -1000, 1};

/**
 * x, y 좌표를 입력받아 이에 대응되는 점 값을 반환한다.
 */
int pointOf(int x, int y) {
    return x*1000+y;
}

/**
 * 점 값을 입력 받아 점 값의 x 좌표를 반환한다.
 */
int xCoordinateOf(int point) {
    return point/1000;
}

/**
 * 점 값을 입력 받아 점 값의 y 좌표를 반환한다.
 */
int yCoordinateOf(int point) {
    return point%1000;
}

string pointToString(int point) {
    return "(" + to_string(xCoordinateOf(point)) + ", " + to_string(yCoordinateOf(point)) + ")";
}


/**
 * 입력받은 방향으로 입력받은 점에 이웃한 점을 반환한다.
 */
int nextPointIn(int direction, int point) {
    return point + dPoint[direction];
}

/**
 * 입력받은 중심 좌표를 중심으로 입력받은 점을 90도 시계방향 회전했을 때 나오는 점을 반환한다.
 */
int rotationBy(int center, int point) {
    int c = xCoordinateOf(center);
    int d = yCoordinateOf(center);
    int x = xCoordinateOf(point);
    int y = yCoordinateOf(point);
    return pointOf(-y+c+d, x-c+d);
}


/**
 * 시작 x좌표, y좌표, 방향 및 세대 수를 입력받아 이에 대응되는 dragon curve를 반환한다.
 */
vector<int> dragonCurveOf(int initialX, int initialY, int initialDirection, int numGenerations) {
    //cout << "log:::::" << initialX << ", " << initialY << ", " << initialDirection << ", " << numGenerations << '\n';
    vector<int> result;
    int initialPoint = pointOf(initialX, initialY);
    result.push_back(initialPoint);
    result.push_back(nextPointIn(initialDirection, initialPoint));

    for (int generation=0; generation<numGenerations; generation++) {
        // 반복을 돌면서 vector에 값을 넣기 때문에 vector.size() 메서드 호출 값이 변할 수 있다. 이를 방지하기 위해
        // vector.size() 메서드 호출 값을 미리 보관해 둔다.
        int sz = result.size();
        // dragon curve에 마지막으로 추가된 점이 회전 중심이 된다.
        int center = result[sz-1];
        // 회전 중심을 제외한 나머지 점들을 역순으로 회전한 결과를 dragon curve에 넣는다.
        for (int pointIndex=sz-2; pointIndex>=0; pointIndex--) {
            int point = result[pointIndex];
            result.push_back(rotationBy(center, point));
        } //pointIndex loop
    } //generation loop
    return result;
}

string dragonCurveToString(vector<int> dragonCurve) {
    string result = "[";
    for (int point:dragonCurve) {
        result += pointToString(point);
    }
    result += "]";
    return result;
}

/**
 * 왼쪽 위 좌표를 입력받아 이에 해당하는 정사각형의 네 꼭지점을 반환한다.
 */
vector<int> squareOf(int topLeftCornerX, int topLeftCornerY) {
    vector<int> result;
    int topLeftCornerPoint = pointOf(topLeftCornerX, topLeftCornerY);
    int topRightCornerPoint = nextPointIn(0, topLeftCornerPoint);
    result.push_back(topLeftCornerPoint);
    result.push_back(topRightCornerPoint);
    result.push_back(nextPointIn(3, topLeftCornerPoint));
    result.push_back(nextPointIn(3, topRightCornerPoint));
    return result;
}

/**
 * 왼쪽 위 점을 입력받아 이에 해당하는 정사각형의 네 꼭지점을 반환한다.
 */
vector<int> squareOf(int topLeftCornerPoint) {
    vector<int> result;
    int topRightCornerPoint = nextPointIn(0, topLeftCornerPoint);
    result.push_back(topLeftCornerPoint);
    result.push_back(topRightCornerPoint);
    result.push_back(nextPointIn(3, topLeftCornerPoint));
    result.push_back(nextPointIn(3, topRightCornerPoint));
    return result;
}



vector<int> dragonCurves[21];
set<int> dragonCurvePoints;

int main() {
    int numDragonCurves;
    scanf("%d", &numDragonCurves);
    for (int i=0; i<numDragonCurves; i++) {
        int initialX, initialY, initialDirection, numGenerations;
        scanf("%d %d %d %d", &initialX, &initialY, &initialDirection, &numGenerations);
        dragonCurves[i] = dragonCurveOf(initialX, initialY, initialDirection, numGenerations);
    }
    for (int i=0; i<numDragonCurves; i++) {
        for (int point:dragonCurves[i]) {
            dragonCurvePoints.insert(point);
        }
    }

    // 정사각형 개수
    int result = 0;

    /*
    (0, 0) 부터 (99, 99) 까지 모든 점에 대해 정사각형이 생성되었는지 묻는 방법
    for (int topLeftCornerX=0; topLeftCornerX<100; topLeftCornerX++) {
        for (int topLeftCornerY=0; topLeftCornerY<100; topLeftCornerY++) {
            bool checkToContainAllFourPoints = true;
            for (int point:squareOf(topLeftCornerX, topLeftCornerY)) {
                if (dragonCurvePoints.find(point)==dragonCurvePoints.end()) {
                    checkToContainAllFourPoints = false;
                    break;
                }
            } //point loop
            if (checkToContainAllFourPoints) // 해당 정사각형 네 꼭지점이 dragon curve에 속하는 경우-
                result++;
        } //topLeftCornerY loop
    } //topLeftCornerX loop
    */

    // 생성된 정사각형의 후보는 [dragon curve에 포함된 점의 목록]만 헤아려도 충분하다.
    // [dragon curve에 포함되지 않은 점]은 정사각형을 생성할 수 없다.
    // 이 작업이 수행되기 전에 [dragon curve에 포함된 점의 목록]은 중복이 제거되어야 한다.
    for (int pointInDragonCurve:dragonCurvePoints) {
        bool checkToContainAllFourPoints = true;
        for (int point:squareOf(pointInDragonCurve)) {
            if (dragonCurvePoints.find(point)==dragonCurvePoints.end()) {
                checkToContainAllFourPoints = false;
                break;
            }
        }
        if (checkToContainAllFourPoints) // 해당 정사각형 네 꼭지점이 dragon curve에 속하는 경우-
            result++;
    } //pointInDragonCurve loop

    printf("%d", result);

    return 0;
}

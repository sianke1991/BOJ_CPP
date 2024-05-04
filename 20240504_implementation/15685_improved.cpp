#include <bits/stdc++.h>

using namespace std;

/*
    1. ���� ��Ÿ���� ���: ���� ��Ÿ�� ���� 6�ڸ� �������� ����Ѵ�. �� �� �ڸ��� x ��ǥ�� ��, �� �� �ڸ��� y ��ǥ�� ���� ����Ѵ�.
       ���� ��� x=51, y= 48�� ���� 10���� 051048�� ��Ÿ����. (int ��� ����)
    2. ��ǥ (c, d)�� �߽����� ��ǥ (x, y)�� �ð� �������� 90�� ȸ���� ��ǥ�� (-y+c+d, x-c+d) �̴�. (�߽� ��ǥ (c, d)�� ȸ���� ���� ������ �ʴ´�.)
*/

/**
 * �� ���⿡ ���� �� ��ȭ
 */
const int dPoint[] = {1000, -1, -1000, 1};

/**
 * x, y ��ǥ�� �Է¹޾� �̿� �����Ǵ� �� ���� ��ȯ�Ѵ�.
 */
int pointOf(int x, int y) {
    return x*1000+y;
}

/**
 * �� ���� �Է� �޾� �� ���� x ��ǥ�� ��ȯ�Ѵ�.
 */
int xCoordinateOf(int point) {
    return point/1000;
}

/**
 * �� ���� �Է� �޾� �� ���� y ��ǥ�� ��ȯ�Ѵ�.
 */
int yCoordinateOf(int point) {
    return point%1000;
}

string pointToString(int point) {
    return "(" + to_string(xCoordinateOf(point)) + ", " + to_string(yCoordinateOf(point)) + ")";
}


/**
 * �Է¹��� �������� �Է¹��� ���� �̿��� ���� ��ȯ�Ѵ�.
 */
int nextPointIn(int direction, int point) {
    return point + dPoint[direction];
}

/**
 * �Է¹��� �߽� ��ǥ�� �߽����� �Է¹��� ���� 90�� �ð���� ȸ������ �� ������ ���� ��ȯ�Ѵ�.
 */
int rotationBy(int center, int point) {
    int c = xCoordinateOf(center);
    int d = yCoordinateOf(center);
    int x = xCoordinateOf(point);
    int y = yCoordinateOf(point);
    return pointOf(-y+c+d, x-c+d);
}


/**
 * ���� x��ǥ, y��ǥ, ���� �� ���� ���� �Է¹޾� �̿� �����Ǵ� dragon curve�� ��ȯ�Ѵ�.
 */
vector<int> dragonCurveOf(int initialX, int initialY, int initialDirection, int numGenerations) {
    //cout << "log:::::" << initialX << ", " << initialY << ", " << initialDirection << ", " << numGenerations << '\n';
    vector<int> result;
    int initialPoint = pointOf(initialX, initialY);
    result.push_back(initialPoint);
    result.push_back(nextPointIn(initialDirection, initialPoint));

    for (int generation=0; generation<numGenerations; generation++) {
        // �ݺ��� ���鼭 vector�� ���� �ֱ� ������ vector.size() �޼��� ȣ�� ���� ���� �� �ִ�. �̸� �����ϱ� ����
        // vector.size() �޼��� ȣ�� ���� �̸� ������ �д�.
        int sz = result.size();
        // dragon curve�� ���������� �߰��� ���� ȸ�� �߽��� �ȴ�.
        int center = result[sz-1];
        // ȸ�� �߽��� ������ ������ ������ �������� ȸ���� ����� dragon curve�� �ִ´�.
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
 * ���� �� ��ǥ�� �Է¹޾� �̿� �ش��ϴ� ���簢���� �� �������� ��ȯ�Ѵ�.
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
 * ���� �� ���� �Է¹޾� �̿� �ش��ϴ� ���簢���� �� �������� ��ȯ�Ѵ�.
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

    // ���簢�� ����
    int result = 0;

    /*
    (0, 0) ���� (99, 99) ���� ��� ���� ���� ���簢���� �����Ǿ����� ���� ���
    for (int topLeftCornerX=0; topLeftCornerX<100; topLeftCornerX++) {
        for (int topLeftCornerY=0; topLeftCornerY<100; topLeftCornerY++) {
            bool checkToContainAllFourPoints = true;
            for (int point:squareOf(topLeftCornerX, topLeftCornerY)) {
                if (dragonCurvePoints.find(point)==dragonCurvePoints.end()) {
                    checkToContainAllFourPoints = false;
                    break;
                }
            } //point loop
            if (checkToContainAllFourPoints) // �ش� ���簢�� �� �������� dragon curve�� ���ϴ� ���-
                result++;
        } //topLeftCornerY loop
    } //topLeftCornerX loop
    */

    // ������ ���簢���� �ĺ��� [dragon curve�� ���Ե� ���� ���]�� ��Ʒ��� ����ϴ�.
    // [dragon curve�� ���Ե��� ���� ��]�� ���簢���� ������ �� ����.
    // �� �۾��� ����Ǳ� ���� [dragon curve�� ���Ե� ���� ���]�� �ߺ��� ���ŵǾ�� �Ѵ�.
    for (int pointInDragonCurve:dragonCurvePoints) {
        bool checkToContainAllFourPoints = true;
        for (int point:squareOf(pointInDragonCurve)) {
            if (dragonCurvePoints.find(point)==dragonCurvePoints.end()) {
                checkToContainAllFourPoints = false;
                break;
            }
        }
        if (checkToContainAllFourPoints) // �ش� ���簢�� �� �������� dragon curve�� ���ϴ� ���-
            result++;
    } //pointInDragonCurve loop

    printf("%d", result);

    return 0;
}

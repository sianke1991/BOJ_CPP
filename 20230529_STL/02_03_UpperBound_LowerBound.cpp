#include <bits/stdc++.h>

using namespace std;

int main() {
    int randNum[] = {15428, -31983, 29536, 22892, -15034, -30699, -23425, 10742, 3974, 11912, 19907, 1464, -21475, 9699, 11563, 7381, 168, 27682, -18406, -3231};
    int len = (int)((sizeof randNum)/(sizeof *randNum));
    sort(randNum, randNum+len); //upper_bound 및 lower_bound를 적용하기 전에 배열을 정렬해야 한다.

    int* upperBound0 = upper_bound(randNum, randNum+len, -21475);
    int* lowerBound0 = lower_bound(randNum, randNum+len, -21475);
    cout << upperBound0-randNum << '\n'; //4 //-21475이하에서 -21475초과로 변하는 공간의 위치
    cout << lowerBound0-randNum << '\n'; //3 //-21475미만에서 -21475이상으로 변하는 공간의 위치
    cout << upperBound0-lowerBound0 << '\n'; //1 //randNum에서 -21475의 개수
    cout << *upperBound0 << '\n'; //-18406 //-21475 초과인 원소의 최소치
    cout << *lowerBound0 << '\n'; //-21475 //-21475 이상인 원소의 최소치

    int* upperBound1 = upper_bound(randNum, randNum+len, 123);
    int* lowerBound1 = lower_bound(randNum, randNum+len, 123);
    cout << upperBound1-randNum << '\n'; //7 //123이하에서 123초과로 변하는 공간의 위치
    cout << lowerBound1-randNum << '\n'; //7 //123미만에서 123이상으로 변하는 공간의 위치
    cout << upperBound1-lowerBound1 << '\n'; //0 //randNum에서 123의 개수
    cout << *upperBound1 << '\n'; //168 //123 초과인 원소의 최소치
    cout << *lowerBound1 << '\n'; //186 //123 이상인 원소의 최소치


    vector<int> randNumVector = {2, 4, 4, 6, 1, 3, 4, 6, 1, 2};
    sort(randNumVector.begin(), randNumVector.end()); //{1, 1, 2, 2, 3, 4, 4, 4, 6, 6}

    vector<int>::iterator upperBound2 = upper_bound(randNumVector.begin(), randNumVector.end(), 4);
    vector<int>::iterator lowerBound2 = lower_bound(randNumVector.begin(), randNumVector.end(), 4);
    cout << upperBound2-randNumVector.begin() << '\n'; //8 //4이하에서 4 초과로 변하는 공간의 위치
    cout << lowerBound2-randNumVector.begin() << '\n'; //5 //4미만에서 4 이상으로 변하는 공간의 위치
    cout << upperBound2-lowerBound2 << '\n'; //3 //randNumVector에서 4의 개수
    cout << *upperBound2 << '\n'; //6 //4 초과인 원소의 최소치
    cout << *lowerBound2 << '\n'; //4 //4 이상인 원소의 최소치

    vector<int>::iterator upperBound3 = upper_bound(randNumVector.begin(), randNumVector.end(), 7);
    vector<int>::iterator lowerBound3 = lower_bound(randNumVector.begin(), randNumVector.end(), 7);
    cout << upperBound3-randNumVector.begin() << '\n'; //10 //7이하에서 7 초과로 변하는 공간의 위치
    cout << lowerBound3-randNumVector.begin() << '\n'; //10 //7미만에서 7 초과로 변하는 공간의 위치
    cout << upperBound3-lowerBound3 << '\n'; //0 //randNumVector에서 7의 개수

    return 0;
}

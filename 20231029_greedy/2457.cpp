#include <bits/stdc++.h>

using namespace std;

struct LocalDate {
    int month;
    int date;
};

struct Flower {
    LocalDate beginDate;
    LocalDate endDate;
};

string toString(LocalDate date) {
    string result = "";
    result += to_string(date.month);
    result += "/";
    result += to_string(date.date);
    return result;
}

/**
 * 두 날짜를 비교하여 date0이 더 뒤라면 양수를, date1이 더 뒤라면 음수를 반환한다.
 */
int compareDates(LocalDate date0, LocalDate date1) {
    if (date0.month > date1.month)
        return 1;
    if (date0.month < date1.month)
        return -1;
    return date0.date-date1.date;
}

/**
 * 꽃 배열을 정렬할 기준을 정의한다.
 * 꽃이 늦게 질 수록, (같은 시기에 진다면) 일찍 필 수록 먼저 배치되는 정렬을 사용한다.
 */
bool compareFlowers(Flower flower0, Flower flower1) {
    int cmp = compareDates(flower0.endDate, flower1.endDate);
    if (cmp!=0)
        return cmp>0;
    cmp = compareDates(flower0.beginDate, flower1.beginDate);
    return cmp<0;
}

string toString(Flower flower) {
    string result = "";
    result += toString(flower.beginDate);
    result += " - ";
    result += toString(flower.endDate);
    return result;
}

LocalDate fromInts(int month, int date) {
    LocalDate result;
    result.month = month;
    result.date = date;
    return result;
}

Flower fromInts(int beginMonth, int beginDate, int endMonth, int endDate) {
    Flower result;
    LocalDate* date = new LocalDate();
    date->month = beginMonth;
    date->date = beginDate;
    result.beginDate = *date;
    date = new LocalDate();
    date->month = endMonth;
    date->date = endDate;
    result.endDate = *date;
    return result;
}



Flower flowers[100001]; //문제에서 입력될 꽃의 종류
int main() {

    int numFlowers; //문제에서 입력될 꽃의 개수
    cin >> numFlowers;
    for (int i=0; i<numFlowers; i++) {
        int beginMonth, beginDate, endMonth, endDate;
        cin >> beginMonth >> beginDate >> endMonth >> endDate;
        flowers[i] = fromInts(beginMonth, beginDate, endMonth, endDate);
    }
    sort(flowers, flowers+numFlowers, compareFlowers); //꽃을 정렬하되, 지는 시기가 늦고 (지는 시기가 동일한 경우) 피는 시기가 빠른 순으로 정렬한다.
                                                    //특정 시기에 피어있는 꽃을 선택할 때 최대한 늦게 지는 꽃을 선택해야 유리한 것이다.

    int numSelectedFlowers = 0; //선택된 꽃의 개수
    LocalDate now = fromInts(3, 1); //고려하고 있는 "현재"
    LocalDate targetDate = fromInts(11, 30); //목표 날짜: 이 날까지 꽃이 피어있어야 한다.
    int flowerIndex, recentFlowerIndex = numFlowers; //recentFlowerIndex: 바로 직전에 선택된 꽃의 인덱스 값 (다음에 선택할 꽃은 바로 직전에 선택된 꽃보다 먼저 위치해 있게 된다.)
    while (compareDates(now, targetDate)<=0) {
        for (flowerIndex=0; flowerIndex<recentFlowerIndex; flowerIndex++) {
            if (compareDates(now, flowers[flowerIndex].beginDate)>=0) { //현재 기준으로 피어있는 꽃를 선택한다.
                break;
            }
        }
        if (flowerIndex==recentFlowerIndex) { //현재 기준으로 피어있는 꽃를 선택하지 못한 경우, targetDate까지 최소 하나의 꽃이 피어있게 만들 수 없는 것이다.
            cout << 0;
            return 0;
        }
        numSelectedFlowers++;
        recentFlowerIndex = flowerIndex;
        now = flowers[flowerIndex].endDate;
    }

    cout << numSelectedFlowers;
    return 0;

}

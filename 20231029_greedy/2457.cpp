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
 * �� ��¥�� ���Ͽ� date0�� �� �ڶ�� �����, date1�� �� �ڶ�� ������ ��ȯ�Ѵ�.
 */
int compareDates(LocalDate date0, LocalDate date1) {
    if (date0.month > date1.month)
        return 1;
    if (date0.month < date1.month)
        return -1;
    return date0.date-date1.date;
}

/**
 * �� �迭�� ������ ������ �����Ѵ�.
 * ���� �ʰ� �� ����, (���� �ñ⿡ ���ٸ�) ���� �� ���� ���� ��ġ�Ǵ� ������ ����Ѵ�.
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



Flower flowers[100001]; //�������� �Էµ� ���� ����
int main() {

    int numFlowers; //�������� �Էµ� ���� ����
    cin >> numFlowers;
    for (int i=0; i<numFlowers; i++) {
        int beginMonth, beginDate, endMonth, endDate;
        cin >> beginMonth >> beginDate >> endMonth >> endDate;
        flowers[i] = fromInts(beginMonth, beginDate, endMonth, endDate);
    }
    sort(flowers, flowers+numFlowers, compareFlowers); //���� �����ϵ�, ���� �ñⰡ �ʰ� (���� �ñⰡ ������ ���) �Ǵ� �ñⰡ ���� ������ �����Ѵ�.
                                                    //Ư�� �ñ⿡ �Ǿ��ִ� ���� ������ �� �ִ��� �ʰ� ���� ���� �����ؾ� ������ ���̴�.

    int numSelectedFlowers = 0; //���õ� ���� ����
    LocalDate now = fromInts(3, 1); //����ϰ� �ִ� "����"
    LocalDate targetDate = fromInts(11, 30); //��ǥ ��¥: �� ������ ���� �Ǿ��־�� �Ѵ�.
    int flowerIndex, recentFlowerIndex = numFlowers; //recentFlowerIndex: �ٷ� ������ ���õ� ���� �ε��� �� (������ ������ ���� �ٷ� ������ ���õ� �ɺ��� ���� ��ġ�� �ְ� �ȴ�.)
    while (compareDates(now, targetDate)<=0) {
        for (flowerIndex=0; flowerIndex<recentFlowerIndex; flowerIndex++) {
            if (compareDates(now, flowers[flowerIndex].beginDate)>=0) { //���� �������� �Ǿ��ִ� �ɸ� �����Ѵ�.
                break;
            }
        }
        if (flowerIndex==recentFlowerIndex) { //���� �������� �Ǿ��ִ� �ɸ� �������� ���� ���, targetDate���� �ּ� �ϳ��� ���� �Ǿ��ְ� ���� �� ���� ���̴�.
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

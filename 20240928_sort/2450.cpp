#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

bool cmp123(int num0, int num1) {
    switch (num0*10+num1) {
        case 12: case 13: case 23: return true;
        default: return false;
    }
}

bool cmp132(int num0, int num1) {
    switch (num0*10+num1) {
        case 13: case 12: case 32: return true;
        default: return false;
    }
}

bool cmp213(int num0, int num1) {
    switch (num0*10+num1) {
        case 21: case 23: case 13: return true;
        default: return false;
    }
}

bool cmp231(int num0, int num1) {
    switch (num0*10+num1) {
        case 23: case 21: case 31: return true;
        default: return false;
    }
}

bool cmp312(int num0, int num1) {
    switch (num0*10+num1) {
        case 31: case 32: case 12: return true;
        default: return false;
    }
}

bool cmp321(int num0, int num1) {
    switch (num0*10+num1) {
        case 32: case 31: case 21: return true;
        default: return false;
    }
}

int numElems;
vector<int> originalArray;

void input() {
    scanf("%d", &numElems);
    for (int i=0; i<numElems; i++) {
        int elem;
        scanf("%d", &elem);
        originalArray.push_back(elem);
    }
}

int sort123() {
    vector<int> sortedArray = originalArray;
    sort(sortedArray.begin(), sortedArray.end(), cmp123);
    //정렬 전과 후를 비교해서 원소 1이 2로 변경이 되면 switched[12] 값을 1 증가...
    int switched[33] = {0};
    for (int i=0; i<numElems; i++) {
        int originalElem = originalArray[i];
        int sortedElem = sortedArray[i];
        if (originalElem!=sortedElem)
            switched[originalElem*10+sortedElem]++;
    }
    int result = 0;
    while (switched[12]>0 && switched[21]>0) {
        result++;
        switched[12]--;
        switched[21]--;
    }
    while (switched[13]>0 && switched[31]>0) {
        result++;
        switched[13]--;
        switched[31]--;
    }
    while (switched[23]>0 && switched[32]>0) {
        result++;
        switched[23]--;
        switched[32]--;
    }
    while (switched[12]>0 && switched[23]>0 && switched[31]>0) {
        result+=2;
        switched[12]--;
        switched[23]--;
        switched[31]--;
    }
    while (switched[13]>0 && switched[32]>0 && switched[21]>0) {
        result+=2;
        switched[13]--;
        switched[32]--;
        switched[21]--;
    }
    return result;
}

int sort132() {
    vector<int> sortedArray = originalArray;
    sort(sortedArray.begin(), sortedArray.end(), cmp132);
    //정렬 전과 후를 비교해서 원소 1이 2로 변경이 되면 switched[12] 값을 1 증가...
    int switched[33] = {0};
    for (int i=0; i<numElems; i++) {
        int originalElem = originalArray[i];
        int sortedElem = sortedArray[i];
        if (originalElem!=sortedElem)
            switched[originalElem*10+sortedElem]++;
    }
    int result = 0;
    while (switched[12]>0 && switched[21]>0) {
        result++;
        switched[12]--;
        switched[21]--;
    }
    while (switched[13]>0 && switched[31]>0) {
        result++;
        switched[13]--;
        switched[31]--;
    }
    while (switched[23]>0 && switched[32]>0) {
        result++;
        switched[23]--;
        switched[32]--;
    }
    while (switched[12]>0 && switched[23]>0 && switched[31]>0) {
        result+=2;
        switched[12]--;
        switched[23]--;
        switched[31]--;
    }
    while (switched[13]>0 && switched[32]>0 && switched[21]>0) {
        result+=2;
        switched[13]--;
        switched[32]--;
        switched[21]--;
    }
    return result;
}

int sort213() {
    vector<int> sortedArray = originalArray;
    sort(sortedArray.begin(), sortedArray.end(), cmp213);
    //정렬 전과 후를 비교해서 원소 1이 2로 변경이 되면 switched[12] 값을 1 증가...
    int switched[33] = {0};
    for (int i=0; i<numElems; i++) {
        int originalElem = originalArray[i];
        int sortedElem = sortedArray[i];
        if (originalElem!=sortedElem)
            switched[originalElem*10+sortedElem]++;
    }
    int result = 0;
    while (switched[12]>0 && switched[21]>0) {
        result++;
        switched[12]--;
        switched[21]--;
    }
    while (switched[13]>0 && switched[31]>0) {
        result++;
        switched[13]--;
        switched[31]--;
    }
    while (switched[23]>0 && switched[32]>0) {
        result++;
        switched[23]--;
        switched[32]--;
    }
    while (switched[12]>0 && switched[23]>0 && switched[31]>0) {
        result+=2;
        switched[12]--;
        switched[23]--;
        switched[31]--;
    }
    while (switched[13]>0 && switched[32]>0 && switched[21]>0) {
        result+=2;
        switched[13]--;
        switched[32]--;
        switched[21]--;
    }
    return result;
}

int sort231() {
    vector<int> sortedArray = originalArray;
    sort(sortedArray.begin(), sortedArray.end(), cmp231);
    //정렬 전과 후를 비교해서 원소 1이 2로 변경이 되면 switched[12] 값을 1 증가...
    int switched[33] = {0};
    for (int i=0; i<numElems; i++) {
        int originalElem = originalArray[i];
        int sortedElem = sortedArray[i];
        if (originalElem!=sortedElem)
            switched[originalElem*10+sortedElem]++;
    }
    int result = 0;
    while (switched[12]>0 && switched[21]>0) {
        result++;
        switched[12]--;
        switched[21]--;
    }
    while (switched[13]>0 && switched[31]>0) {
        result++;
        switched[13]--;
        switched[31]--;
    }
    while (switched[23]>0 && switched[32]>0) {
        result++;
        switched[23]--;
        switched[32]--;
    }
    while (switched[12]>0 && switched[23]>0 && switched[31]>0) {
        result+=2;
        switched[12]--;
        switched[23]--;
        switched[31]--;
    }
    while (switched[13]>0 && switched[32]>0 && switched[21]>0) {
        result+=2;
        switched[13]--;
        switched[32]--;
        switched[21]--;
    }
    return result;
}

int sort312() {
    vector<int> sortedArray = originalArray;
    sort(sortedArray.begin(), sortedArray.end(), cmp312);
    //정렬 전과 후를 비교해서 원소 1이 2로 변경이 되면 switched[12] 값을 1 증가...
    int switched[33] = {0};
    for (int i=0; i<numElems; i++) {
        int originalElem = originalArray[i];
        int sortedElem = sortedArray[i];
        if (originalElem!=sortedElem)
            switched[originalElem*10+sortedElem]++;
    }
    int result = 0;
    while (switched[12]>0 && switched[21]>0) {
        result++;
        switched[12]--;
        switched[21]--;
    }
    while (switched[13]>0 && switched[31]>0) {
        result++;
        switched[13]--;
        switched[31]--;
    }
    while (switched[23]>0 && switched[32]>0) {
        result++;
        switched[23]--;
        switched[32]--;
    }
    while (switched[12]>0 && switched[23]>0 && switched[31]>0) {
        result+=2;
        switched[12]--;
        switched[23]--;
        switched[31]--;
    }
    while (switched[13]>0 && switched[32]>0 && switched[21]>0) {
        result+=2;
        switched[13]--;
        switched[32]--;
        switched[21]--;
    }
    return result;
}

int sort321() {
    vector<int> sortedArray = originalArray;
    sort(sortedArray.begin(), sortedArray.end(), cmp321);
    //정렬 전과 후를 비교해서 원소 1이 2로 변경이 되면 switched[12] 값을 1 증가...
    int switched[33] = {0};
    for (int i=0; i<numElems; i++) {
        int originalElem = originalArray[i];
        int sortedElem = sortedArray[i];
        if (originalElem!=sortedElem)
            switched[originalElem*10+sortedElem]++;
    }
    int result = 0;
    while (switched[12]>0 && switched[21]>0) {
        result++;
        switched[12]--;
        switched[21]--;
    }
    while (switched[13]>0 && switched[31]>0) {
        result++;
        switched[13]--;
        switched[31]--;
    }
    while (switched[23]>0 && switched[32]>0) {
        result++;
        switched[23]--;
        switched[32]--;
    }
    while (switched[12]>0 && switched[23]>0 && switched[31]>0) {
        result+=2;
        switched[12]--;
        switched[23]--;
        switched[31]--;
    }
    while (switched[13]>0 && switched[32]>0 && switched[21]>0) {
        result+=2;
        switched[13]--;
        switched[32]--;
        switched[21]--;
    }
    return result;
}


int main() {
    input();
    int result = sort123();
    //printf("%d\n", result);
    result = min(result, sort132());
    //printf("%d\n", result);
    result = min(result, sort213());
    //printf("%d\n", result);
    result = min(result, sort231());
    //printf("%d\n", result);
    result = min(result, sort312());
    //printf("%d\n", result);
    result = min(result, sort321());
    printf("%d", result);
    return 0;
}

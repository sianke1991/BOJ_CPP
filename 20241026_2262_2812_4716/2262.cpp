#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int abs(int num) {
    return num>=0 ? num : -num;
}

int max(int num0, int num1) {
    return num0 > num1 ? num0 : num1;
}

int main() {
    int numParticipants;
    scanf("%d", &numParticipants);
    vector<int> participants;
    for (int i=0; i<numParticipants; i++) {
        int participant;
        scanf("%d", &participant);
        participants.push_back(participant);
    } //i loop
    long long sumDiffs = 0LL;
    for (int maxElem=numParticipants; maxElem>1; maxElem--) {
        int maxElemIndex = -1;
        for (int i=0; i<participants.size(); i++) {
            if (participants[i]==maxElem) {
                maxElemIndex = i;
                break;
            }
        } //i loop
        //printf("maxElemIndex: %d\n", maxElemIndex);
        if (maxElemIndex==0) {
            sumDiffs += maxElem-participants[1];
        } else if (maxElemIndex==participants.size()-1) {
            sumDiffs += maxElem-participants[participants.size()-2];
        } else {
            sumDiffs += maxElem-max(participants[maxElemIndex-1], participants[maxElemIndex+1]);
        }
        participants.erase(participants.begin()+maxElemIndex);
    } //maxElem loop
    printf("%lld", sumDiffs);
    return 0;
}

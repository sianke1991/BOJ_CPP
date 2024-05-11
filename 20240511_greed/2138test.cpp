#include <bits/stdc++.h>
#include <stdio.h>
#define NUM_SWITCHES 5
#define LENGTH_VISITED 2048

using namespace std;

int originalState;
int targetState;

struct Node {
    int currentState;
    int currentSteps;
    vector<int> currentMoveHistory;
};

bool visited[LENGTH_VISITED];

void printMoveHistory(vector<int> moveHistory) {
    printf("\n{");
    for (int index=0; index<moveHistory.size()-1; index++) {
        printf("%d, ", moveHistory[index]);
    }
    printf("%d}\n", moveHistory[moveHistory.size()-1]);
}

void bfs() {
    for (int i=0; i<LENGTH_VISITED; i++)
        visited[i] = false;

    queue<Node> q;
    visited[originalState] = true;
    q.push({originalState, 0, {}});
    while (!q.empty()) {
        Node currentNode = q.front();
        q.pop();
        int currentState = currentNode.currentState;
        int currentSteps = currentNode.currentSteps;
        vector<int> currentMoveHistory = currentNode.currentMoveHistory;
        for (int i=0; i<NUM_SWITCHES; i++) {
            int nextState = currentState;
            int nextSteps = currentSteps+1;
            vector<int> nextMoveHistory = currentMoveHistory;
            nextMoveHistory.push_back(i);
            switch (i) {
                case 0: {
                    nextState ^= (1<<0);
                    nextState ^= (1<<1);
                    break;
                }

                case NUM_SWITCHES-1: {
                    nextState ^= (1<<(NUM_SWITCHES-1));
                    nextState ^= (1<<(NUM_SWITCHES-2));
                    break;
                }

                default: {
                    nextState ^= (1<<(i-1));
                    nextState ^= (1<<i);
                    nextState ^= (1<<(i+1));
                    break;
                }
            }

            if (nextState==targetState) {
                printf("numSteps: %d", nextSteps);
                printMoveHistory(nextMoveHistory);
                return;
            }
            else if (!visited[nextState]) {
                visited[nextState] = true;
                q.push({nextState, nextSteps, nextMoveHistory});
            }
        } //i: 스위치 번호 loop
    }

    printf("numSteps: -1\n");
}

int main() {
    originalState = 0;
    for (targetState = 0; targetState<(1<<NUM_SWITCHES); targetState++) {
        printf("targetState: %d\n", targetState);
        bfs();
    }
    return 0;

}

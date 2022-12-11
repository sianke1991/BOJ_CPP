#include <iostream>
#include <vector>

using namespace std;

int dCol[] = {0, 1, 0, -1};
int dRow[] = {-1, 0, 1, 0};

//1: up, 2: right, 4: down, 8: left
//각 타입에 해당하는 카메라가 볼 수 있는 방향 //첫 번째 인덱스는 카메라 종류
const int CAMERA_DIRECTIONS[][] = {
    {0, 0, 0, 0},
    {1, 2, 4, 8},
    {5, 10, 0, 0},
    {3, 6, 9, 12},
    {7, 11, 13, 14},
    {15, 0, 0, 0}
};

struct Camera {
    int type;
    int row;
    int col;
    int dirIndx;
};

vector <Camera> cameraList;
int N, M; //N: 행의 개수, M: 열의 개수
int board[9][9];
int boardBackup[9][9];

//boardBackup의 내용으로 board의 내용을 초기화함
void reset() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            board[i][j] = boardBackup[i][j];
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> boardBackup[i][j];
            if (boardBackup[i][j]>0 && boardBackup[i][j]<6) {
                Camera camera = {boardBackup[i][j], i, j, -1};
                cameraList.push_back(camera);
            }
        }
    }
    int numCameras = cameraList.size();
    for (int camerasDirectionIdx=0; camerasDirectionIdx<65536; camerasDirectionIdx++) {
        reset();
        int camera0DirectionIdx = camerasDirectionIdx&3;
        int camera1DirectionIdx = (camerasDirectionIdx&12)>>2;
        int camera2DirectionIdx = (camerasDirectionIdx&48)>>4;
        int camera3DirectionIdx = (camerasDirectionIdx&192)>>6;
        int camera4DirectionIdx = (camerasDirectionIdx&768)>>8;
        int camera5DirectionIdx = (camerasDirectionIdx&3072)>>10;
        int camera6DirectionIdx = (camerasDirectionIdx&12288)>>12;
        int camera7DirectionIdx = (camerasDirectionIdx&49152)>>14;
        int cameraDirectionIdx[] = {camera0DirectionIdx, camera1DirectionIdx, camera2DirectionIdx, camera3DirectionIdx, camera4DirectionIdx, camera5DirectionIdx, camera6DirectionIdx, camera7DirectionIdx};
        /*
        if (numCameras<8 && camera7DirectionIdx) break;
        if (numCameras<7 && camera6DirectionIdx) break;
        if (numCameras<6 && camera5DirectionIdx) break;
        if (numCameras<5 && camera4DirectionIdx) break;
        if (numCameras<4 && camera3DirectionIdx) break;
        if (numCameras<3 && camera2DirectionIdx) break;
        if (numCameras<2 && camera1DirectionIdx) break;
        if (numCameras<1 && camera0DirectionIdx) break;
        */

        for (int cameraIdx=0; cameraIdx<numCameras; cameraIdx++) {
            int direction = cameraDirectionIdx[cameraIdx];
            int startingCol = cameraList[cameraIdx].col;
            int startingRow = cameraList[cameraIdx].row;
            if (direction&1) {
                int currentCol = startingCol;
                int currentRow = startingRow;
                while(1) {
                    currentCol += dCol[0];
                    currentRow += dRow[0];
                    //빠져 나갈 조건
                    if (currentCol<0 || currentCol>=M) break;
                    if (currentRow<0 || currentRow>=N) break;
                    if (board[currentRow][currentCol]==6) break;
                    board[currentRow][currentCol] = -1;
                } //while loop
            }
        }


    } //8개의 카메라 방향 루프



}


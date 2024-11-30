#include <iostream>

using namespace std;

//시간표: 해당 시각에 할 일이 정해졌는지 여부
bool timeTable[1000010] = {};
int main()
{
    int numCusts, wetDuration;
    cin >> numCusts >> wetDuration;

    int custTime;
    int last = 0, dl = 0; //last: 마지막으로 토기 만든 시각, dl: 마지막으로 커피 담은 시각
    for (int i=0; i<numCusts; i++)
    {
        cin >> custTime;
        timeTable[custTime] = true; // 이시간에는 일단 서빙
        int ck = 1;        // 커피 담는 시각 및 토기 만든 시각을 찾으면 0으로 돌려놓는다.
        /*
            커피 담을 시각을 찾는 loop
        */
        for (int j=max(dl, custTime-wetDuration); j<custTime; j++)
        {
            if (!timeTable[j])
            {
                timeTable[j] = true;
                dl = j; //마지막으로 커피 담은 시각 갱신 => 커피 담는 시각을 찾는 loop 범위를 점차적으로 줄인다.
                ck = 0;
                break;
            }
        } //j loop (커피 담을 시각을 찾는 loop), 손님이 온 시각으로 부터 최대한 먼 시각을 찾는다.

        if (ck) // 커피 담을 시각을 확보하지 못하면-
        {
            cout<<"fail";
            return 0;
        }

        ck = 1; // 토기 만들 시각을 찾으면 0으로 돌려놓는다.
        /*
            토기 만들 시각을 찾는 loop
        */
        for (int j=last; j<custTime; j++)
        {
            if (!timeTable[j])
            {
                timeTable[j] = true;
                last = j; //마지막으로 토기 만든 시각 갱신 => 토기 제작 시각을 찾는 loop 범위를 점차적으로 줄인다.
                ck = 0;
                break;
            }
        } //j loop (토기 제작 시각을 찾는 loop)

         if (ck) // 토기 제작 시각을 확보하지 못하면-
        {
            cout<<"fail";
            return 0;
        }

    } //i loop: 각 손님에 대한 루프
    cout << "success";
    return 0;
}

#include <iostream>

using namespace std;

//�ð�ǥ: �ش� �ð��� �� ���� ���������� ����
bool timeTable[1000010] = {};
int main()
{
    int numCusts, wetDuration;
    cin >> numCusts >> wetDuration;

    int custTime;
    int last = 0, dl = 0; //last: ���������� ��� ���� �ð�, dl: ���������� Ŀ�� ���� �ð�
    for (int i=0; i<numCusts; i++)
    {
        cin >> custTime;
        timeTable[custTime] = true; // �̽ð����� �ϴ� ����
        int ck = 1;        // Ŀ�� ��� �ð� �� ��� ���� �ð��� ã���� 0���� �������´�.
        /*
            Ŀ�� ���� �ð��� ã�� loop
        */
        for (int j=max(dl, custTime-wetDuration); j<custTime; j++)
        {
            if (!timeTable[j])
            {
                timeTable[j] = true;
                dl = j; //���������� Ŀ�� ���� �ð� ���� => Ŀ�� ��� �ð��� ã�� loop ������ ���������� ���δ�.
                ck = 0;
                break;
            }
        } //j loop (Ŀ�� ���� �ð��� ã�� loop), �մ��� �� �ð����� ���� �ִ��� �� �ð��� ã�´�.

        if (ck) // Ŀ�� ���� �ð��� Ȯ������ ���ϸ�-
        {
            cout<<"fail";
            return 0;
        }

        ck = 1; // ��� ���� �ð��� ã���� 0���� �������´�.
        /*
            ��� ���� �ð��� ã�� loop
        */
        for (int j=last; j<custTime; j++)
        {
            if (!timeTable[j])
            {
                timeTable[j] = true;
                last = j; //���������� ��� ���� �ð� ���� => ��� ���� �ð��� ã�� loop ������ ���������� ���δ�.
                ck = 0;
                break;
            }
        } //j loop (��� ���� �ð��� ã�� loop)

         if (ck) // ��� ���� �ð��� Ȯ������ ���ϸ�-
        {
            cout<<"fail";
            return 0;
        }

    } //i loop: �� �մԿ� ���� ����
    cout << "success";
    return 0;
}

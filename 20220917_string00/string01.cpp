#include <string>
#include <iostream>

using namespace std;

int main() {
    /*
        number <--> string conversion
        1. number to string by using std::to_string function
        string to_string(number)

        2. string to number by using std::stoi or std::stof function
        int stoi(string)
        float stof(string)
    */

    int liNum = 25;
    string lsNum = to_string(liNum);
    cout << lsNum << '\n';

    lsNum = "30";
    liNum = stoi(lsNum);
    cout << liNum << '\n';

    float lfNum = 3.14159;
    lsNum = to_string(lfNum);
    cout << lsNum << '\n';

    lsNum = "2.71828";
    lfNum = stof(lsNum);
    cout << lfNum << '\n';

    return 0;
}

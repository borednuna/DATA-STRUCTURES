#include <iostream>
#include <array>

using namespace std;

array<unsigned long long int, 36> resultContainer;

unsigned long long int result(int);

int main() {
    int testCases;

    cin >> testCases;
    resultContainer.fill(0);

    for (int i=0; i < testCases; i++) {
        int buff;
        cin >> buff;
        
        unsigned long long int tempResult = result(buff);
        if (buff == 0) {
            tempResult = 0;
        }

        cout << tempResult << endl;
    }
}

unsigned long long int result(int buff) {
    if (buff <= 1) {
        return 1;
    }

    if (resultContainer[buff] != 0) {
        return resultContainer[buff];
    }

    unsigned long long int tempRes = 0;
    for (int i = 0; i < buff; i++) {
        tempRes += result(i) * result(buff - i - 1);
    }

    resultContainer[buff] = tempRes;
    return tempRes;
}

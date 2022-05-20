#include <iostream>
#include <vector>
using namespace std;


int main() {
    while (!EOF) {
        vector<int, int> field;
        int buff;
        for (int i=0; i < 3; i++) {
            for (int j=0; j < 3; j++) {
                cin >> buff;
                field[i][j] = buff;
            }
        }
    }
}
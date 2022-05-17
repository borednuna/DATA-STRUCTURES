#include <iostream>
using namespace std;

char field [30][30];
int row, coloumn;

void fallenDown(int, int);

int main() {
    int testCase;

    cin >> testCase;

    for (int k=0; k < testCase; k++) {
        cin >> row;
        cin >> coloumn;

        for (int i=0; i <= row; i++) {
            for (int j=0; j <= coloumn; j++) {
                field[i][j] = 'x';
            }
        }

        for (int i=0; i < row; i++) {
            for (int j=0; j < coloumn; j++) {
                cin >> field[i][j];
            }
        }

        for (int i = row-1; i >= 0; i--) {
            for (int j = coloumn-1; j >= 0; j--) {
                if (field[i][j] == '*') {
                    fallenDown(i, j);
                }
            }
        }

        for (int i=0; i < row; i++) {
            for (int j=0; j < coloumn; j++) {
                cout << field[i][j];
            }
            cout << endl;
        }
    }
}

void fallenDown(int x, int y) {
    if (x + 1 == row) {
        return;
    }

    if ((field[x+1][y] == 'o') || (field[x+1][y] == '*')) {
        return;
    }

    field[x][y] = '.';
    field[x+1][y] = '*';
    fallenDown(x+1, y);
}
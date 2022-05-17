#include <iostream>
#include <list>
#include <array>
#include <queue>
using namespace std;

int size, isFound = 0;
array<array<int, 41>, 41> field;
array<array<int, 41>, 41> isVisited;
queue<int> waitList;
int startX, startY;

void traverse(int, int);
void findStart();

int main() {
    cin >> size;
    for (int i=0; i <= size; i++) {
        field[i].fill(-1);
        isVisited[i].fill(0);
    }

    for (int i=0; i < size; i++) {
        for (int j=0; j < size; j++) {
            cin >> field[i][j];
        }
    }

    findStart();
    traverse(startX, startY);

    if (isFound) {
        cout << "yey" << endl;
    } else {
        cout << "yah" << endl;
    }
}

void findStart() {
    for (int i=0; i < size; i++) {
        for (int j=0; j < size; j++) {
            if (field[i][j] == 2) {
                startX = i;
                startY = j;
                return;
            }
        }
    }
    return;
}

void traverse(int x, int y) {
    if ((x < 0) || (y < 0)) {
        return;
    }

    if (isVisited[x][y]) {
        return;
    }

    if (field[x][y] == -1) {
        return;
    }

    if (field[x][y] == 1) {
        return;
    }

    if (field[x][y] == 3) {
        isFound = 1;
        return;
    }

    isVisited[x][y] = 1;
    traverse(x - 1, y);
    traverse(x, y - 1);
    traverse(x + 1, y);
    traverse(x, y+1);
}
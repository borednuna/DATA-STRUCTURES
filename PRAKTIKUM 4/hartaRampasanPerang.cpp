#include <iostream>
#include <list>
#include <array>
#include <queue>
using namespace std;

int size, isFound = 0;
array<array<int, 41>, 41> field;        // 2-dimensional array to store field
array<array<int, 41>, 41> isVisited;    // 2-dimensional array to mark each vertex visited or not visited
int startX, startY;                     // X and Y starting position

void traverse(int, int);                // traverse graph to find treasure
void findStart();                       // determine where is startX and startY

int main() {
    cin >> size;
    for (int i=0; i <= size; i++) {
        field[i].fill(-1);              // fill field with -1, notice it fills until size
                                        // so there will be margin of -1
        isVisited[i].fill(0);           // fill isVisited as 0 or false
    }

    for (int i=0; i < size; i++) {
        for (int j=0; j < size; j++) {
            cin >> field[i][j];         // input field
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
    // loop through all vertex and set vertex filled with 2 as starting point
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
    // traverse through graph from starting point recursively
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
    traverse(x - 1, y);     // traverse up
    traverse(x, y - 1);     // traverse left
    traverse(x + 1, y);     // traverse down
    traverse(x, y+1);       // traverse right
}
/* 
Unweighted graph using array of lists

Constraints :
- Vertex are in order and no skipped vertex integer
- array elements <= 100

Test Case :
6
1 2
1 3
1 6
2 5
4 6
1 5
*/

#include <iostream>
#include <list>
#include <array>
using namespace std;

array<int, 100> isVisited;
list<int> graph[100];
void displayGraph();
void doDFS(int);

int main() {
    isVisited.fill(0);
    int pairs, buffA, buffB;
    cin >> pairs;

    for (int i = 0; i < pairs; i++) {
        cin >> buffA >> buffB;
        graph[buffA].push_back(buffB);
        graph[buffB].push_back(buffA);
    }

    displayGraph();
    doDFS(1);
}

void displayGraph() {
    int i = 1;
    while (!graph[i].empty()) {
        printf("Vertex %d :\n", i);
        for (auto j = graph[i].begin(); j != graph[i].end(); ++j) {
            cout << "\t---->> " << *j;
            cout << endl;
        }
        i++;
    }
    cout << endl;
}

void doDFS(int startingVertex) {
    isVisited[startingVertex] = 1;
    cout << startingVertex << " ";
    for (auto i = graph[startingVertex].begin(); i != graph[startingVertex].end(); ++i) {
        int currentVertex = *i;
        cout << *i << " ";
        if (!isVisited[currentVertex]) {
            doDFS(currentVertex);
        }
    }
}

/* 
Unweighted graph using array of lists with skipped vertex

Constraints :
- array elements <= 100

Test Case :
6
1 2
1 3
1 6
2 9
4 6
1 5
*/

#include <iostream>
#include <list>
#include <array>
using namespace std;

array<int, 100> isVisited;
list<int> graph[100];
int biggest;
void displayGraph();
void doDFS(int);

int main() {
    int pairs, buffA, buffB;
    biggest = 0;
    cin >> pairs;
    for (int i = 0; i < pairs; i++) {
        cin >> buffA >> buffB;
        graph[buffA].push_back(buffB);
        graph[buffB].push_back(buffA);

        if (buffA > biggest) biggest = buffA;
        
        if (buffB > biggest) biggest = buffB;
    }

    displayGraph();
    doDFS(1);
}

void displayGraph() {
    int i = 1;
    while (i <= biggest) {
        if (!graph[i].empty()) printf("Vertex %d :\n", i);
        for (auto j = graph[i].begin(); j != graph[i].end(); ++j) {
            printf("\t---->> %d\n", *j);
        }
        i++;
    }
}

void doDFS(int startingVertex) {
    isVisited[startingVertex] = 1;
    cout << startingVertex << " ";
    int i = 0;
    for (auto i = graph[startingVertex].begin(); i != graph[startingVertex].end(); ++i) {
        int currentVertex = *i;
        cout << *i << " ";
        if (!isVisited[currentVertex]) {
            doDFS(currentVertex);
        }
    }
}

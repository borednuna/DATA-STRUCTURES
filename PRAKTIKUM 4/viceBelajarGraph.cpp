#include <iostream>
#include <array>
#include <list>

using namespace std;

array<int, 1000> isVisited;
list<int> adjList[1000];

void doDFS(int);

int main() {
    int vertex, pairs, totalGraphs = 0;
    isVisited.fill(0);

    cin >> vertex;
    cin >> pairs;

    for (int i=0; i < pairs; i++) {
        int buffA, buffB;
        cin >> buffA;
        cin >> buffB;

        adjList[buffA].push_back(buffB);
        adjList[buffB].push_back(buffA);
    }

    for (int i = 1; i <= vertex; i++) {
        if (!isVisited[i] ) {
            doDFS(i);
            totalGraphs++;
        }
    }
    cout << --totalGraphs << endl;
}

void doDFS(int startVertex) {
    isVisited[startVertex] = 1;
    for (auto i = adjList[startVertex].begin(); i != adjList[startVertex].end(); ++i) {
        int currentVertex = *i;
        if (!isVisited[currentVertex]) {
            doDFS(currentVertex);
        }
    }
}

/* 
Weighted graph using vector of lists

Constraints :
- Vertex are in order and no skipped vertex integer
- vector elements <= 100

Test Case :
6
1 2 5
1 3 3
1 6 1
2 5 1
4 6 7
1 5 12
*/

#include <iostream>
#include <array>
#include <vector>
using namespace std;

vector<pair<int, int>> graph[100];
array<int, 100> isVisited;
void displayGraph();
void doDFS(int);

int main() {
    int pairs, buffA, buffB, weight;
    cin >> pairs;

    for (int i = 0; i < pairs; i++) {
        cin >> buffA >> buffB >> weight;
        graph[buffA].push_back(make_pair(buffB, weight));
        graph[buffB].push_back(make_pair(buffA, weight));
    }

    displayGraph();
    doDFS(1);
}

void displayGraph() {
    int i = 1;
    while(!graph[i].empty()) {
        cout << "Vertex " << i;
        cout << endl;
        for (auto j = graph[i].begin(); j != graph[i].end(); j++) {
            cout << "\t---> " << j->first << ", weight = " << j->second;
            cout << endl;
        }
        i++;
    }
}

void doDFS(int startingVertex) {
    isVisited[startingVertex] = 1;
    cout << startingVertex << " ";
    for (auto i = graph[startingVertex].begin(); i != graph[startingVertex].end(); ++i) {
        int currentVertex = i->first;
        cout << i->first << " ";
        if (!isVisited[currentVertex]) {
            doDFS(currentVertex);
        }
    }
}

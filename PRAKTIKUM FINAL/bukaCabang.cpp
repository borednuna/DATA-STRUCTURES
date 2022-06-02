#include <stdio.h>
#include <array>
#include <vector>

using namespace std;

vector<pair<int, int>> graph[100];
array<int, 1000001> isVisited;
array<int, 1000001> vertexDistance;
int tempDist, vertexes, edges;
void getDistance(int, int, int);
void displayDistance();
void displayGraph();

int main() {
    int buffA, buffB, wght;
    vertexDistance.fill(0);

    scanf("%d %d", &vertexes, &edges);

    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &buffA, &buffB, &wght);
        graph[buffA].push_back(make_pair(buffB, wght));
    }

    if (graph[0].empty())
        return 0;

    for (auto i = graph[0].begin(); i != graph[0].end(); ++i) {
        tempDist = 0;
        getDistance(i->first, tempDist, i->second);
    }

    displayDistance();
}

void displayGraph() {
    int i = 1;
    while(!graph[i].empty()) {
        printf("Vertex %d\n", i);
        for (auto j = graph[i].begin(); j != graph[i].end(); j++) {
            printf("\t--> %d weight = %d\n", j->first, j->second);
        }
        i++;
    }
}

void getDistance(int destination, int tempDist, int weight) {
    tempDist += weight;
    vertexDistance[destination] = tempDist;
    if (graph[destination].empty()) {
        return;
    }

    for (auto i = graph[destination].begin(); i != graph[destination].end(); ++i) {
        getDistance(i->first, tempDist, i->second);
    }
    return;
}

void displayDistance() {
    for (int i = 1; i < vertexes; i++) {
        printf("%d %d\n", i, vertexDistance[i]);
    }
}

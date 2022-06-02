#include <stdio.h>

int vertexes[100][100];
int nodes, edges;
void displayGraph();

int main() {
    int buffA, buffB, buffC;
    scanf("%d %d", &nodes, &edges);
    printf("%d %d\n", nodes, vertexes);
    
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &buffA, &buffB, &buffC);
        vertexes[buffA][buffB] = buffC;
    }

    displayGraph();
}

void displayGraph() {
    for (int i = 0; i < nodes; i++) {
        printf("Vertex %d\n", i);
        for (int j = 0; j < nodes; j++) {
            if (vertexes[i][j] != 0)
                printf("\t---> %d\n", vertexes[i][j]);
        }
    }
}
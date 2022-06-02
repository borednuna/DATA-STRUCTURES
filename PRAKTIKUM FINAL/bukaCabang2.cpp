#include <stdio.h>
#include <array>

using namespace std;

int nodes, edges;
array<int, 1000000> sequence;

int main() {
    sequence.fill(0);
    int buffA, buffB, weight;

    scanf("%d %d", &nodes, &edges);

    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &buffA, &buffB, &weight);
        if (buffA == 0) {
            sequence[buffB] = weight;
        } else {
            sequence[buffB] = sequence[buffA] + weight;
        }
    }

    for (int i = 1; i < nodes; i++) {
        printf("%d %d\n", i, sequence[i]);
    }
}

#include <iostream>
#include <list>
#include <array>

using namespace std;

list<pair<int, int>> adjList[100000];

int main() {
    int buildings, vertex, A, B;

    cin >> buildings >> vertex >> A >> B;

    for (int i=0; i < vertex; i++) {
        int buff, buff1, buff2;
        cin >> buff >> buff1 >> buff2;
        adjList[i].push_back(buff);
    }
}
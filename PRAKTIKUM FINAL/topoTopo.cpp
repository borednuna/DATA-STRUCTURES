#include <iostream>
#include <stack>
#include <list>
#include <array>

using namespace std;

array<int, 500000> isVisited;
list<int> graph[500000];
int vertexes, edges;
void displayGraph();
void topologicalSortUtil(int, stack<int>& Stack);
void topologicalSort();
bool isCyclicUtil(int , bool, bool);
bool isCyclic();

int main() {
    isVisited.fill(0);

    cin >> vertexes >> edges;

    for (int i = 0; i < edges; i++) {
        int buffA, buffB;
        cin >> buffA >> buffB;
        graph[buffA].push_back(buffB);
    }

    if (isCyclic()) {
        cout << "-1" << endl;
        return 0;
    } else {
        topologicalSort();
    }
}

void topologicalSortUtil(int v, stack<int>& Stack) {
    isVisited[v] = 1;
 
    for (auto i = graph[v].begin(); i != graph[v].end(); i++)
        if (!isVisited[*i])
            topologicalSortUtil(*i, Stack);
 
    Stack.push(v);
}

void topologicalSort() {
    stack<int> Stack;
 
    for (int i = 0; i <= vertexes; i++)
        if (!isVisited[i])
            topologicalSortUtil(i, Stack);

    for (int i = 0; i < vertexes; i++) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

bool isCyclicUtil(int v, bool visited[], bool *recStack) {
    if(visited[v] == false)
    {
        visited[v] = true;
        recStack[v] = true;
 
        list<int>::iterator i;
        for(i = graph[v].begin(); i != graph[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }
 
    }
    recStack[v] = false;
    return false;
}
 
bool isCyclic() {
    bool *visited = new bool[vertexes];
    bool *recStack = new bool[vertexes];
    for(int i = 1; i <= vertexes; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
 
    for(int i = 1; i <= vertexes; i++)
        if ( !visited[i] && isCyclicUtil(i, visited, recStack))
            return true;
 
    return false;
}

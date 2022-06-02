#include <iostream>
#include <stack>

using namespace std;

int main() {
    int m, n, buffA = 0, buffB = 0, carry = 0, temp;
    stack<int> tempA;
    stack<int> tempB;

    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        cin >> temp;
        tempA.push(temp);
    }

    for (int i = 0; i < n; i++) {
        cin >> temp;
        tempB.push(temp);
    }

    int i = 1;
    while(!tempA.empty()) {
        buffA += tempA.top() * i;
        tempA.pop();
        i *= 10;
    }

    i = 1;
    while(!tempB.empty()) {
        buffB += tempB.top() * i;
        tempB.pop();
        i *= 10;
    }

    cout << "[" << buffA + buffB << "]" << endl;
}

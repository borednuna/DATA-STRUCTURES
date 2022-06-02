#include <iostream>
#include <deque>

using namespace std;

deque<int> hole;
void lostBall();

int main() {
    int order, buff;

    cin >> order;

    for (int i = 0; i < order; i++) {
        cin >> buff;
        hole.push_front(buff);
        lostBall();
        cout << hole.size() << endl;
    }
}

void lostBall() {
    int iterate = hole.front();

    for (int i = 0; i < iterate; i++) {
        if (i > hole.size()) {
            return;
        }

        if (hole[i] != iterate)
            return;
    }

    for (int i = 0; i < iterate; i++) {
        hole.pop_front();
    }
    return;
}

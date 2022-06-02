#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<string> directory;

int main() {
    string currentDir = "home/anton";
    string buffDir = "";
    string buffOrder = "";
    int lost = 0;
    int orders;

    directory.push("i am nowhere");
    directory.push("home");
    directory.push(currentDir);

    cin >> orders;

    for (int i=0; i < orders; i++) {
        cin >> buffOrder;
        if (buffOrder == "goto") {
            if (lost) {
                cin >> currentDir;
                directory.push(currentDir);
                lost = !lost;
                continue;
            }

            cin >> buffDir;
            currentDir += "/";
            currentDir += buffDir;
            directory.push(currentDir);
        } else if (buffOrder == "goback") {
            if (directory.size() == 1) {
                cout << "cannot go back" << endl;
                lost = 1;
                continue;
            }

            directory.pop();
            currentDir = directory.top();
        } else if (buffOrder == "whereami") {
            cout << currentDir << endl;
        } else {
            cout << "Query not found" << endl;
        }
    }
}

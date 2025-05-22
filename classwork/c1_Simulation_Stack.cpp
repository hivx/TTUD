/*
Description
Perform a sequence of operations over a stack, each element is an integer:
PUSH v: push a value v into the stack
POP: remove an element out of the stack and print this element to stdout (print NULL if the stack is empty)
Input
Each line contains a command (operration) of type 
PUSH  v
POP
Output
Write the results of POP operations (each result is written in a line)
Example
Input
PUSH 1
PUSH 2
PUSH 3
POP
POP
PUSH 4
PUSH 5
POP
#
Output
3
2
5
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<int> S;
    string command;
    
    while (cin >> command) {
        if (command == "PUSH") {
            int v;
            cin >> v;
            S.push(v);
        }
        else if (command == "POP") {
            if (S.empty()) {
                cout << "NULL\n";
            } else {
                cout << S.top() << '\n';
                S.pop();
            }
        }
    }

    return 0;
}

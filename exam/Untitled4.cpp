#include <iostream>

using namespace std;

int d, count;

void find_solutions(int a, int b) {
    int c = d - a - b;
    if (c > 0) {
        count++;
        find_solutions(a, b + 1);
        find_solutions(a + 1, b);
    }
}

int main() {
    cin >> d;
    find_solutions(0, 0);
    cout << count << endl;
    return 0;
}


#include <iostream>
#include <string>
#include <vector>
#include <queue>
const N=100000;
using namespace std;

int main() {
    int n;
    int a[N];
    cin >> n;
    priority_queue<int> heap;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        heap.push(x);
    }

    string s;
    while (cin >> s && s != "*") {
        if (s == "insert") {
            int x;
            cin >> x;
            heap.push(x);
        } else if (s == "delete-max") {
        	
            cout << heap.top() << endl;
            heap.pop();
        }
    }
	
    return 0;
}


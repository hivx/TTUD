#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main() {
int n;
cin >> n;
priority_queue<int> heap;
for (int i = 0; i < n; i++) {
int x;
cin >> x;
heap.push(x);
}
vector<int> output;
string s;
while (cin >> s && s != "*") {
    if (s == "insert") {
        int x;
        cin >> x;
        heap.push(x);
    } else if (s == "delete-max") {
        output.push_back(heap.top());
        heap.pop();
    }
}

for (int i = 0; i < output.size(); i++) {
    cout << output[i] << endl;
}

return 0;
}






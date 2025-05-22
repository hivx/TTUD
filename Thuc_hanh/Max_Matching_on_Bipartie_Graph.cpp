#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 10005;

int n, m; // n tasks, m staffs
vector<int> graph[MAXN]; // graph[i]: list of staffs that can do task i
int match[MAXN];         // match[staff] = task
bool used[MAXN];         // used[staff] in current DFS

bool bpm(int task) {
    for (int staff : graph[task]) {
        if (!used[staff]) {
            used[staff] = true;
            if (match[staff] == -1 || bpm(match[staff])) {
                match[staff] = task;
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        int k, staff;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            cin >> staff;
            graph[i].push_back(staff);
        }
    }

    memset(match, -1, sizeof(match));
    int result = 0;

    for (int task = 0; task < n; ++task) {
        memset(used, false, sizeof(used));
        if (bpm(task))
            ++result;
    }

    cout << result << "\n";
    return 0;
}
// Description
// There are  n tasks 1,. . .,n and m staffs 1, . . , m. T(i) is the set of staffs that can perform the task i (i=1, . . ., n). Compute an assignment of staffs to tasks such that each task is assigned to at most one staff and each staff cannot be assigned to more than one task and the number of tasks assigned is maximal.
// Input
// Line 1: contains 2 positive integer n và m (1 <=  n,m <= 10000)
// Line i+1 (i=1, . . .,n) contains a positive integer k and k integer of T(i)
// Output
// Write the maximum number of tasks that are assigned to staffs.
// Example
// Input
// 3 4
// 2 1 4
// 2 1 3
// 1 2

// Output
// 3
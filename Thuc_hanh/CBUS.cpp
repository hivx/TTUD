#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int m, n;
vector<int> teach[11];
bool conflict[31][31];
int load[11];
int assignment[31];
int result = 1e9;

bool canAssign(int course, int teacher) {
    for (int i = 1; i <= n; i++) {
        if (assignment[i] == teacher && conflict[course][i]) {
            return false;
        }
    }
    return true;
}

void backtrack(int course) {
    if (course > n) {
        int maxLoad = *max_element(load + 1, load + m + 1);
        result = min(result, maxLoad);
        return;
    }

    for (int i = 1; i <= m; i++) {
        if (find(teach[i].begin(), teach[i].end(), course) != teach[i].end() && canAssign(course, i)) {
            assignment[course] = i;
            load[i]++;
            if (*max_element(load + 1, load + m + 1) < result) {
                backtrack(course + 1);
            }
            load[i]--;
            assignment[course] = 0;
        }
    }
}

int main() {
    cin >> m >> n;

    for (int i = 1; i <= m; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int course;
            cin >> course;
            teach[i].push_back(course);
        }
    }

    int k;
    cin >> k;
    memset(conflict, 0, sizeof(conflict));

    for (int i = 0; i < k; i++) {
        int c1, c2;
        cin >> c1 >> c2;
        conflict[c1][c2] = conflict[c2][c1] = true;
    }

    memset(load, 0, sizeof(load));
    memset(assignment, 0, sizeof(assignment));

    backtrack(1);

    if (result == 1e9) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}

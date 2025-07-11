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

// Description
// At the beginning of the semester, the head of a computer science department D have to assign courses to teachers in a balanced way. The department D has m teachers T={1,2,...,m} and n courses C={1,2,...,n}. Each teacher t∈T has a preference list which is a list of courses he/she can teach depending on his/her specialization. We known a list of pairs of conflicting two courses that cannot be assigned to the same teacher as these courses have been already scheduled in the same slot of the timetable. The load of a teacher is the number of courses assigned to her/him. How to assign nn courses to mm teacher such that each course assigned to a teacher is in his/her preference list, no two conflicting courses are assigned to the same teacher, and the maximal load is minimal.
// Input
// The input consists of following lines
// Line 1: contains two integer m and n (1≤m≤10, 1≤n≤30)
// Line i+1: contains an positive integer k and k positive integers indicating the courses that teacher i can teach (∀i=1,…,m)
// Line m+2: contains an integer k
// Line i+m+2: contains two integer i and j indicating two conflicting courses (∀i=1,…,k)
// Output
// The output contains a unique number which is the maximal load of the teachers in the solution found and the value -1 if not solution found.
// Example
// Input
// 4 12
// 5 1 3 5 10 12
// 5 9 3 4 8 12
// 6 1 2 3 4 9 7
// 7 1 2 3 5 6 10 11
// 25
// 1 2
// 1 3
// 1 5
// 2 4
// 2 5
// 2 6
// 3 5
// 3 7
// 3 10
// 4 6
// 4 9
// 5 6
// 5 7
// 5 8
// 6 8
// 6 9
// 7 8
// 7 10
// 7 11
// 8 9
// 8 11
// 8 12
// 9 12
// 10 11
// 11 12

// Output
// 3
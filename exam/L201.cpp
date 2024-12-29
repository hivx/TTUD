#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30;
const int MAXM = 10;

int m, n;  
vector<int> preferences[MAXM];  
bool conflict[MAXN][MAXN];  
int load[MAXM];  
int teacher[MAXN];  
int bestMaxLoad;  

bool canAssign(int course, int t) {

    if (find(preferences[t].begin(), preferences[t].end(), course) == preferences[t].end())
        return false;
    

    for (int i = 0; i < n; i++) {
        if (teacher[i] == t && conflict[course][i])
            return false;
    }

    return true;
}


void backtrack(int course) {

    if (course == n) {

        int maxLoad = *max_element(load, load + m);
        bestMaxLoad = min(bestMaxLoad, maxLoad);
        return;
    }


    for (int t = 0; t < m; t++) {
        if (canAssign(course, t)) {

            teacher[course] = t;
            load[t]++;


            if (*max_element(load, load + m) < bestMaxLoad)  
                backtrack(course + 1);


            load[t]--;
            teacher[course] = -1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        preferences[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> preferences[i][j];
            preferences[i][j]--;  
        }
    }


    memset(conflict, 0, sizeof(conflict));


    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int c1, c2;
        cin >> c1 >> c2;
        c1--; c2--;  
        conflict[c1][c2] = conflict[c2][c1] = true;
    }


    memset(load, 0, sizeof(load));
    memset(teacher, -1, sizeof(teacher));
    bestMaxLoad = INT_MAX;


    backtrack(0);


    if (bestMaxLoad == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << bestMaxLoad << endl;
    }

    return 0;
}


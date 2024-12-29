#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
int n, K, Q;
vector<int> d; 
vector<vector<int>> c; 
int best_cost = INF;


int calc_route_cost(const vector<int>& route) {
    int cost = 0;
    int prev = 0; 
    for (int client : route) {
        cost += c[prev][client];
        prev = client;
    }
    cost += c[prev][0]; 
    return cost;
}


void solve(int idx, vector<vector<int>>& routes, vector<int>& current_load) {
    if (idx == n + 1) { 
        int total_cost = 0;
        for (const auto& route : routes) {
            if (!route.empty()) {
                total_cost += calc_route_cost(route);
            }
        }
        best_cost = min(best_cost, total_cost);
        return;
    }

  
    for (int i = 0; i < K; ++i) {

        if (current_load[i] + d[idx] <= Q) {
            current_load[i] += d[idx];
            routes[i].push_back(idx);
            solve(idx + 1, routes, current_load);
            routes[i].pop_back();
            current_load[i] -= d[idx];
        }
    }
}

int main() {

    cin >> n >> K >> Q;
    d.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }


    c.resize(n + 1, vector<int>(n + 1));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> c[i][j];
        }
    }


    vector<vector<int>> routes(K);  
    vector<int> current_load(K, 0);


    solve(1, routes, current_load);


    cout << best_cost << endl;

    return 0;
}


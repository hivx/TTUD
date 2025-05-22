#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> graph[MAXN], rev_graph[MAXN];
vector<bool> visited(MAXN);
stack<int> order;
int N, M;

void dfs1(int u) {
    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v]) dfs1(v);
    }
    order.push(u);
}

void dfs2(int u) {
    visited[u] = true;
    for (int v : rev_graph[u]) {
        if (!visited[v]) dfs2(v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        rev_graph[v].push_back(u); // Reverse graph
    }

    // 1st pass: Order by finishing time
    fill(visited.begin(), visited.begin() + N + 1, false);
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) dfs1(i);
    }

    // 2nd pass: DFS on reversed graph
    fill(visited.begin(), visited.begin() + N + 1, false);
    int scc_count = 0;
    while (!order.empty()) {
        int u = order.top(); order.pop();
        if (!visited[u]) {
            dfs2(u);
            ++scc_count;
        }
    }

    cout << scc_count << "\n";
    return 0;
}

/*
Description
Given a tree T=(V,E) in which V={1,. . ., n} is the set of nodes. Each edge (u,v) of T has length w(u,v). Denote f(v) the sum of length of paths from all other nodes to v. Write a program to compute max{f(1), .  . ., f(n)}.

Input
Line 1 contains a positive integer n (2 <= n <= 10^5)
Line i+1 (i=1, . . ., n): contains u, v and w in which w is the weight of the edge (u,v)
Output
Write the value max{f(1), . . , f(n}.

Example
Input
4
1 2 1
1 3 3
3 4 2
Output
13
*/
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100005;
typedef long long ll;

int n;
vector<pair<int, int>> adj[MAXN];
ll sz[MAXN];     // size of subtree
ll dp[MAXN];     // sum of distances in subtree
ll f[MAXN];      // total distance from all other nodes to node
ll result = 0;

// First DFS: compute sz[v] and dp[v]
void dfs1(int u, int parent) {
    sz[u] = 1;
    dp[u] = 0;
    for (auto& [v, w] : adj[u]) {
        if (v == parent) continue;
        dfs1(v, u);
        sz[u] += sz[v];
        dp[u] += dp[v] + sz[v] * w;
    }
}

// Second DFS: reroot and compute f[v]
void dfs2(int u, int parent) {
    result = max(result, f[u]);
    for (auto& [v, w] : adj[u]) {
        if (v == parent) continue;
        f[v] = f[u] - sz[v] * w + (n - sz[v]) * w;
        dfs2(v, u);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    dfs1(1, -1);         // compute dp and sz
    f[1] = dp[1];        // total distance from all other nodes to node 1
    dfs2(1, -1);         // reroot and compute f[v] for all nodes

    cout << result << endl;
    return 0;
}

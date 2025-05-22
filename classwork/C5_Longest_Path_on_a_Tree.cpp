/*
Description
Given a undirected tree $G = (V, E)$ in which $V = \{1,…,N\}$ is the set of nodes. Each edge $(u,v) \in E$ has weight $w(u,v)$. The length of a path is defined to be the sum of weights of edges of this path. Find the longest elementary path on $G$.
Input
Line 1: positive integer $N$ ($1 \leq N \leq 10^5$)
Line $i + 1$ ($i = 1,…,N-1$): positive integers $u, v, w$ in which $w$ is the weight of edge $(u,v)$ (1 ≤ w ≤ 100)
Output
The weight of the longest path on the given tree
Example
Input
6 
1 3 3
 1 6 2 
2 6 5 
4 5 2
 4 6 1
Output
10
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100005;

vector<pair<int, int>> adj[MAXN]; // adjacency list: (neighbor, weight)
int max_dist = 0;
int farthest_node = 0;

void dfs(int node, int parent, int dist) {
    if (dist > max_dist) {
        max_dist = dist;
        farthest_node = node;
    }

    for (auto& edge : adj[node]) {
        int neighbor = edge.first;
        int weight = edge.second;
        if (neighbor != parent) {
            dfs(neighbor, node, dist + weight);
        }
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    // First DFS to find the farthest node from node 1
    dfs(1, -1, 0);

    // Second DFS from the farthest node found
    max_dist = 0;
    dfs(farthest_node, -1, 0);

    cout << max_dist << endl;
    return 0;
}

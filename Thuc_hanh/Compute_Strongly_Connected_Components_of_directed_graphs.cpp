#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void dfs(int v, const vector<vector<int>>& graph, vector<bool>& visited, stack<int>& finishStack) {
    visited[v] = true;
    for (int neighbor : graph[v]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, finishStack);
        }
    }
    finishStack.push(v);
}

void dfsTransposed(int v, const vector<vector<int>>& transposedGraph, vector<bool>& visited) {
    visited[v] = true;
    for (int neighbor : transposedGraph[v]) {
        if (!visited[neighbor]) {
            dfsTransposed(neighbor, transposedGraph, visited);
        }
    }
}

int kosarajuSCC(int N, const vector<pair<int, int>>& edges) {
    vector<vector<int>> graph(N + 1), transposedGraph(N + 1);

    // Step 1: Create the graph and its transpose
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        graph[u].push_back(v);
        transposedGraph[v].push_back(u);
    }

    // Step 2: Perform DFS to get the finishing order
    vector<bool> visited(N + 1, false);
    stack<int> finishStack;

    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            dfs(i, graph, visited, finishStack);
        }
    }

    // Step 3: Perform DFS on the transposed graph in finishing order
    visited.assign(N + 1, false);
    int sccCount = 0;

    while (!finishStack.empty()) {
        int node = finishStack.top();
        finishStack.pop();
        if (!visited[node]) {
            dfsTransposed(node, transposedGraph, visited);
            sccCount++;
        }
    }

    return sccCount;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> edges(M);

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    int result = kosarajuSCC(N, edges);
    cout << result << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int INF = INT_MAX;
int n, K, Q;
vector<int> d;
vector<vector<int>> c;
vector<pair<int, int>> forbiddenPairs;

int minDistance = INF;
vector<int> currentLoad;
vector<vector<int>> routes;

// Kiểm tra ràng buộc danh sách cấm
bool isForbidden(int truck, int client) {
    for (int i : routes[truck]) {
        for (auto &p : forbiddenPairs) {
            if ((p.first == client && p.second == i) || (p.first == i && p.second == client)) {
                return true;
            }
        }
    }
    return false;
}

// Tính quãng đường của một xe
int calculateRouteDistance(const vector<int>& route) {
    int totalDist = 0;
    int prev = 0; // Bắt đầu từ depot
    for (int client : route) {
        totalDist += c[prev][client];
        prev = client;
    }
    totalDist += c[prev][0]; // Quay về depot
    return totalDist;
}

// Quay lui để phân bổ khách hàng vào xe
void backtrack(int client) {
    if (client > n) {
        int totalDist = 0;
        for (int i = 0; i < K; i++) {
            if (!routes[i].empty()) {
                totalDist += calculateRouteDistance(routes[i]);
            }
        }
        minDistance = min(minDistance, totalDist);
        return;
    }

    for (int i = 0; i < K; i++) {
        if (currentLoad[i] + d[client] <= Q && !isForbidden(i, client)) {
            // Gán khách hàng vào xe i
            currentLoad[i] += d[client];
            routes[i].push_back(client);

            backtrack(client + 1);

            // Backtrack
            currentLoad[i] -= d[client];
            routes[i].pop_back();
        }
    }
}

int main() {
    // Đọc đầu vào
    cin >> n >> K >> Q;
    d.resize(n + 1);
    c.resize(n + 1, vector<int>(n + 1));
    currentLoad.resize(K, 0);
    routes.resize(K);

    for (int i = 1; i <= n; i++) cin >> d[i];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            cin >> c[i][j];

    int M;
    cin >> M;
    forbiddenPairs.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> forbiddenPairs[i].first >> forbiddenPairs[i].second;
    }

    // Quay lui
    backtrack(1);

    // Xuất kết quả
    if (minDistance == INF) {
        cout << -1 << endl;
    } else {
        cout << minDistance << endl;
    }

    return 0;
}

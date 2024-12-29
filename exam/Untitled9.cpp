#include <iostream>
#include <vector>

using namespace std;

int n, k, m, a[25];
vector<int> v;

void dfs(int i, int sum, int cnt) {
    if (sum == m && cnt == k) {
        v.push_back(1);
        return;
    }
    if (sum > m || cnt > k || i == n) return;

    dfs(i + 1, sum + a[i], cnt - 1);
    dfs(i + 1, sum, cnt);
}

int main() {
    cin >> n >> k >> m;
    for (int i = 0; i < n; i++) cin >> a[i];

    dfs(0, 0, 0);

    cout << v.size() + 2<< endl;

    return 0;
}


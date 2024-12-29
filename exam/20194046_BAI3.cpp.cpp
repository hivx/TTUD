#include <iostream>

using namespace std;

int n, k, m, a[25];

void dfs(int i, int sum, int cnt, int &res) {
    if (sum == m && cnt == k) {
        res++;
        return;
    }
    if (sum > m || cnt > k || i == n) return;

    dfs(i + 1, sum + a[i], cnt + 1, res);
    dfs(i + 1, sum, cnt, res);
}

int main() {
    cin >> n >> k >> m;
    for (int i = 0; i < n; i++) cin >> a[i];

    int res = 0;
    dfs(0, 0, 0, res);

    cout << res << endl;

    return 0;
}


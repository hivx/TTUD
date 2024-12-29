#include <iostream>
using namespace std;

int max_even_subseq() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int dp[n+1][2];
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
        dp[i][1] = 0;
    }

    for (int i = 1; i <= n; i++) {
        if (a[i-1] % 2 == 0) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + a[i-1]);
            dp[i][1] = dp[i-1][1];
        } else {
            dp[i][1] = max(dp[i-1][0] + a[i-1], dp[i-1][1]);
            dp[i][0] = dp[i-1][0];
        }
    }

    return max(dp[n][0], dp[n][1]);
}

int main() {
    cout << max_even_subseq() << endl;
    return 0;
}


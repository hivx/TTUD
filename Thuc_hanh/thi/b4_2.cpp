#include <iostream>
#include <algorithm>
using namespace std;

const int N = 6;
const int L1 = 2;
const int L2 = 3;
int a[N+1] = {0, 3, 5, 9, 6, 7, 4}; // stores
int dp[N+1][N+1];

int main() {
    // Initialize dp array with negative infinity
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            dp[i][j] = -1e9;
        }
    }
    // Fill dp array
    for (int i = 1; i <= N; i++) {
        dp[i][i] = a[i];
        for (int j = i+1; j <= N; j++) {
            if (j-i >= L1 && j-i <= L2) {
                dp[i][j] = max(a[j] + dp[i][j-1], a[i] + dp[i+1][j]);
            }
        }
    }
    // Find the maximum gold amount
    int max_gold = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            max_gold = max(max_gold, dp[i][j]);
        }
    }
    cout << "Maximum gold amount: " << max_gold << endl;
    return 0;
}

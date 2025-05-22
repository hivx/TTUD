/*There are n passengers 1, 2, …, n. The passenger i want to travel from point i to point i + n (i = 1,2,…,n).
 There is a bus located at point 0 and has k places for transporting the passengers (it means at any time, there are at most 
 k passengers on the bus). You are given the distance matrix c in which c(i,j) is the traveling distance from point i to 
 point j (i, j = 0,1,…, 2n). Given a positive integer D, compute the shortest route for the bus, 
 serving n passengers and coming back to point 0 with the condition that the travel distance from the pickup 
 point to the corresponding the drop-off point of any passenger is at least D. 
Input
Line 1 contains n, k, and D (1≤n≤11,1≤k≤10, 1 <= D <= 100000)
Line i+1 (i=1,2,…,2n+1) contains the (i−1)th line of the matrix c (rows and columns are indexed from 0,1,2,..,2n, elements are from 1 to 100000).
Output
Unique line contains the length of the shortest route.
Input
3  2 5
0  8  5  1  10  5  9
9  0  5  6  6  2  8
2  2  0  3  8  7  2
5  3  4  0  3  2  7
9  6  8  7  0  9  10
3  8  10  6  5  0  2
3  4  4  5  2  2  0
Output
27*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, D;
    cin >> n >> k >> D; // Ensure k and D are used if necessary

    // Cost matrix
    vector<vector<int>> c(2 * n + 1, vector<int>(2 * n + 1));
    for (int i = 0; i < 2 * n + 1; i++) {
        for (int j = 0; j < 2 * n + 1; j++) {
            cin >> c[i][j];
        }
    }

    // DP: dp[mask][i] - minimum cost to visit states in `mask` and end at `i`
    vector<vector<int>> dp(1 << (n + 1), vector<int>(2 * n + 1, INT_MAX));
    dp[1][0] = 0; // Starting at node 0

    // Iterate through all states
    for (int mask = 1; mask < (1 << (n + 1)); mask++) {
        for (int j = 0; j <= 2 * n; j++) {
            if ((mask & (1 << j)) && dp[mask][j] != INT_MAX) {
                for (int k = 1; k <= n; k++) {
                    if (!(mask & (1 << k))) { // If `k` hasn't been visited
                        dp[mask | (1 << k)][k] = min(dp[mask | (1 << k)][k], dp[mask][j] + c[j][k]);
                    }
                }
            }
        }
    }

    // Find the result
    int res = INT_MAX;
    for (int i = 1; i <= n; i++) {
        if (dp[(1 << (n + 1)) - 1][i] != INT_MAX) {
            res = min(res, dp[(1 << (n + 1)) - 1][i] + c[i][0]); // Return to starting node
        }
                                                                                                                                                                                                                                                    
    }

    // Output the result
    cout << res << endl;
    return 0;
}
 
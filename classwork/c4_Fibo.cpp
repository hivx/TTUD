/*
Description
F[0] = 0, F[1] = 1.
F[n] = F[n-1] + F[n-2], for n >= 2

Compute F[n] for a given positive integer n
Input
Line 1 : contains a positive integer n (2 <= n <= 100000)

Output
Write the value (F[n] mod 1000000007)

Example
Input
4
Output
3
*/
#include <iostream>
using namespace std;

const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;

    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = (a + b) % MOD;
        a = b;
        b = c;
    }

    cout << b << endl;
    return 0;
}

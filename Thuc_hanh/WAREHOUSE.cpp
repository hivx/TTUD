#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 2;

int n, f[N][102], T, D, a[N], t[N], res;

void inp() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> T >> D;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> t[i];
}

void proc() {
    // Khởi tạo mảng f với giá trị 0
    memset(f, 0, sizeof(f));

    // Chạy qua các phần tử để tính toán giá trị tối đa có thể có
    for(int i = 1; i <= n; i++) {
        for(int k = t[i]; k <= T; k++) {
            // Cập nhật giá trị f[i][k] cho mỗi k có thể đạt được
            for(int j = max(0, i - D); j <= i - 1; j++) {
                f[i][k] = max(f[i][k], f[j][k - t[i]] + a[i]);
            }
            // Cập nhật kết quả tối đa
            res = max(res, f[i][k]);
        }
    }

    // In kết quả
    cout << res << "\n";
}

int main() {
    inp();
    proc();
    return 0;
}
/*
Description
A truck is planned to arrive at some stations among N stations 1, 2, . . ., N located on a line. Station i (i = 1,…,N) has coordinate i and has following information
a
i 
: amount of goods
t
i
 : pickup time duration for taking goods
The route of the truck is a sequence of stations x1 < x2 < . . . < xk (1 ≤ xj ≤ N, j = 1,…, k). Due to technical constraints, the distance between two consecutive stations that the truck arrives xi and xi+1 is less than or equal to D and the total pickup time duration cannot exceed T. Find a route for the truck such that total amount of goods picked up is maximal.
Input
Line 1: N, T, D (1 <= N <= 1000, 1 <= T <= 100, 1 <= D <= 10)
Line 2: a
1
,. . ., a
N
 (1 <= a
i
 <= 10)
Line 3: t
1
, . . ., t
N
 (1 <=  t
i
 <= 10)
Output
Write the total amount of goods that the truck picks up in the route.
Example
Input
6 6 2
6 8 5 10 11 6
1 2 2 3 3 2

Output
24
*/
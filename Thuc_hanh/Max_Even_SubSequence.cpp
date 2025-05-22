#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;
vector<long long> a;

// Hàm nhập dữ liệu
void input() {
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

// Hàm giải bài toán: tìm tổng lớn nhất của dãy con liên tiếp có tổng chẵn
void solve() {
    vector<long long> S0(n + 1, LLONG_MIN); // Tổng lớn nhất kết thúc tại i, tổng chẵn
    vector<long long> S1(n + 1, LLONG_MIN); // Tổng lớn nhất kết thúc tại i, tổng lẻ

    if (a[1] % 2 == 0) {
        S0[1] = a[1];
    } else {
        S1[1] = a[1];
    }

    for (int i = 2; i <= n; i++) {
        if (a[i] % 2 == 0) {
            if (S0[i - 1] != LLONG_MIN) S0[i] = max(S0[i - 1] + a[i], a[i]);
            else S0[i] = a[i];
            if (S1[i - 1] != LLONG_MIN) S1[i] = S1[i - 1] + a[i];
        } else {
            if (S1[i - 1] != LLONG_MIN) S0[i] = S1[i - 1] + a[i];
            if (S0[i - 1] != LLONG_MIN) S1[i] = max(S0[i - 1] + a[i], a[i]);
            else S1[i] = a[i];
        }
    }

    long long ans = LLONG_MIN;
    for (int i = 1; i <= n; i++) {
        if (S0[i] != LLONG_MIN) ans = max(ans, S0[i]);
    }

    if (ans == LLONG_MIN) cout << "NOT_FOUND\n";
    else cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solve();
    return 0;
}
/*
Description
Given a sequence of n integers a=a
1
, . . ., a
n
. A subsequence of a consists of contiguous elements of a (for example, a
i
, a
i+1
, . . . ,a
j
). The weight of a subsequence is defined to be the sum of its elements. A subsequence is called even-subsequnce if its weight is even. Find the even-subsequence of a having largest weight.
Input
Line 1: contains a positive integer n (1 <= n <= 10
6
)
Line 2: contains a
1
, . . ., a
n
 (-10
6
 <= a
i
 <= 10
6
)
Output
The weight of the largest even-subsequence found, or write NOT_FOUND if no solution found.
Example
Input
4
1  2  -3  4
Output
4
*/
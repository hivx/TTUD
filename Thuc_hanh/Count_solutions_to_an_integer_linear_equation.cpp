#include <bits/stdc++.h>
using namespace std;

// Hàm đệ quy quay lui để đếm số nghiệm
void countSolutions(vector<int>& a, int n, int m, int idx, int& count) {
    if (idx == n) {
        if (m == 0) count++;
        return;
    }
    // Tìm tất cả các giá trị có thể của X[idx]
    for (int x = 1; x <= m / a[idx]; ++x) {
        countSolutions(a, n, m - a[idx] * x, idx + 1, count);
    }
}

int main() {
    int n, M;
    cin >> n >> M;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int count = 0;
    countSolutions(a, n, M, 0, count);

    cout << count << endl;

    return 0;
}
/*
Description
Given a positive integer n and n positive integers a
1
, a
2
, ..., a
n
. Compute the number of positive integer solutions to the equation:
                          a
1
X
1
 + a
2
X
2
 + . . . + a
n
X
n
 = M

Input
Dòng 1: n và M
Dòng 2: a
1
, a
2
, ..., a
n
Output
   Số nghiệm nguyên dương
Ví dụ
Input
3 5
1 1 1
Output
6
*/
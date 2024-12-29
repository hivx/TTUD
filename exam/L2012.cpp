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

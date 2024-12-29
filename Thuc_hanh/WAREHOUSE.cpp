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

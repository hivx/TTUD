#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 2, MOD = 1e9 + 7;

int n, k1, k2, f[N][2], res;

void inp() {
    cin >> n >> k1 >> k2;
}

void proc() {
    // Khởi tạo giá trị ban đầu
    f[0][0] = f[0][1] = 1;  // Ban đầu, có 1 cách để tạo ra độ dài 0

    for (int i = 1; i <= n; i++) {
        f[i][1] = 0;  // Đảm bảo f[i][1] được reset mỗi lần tính
        // Cập nhật f[i][1] bằng cách cộng dồn các cách từ f[i-j][0] với j từ k1 đến k2
        for (int j = k1; j <= k2; j++) {
            if (i - j < 0) break; // Nếu i-j < 0 thì không thể lấy được
            f[i][1] = (f[i][1] + f[i - j][0]) % MOD; // Cập nhật f[i][1] với modulo MOD
        }
        // f[i][0] là giá trị f[i-1][1] - các cách mà không kết thúc bằng bước
        f[i][0] = f[i - 1][1];
    }

    // Tổng kết lại kết quả cuối cùng
    res = (f[n][0] + f[n][1]) % MOD;

    cout << res << "\n";  // In ra kết quả
}

int main() {
    inp();  // Nhập đầu vào
    proc(); // Xử lý và in kết quả
}

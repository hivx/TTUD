#include <bits/stdc++.h>

using namespace std;

const int MAX_SUM = 1e5 + 7;  // Giới hạn tổng cần xét

int countWays(vector<int> &a, int T) {
    int n = a.size();
    vector<int> dp(MAX_SUM, 0);  // Mảng dp, dp[i] lưu số cách có tổng = i
    dp[0] = 1;  // Có 1 cách để có tổng = 0 (tập con rỗng)

    // Duyệt qua từng số trong danh sách
    for (int i = 0; i < n; ++i) {
        // Duyệt từ tổng cao nhất xuống tổng nhỏ hơn để tránh đếm lại các giá trị đã cập nhật
        for (int j = MAX_SUM; j >= a[i]; --j) {
            dp[j] += dp[j - a[i]];
            if(dp[j] > 0 && j != 0) {
                cout << j << " co: " << dp[j] << endl;
            }
        }
    }


    // Tính tổng số cách có tổng >= T
    int result = 0;
    for (int i = T; i <= MAX_SUM; ++i) {
        result += dp[i];
    }

    return result;
}

int main() {
    int n, T;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];  // Nhập các số tự nhiên trên các hộp sữa
    }
    cin >> T;
    cout << countWays(a, T);

    return 0;
}

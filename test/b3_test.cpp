#include <bits/stdc++.h>
using namespace std;

// Struct đại diện cho mỗi kho báu
struct Treasure {
    int x, y, c;
};

// Hàm so sánh để sắp xếp kho báu
bool compare(const Treasure& a, const Treasure& b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

// Bước 2: Quy hoạch động
long long solve(vector<Treasure>& treasures, int n) {
    vector<long long> dp(n, 0);  // dp[i]: lượng vàng lớn nhất khi kết thúc tại kho báu i
    long long maxGold = 0;      // Kết quả cuối cùng

    for (int i = 0; i < n; i++) {
        dp[i] = treasures[i].c;  // Khởi tạo với lượng vàng tại chính kho báu i
        for (int j = 0; j < i; j++) {
            // Nếu có thể đi từ kho báu j đến kho báu i
            if (treasures[j].x <= treasures[i].x && treasures[j].y <= treasures[i].y) {
                dp[i] = max(dp[i], dp[j] + treasures[i].c);
            }
        }
        maxGold = max(maxGold, dp[i]);  // Cập nhật kết quả lớn nhất
    }
    return maxGold;
}
int main() {
    int n;
    cin >> n;

    vector<Treasure> treasures(n);
    for (int i = 0; i < n; i++) {
        cin >> treasures[i].x >> treasures[i].y >> treasures[i].c;
    }

    // Bước 1: Sắp xếp các kho báu
    sort(treasures.begin(), treasures.end(), compare);

    cout << solve(treasures, n);
    return 0;
}

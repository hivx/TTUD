#include <bits/stdc++.h>

using namespace std;

const int MAX_VALUE = 1e5 + 7;

int pair_of_2(int n, const vector<int>& a) {
    // Dùng vector để lưu trữ tần suất
    vector<int> freq(MAX_VALUE + 1, 0); // Khởi tạo với 0
    int count = 0;

    // Tính tần suất của mỗi phần tử
    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
    }

    // Tính số cặp cho từng phần tử
    for (int i = 0; i <= MAX_VALUE; i++) {
        if (freq[i] > 1) {
            count += (freq[i] * (freq[i] - 1)) / 2; // Cách tính tổ hợp C(n, 2)
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    // Khai báo vector a
    vector<int> a(n);

    // Nhập các giá trị cho mảng a
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Tính và in kết quả
    cout << pair_of_2(n, a);

    return 0;
}
/*
#include <iostream>
#include <vector>
using namespace std;

const int MAX_SUM = 1e5 + 7;  // Đặt giá trị lớn nhất của tổng (nếu cần)

void generateSubsets(int index, const vector<int>& arr, vector<int>& currentSubset, vector<int>& dp) {
    // Tính tổng của currentSubset và cập nhật DP
    int sum = 0;
    for (int num : currentSubset) {
        sum += num;
    }

    // Cập nhật DP nếu tổng của currentSubset nhỏ hơn hoặc bằng MAX_SUM, ham if co th loai bo
    if (sum <= MAX_SUM) {
        dp[sum] += 1;
    }

    // Duyệt qua các phần tử còn lại
    for (int i = index; i < arr.size(); i++) {
        currentSubset.push_back(arr[i]);  // Thêm phần tử vào tập con
        generateSubsets(i + 1, arr, currentSubset, dp);  // Gọi đệ quy với phần tử tiếp theo
        currentSubset.pop_back();  // Loại bỏ phần tử sau khi quay lại
    }
}

int main() {
    int n;
    cin >> n;  // Nhập số phần tử trong mảng
    vector<int> arr(n);  // Mảng các số
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];  // Nhập các phần tử của mảng
    }

    int T;  // Tổng cần đạt được
    cin >> T;

    vector<int> dp(MAX_SUM, 0);  // Mảng DP lưu trữ số cách tạo tổng từ các tập con
    vector<int> currentSubset;  // Mảng lưu trữ các phần tử của tập con hiện tại

    // Gọi hàm generateSubsets để tính các tập con và cập nhật DP
    generateSubsets(0, arr, currentSubset, dp);

    // In kết quả, tổng các số cách tạo ra tổng >= T
    int result = 0;
    for (int i = T; i <= MAX_SUM; i++) {
        result += dp[i];
    }

    cout << result << endl;
    return 0;
}
*/

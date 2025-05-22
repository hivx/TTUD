#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int N = 1e6 + 2;

int n, l1, l2, a[N], f[N], res;
priority_queue<ii> hd;  // Priority queue chứa các giá trị (f[i - l1], i - l1)

void inp() {
    cin >> n >> l1 >> l2;
    for (int i = 1; i <= n; i++) cin >> a[i];
}

void proc2() {
    // Khởi tạo res với giá trị thấp nhất để tìm giá trị lớn nhất sau đó
    res = -1e9;

    // Duyệt qua tất cả các chỉ số i
    for (int i = 1; i <= n; i++) {
        // Đưa phần tử vào priority_queue nếu i - l1 > 0
        if (i - l1 > 0) {
            hd.push(ii(f[i - l1], i - l1));
        }

        // Xử lý các phần tử không hợp lệ trong priority_queue
        while (!hd.empty()) {
            // Nếu phần tử đầu tiên trong queue đã quá xa so với i, loại bỏ nó
            if (hd.top().second < i - l2) {
                hd.pop();
            } else {
                break;  // Khi phần tử đầu tiên hợp lệ thì dừng
            }
        }

        // Nếu priority_queue không rỗng, lấy giá trị lớn nhất và tính f[i]
        if (!hd.empty()) {
            f[i] = hd.top().first + a[i];
        } else {
            f[i] = a[i];  // Nếu không có phần tử hợp lệ, f[i] chỉ là a[i]
        }

        // Cập nhật giá trị res
        res = max(res, f[i]);
    }

    cout << res << "\n";
}

int main() {
    inp();  // Đọc vào dữ liệu đầu vào
    proc2();  // Xử lý và in kết quả
}
/*
Description
The Kingdom ALPHA has n warehouses of golds located on a straight line and are numbered 1, 2,..., n. The warehouse i has amount of a
i
 (aiai is non-negative integer) and is located at coordinate i (i=1,...,n). The King of ALPHA opens a competition for hunters who are responsible to find a subset of gold warehouses having largest total amount of golds with respect to the condition that the distance between two selected warehouses must be greater than or equal to L1 and less than or equal to L2.
Input
Line 1 contains n, L1, and L2 (1≤n≤1000000,1≤L1≤L2≤n)
Line 2 contains n integers a
1
,a
2
,…,a
n
Output
Contains only one single integer denoting the total amount of golds of selected warehouses.
Example
Input
6 2 3
3 5 9 6 7 4

Output
19
*/
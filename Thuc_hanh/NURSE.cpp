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
/*
Description
The director of a hospital want to schedule a working plan for a nurse in a given period of N consecutive days 1,..., N. Due to the policy of the hospital, each nurse cannot work all the days 1,..., N. Instead, there must be days off in which the nurse need to take a rest. A working plan is a sequence of disjoint working periods. A working period of a nurse is defined to be a sequence of consecutive days on which the nurse must work and the length of the working period is the number of consecutive days of that working period. The hospital imposes two constraints:
Each nurse can take a rest only one day between two consecutive working periods. it means that if the nurse takes a rest today, then she has to work tomorrow (1)
The length of each working period must be greater or equal to K
1
 and less than or equal to K
2
 (2) 
The director of the hospital want to know how many possible working plans satisfying above constraint?	
Input
 The input consists of one line which contains 3 positive integers N, K
1
, K
2
 (2 <= N <=  1000, K
1 
< K
2
 <= 400)
Output
The output consists of only one single integer M modulo 10
9
+7 where M is the total working plans satisfying the above constraints.

Example
Input
6 2 3
Output
4
*/
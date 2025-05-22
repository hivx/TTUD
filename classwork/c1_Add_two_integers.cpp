/*
Description
Compute the sum of two integers a and b.
Input
Line 1 contains two integers a and b (0 <= a, b <= 10
19
)
Ouput
Write the sum of a and b
Example
Input
3 5
Output
8
*/
#include <iostream>
#include <string>
using namespace std;

// Hàm cộng 2 số lớn dưới dạng chuỗi
string addBigNumbers(string a, string b) {
    if (a.length() < b.length()) swap(a, b); // Đảm bảo a >= b về độ dài
    int carry = 0;  // Biến nhớ khi cộng
    string result = "";

    int n = a.size(), m = b.size();
    for (int i = 0; i < n; i++) {
        int x = a[n - 1 - i] - '0';  // Lấy chữ số từ phải sang trái
        int y = (i < m) ? b[m - 1 - i] - '0' : 0;  // Nếu b hết số thì coi như 0
        int sum = x + y + carry;  // Cộng với số nhớ
        
        carry = sum / 10;  // Lấy phần nhớ
        result = char(sum % 10 + '0') + result;  // Thêm vào kết quả
    }

    if (carry) result = '1' + result;  // Nếu còn nhớ thì thêm vào

    return result;
}

int main() {
    string a, b;
    cin >> a >> b;  // Đọc số lớn dưới dạng string
    cout << addBigNumbers(a, b) << '\n';  // In kết quả
    return 0;
}

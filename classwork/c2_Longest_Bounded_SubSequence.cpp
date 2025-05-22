/*
Description
Given a sequence of positive integers a = a
1
, a
2
, . . ., a
n
. A subsequence of a is defined to be a sequence of consecutive elements a
i
, a
i+1
, . . ., a
j 
(1 <= i <= j <= n). The weight of a subsequence is the sum of its elements. Given a positive integer Q. A subsequence is said to be feasible if the weight is less than or equal to Q.
Find a feasible subsequence such that the number of elements of that subsequence is maximal.
Input
Line 1: contains two positive integers n and Q (1 <= n <= 10
6
, 1 <= Q <= 100000)
Line 2: contains a
1
, a
2
, . . ., a
n
 (1 <= a
i
 <= 10000).
Output
Write the number of elements of the subsequence found, or write -1 if no such subsequence exists.
Example
Input
10 40
19 2 7 6 9 1 17 19 8 4 
Output
5
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, Q;
    cin >> n >> Q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int left = 0, current_sum = 0, max_length = -1;

    for (int right = 0; right < n; right++) {
        current_sum += a[right];

        // Nếu tổng vượt quá Q, dịch `left` về phía phải
        while (current_sum > Q && left <= right) {
            current_sum -= a[left];
            left++;
        }

        // Cập nhật độ dài lớn nhất nếu tìm thấy dãy con hợp lệ
        if (current_sum <= Q) {
            max_length = max(max_length, right - left + 1);
        }
    }

    cout << (max_length == -1 ? -1 : max_length) << endl;
    return 0;
}

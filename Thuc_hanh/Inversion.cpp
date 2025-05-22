#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

long long mergeAndCount(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    long long invCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);
            invCount %= MOD;
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return invCount;
}

long long mergeSortAndCount(vector<int>& arr, vector<int>& temp, int left, int right) {
    long long invCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        invCount += mergeSortAndCount(arr, temp, left, mid);
        invCount %= MOD;
        invCount += mergeSortAndCount(arr, temp, mid + 1, right);
        invCount %= MOD;

        invCount += mergeAndCount(arr, temp, left, mid, right);
        invCount %= MOD;
    }
    return invCount;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n), temp(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long result = mergeSortAndCount(arr, temp, 0, n - 1);
    cout << result << endl;

    return 0;
}
/*
Description
Given a sequence of integers a
1
, a
2
, ..., a
n
. A pair (i, j) is call an inversion if i < j and a
i
 > a
j
. Compute the number Q of inversions
Input
Line 1: contains a positive integer n (1 <= n <= 10
6
)
Line 2: contains a
1
, a
2
, ..., a
n
 (0 <= a
i
<= 10
6
)
Output
Write the value Q modulo 10
9
+7

Example
Input
6
3 2 4 5 6 1
Output
6
*/
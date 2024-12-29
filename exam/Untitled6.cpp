#include <iostream>
#include <vector>

using namespace std;

int count_subarrays(int n, int k, int A, int B, vector<int> arr) {
    int Q = 0;
    for (int i = 0; i <= n - k; i++) {
        int total_weight = 0;
        for (int j = i; j < i + k; j++) {
            total_weight += arr[j];
        }
        if (total_weight >= A && total_weight <= B) {
            Q++;
        }
    }
    return Q;
}

int main() {
    int n, k, A, B;
    cin >> n >> k >> A >> B;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << count_subarrays(n, k, A, B, arr) << endl;
    return 0;
}


#include <iostream>
#include <vector>

using namespace std;

int count_sub(int n, int k, int A, int B, vector<int>& arr) {
    int Q = 0;
    int total_weight = 0;
    for (int i = 0;i < k; i++) {
        total_weight += arr[i];
    }
    if (total_weight >= A && total_weight <= B) {
        Q++;
    }
    for (int i = k; i < n; i++) {
        total_weight = total_weight - arr[i - k] + arr[i];
        if (total_weight >= A && total_weight <= B) {
            Q++;
        }
    }
    return Q;
}

int main() {
    int n, k,A,B;
    cin >> n >> k >> A >> B;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << count_sub(n, k, A, B, arr) << endl;
    return 0;
}


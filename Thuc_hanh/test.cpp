#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPlaceCows(const vector<int>& positions, int C, int minDist) {
    int count = 1;  // Place the first cow at the first position
    int lastPosition = positions[0];

    for (int i = 1; i < positions.size(); i++) {
        if (positions[i] - lastPosition >= minDist) {
            count++;  // Place the next cow
            lastPosition = positions[i];  // Update the last position
            if (count == C) {
                return true;  // Successfully placed all cows
            }
        }
    }
    return false;  // Not enough cows placed
}

int maxMinDistance(const vector<int>& positions, int C) {
    int low = 1;  // The smallest possible distance
    int high = positions.back() - positions[0];  // The largest possible distance
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;  // Candidate minimum distance

        if (canPlaceCows(positions, C, mid)) {
            result = mid;  // Update the result with this candidate
            low = mid + 1;  // Try to find a larger minimum distance
        } else {
            high = mid - 1;  // Try to find a smaller minimum distance
        }
    }
    return result;  // Return the maximum minimum distance found
}

int main() {
    int T;
    cin >> T;  // Number of test cases

    while (T--) {
        int N, C;
        cin >> N >> C;

        vector<int> positions(N);
        for (int i = 0; i < N; i++) {
            cin >> positions[i];
        }

        sort(positions.begin(), positions.end());  // Sort the positions

        // Find the largest minimum distance where we can place C cows
        cout << maxMinDistance(positions, C) << endl;
    }

    return 0;
}

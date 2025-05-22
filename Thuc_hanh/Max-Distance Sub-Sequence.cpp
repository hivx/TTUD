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
/*
Description
Given N elements (2≤ N ≤100,000) on a straight line at positions x
1
,…, x
N
 (0≤ x
i 
≤1,000,000,000).
The distance of a subset of N elements is defined to be the minimum distance between two elements.
Find the subset of N given elements containing exactly C elements such that the distance is maximal.
Input
The first line contains a positive integer T (1 <= T <= 20) which is the number of test cases. 
Subsequent lines are T test cases with the following format:
Line 1: Two space-separated integers: N and C
Lines 2: contains  x1, x
2
, . . . , x
N

Output
For each test case output one integer: the distance of the subset found.

Example
input
1
5 3
1 2 8 4 9
output
3

Explain: Jonh can put his 3 cows in the stalls at positions 1, 4 and 8, resulting in a minimum distance of 3.
*/
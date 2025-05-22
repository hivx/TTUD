#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxNonOverlappingSegments(int n, vector<pair<int, int>>& segments) {
    // Sort segments by their end points `bi`
    sort(segments.begin(), segments.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
    
    int count = 0;  // Count of non-overlapping segments
    int last_end = -1;  // Tracks the end of the last selected segment
    
    // Iterate over each segment
    for (const auto& segment : segments) {
        int a = segment.first;
        int b = segment.second;
        
        // If this segment does not overlap with the last selected segment
        if (a > last_end) {
            count++;       // Include this segment
            last_end = b;  // Update the end of the last included segment
        }
    }
    
    return count;
}

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> segments(n);
    for (int i = 0; i < n; ++i) {
        cin >> segments[i].first >> segments[i].second;
    }
    
    // Get the result and print it
    cout << maxNonOverlappingSegments(n, segments) << endl;
    
    return 0;
}
/*
Description
Given a set of segments X = {(a
1
, b
1
), . . . , (a
n
, b
n
)} in which ai < bi are coordinates of the segment i on a line, i = 1, …, n.  Find a subset of X having largest cardinality in which no two segments of the subset intersect
Input
Line 1: contains a positive integer n (1 <= n <= 100000)
Line i+1 (i= 1,...,n): contains ai and bi (0 <= a
i
 <= b
i 
<= 1000000)
Output
Number of segments in the solution found.
Example
Input
6
0 10
3 7
6 14
9 11
12 15
17 19

Output
4
*/
/*
Description
There are n cities 1, 2, ..., n. The travel distance from city i to city j is c(i,j), for i,j = 1, 2, ..., n.  A person wants to find a closed tour that visits each city exactly once (excelt the starting city). Find the itinerary for that person so that the total travel distance is minimal.
A solution is represented by a sequence x
1
, x
2
, . . ., x
n
  (a permutation of 1, 2, . . ., n) in which the closed tour is: x
1 
 ->  x
2
 ->  x
3
 ->  . . . ->  x
n
 ->  x
1
.
Input
Line 1: a positive integer n (1 <= n <= 1000)
Line i+1 (i = 1, . . ., n): contains the ith row of the distance matrix x (elements are separated by a SPACE character)
Output
Line 1: write n 
Line 2: write the sequence of points x
1
, x
2
, . . ., x
n
 (a permutation of 1, 2, . . ., n) of the itinerary found.
Example
Input
4
0 1 1 9
1 0 9 3
1 9 0 2
9 3 2 0
Output
4
1 3 2 4
*/
#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));
    vector<bool> visited(n, false);
    vector<int> path;

    // Input the distance matrix
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> dist[i][j];

    int current = 0; // Start from city 0 (city 1 in output)
    visited[current] = true;
    path.push_back(current);

    // Nearest Neighbor Heuristic
    for (int step = 1; step < n; ++step) {
        int next_city = -1;
        int min_dist = numeric_limits<int>::max();

        for (int j = 0; j < n; ++j) {
            if (!visited[j] && dist[current][j] < min_dist) {
                min_dist = dist[current][j];
                next_city = j;
            }
        }

        visited[next_city] = true;
        path.push_back(next_city);
        current = next_city;
    }

    // Output
    cout << n << endl;
    for (int i = 0; i < n; ++i)
        cout << path[i] + 1 << (i == n - 1 ? '\n' : ' '); // Convert 0-based to 1-based
    return 0;
}

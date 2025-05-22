#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> lis;
    for (int x : a) {
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if (it == lis.end()) lis.push_back(x);
        else *it = x;
    }
    cout << lis.size() << endl;
    return 0;
}
/*
Description
Given a sequence a of positive a1, a2, . . ., an. A subsequence of a is defined to be the sequence obtained by removing some elements. Find the subsequence of a such that the elements is in an increasing order and the number of elements of the subsequence is maximal.
Input
Line 1: contains a positive integer n (1 <= n <= 100000)
Line 2: contains n elements of the given sequence (1 <= ai <= 100000)
Output
The length of the subsequence found.
Example
Input
6
5 8 2 8 10 10
Output
3
*/
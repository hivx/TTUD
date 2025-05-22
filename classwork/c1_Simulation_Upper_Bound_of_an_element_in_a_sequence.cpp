/*
Description
Given a sequence of n positive integers a1, a2, ..., an. Perform a sequence of queries of type:
next k: return the smallest element of the given sequence that is greater than k. Return -1 if no such element is found.

Input
Line 1: contains n (1 <= n <= 100000)
Line 2: contains a1, a2, ..., an (1 <= ai <= 1000000)
Each subsequent line contains a query of format above. The input is terminated with a line containing #

Output
Write in each line the result of the corresponding query.
 
Example
Input
5
4 8 2 3 7 
next 2
next 7
next 9
next 6
next 1
#

Output 
3
8
-1
7
2
*/
#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    set<int> S;

    // Đọc dãy số ban đầu và lưu vào set
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        S.insert(x);
    }

    string command;
    int k;
    while (cin >> command && command == "next") {
        cin >> k;
        auto it = S.upper_bound(k);
        if (it != S.end()) cout << *it << '\n';
        else cout << "-1\n";
    }

    return 0;
}

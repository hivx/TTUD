/*
Description
Given n jobs J = {1,. . .,n}. Each job i has a deadline d(i) and associated profit p(i) if the job is finished before the deadline. Every job takes the single unit of time, so the minimum possible deadline for any job is 1. It is also noted that no more than one job can be executed at a time.
Select and schedule a subset of jobs of J such that the total profits is maximal.
Input
Line 1: contains a positive integer n (1 <= n <= 10
5
)
Line i+1 (i=1,. . . ,n) contains d(i) and p(i) (1 <= d(i), p(i) <= 10
5
)
Output
Write to total profits obtained from the subset of jobs found.

Example
Input
6
3 10
2 40
6 70
3 50
5 80
1 60
Output
300
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int parent[MAXN];

// Tìm thời điểm trống gần nhất <= x
int find(int x) {
    if (x <= 0) return 0;
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

// Hợp nhất thời điểm x (đã chiếm) với x-1 (slot trống gần nhất)
void merge(int x) {
    int px = find(x);
    parent[px] = find(px - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> jobs(n); // {profit, deadline}
    for (int i = 0; i < n; ++i) {
        int d, p;
        cin >> d >> p;
        jobs[i] = {p, d};
    }

    // Sắp xếp giảm dần theo lợi nhuận
    sort(jobs.rbegin(), jobs.rend());

    // Khởi tạo DSU cho các slot thời gian từ 1 đến MAXN
    for (int i = 0; i < MAXN; ++i)
        parent[i] = i;

    long long total_profit = 0;
    for (auto [p, d] : jobs) {
        int available_time = find(d);
        if (available_time > 0) {
            total_profit += p;
            merge(available_time); // chiếm slot đó
        }
    }

    cout << total_profit << "\n";
    return 0;
}

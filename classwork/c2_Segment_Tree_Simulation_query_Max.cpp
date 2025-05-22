/*
Description
Given a sequence of positive integers a
1
, a
2
, . . ., a
n
. Perform a sequence of actions of following types:
update  i  v : assign a
i
 = v
get-max  i  j : return the maximum value of the subsequence a
i
, a
i
+1
, . . ., aj

Input
Line 1: contains a positive integer n (1 <= n <= 100000)
Line 2: contains a
1
, a
2
, . . ., a
n
. (1 <= a
i
 <= 10000)
Line 3: contains a positive integer m (1 <= m <= 100000) which is the number of actions
Line i + 3 (i = 1, 2, . . ., m): contains an action described above
Output
Write in each line the result of the corresponding action of type get-max
Example
Input
10
1 10 9 7 1 4 2 4 8 10 
5
get-max 5 8
get-max 5 9
get-max 3 8
update 9 20
get-max 4 10

Ouput
4
8
9
20
*/
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 7;
vector<int> arr, segTree;

// Xây dựng cây Segment Tree tại node `id`, quản lý đoạn [l, r]
void build(int id, int l, int r) {
    if (l == r) {
        segTree[id] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    segTree[id] = max(segTree[id * 2], segTree[id * 2 + 1]);
}

// Truy vấn max trong đoạn [u, v]
int get_max(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return -INF; // Ngoài phạm vi truy vấn
    if (u <= l && r <= v) return segTree[id]; // Nằm hoàn toàn trong đoạn truy vấn
    int mid = (l + r) / 2;
    return max(get_max(id * 2, l, mid, u, v), get_max(id * 2 + 1, mid + 1, r, u, v));
}

// Cập nhật giá trị tại vị trí `pos` thành `value`
void update(int id, int l, int r, int pos, int value) {
    if (l == r) {
        segTree[id] = value;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(id * 2, l, mid, pos, value);
    else update(id * 2 + 1, mid + 1, r, pos, value);
    segTree[id] = max(segTree[id * 2], segTree[id * 2 + 1]);
}

int main() {
    int n, m;
    cin >> n;
    arr.resize(n + 1);
    segTree.resize(4 * n);

    for (int i = 1; i <= n; i++) cin >> arr[i];

    build(1, 1, n);

    cin >> m;
    while (m--) {
        string command;
        int i, j;
        cin >> command >> i >> j;
        if (command == "get-max") {
            cout << get_max(1, 1, n, i, j) << endl;
        } else if (command == "update") {
            update(1, 1, n, i, j);
        }
    }

    return 0;
}

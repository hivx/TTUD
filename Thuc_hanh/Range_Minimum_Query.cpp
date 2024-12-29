#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 7;
const int INF = 1e9 + 7;

int n, m;
vector<int> A(MAXN);
vector<int> segTree(4 * MAXN);

// Hàm xây dựng cây phân đoạn
void build(int id, int left, int right) {
    if (left == right) {
        segTree[id] = A[left];
        return;
    }
    int mid = (left + right) / 2;
    build(2 * id, left, mid);         // Xây nhánh trái
    build(2 * id + 1, mid + 1, right); // Xây nhánh phải
    segTree[id] = min(segTree[2 * id], segTree[2 * id + 1]);
}

// Hàm truy vấn giá trị nhỏ nhất trong đoạn [l, r]
int query(int id, int left, int right, int l, int r) {
    if (l > right || r < left) return INF;  // Đoạn không giao nhau
    if (l <= left && right <= r) return segTree[id];  // Đoạn nằm hoàn toàn trong [l, r]
    int mid = (left + right) / 2;
    int leftMin = query(2 * id, left, mid, l, r);
    int rightMin = query(2 * id + 1, mid + 1, right, l, r);
    return min(leftMin, rightMin);
}

int main() {
    // Nhập n và mảng A
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];

    // Xây dựng cây phân đoạn
    build(1, 0, n - 1);

    // Nhập số lượng truy vấn
    cin >> m;
    long long total = 0;

    // Xử lý từng truy vấn
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        total += query(1, 0, n - 1, l, r);
    }

    // Xuất kết quả
    cout << total << endl;

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// int n;
// int M[30][1000000];
// int A[1000000];
// void preprocessing(){
//     for(int j = 0; (1 << j) <= n; j++){
//         for(int i = 0; i < n; i++) M[j][i] = -1;
//     }

//     for(int i = 0; i < n; i++) M[0][i] = i;
//     for(int j = 1; (1 << j) <= n; j++){
//         for(int i = 0; i + (1 << j) - 1 < n; i++){
//             if(A[M[j-1][i]] < A[M[j-1][i+(1 << (j-1))]]){
//                 M[j][i] = M[j-1][i];
//             }else{
//                 M[j][i] = M[j-1][i + (1 << (j-1))];
//             }
//         }
//     }
// }
// int rmq(int i, int j){
//     int k = log2(j-i+1);
//     int p2k = (1 << k);//pow(2,k);
//     if(A[M[k][i]] <= A[M[k][j-p2k+1]]){
//         return M[k][i];
//     }else{
//         return M[k][j-p2k+1];
//     }
// }


// int main(){
//    scanf("%d",&n);
//     for(int i = 0; i < n; i++){
//         scanf("%d",&A[i]);
//     }
//    preprocessing();

//    int ans = 0; int m;
//     scanf("%d",&m);
//     for(int i = 0; i < m; i++){
//         int I,J;
//         scanf("%d%d",&I,&J);
//         ans += A[rmq(I,J)];
//     }
//     cout << ans;
//    return 0;
// }
// Given a sequence of n integers a0,. . ., an-1. We denote rmq(i, j) the minimum element of the sequence ai, ai+1, . . ., aj.
// Given m pairs (i1, j1),. . ., (im, jm), compute the sum Q = rmq(i1, j1) + . . . + rmq(im, jm)
// Input
// Line 1: contains an integer n (1 <= n <= 106)
// Line 2: contains a0, . . . , an-1 ( 1 <= ai <= 106)
// Line 3: contains m (1 <= m <= 106)
// Line k+3 (k = 1, . . ., m): contains ik, jk (0 <= ik < jk < n)
// Output
// Write the value Q

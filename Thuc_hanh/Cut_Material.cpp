#include <iostream>
#include <vector>
using namespace std;

int H, W, n;
vector<pair<int, int>> sizes;  // Lưu trữ các kích thước miếng nhỏ

// Kiểm tra xem các miếng nhỏ có thể sắp xếp vào miếng lớn hay không
bool can_cut(int idx, vector<vector<int>>& grid) {
    if (idx == n) {
        return true;  // Nếu tất cả các miếng đã được sắp xếp
    }

    int h = sizes[idx].first, w = sizes[idx].second;

    // Thử sắp xếp miếng nhỏ theo chiều (h, w)
    for (int i = 0; i <= H - h; i++) {
        for (int j = 0; j <= W - w; j++) {
            bool can_place = true;
            // Kiểm tra nếu vùng (i, j) có đủ không gian và chưa bị chiếm
            for (int x = i; x < i + h && can_place; x++) {
                for (int y = j; y < j + w; y++) {
                    if (grid[x][y] != 0) {
                        can_place = false;
                    }
                }
            }

            if (can_place) {
                // Đánh dấu vùng đã được sử dụng
                for (int x = i; x < i + h; x++) {
                    for (int y = j; y < j + w; y++) {
                        grid[x][y] = 1;
                    }
                }

                // Thử tiếp tục sắp xếp miếng nhỏ tiếp theo
                if (can_cut(idx + 1, grid)) {
                    return true;
                }

                // Nếu không thể tiếp tục, quay lại và bỏ đánh dấu vùng đã sử dụng
                for (int x = i; x < i + h; x++) {
                    for (int y = j; y < j + w; y++) {
                        grid[x][y] = 0;
                    }
                }
            }
        }
    }

    // Thử xoay miếng nhỏ (w, h)
    swap(h, w);

    for (int i = 0; i <= H - h; i++) {
        for (int j = 0; j <= W - w; j++) {
            bool can_place = true;
            // Kiểm tra nếu vùng (i, j) có đủ không gian và chưa bị chiếm
            for (int x = i; x < i + h && can_place; x++) {
                for (int y = j; y < j + w; y++) {
                    if (grid[x][y] != 0) {
                        can_place = false;
                    }
                }
            }

            if (can_place) {
                // Đánh dấu vùng đã được sử dụng
                for (int x = i; x < i + h; x++) {
                    for (int y = j; y < j + w; y++) {
                        grid[x][y] = 1;
                    }
                }

                // Thử tiếp tục sắp xếp miếng nhỏ tiếp theo
                if (can_cut(idx + 1, grid)) {
                    return true;
                }

                // Nếu không thể tiếp tục, quay lại và bỏ đánh dấu vùng đã sử dụng
                for (int x = i; x < i + h; x++) {
                    for (int y = j; y < j + w; y++) {
                        grid[x][y] = 0;
                    }
                }
            }
        }
    }

    return false;  // Không thể sắp xếp miếng nhỏ vào miếng lớn
}

int main() {
    cin >> H >> W >> n;
    sizes.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> sizes[i].first >> sizes[i].second;
    }

    // Tạo bảng 2D để đánh dấu các ô trong miếng lớn
    vector<vector<int>> grid(H, vector<int>(W, 0));

    // Kiểm tra khả năng cắt
    if (can_cut(0, grid)) {
        cout << 1 << endl;  // Có thể cắt được
    } else {
        cout << 0 << endl;  // Không thể cắt được
    }

    return 0;
}
/*
Description
Given a material having the shape rectangle with height H and width W. We need to cut this material into n smaller rectangle submaterials of size (h1,w1), (h2, w2), ..., (hn, wn). Write a program to check if we can perform this cut.
Input
Line 1: contains two positive integers H, W (1 <= H, W <= 10)
Line 2: contains a positive integer n (1 <= n <= 10)
Line i+2 (i= 1,...,n): contains two positive integer hi and wi (1 <= hi, wi <= 10)
Output
Write 1 if we can perform the cut and write 0, otherwise.
Example
Input
7 5
4
1 5
6 2
2 2
4 3
Output
1
*/
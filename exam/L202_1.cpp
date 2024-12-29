#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_N = 12;
const int INF = INT_MAX;

int n, k;
int dist[2 * MAX_N][2 * MAX_N];
vector<int> best_route;
int best_cost = INF;

// Hàm tính tổng chi phí của lộ trình
int calculate_cost(const vector<int>& route) {
    int cost = 0;
    int current_pos = 0; // Xe bắt đầu từ điểm 0
    for (int stop : route) {
        cost += dist[current_pos][stop];
        current_pos = stop;
    }
    cost += dist[current_pos][0]; // Quay lại điểm 0
    return cost;
}

// Hàm tạo lời giải ban đầu
vector<int> generate_initial_solution() {
    vector<int> route;
    // Đón các hành khách 1 đến n
    for (int i = 1; i <= n; i++) {
        route.push_back(i);
        route.push_back(i + n); // Sau đó trả hành khách từ n+1 đến 2n
    }
    return route;
}

// Hàm tìm kiếm cục bộ: hoán đổi hai điểm trong lộ trình
vector<int> local_search(const vector<int>& route) {
    vector<int> new_route = route;
    int i = rand() % (2 * n); // Chọn ngẫu nhiên một điểm
    int j = rand() % (2 * n); // Chọn ngẫu nhiên một điểm khác
    swap(new_route[i], new_route[j]); // Hoán đổi hai điểm
    return new_route;
}

// Hàm thực hiện perturbation: đảo ngược một đoạn của lộ trình
vector<int> perturbation(const vector<int>& route) {
    vector<int> new_route = route;
    int i = rand() % (2 * n);
    int j = rand() % (2 * n);
    if (i > j) swap(i, j); // Đảm bảo i < j
    reverse(new_route.begin() + i, new_route.begin() + j + 1);
    return new_route;
}

// Thuật toán ILS
void iterated_local_search() {
    vector<int> current_route = generate_initial_solution();
    int current_cost = calculate_cost(current_route);
    
    best_route = current_route;
    best_cost = current_cost;
    
    int iterations = 1000; // Số lần lặp tối đa
    for (int iter = 0; iter < iterations; iter++) {
        vector<int> new_route = local_search(current_route);
        int new_cost = calculate_cost(new_route);
        
        // Nếu lời giải mới tốt hơn, cập nhật lời giải hiện tại
        if (new_cost < current_cost) {
            current_route = new_route;
            current_cost = new_cost;
        } else {
            // Nếu không tốt hơn, thử thực hiện perturbation
            current_route = perturbation(current_route);
            current_cost = calculate_cost(current_route);
        }
        
        // Cập nhật lời giải tốt nhất toàn cục
        if (current_cost < best_cost) {
            best_route = current_route;
            best_cost = current_cost;
        }
    }
}

int main() {
    srand(time(0)); // Khởi tạo seed ngẫu nhiên

    cin >> n >> k;

    // Đọc vào ma trận khoảng cách
    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j <= 2 * n; j++) {
            cin >> dist[i][j];
        }
    }

    // Thực hiện thuật toán ILS
    iterated_local_search();

    // Xuất kết quả
    cout << best_cost << endl;

    return 0;
}

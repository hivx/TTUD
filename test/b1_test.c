#include <stdio.h>
#include <stdlib.h>

const int MAX_VALUE = 100000 + 7;

int pair_of_2(int n, int* a) {
    // Dùng malloc để cấp phát bộ nhớ cho mảng tần suất
    int* freq = (int*)calloc(MAX_VALUE + 1, sizeof(int)); // Khởi tạo với 0
    int count = 0;

    // Tính tần suất của mỗi phần tử
    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
    }

    // Tính số cặp cho từng phần tử
    for (int i = 0; i <= MAX_VALUE; i++) {
        if (freq[i] > 1) {
            count += (freq[i] * (freq[i] - 1)) / 2; // Cách tính tổ hợp C(n, 2)
        }
    }

    // Giải phóng bộ nhớ đã cấp phát
    free(freq);

    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    // Cấp phát bộ nhớ cho mảng a
    int* a = (int*)malloc(n * sizeof(int));

    // Kiểm tra xem việc cấp phát bộ nhớ có thành công không
    if (a == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Nhập các giá trị cho mảng a
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    // Tính và in kết quả
    printf("%d", pair_of_2(n, a));

    // Giải phóng bộ nhớ đã cấp phát
    free(a);

    return 0;
}

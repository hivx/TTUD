#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 2;
int n;
long long res = LLONG_MIN, a[N];

void inp() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
}

void proc() {
    long long f[2] = {LLONG_MAX, LLONG_MAX};
    long long sum = 0;

    for (int i = 1; i <= n; i++) {
        sum += a[i];
        int tmp = (sum % 2 + 2) % 2; // Đảm bảo tmp luôn là 0 hoặc 1

        if (f[tmp] != LLONG_MAX) {
            res = max(res, sum - f[tmp]);
        }

        f[tmp] = min(f[tmp], sum);
    }

    if (res == LLONG_MIN)
        cout << "NOT_FOUND\n";
    else
        cout << res << "\n";
}

int main() {
    inp();
    proc();
    return 0;
}

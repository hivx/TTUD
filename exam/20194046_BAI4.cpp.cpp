#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100005;

int n;
int a[N];
int f[N];

int main() {
cin >> n;
for (int i = 0; i < n; i++) {
cin >> a[i];
}
for (int i = n - 1; i >= 0; i--) {
if (i + 2 < n) {
f[i] = max(f[i + 1], f[i + 2] + a[i]);
} else {
f[i] = f[i + 1];
}
if (i + 3 < n) {
f[i] = max(f[i], f[i + 3] + a[i] + a[i + 1]);
}
}
cout << f[0]+a[n-1] << endl;
return 0;
}

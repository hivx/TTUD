#include<bits/stdc++.h>
using namespace std;

const int N = 100005;
int n, L1, L2, a[N], f[N];

int main()
{
    cin >> n >> L1 >> L2;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        f[i] = a[i];
        for (int j = max(i - L2, 0); j < i - L1; j++)
            f[i] = max(f[i], f[j] + a[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, f[i]);
    cout << ans << endl;
    return 0;
}

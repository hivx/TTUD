#include<bits/stdc++.h>
#define MAX_N 35
#define MAX_M 12
using namespace std;

int m, n, ans, ans2 = -1;
int head[MAX_N], to[MAX_N*MAX_N], nex[MAX_N*MAX_N], cnt;
bool flag[MAX_N];
int f[MAX_M];
vector<int> a[MAX_M];

void add(int x, int y)
{
    to[++cnt] = y;
    nex[cnt] = head[x];
    head[x] = cnt;
}

bool dfs(int x, int num)
{
    if (x == n + 1)
    {
        ans2 = max(ans2, num);
        return 1;
    }
    bool flag1 = 0;
    for (int i = 1; i <= m; i++)
    {
        if (flag[i])
            continue;
        for (int j = 0; j < a[i].size(); j++)
        {
            int v = a[i][j];
            if (flag[v])
                continue;
            flag[i] = flag[v] = 1;
            if (dfs(x + 1, num + 1))
                flag1 = 1;
            flag[i] = flag[v] = 0;
        }
    }
    if (flag1 == 0)
        return 0;
    return 1;
}

int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        int k;
        cin >> k;
        while (k--)
        {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
    }
    int k;
    cin >> k;
    while (k--)
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    for (int i = 1; i <= n; i++)
    {
        memset(flag, 0, sizeof flag);
        flag[i] = 1;
        ans = 1;
        if (dfs(1, 1))
            break;
    }
    cout << ans2 + 1 << endl;
    return 0;
}


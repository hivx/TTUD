// Description
// Có n thành phố 1, 2, ..., n. Giữa 2 thành phố i và j có thể có 1 con đường (2 chiều) kết nối giữa chúng. 
// Mỗi thành phố i có tuyến buýt i với C[i] là giá vé mỗi khi lên xe và D[i] là số thành phố tối đa mà buýt i có thể đi đến trên 1 hành trình đi qua các con đường kết nối.
// Hãy tìm cách đi từ thành phố 1 đến thành phố n với số tiền phải trả là ít nhất
// Input
// Dòng 1: chứa 2 số nguyên dương n và m trong đó n là số thành phố và m là số con đường kết nối các thành phố (1 <= n <= 5000, 1 <= m <= 10000)
// Dòng i+1 (i = 1,2,...,n): chứa 2 số nguyên dương C[i] và D[i] (1 <= C[i] <= 10000, 1 <= D[i] <= 100)
// Dòng n+1+i (i = 1, 2, ..., m): chứa 2 số nguyên dương i và j trong đó giữa thành phố i và j có con đường kết nối
// Output
// Số tiền tối thiểu phải bỏ ra để đi buýt từ thành phố 1 đến thành phố n

// Example
// Input
// 6 6
// 10 2
// 30 1
// 50 1
// 20 3
// 30 1
// 20 1
// 1 2
// 1 3
// 1 5
// 2 4
// 2 5
// 4 6
// Output
// 30

// Giải thích: 
// -Lên buýt 1 từ thành phố 1 đến thành phố 4 mất 10 đồng
// -Lên buýt 4 từ thành phố 4 đến thành phố 6 mất 20 đồng
// Tổng cộng mất 10 + 20 = 30 đồng
#include <bits/stdc++.h>
#define ft(i,x,y) for(int i=x;i<=y;i++)
using namespace std;

int n,m;

long long c[5001], d[5001];

long long f[5001][5001];
vector <int> X[5001];
typedef struct pair<long long, long long> ii;
typedef struct pair<ii, int> iii;
priority_queue<iii, vector <iii>, greater<iii> > pri;
long long find_path(int start, int finish)
{
    ft(i,1,n)
    {
        ft(j,0,n)
        {
            f[i][j] = 1e18;
        }
    }
    f[start][d[start]] = c[start];
    pri.push(
        iii(
            ii(
                f[start][d[start]],
                d[start]
            ),
            start
        )
    );
    while(!pri.empty())
    {
        int u = pri.top().second;
        long long cost = pri.top().first.first;
        int remaining_des = pri.top().first.second;

        pri.pop();
        
        if(cost != f[u][remaining_des]) continue;
        if(u == finish) return cost;
        for(int v: X[u])
        {
            if(remaining_des > 0)
            {
                if(f[v][remaining_des - 1] > cost)
                {
                    f[v][remaining_des-1] = cost;
                    pri.push(
                        iii(
                            ii(
                                cost,
                                remaining_des - 1
                            ),
                            v
                        )
                    );
                }
                if(f[v][d[v]] > cost + c[v])
                {
                    f[v][d[v]] = cost + c[v];
                    pri.push(
                        iii(
                            ii(
                                cost + c[v],
                                d[v]
                            ),
                            v
                        )
                    );
                }
            }
        }
    }
    return -1;
}
int main()
{
    // freopen("./text.input","r",stdin);
    cin>>n>>m;
    ft(i,1,n)
    {
        cin>>c[i]>>d[i];
    }
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        X[a].push_back(b);
        X[b].push_back(a);
    }

    cout<<find_path(1, n);
    return 0;
}

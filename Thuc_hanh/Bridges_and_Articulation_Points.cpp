// Description
// Given an undirected graph containing N vertices and M edges, find all the articulation points and the bridges in the graph.
// Input
// The first line consists of two space-separated integers denoting N and M, 
// M lines follow, each containing two space-separated integers X and Y denoting there is an edge between X and Y.
// Output
// One line consists of two integers denoting the number of articulation points and the number of bridges.
// Example
// Input
// 10 12
// 1 10
// 10 2
// 10 3
// 2 4
// 4 5
// 5 2
// 3 6
// 6 7
// 7 3
// 7 8
// 8 9
// 9 7
// Output
// 4  3
#include <bits/stdc++.h>
#define ft(i,x,y) for(int i = x; i<=y;i++)
using namespace std;

int n,m;
int num[100001], low[100001], cnt= 0;
bool critical_point[100001];

int p[100001];
vector <int> X[100001];

int edge = 0;
int point = 0;

void run(int u)
{
    num[u]=low[u] = ++cnt;
    int numChild = 0;
    for(int v: X[u])
    {
        if(p[u] == v) continue;
        if(num[v])
        {                                                                                                                    
            low[u] = min(low[u], num[v]);                                                  
        }
        else
        {
            p[v] = u;
            run(v);
            low[u] = min(low[u], low[v]);
            numChild ++;
            if(low[v] >= num[v]) edge ++;
            if(u == p[u])
            {
                if(numChild >= 2)
                {
                    critical_point[u] = true;
                }
            }
            else
            {
                if(low[v] >= num[u])
                {
                    critical_point[u] = true;
                }
            }
        }
    }
}
int main()
{
    // freopen("./text.input","r",stdin);
    cin>>n>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        X[a].push_back(b);
        X[b].push_back(a);
    }
    ft(i, 1, n)
    {
        p[i] = i;
    }
    ft(i,1, n)
    {
        if(!num[i]) run(i);
    }
    ft(i,1,n)
    {
        point += critical_point[i];
    }
    cout<<point<<" "<<edge;
    return 0;
}

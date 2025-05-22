#include <bits/stdc++.h>
#define ft(i, x, y) for(int i = x;i<=y;i++)
using namespace std;

int n,m;
int duration[10001];

int in[10001], out[10001];
int arrived[10001];
int start_time[10001];

vector <int> X[10001];

bool check_valid_graph()
{
    bool isHasNoInp = false;
    int count = 0;
    ft(i,1,n)
    {
        count+= (in[i] == 0);
    }
    if(count == 0) isHasNoInp = true;

    if(isHasNoInp == true) return false;
    ft(i, 1, n)
    {
        if(arrived[i] != in[i] ) return false;
    }
    return true;
}

void DFS(int u)
{
    if(in[u] != arrived[u]) return;
    for(int v: X[u])
    {
        arrived[v]++;
        start_time[v] = max(start_time[v], start_time[u] + duration[u]);
        DFS(v);
    }
}
int main()
{
    // freopen("./text.input","r",stdin);
    cin>>n>>m;
    ft(i,1,n)
    {
        cin>>duration[i];
    }
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        X[a].push_back(b);
        in[b] ++;
        out[a] ++;
    }
    ft(i,1,n)
    {
        if(in[i] == 0)
        {
            DFS(i);
        }
    }

    if(check_valid_graph() == false)
    {
        cout<<-1;
    }
    else
    {
        int res = -1 ;
        ft(i,1,n)
        {
            res = max(res, start_time[i] + duration[i]);
        }
        cout<<res;
    }
    return 0;
}
/*
Description
A project has n tasks 1,. . ., n. Task i has duration d(i) to be completed (i=1,. . ., n). There are precedence constraints between tasks represented by a set Q of pairs: for each (i,j)  in Q, task j cannot be started before the completion of task i. Compute the earliest completion time  of the project.
Input
Line 1: contains n and m (1 <= n <= 10
4
, 1 <= m <= 200000)
Line 2: contains d(1),. . ., d(n) (1 <= d(i) <= 1000)
Line i+3 (i=1,. . ., m) : contains i and j : task j cannot be started to execute before the completion of task i
Output
Write the earliest completion time of the project.
Example
Input
9 13
5 3 1 2 6 4 3 1 4
1 3
1 5
1 6
2 1
2 3
3 5
4 1
4 2
4 6
5 8
7 9
9 5
9 8

Output
18
*/
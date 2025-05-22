#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int N;// number of requests (1,2,...,N). Request i has pickup point i and drop-off point i + N
int cap;// number of places of the bus
int A[2*MAX+1][2*MAX+1];

int x[MAX];
int appear[MAX];// marking
int load;
int f;
int f_best;
int x_best[MAX];
int cmin;
void input(){
    scanf("%d%d",&N,&cap);
    cmin = 1000000;
    for(int i = 0; i <= 2*N;  i++){
        for(int j= 0; j <= 2*N; j++){
            scanf("%d",&A[i][j]);
            if(i != j && cmin > A[i][j]) cmin = A[i][j];
        }
    }

}

int check(int v, int k){
    if(appear[v] == 1) return 0;
    if(v >N){
        if(!appear[v-N]) return 0;
    }else{
        if(load + 1 > cap) return 0;
    }
    return 1;
}
void solution(){
    if(f + A[x[2*N]][0] < f_best){
        f_best = f + A[x[2*N]][0];
        for(int i = 0; i <= 2*N; i++) x_best[i] = x[i];
        //printf("update best %d\n",f_best);
    }
}
void TRY(int k){
    for(int v = 1; v <=2*N; v++){
        if(check(v,k)){
            x[k] = v;
            f += A[x[k-1]][x[k]];
            if(v <= N) load += 1; else load += -1;
            appear[v] = 1;
            if(k == 2*N) solution();
            else{
                if(f + (2*N+1-k)*cmin < f_best)
                    TRY(k+1);
            }
            if(v <= N) load -= 1; else load -= -1;
            appear[v] = 0;
            f -= A[x[k-1]][x[k]];
        }
    }
}
void solve(){
    load = 0;
    f = 0;
    f_best = 1000000;
    for(int i = 1; i <= 2*N; i++) appear[i] = 0;
    x[0] = 0;// starting point
    TRY(1);
    printf("%d",f_best);
}
void print(){
    for(int i = 0; i <= 2*N; i++) printf("%d ",x_best[i]);
}
int main(){
    input();
    solve();
  return 0;
}
// Description
// There are n passengers 1, 2, …, n. The passenger i want to travel from point i to point i + n (i = 1,2,…,n). There is a bus located at point 0 and has k places for transporting the passengers (it means at any time, there are at most k passengers on the bus). You are given the distance matrix c in which c(i,j) is the traveling distance from point i to point j (i, j = 0,1,…, 2n). Compute the shortest route for the bus, serving n passengers and coming back to point 0. 
// Input
// Line 1 contains n and k (1≤n≤11,1≤k≤10)
//  Line i+1 (i=1,2,…,2n+1) contains the (i−1)
// th
//  line of the matrix c (rows and columns are indexed from 0,1,2,..,2n).
// Output
// Unique line contains the length of the shortest route.
// Example
// Input
// 3  2
// 0  8  5  1  10  5  9
// 9  0  5  6  6  2  8
// 2  2  0  3  8  7  2
// 5  3  4  0  3  2  7
// 9  6  8  7  0  9  10
// 3  8  10  6  5  0  2
// 3  4  4  5  2  2  0
// Output
// 25
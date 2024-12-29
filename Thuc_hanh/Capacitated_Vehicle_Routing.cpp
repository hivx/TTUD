#include <stdio.h>
#define MAX 50
#define INF 1e9
int n,K,Q;
int d[MAX];
int c[MAX][MAX];

int x[MAX]; // x[i] is the next point of i (i = 1,...,n), x[i] \in {0,1,...,n}
int y[MAX];// y[k] is the start point of route k
int x_best[MAX]; // x[i] is the next point of i (i = 1,...,n), x[i] \in {0,1,...,n}
int y_best[MAX];// y[k] is the start point of route k

int visited[MAX];// visited[i] = 1 means that client point i has been visited
int fd[MAX];// fd[k] is the distance of kth route
int load[MAX];// load[k] is the accumulate load of kth route
int f;// total distance of the current solution
int f_best;
int segments;// number of segments accumulated
int nbRoutes;
int cmin;
void inputFile(char* fi){
    freopen(fi,"r",stdin);
    scanf("%d%d%d",&n,&K,&Q);

    for(int i = 1; i <= n; i++){
        scanf("%d",&d[i]);
    }
    d[0] = 0;
    cmin = 1e9;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            scanf("%d",&c[i][j]);
            if(i != j && cmin > c[i][j]) cmin = c[i][j];
        }
    }

}
void input(){
    scanf("%d%d%d",&n,&K,&Q);


    for(int i = 1; i <= n; i++){
        scanf("%d",&d[i]);
    }
    d[0] = 0;
    cmin = 1e9;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            scanf("%d",&c[i][j]);
            if(i != j && cmin > c[i][j]) cmin = c[i][j];
        }
    }

}

void solution(){
   // printSol();
    if(f < f_best){
        f_best = f;

    }
}
void printSol(){
    int tf = 0;
    for(int k = 1; k <= K; k++){
        int s = y[k];
        tf += c[0][y[k]];
        printf("c[%d,%d] = %d, tf = %d\n ",0,y[k],c[0][y[k]],tf);
        for(int v = s; v != 0; v = x[v]){
            tf += c[v][x[v]];
            printf("c[%d,%d] = %d, tf = %d\n ",v,x[v],c[v][x[v]],tf);
        }
    }
    for(int k = 1; k <= K; k++){
        int s = y[k];
        printf("route[%d]:  0 ",k);
        for(int v = s; v != 0; v = x[v]){
            printf("%d ",v);
        }
        printf("0\n");
    }
    printf("f = %d\n",f);
}
void printBestSol(){
    for(int k = 1; k <= K; k++){
        int s = y_best[k];
        printf("best route[%d]:  0 ",k);
        for(int v = s; v != 0; v = x_best[v]){
            printf("%d ",v);
        }
        printf("0\n");
    }
    printf("f_best = %d\n",f_best);
}
void printStatus(){
    for(int i = 1; i <= n; i++) printf("%d ",x[i]); printf("\n");
    for(int i = 1; i <= n; i++) printf("%d ",visited[i]); printf("\n");

}
int checkX(int v,int k){
    if(v > 0 && visited[v]) return 0;
    if(load[k] + d[v] > Q) return 0;
    return 1;
}
void TRY_X(int s, int k){


    if(s == 0){
        if(k < K)
            TRY_X(y[k+1],k+1);
        return;
    }
    for(int v = 0; v <= n; v++){
        if(checkX(v,k)){

            x[s] = v;
            visited[v] = 1;
            f += c[s][v];
            load[k] += d[v];
            segments++;
            if(v > 0){
                if(f + (n+nbRoutes - segments)*cmin < f_best)
                    TRY_X(v,k);
            }else{
                if(k == K){
                        if(segments == n+nbRoutes) solution();
                }else{
                    if(f + (n+nbRoutes - segments)*cmin < f_best)
                        TRY_X(y[k+1],k+1);
                }
            }
            segments--;
            load[k] -= d[v];
            f -= c[s][v];
            visited[v] = 0;
        }
    }
}
int checkY(int v, int k){
    if(v == 0) return 1;
    if(load[k] + d[v] > Q) return 0;
    return !visited[v];
}
void TRY_Y(int k){

    for(int v = (y[k-1]==0 ? 0 : y[k-1] + 1); v <= n; v++){
        if(checkY(v,k)){
            y[k] = v;
            if(v > 0) segments += 1;
            visited[v] = 1;
            f += c[0][v];
            load[k] += d[v];
            if(k < K){
                TRY_Y(k+1);
            }else{

                nbRoutes = segments;
                TRY_X(y[1],1);
            }
            load[k] -= d[v];
            f -= c[0][v];
            visited[v] = 0;
            if(v > 0) segments -= 1;
        }
    }
}
void solve(){
    f = 0;
    f_best = INF;
    for(int v = 1; v <= n; v++) visited[v] = 0;
   // printf("start TRY_Y...\n");
    y[0] = 0;
    TRY_Y(1);
    //printBestSol();
    if(f_best == INF) f_best = -1;
    printf("%d",f_best);
}

int main(){
    input();
    solve();
}
// Description
// A fleet of K identical trucks having capacity Q need to be scheduled to delivery pepsi packages from a central depot 0 to clients 1,2,…,n. Each client i requests d[i] packages. The distance from location i to location j is c[i,j], 0≤i,j≤n. A delivery solution is a set of routes: each truck is associated with a route, starting from depot, visiting some clients and returning to the depot for deliverying requested pepsi packages such that:
// Each client is visited exactly by one route
// Total number of packages requested by clients of each truck cannot exceed its capacity
// Goal
// Find a solution having minimal total travel distance
// Note that: 
// There might be the case that a truck does not visit any client (empty route)
// The orders of clients in a route is important, e.g., routes 0 -> 1 -> 2 -> 3 -> 0 and 0 -> 3-> 2 -> 1 -> 0 are different.
// Input
// Line 1: n,K,Q (2≤n≤12,1≤K≤5,1≤Q≤50)
// Line 2: d[1],...,d[n](1≤d[i]≤10)
// Line i+3 (i=0,…,n): the i
// th
//  row of the distance matrix c (1≤c[i,j]≤30)
// Output
// Minimal total travel distance
// Example
// Input
// 4 2 15
// 7 7 11 2
// 0 12 12 11 14
// 14 0 11 14 14
// 14 10 0 11 12
// 10 14 12 0 13
// 10 13 14 11 0

// Output
// 70
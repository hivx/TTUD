#include <stdio.h>
const int N=100;
int a[N];
int main(){
    int n;
    printf("n = "); scanf("%d\n", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int tg;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] > a[j]){
                tg = a[i];
                a[i] = a[j];
                a[j] = tg;       
            }
        }
    }
        
    for(int i = 0; i < n; i++){
        printf("%d", a[i]);
    }
}

#include<bits/stdc++.h>
using namespace std;
int n, L1, L2;
const int N=100100;
int a[N], f[N];
int main(){
cin >> n >> L1 >> L2;
for(int i=1;i<=n;i++){
cin >> a[i];
}
for(int i=1;i<=n;i++){
int mx=0;
for(int j=max(1,i-L2);j<=i-L1;j++){
mx=max(mx,f[j]);
}
f[i]=mx+a[i];
}
int ans=0;
for(int i=1;i<=n;i++){
ans=max(ans,f[i]);
}
cout << ans << endl;
return 0;
}

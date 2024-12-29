#include <iostream>
#include <cmath>
using namespace std;

const int N=1000005;

int n, a[N], ans;

int main()
{
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>a[i];
        if (a[i]%2==0) ans=max(ans, a[i]);
    }
    int sum=0, flag=0;
    for (int i=0; i<n; i++)
    {
        sum+=a[i];
        if (sum%2==0) flag=1, ans=max(ans, sum);
        if (sum==0) flag=1, ans=max(ans, sum);
        if (sum<0) sum=0;
    }
    if (!flag) cout<<"NOT_FOUND"<<endl;
    else cout<<ans<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
int main()
{
    ll n;
    cin>>n;
    ll d=2;
    ll ans=1;
    for(int i=1;i<=n;i++)
    {
        ans=(ans%mod*d%mod)%mod;
    }
    cout<<ans<<endl;
}
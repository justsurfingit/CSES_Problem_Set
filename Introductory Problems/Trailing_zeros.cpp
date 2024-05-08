#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
int main()
{
    ll n;
    cin>>n;
    ll d=5;
    ll ans=0;
    while(n)
    {
        ans+=(n/5);
        n/=5;
    }
    cout<<ans<<endl;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
int main()
{
    ll n;
    cin>>n;
    while(n--)
    {
        ll a,b;
        cin>>a>>b;
        if((a+b)%3)
        {
            cout<<"NO\n";
        }
        else{
            ll sm=min(a,b);
            ll bg=max(a,b);
            if(bg<=sm*2)
            {
                cout<<"YES\n";
            }
            else cout<<"NO\n";
        }
    }
}
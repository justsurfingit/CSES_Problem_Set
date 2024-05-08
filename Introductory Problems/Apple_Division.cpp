#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin>>n;
    vector<ll>arr(n);
    ll s=0;
    for(auto &i : arr)
    {
        cin>>i;
        s+=i;
    }
    ll maxi=1e15;
    for(ll i=0;i<(1<<n);i++)
    {
        ll temp=i;
        ll val=0;
        int c=0;
        while(temp)
        {
            if(temp&1)
            {
                val+=arr[c];
            }
            temp/=2;
            c++;
        }
        ll d=abs(val-(s-val));
        maxi=min(maxi,d);
    }
    cout<<maxi<<endl;
}
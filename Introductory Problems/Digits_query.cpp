#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ca;
bool good(ll req,ll val)
{
    ll cur=0;
    // for(ll i=1;)
    ll a=1;
    while(true)
    {
        if(a>val )
        {
            // so this is out of the bound so can't be traced
            break;
        }
        ll d=log10(a)+1;
        ll temp=min((ll)(a*10-1),val);
        cur+=((1ll)*(temp-a+1)*d);
        a=(1ll)*a*(10);
    }
    ca=cur;
    // cout<<cur<<endl;
    return cur>=req;
}
int main()
{
    // cout<<good(12,11)<<endl;
   bool a=good(19,16);
   int q;
   cin>>q;
   while(q--)
   {
    ll x;
    cin>>x;
    ll l=1,r=1;
    // cout
    while(!good(x,r))
    {
        r=(1ll)*r*2;
    }
    ll value=0;
    while(l<=r)
    {
        ll m=(l+r)/2;
        if(!good(x,m))
        {
            value=m;
            l=m+1;
        }else r=m-1;
    
    }
    // to get the digit count till now
    // created a variable for storing that 
    good(x,value);
    ll nexo=value+1;
    string num=to_string(nexo);
    // cout<<ca<<endl;
    ll left=x-ca;
    int last=value%10;
    char ch=char(last+'0');
    int in=0;
    // cout<<value<<endl;
    // cout<<left<<endl;
    while(in<num.length() and left--)
    {
        ch=num[in++];

    }
    cout<<ch<<endl;
    
   }
   cout<<endl;
}
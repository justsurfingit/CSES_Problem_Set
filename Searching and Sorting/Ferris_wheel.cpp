#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    cin>>n>>x;
    vector<int>arr(n);
    for(auto &i:arr)cin>>i;
    sort(arr.begin(),arr.end());
    int i=0,j=n-1;
    int ans=0;
    while(i<=j)
    {
        if(i==j)
        {
            ans++;
            break;
        }
        if(arr[i]+arr[j]<=x)
        {
            ans++;
            i++;
            j--;
        }
        else{
            ans++;
            j--;
        }
    }
    cout<<ans<<endl;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>arr(n);
    multiset<int>rooms;
    for(auto &i:arr)
    {
        cin>>i;
    }
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        rooms.insert(x);
    }
    sort(arr.begin(),arr.end());
    int ans=0;
    for(auto i:arr)
    {
        //search for it
        auto it=rooms.lower_bound(i-k);
        if(it==rooms.end() or *it>i+k)continue;
        ans++;
        rooms.erase(it);
    }

    cout<<ans<<endl;

}
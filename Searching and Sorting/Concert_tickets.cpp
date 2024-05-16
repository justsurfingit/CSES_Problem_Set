#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    multiset<int>arr;
    vector<int>p(m);
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.insert(-x);
    }
    for(auto &i:p)
    {
        cin>>i;
        auto it=arr.lower_bound(-i);
        if(it==arr.end())
        {
            cout<<-1<<endl;
        }
        else{
            cout<<abs(*it)<<endl;
            arr.erase(it);
            
        }
    }
   
}
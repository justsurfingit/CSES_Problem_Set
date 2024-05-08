#include<bits/stdc++.h>
using namespace std;
vector<string>arr(8);
int row[8];
int col[8];
int is_safe(int x,int y)
{
    if(row[x] or col[y])return false;
    // dia
    int tx=x,ty=y;
    while(tx>-1 and ty>-1)
    {
        if(arr[tx][ty]=='Q')
        {
            return false;
        }
        tx--; ty--;
    }
    tx=x,ty=y;
    while(tx<8 and ty>-1)
    {
         if(arr[tx][ty]=='Q')
        {
            return false;
        }
        tx++;
        ty--;
    }
    return true;
}
int solve(int co)
{
    if(co==8)
    {
        return 1;
    }
    //just safety check 
    int ans=0;
    for(int i=0;i<8;i++)
    {
        if(arr[i][co]!='*' and is_safe(i,co))
        {
            arr[i][co]='Q';
            row[i]++;
            col[co]++;
            ans+=solve(co+1);
            arr[i][co]='.';
            row[i]--;
            col[co]--;
        }
    }
    return ans;

}
int main()
{
    
    for(auto &i:arr)
    {
        cin>>i;
    }
    cout<<solve(0)<<endl;

}
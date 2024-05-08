#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<(1<<n);i++)
    {
        int temp=i;
        string b;
        for(int j=0;j<n;j++)
        {
            if(temp&1)
            {
                b.push_back('1');
            }
            else b.push_back('0');
            temp/=2;
        }
        reverse(b.begin(),b.end());
        string ans;
        ans+=b[0];
        for(int i=1;i<n;i++)
        {
            int val=(b[i]-'0')^(b[i-1]-'0');
            if(val)
            {
                ans.push_back('1');
            }
            else ans.push_back('0');
        }
        cout<<ans<<endl;

    }

}

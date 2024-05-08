#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    vector<int>alp(26);
    for(auto i:s)alp[i-'A']++;
    string ans=s;
    if(n&1)
    {
        //only single odd is req
        int o=0;
        char ch;
        int c=0;
        for(auto i:alp)
        {
            if(i&1)
            {
                ch=char(c+'A');
                o++;
            }
            c++;
        }
        if(o!=1)
        {
            ans="NO SOLUTION";
        }
        else{
            ans[n/2]=ch;
            // cout<<ans[n/2]<<endl;
            alp[ch-'A']--;
            int i=0;
            int c=0;
            while(i<n/2)
            {   
                while(c<26 and !alp[c])
                {
                    c++;
                }
                ans[i]=char('A'+c);
                alp[c]-=2;
                ans[n-1-i]=ans[i];
                i++;
            }
            // cout<<endl;
        }
    }
    else{
        //all must be even
        int o=0;
        char ch;
        for(auto i:alp)
        {
            if(i&1)
            {
                ch=i;
                o++;
            }
        }
        if(o)
        {
            ans="NO SOLUTION";
        }
        else{

            int i=0;
            int c=0;
            while(i<n/2)
            {   
                while(c<26 and !alp[c])
                {
                    c++;
                }
                ans[i]=char('A'+c);
                ans[n-1-i]=ans[i];
                alp[c]-=2;
                i++;
            }
            // cout<<endl;
    }
    }
    cout<<ans<<endl;

}
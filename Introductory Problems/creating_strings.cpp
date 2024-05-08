#include<bits/stdc++.h>
using namespace std;
vector<string>ans;
//now got to truly know how it works...
void solve(int in,string &s)
{
    if(in==s.length())
    {
        // cout<<s<<endl;
        ans.push_back(s);
        return;
    }
    vector<int>alp(26);
    for(int i=in;i<s.length();i++)
    {
        // if(i!=in and s[i]==s[i-1])continue;
        if(alp[s[i]-'a'])continue;
        alp[s[i]-'a'] ++;
        swap(s[in],s[i]);
        solve(in+1,s);
        swap(s[in],s[i]);
    }

}
int main()
{
    string s;
    cin>>s;
    sort(s.begin(),s.end());

    solve(0,s);
    
     cout<<ans.size()<<endl;
     sort(ans.begin(),ans.end());
    for(auto i:ans)cout<<i<<endl;  
}
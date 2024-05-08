#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll x;
    cin >> x;
    for (ll i = 1; i <= x; i++)
    {
        ll tot = ((i * i) * (i * i - 1)) / 2;
        ll dan = (1ll) * (i - 2) * (i - 1) * 4;
        dan = max(dan, (ll)0);
        cout << tot - dan << endl;
    }

}
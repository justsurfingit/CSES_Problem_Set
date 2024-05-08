#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin >> n;
    ll sum = (1ll) * (n) * (n + 1) / 2;
    // cout << sum << endl;
    //overflow can be very problematics we must handle them at any cost
    if (sum & 1)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        ll req = sum / 2;
        map<ll, int>taken;

        ll cur = 0;
        for (int i = n; i >= 1; i--)
        {
            if ((cur + i) <= req)
            {
                cur += i;
                taken[i]++;
            }
            if (cur == req)
            {
                break;
            }
        }
        cout << taken.size() << endl;
        int a = 0;
        for (int i = 1; i <= n; i++)
        {
            if (taken[i])
            {
                cout << i << " ";
                a++;
            }
        }
        cout << endl;
        // cout<<n<<endl;
        cout << n - a << endl;
        for (int i = 1; i <= n; i++)
        {
            if (!taken[i])cout << i << " ";
        }
        cout << endl;
    }
}


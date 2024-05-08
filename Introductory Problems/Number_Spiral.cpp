#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll x, y;
        cin >> x >> y;
        if (x == 1 and y == 1)
        {
            cout << 1 << endl;
            continue;
        }
        ll maxi = max(x, y);
        ll sm = (((maxi - 1)) * (2 + (maxi - 2) * 2)) / 2 + 1;
        ll big = (maxi ) * (2 + (maxi - 1) * 2) / 2;
        // cout << sm << " " << big << endl;
        ll val;
        if (maxi == x)
        {
            //x is fixed
            //so now let's figure out it's upper or lower end
            if (maxi & 1)
            {
                val = sm + y - 1;
            }
            else val = big - (y - 1);
        }
        else {
            if (!(maxi & 1))
            {
                val = sm + x - 1;
            }
            else val = big - (x - 1);
        }
        cout << val << endl;

    }
}
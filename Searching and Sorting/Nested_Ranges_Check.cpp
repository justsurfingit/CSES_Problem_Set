/*Author: justsurfing
Go hard or go home
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define pb push_back
#define mod 1000000007
#define inf 100000000000000000
#define CHAR 256
#define all(x) x.begin(), x.end()
#define limit 100005
#define loop(i, s, l, j) for(int i = s; i < l; i += j)
#define N  200005
ll fact[N + 1];
ll inv[N + 1];
ll invFact[N + 1];
bool isComputed = false;
void compute() {
    inv[0] = inv[1] = 1;

    for (int i = 2; i <= N; i++) {
        inv[i] = (inv[mod % i] * (mod - mod / i)) % mod;
    }

    invFact[0] = invFact[1] = 1;
    for (int i = 2; i <= N; i++) {
        invFact[i] = (invFact[i - 1] * inv[i]) % mod;
    }

    fact[0] = fact[1] = 1;
    for (int i = 2; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    isComputed = true;
}
ll ncr(ll n, ll k) {
    if (!isComputed) {
        printf("Call compute function, you idiot");
    }
    else {
        return (((fact[n] * invFact[k]) % mod) * invFact[n - k]) % mod;
    }
    return -1;
}
ll power( int x, int y)
{
    ll temp = x;
    ll result = 1;
    while (y > 0) {
        if ((y & 1) == 1) // y is odd
        {
            result = (result * temp) % mod;
        }
        temp = (temp * temp) % mod;
        y = y >> 1; // y=y/2;
    }
    return result % mod;
}
void SieveOfEratosthenes(int n, vector<int>&get)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++) {

        if (prime[p] == true) {

            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            // cout << p << " ";
            get.pb(p);
}
int main() {
    /*Uncommment for the sieve */
    //  vector<int>get;
    //     SieveOfEratosthenes(1000005,get);
    // compute();
    //uncomment this for calc nCr
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int t, n;
    // int mod=1e9+7;
    cin >> n;
    vector<pair<int, int>>arr(n);
    map<pair<int, int>, int>mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
        mp[ {arr[i].first, arr[i].second}] = i;
    }

    sort(all(arr), [](pair<int, int>&a, pair<int, int>&b)
    {
        if (a.first < b.first)return 1;
        if (a.first == b.first)
        {
            if (a.second > b.second)return 1;
            return 0;
        }
        return 0;
    });
    // for (auto i : arr)cout << i.first << " " << i.second << endl;
    //contained logic
    //for to be contained the conditions is the x must be smaller and y must be greater that's it
    int maxi = 0;
    maxi = arr[0].second;
    map<pair<int, int>, int>contained;
    contained[arr[0]] = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i].second <= maxi)
        {
            contained[arr[i]] = 1;
        }
        maxi = max(arr[i].second, maxi);
    }

    vector<int>contained_arr(n);
    for (auto i : contained)
    {
        contained_arr[mp[i.first]] = i.second;
    }

//container logic
    // now we have to check whether this contained other array or not
    int mini = arr[n - 1].second;
    // cout << mini << endl;
    map<pair<int, int>, int>container;
    container[arr[n - 1]] = 0;
    for (int i = n - 2; i > -1; i--)
    {
        if (arr[i].second >= mini)
        {
            container[arr[i]] = 1;
        }
        mini = min(arr[i].second, mini);
        // cout<
    }

    vector<int>containor_arr(n);
    for (auto i : container)
    {
        containor_arr[mp[i.first]] = i.second;
    }
    for (auto i : containor_arr)cout << i << " ";
    cout << endl;

    for (auto i : contained_arr)cout << i << " ";
    cout << endl;
    return 0;
}
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
	cin >> t;
	// 1. brute force | 2. two pointers | 3. Prefix sum | 4. Binary search
	// 5. DSA | 6. Graphs | 7. DP
	// constructive fucks //string
	while (t--)
	{
		// int mod=1e9+7;
		cin >> n;
		//we need sum of Ci and difference of max and min in Di's
		ll a;
		cin >> a;
		vector<ll>c(n), d(n);
		for (int i = 0; i < n; i++)
		{
			cin >> c[i] >> d[i];
		}
		//done
		ll maxi = 0;
		for (int i = 0; i < n; i++)
		{
			ll cmin = INT_MAX, cmax = I_MIN;
			ll su = 0;
			for (int j = i; j < n; j++)
			{
				ll el = j - i + 1;
				su += c[j];
				cmax = max(d[i], cmax);
				cmin = max(d[i], cmin);
				ll temp = el * a - (su) - (cmax - cmin) * (cmax - cmin);
				maxi = max(temp, maxi);
			}
		}
		cout << maxi << endl;


	}
	return 0;
}
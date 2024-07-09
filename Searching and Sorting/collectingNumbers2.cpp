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
	int n, m;
	cin >> n >> m;
	vector<int>arr(n);
	unordered_map<int, int>mp;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		mp[arr[i]] = i;
	}
	// good obseravating swapping two number can only break there grouping from next and previous element
	vector<pair<int, int>>q;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		x--; y--;
		q.push_back({x, y});
	}
	int in = 1;
	for (int i = 1; i < n; i++)
	{
		if (mp[i] > mp[i + 1])in++;
	}
	// cout << in << endl;
	for (auto i : q)
	{
		set<pair<int, int>>ex;
		if (arr[i.first] + 1 <= n)
			ex.insert({arr[i.first], arr[i.first] + 1});
		if (arr[i.first] - 1 > 0)
			ex.insert({arr[i.first] - 1, arr[i.first]});
		if (arr[i.second] + 1 <= n)
			ex.insert({arr[i.second], arr[i.second] + 1});
		if (arr[i.second] - 1 > 0)
			ex.insert({arr[i.second] - 1, arr[i.second]});
		// okay remove previous dependency
		// map<pair<int, int>, int>what;
		for (auto j : ex)
		{
			// cout << j.first << " " << j.second << endl;
			if (mp[j.first] > mp[j.second])
			{
				in--;
			}

		}
		// cout << endl;
		// cout << in << " " ;
		// s
		// cout << mp[arr[i.first]] << " " << mp[arr[i.second]] << endl;
		// swap(mp[arr[i.first]], mp[arr[i.second]]);
		swap(arr[i.first], arr[i.second]);
		mp[arr[i.first]] = i.first;

		mp[arr[i.second]] = i.second;


		// for (auto i : arr)cout << i << " ";
		// cout << endl;
		// for (int i = 1; i <= n; i++)cout << mp[i] << " ";
		// cout << endl;
		// cout << mp[arr[i.first]] << " " << mp[arr[i.second]] << endl;
		int c = 0;
		for (auto j : ex)
		{
			// cout << j.first << " " << j.second << endl;
			if (mp[j.first] > mp[j.second])
			{
				//after there  inversion
				// in--;
				// c++;

				in++;
			}

		}
		// cout << c << endl;
		cout << in << "\n";


	}
	cout << endl;
	return 0;
}
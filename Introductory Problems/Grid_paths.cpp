#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

unordered_map<char, pair<int, int>> mp;
string s;

ll arun = 0;
ll one = 0;
int visi[7][7];
// we can add great optimisation here to get he answer and solve this fast
//idea is to use alpha beta pruning and get the answer
bool prune(int row, int col)
{
	//upper wall
	//problem is when we hit a case where we have to choose between the left and right we can only choose one
	//and that's why all the paths can't be visitedb
	if (row == 0 and col >= 1 and col <= 5 and !visi[row][col - 1] and !visi[row][col + 1] and visi[row + 1][col])return 1;
	//down wall
	if (row == 6 and col >= 1 and col <= 5 and !visi[row][col - 1] and !visi[row][col + 1] and visi[row - 1][col])return 1;
	//left wall
	if (col == 0 and row >= 1 and row <= 5 and !visi[row - 1][col] and !visi[row + 1][col] and visi[row][col + 1])return 1;
	//right wall
	if (col == 6 and row >= 1 and row <= 5 and !visi[row - 1][col] and !visi[row + 1][col] and visi[row][col - 1])return 1;
	//wall all ended
	//now obstacles are to be
	//row obstacles
	if (row >= 1 and row <= 5 and col >= 1 and col <= 5)
	{
		if (visi[row + 1][col] and visi[row - 1][col] and !visi[row][col - 1] and !visi[row][col + 1])return 1;
		if (visi[row][col + 1] and visi[row][col - 1] and !visi[row - 1][col] and !visi[row + 1][col])return 1;
	}

	return 0;
}
ll dfs(int in, int row, int col) {

	if (in == s.length())
	{
		if (row == 6 and col == 0)
		{

			return 1;
		}
		return 0;
	}
	if (row == 6 and col == 0)return 0;
	if (visi[row][col])return 0;
	if (prune( row,  col))
	{
		return 0;
	}

	visi[row][col] = 1;
	ll ans = 0;
	if (s[in] == '?') {
		for (auto i : mp) {
			pair<int, int> p = i.second;
			if ((row + p.first) < 0 || (row + p.first) > 6 || (col + p.second) < 0 || (col + p.second) > 6 or visi[row + p.first][col + p.second] or prune(row + p.first, col + p.second)) continue;
			ans += dfs(in + 1, row + p.first, col + p.second);
		}
	} else {
		pair<int, int> p = mp[s[in]];
		if ((row + p.first) < 0 || (row + p.first) > 6 || (col + p.second) < 0 || (col + p.second) > 6 or visi[row + p.first][col + p.second] or prune(row + p.first, col + p.second))
		{
			ans += 0;

		}
		else ans += dfs(in + 1, row + p.first, col + p.second);
	}
	visi[row][col] = 0;
	return  ans;
}

int main() {
	cin >> s;
	mp['U'] = { -1, 0};
	mp['D'] = {1, 0};
	mp['L'] = {0, -1};
	mp['R'] = {0, 1};




	// cout << "va\n";
	// cout << s.length() << endl;
	cout << dfs(0, 0, 0) << endl;

	// cout << arun << endl;
	return 0;
}

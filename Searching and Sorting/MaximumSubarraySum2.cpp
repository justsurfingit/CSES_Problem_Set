#include <iostream>
#include <vector>
#include <climits>
typedef long long ll;
using namespace std;
#define pb push_back

class SegmentTree {
private:
	vector<int> tree;
	int n;

	void buildTree(const vector<int>& arr, int start, int end, int node) {
		if (start == end) {
			tree[node] = arr[start];
			return;
		}

		int mid = start + (end - start) / 2;
		buildTree(arr, start, mid, 2 * node + 1);
		buildTree(arr, mid + 1, end, 2 * node + 2);

		tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
	}

	int queryMin(int start, int end, int l, int r, int node) {
		if (start > r || end < l) {
			return INT_MAX;
		}

		if (start >= l && end <= r) {
			return tree[node];
		}

		int mid = start + (end - start) / 2;
		int leftMin = queryMin(start, mid, l, r, 2 * node + 1);
		int rightMin = queryMin(mid + 1, end, l, r, 2 * node + 2);

		return min(leftMin, rightMin);
	}

public:
	SegmentTree(const vector<int>& arr) {
		n = arr.size();
		tree.resize(4 * n);
		buildTree(arr, 0, n - 1, 0);
	}

	int queryMin(int l, int r) {
		return queryMin(0, n - 1, l, r, 0);
	}
};

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	vector<int>arr(n), pre;
	ll s = 0;
	pre.pb(0);
	for (auto &i : arr)
	{
		cin >> i;
		s += i;
		pre.pb(s);
	}
	SegmentTree seg(pre);
	int maxi = INT_MIN;
	// for (auto i : pre)cout << i << " ";
	// cout << endl;
	// cout << seg.queryMin(2, 5) << endl;
	for (int i = a; i <= n; i++)
	{
		int r = max(i - a , 0);
		int l = max(i - b, 0);
		int mini = seg.queryMin(l, r);
		int cur = pre[i] - mini;
		maxi = max(maxi, cur);
	}
	cout << maxi << endl;

	return 0;
}

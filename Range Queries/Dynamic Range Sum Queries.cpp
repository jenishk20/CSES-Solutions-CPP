#include<bits/stdc++.h>
using namespace std;



#define ff              first
#define ss              second
#define int             long long


#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define all(a)      (a).begin(),(a).end()
#define pb push_back


#define light             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using mii = map<int, int>;
using pii = pair<int, int>;

const long long   M = 1e9 + 7;
void io() {
#ifndef  ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
#endif
}

class Fenwick {
private:
	vi BIT;
public:

	Fenwick(int n)
	{
		BIT = vi(n + 1, 0);
	}
	void update(int idx, int val, int n)
	{
		while (idx <= n)
		{
			BIT[idx] += val;
			idx = idx + (idx & -idx);
		}
	}
	int getSum(int idx)
	{
		int sum = 0;
		while (idx >= 1)
		{
			sum += BIT[idx];
			idx -= (idx & -idx);
		}
		return sum;
	}
	int rangeSum(int l, int r)
	{
		return getSum(r) - getSum(l - 1);
	}
};
void solve()
{

	int n, q;
	cin >> n >> q;

	vi a(n);
	int i;
	Fenwick fen(n + 1);
	for (i = 0; i < n; i++) {

		cin >> a[i];
		fen.update(i + 1, a[i], n);
	}

	while (q--)
	{
		int type, l, r;
		cin >> type >> l >> r;

		if (type == 1)
		{
			fen.update(l, r - fen.rangeSum(l, l), n);
		}
		else
		{

			cout << fen.rangeSum(l, r) << endl;
		}

	}

}
int32_t main()
{
	io();
	light;
	int tc = 1;
	//cin >> tc;
	while (tc--) {

		solve();

	}
}


